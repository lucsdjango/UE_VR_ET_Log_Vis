# VR Eye-Tracking Logger & Visualizer

Unreal Engine plugin for logging eye-tracking and head-tracking data from a VR headset to TSV files, computing fixations with a VR-centered I-DT algorithm [Llanes-Jurado et al. 2020](https://www.mdpi.com/1424-8220/20/17/4956), and replaying/visualizing the recorded gaze data in the editor. 

Developed and tested with Unreal Engine 5.7.

## Installation

1. Copy the `VRETLogger` folder into your project's `Plugins/` directory (create it if it does not exist).
2. Open the project. If you installed a source-only copy, accept the prompt to rebuild the plugin module (requires a C++ toolchain; a prebuilt copy needs no compiler).
3. Enable the plugin under **Edit > Plugins > Virtual Reality > VR Eye-Tracking Logger** if it is not already enabled, and restart the editor. The required *Python Editor Script Plugin* and *Editor Scripting Utilities* plugins are enabled automatically.
4. Enable an OpenXR eye-tracking source for your headset (e.g. *OpenXR Eye Tracker* plugin).
5. To see the plugin's blueprints in the Content Browser, enable **Settings > Show Plugin Content**. They are under `Plugins/VRETLogger Content/`.

### Meta Quest Pro: per-eye gaze and blinks (optional)

Unreal's OpenXR eye tracker only provides the combined gaze, so the per-eye and blink columns stay empty (see [Eye-tracking data availability](#eye-tracking-data-availability)). For Quest Pro, the optional `VRETLoggerMetaXR` companion plugin fills them in from the Meta XR plugin:

1. Install the [Meta XR plugin](https://developers.meta.com/horizon/downloads/package/unreal-engine-5-integration/) for your engine version.
2. Copy the `VRETLoggerMetaXR` folder next to `VRETLogger` in your project's `Plugins/` directory and enable *VR Eye-Tracking Logger - Meta XR* (this also enables *Meta XR*). It is a source plugin, so the project needs a C++ toolchain to build it.
3. In **Project Settings > Plugins > Meta XR**, enable *Eye Tracking Enabled* and *Face Tracking Enabled*.
4. When running over Quest Link, enable eye tracking and natural facial expressions in the Meta Quest Link app (**Settings > Beta**), and allow them on the headset.

No blueprint changes are needed: `VRLogger` picks the data up automatically (disable with its *Use Eye Data Provider* property). Blink sensitivity can be tuned with the console variable `vret.MetaXR.BlinkThreshold` (default 0.5).

Only enable this plugin in projects that target Quest, since it enables the Meta XR plugin.

### Varjo: per-eye gaze, blinks, pupil size and focus distance (optional)

For Varjo headsets, the optional `VRETLoggerVarjo` companion plugin reads eye data from the [Varjo Native SDK](https://developer.varjo.com/docs/native/eye-tracking), through a native Varjo session that runs alongside the engine's OpenXR session:

1. Download the Varjo Native SDK (*Varjo SDK for Custom Engines*) from the Varjo developer site, and either set the environment variable `VARJO_SDK_DIR` to the extracted `varjo-sdk` folder or copy that folder to `VRETLoggerVarjo/Source/ThirdParty/VarjoSDK` (git-ignored, the SDK is not redistributed). The build expects `include/Varjo.h`, `lib/VarjoLib.lib` and, if present, `bin/VarjoLib.dll`, which is copied next to the plugin binary.
2. Copy the `VRETLoggerVarjo` folder next to `VRETLogger` in your project's `Plugins/` directory and enable *VR Eye-Tracking Logger - Varjo*. It is a source plugin, so the project needs a C++ toolchain to build it. Without the SDK it still builds, but logs a warning and provides no data.
3. In Varjo Base, enable *Allow eye tracking*, and calibrate eye tracking.

The data is read once per engine frame (latest gaze sample) and converted to world space with the engine's HMD pose for that frame, so it lines up with HeadPos and the gaze traces. Blink sensitivity can be tuned with the console variable `vret.Varjo.BlinkOpennessThreshold` (default 0.2).

Enable only one of the companion plugins in a project: `VRLogger` uses the first provider that registers.

## Recording

- Add a **TSVLogger** actor to your level.
- Add a **VRLogger** actor to your level, and set its *Logger* property to the TSVLogger instance.
- Add a **VRETLogging** actor (blueprint) to your level, set its *VRLogger* property to the VRLogger instance, and set the file prefix to the desired log file name.
- Wear the headset with eye tracking enabled and run the level in VR Preview mode.
- Logs are written to `<YourProject>/Content/VRETLogs/<prefix>.tsv`.

`TSVLogger` is a general-purpose tab-separated logger: register custom columns with `AddEntry()` before logging starts, then call the `Update*()` functions every tick (all BlueprintCallable). See the `LogTest` blueprint for an example.

## Visualizing fixations

- Right-click `FixationsVisualizationWidgetBlueprint` (in the plugin content folder) and select **Run Editor Utility Widget**.
- On first use, click **Install Requirements** to install the required Python packages (numpy, numba, pandas) into the editor's Python environment.
- Check that the latest log file name appears in the *Input Log File* field, then click **Calculate Fixations** (parameters follow [Llanes-Jurado et al. 2020](https://www.mdpi.com/1424-8220/20/17/4956)).
- The processed file is written to `Content/VRETLogs/withCalculatedFixations/`. [Column keys](./log_files_format_key.md)
- Click **Visualize Fixations**: an `ETVisualization` actor appears in the level with blue spheres (fixations) as children. Scrub the slider to replay head movement, gaze intersection point, and fixations; pressing Play replays in real time.


## Components

| Component | Type | Purpose |
|---|---|---|
| `TSVLogger` | C++ actor | Column/row-based TSV file logging, callable from blueprints |
| `VRLogger` | C++ actor | Registers tracking columns, performs gaze line traces against the scene |
| `VRETLogging` | Blueprint actor | Polls eye tracker each tick and feeds the loggers; checks tracking is available; start delay |
| `LogTest` | Blueprint actor | Example of logging custom variables with TSVLogger |
| `ETVisualization` / `Fixation` | Blueprint actors | Replay visualization of recorded gaze and fixation data |
| `FixationsVisualizationWidgetBlueprint` | Editor Utility Widget | UI for fixation computation and visualization, drives the Python scripts |
| `VRETLoggerMetaXR` | C++ plugin (optional) | Provides per-eye gaze and blinks from the Meta XR plugin to `VRLogger` |
| `VRETLoggerVarjo` | C++ plugin (optional) | Provides per-eye gaze, blinks, pupil size and focus distance from the Varjo Native SDK to `VRLogger` |
| `Content/Python/` | Python | `VrEtVisualizer.py` (editor-side processing/visualization), `IDT_alg_VR_centred.py` (I-DT fixation algorithm), `InstallDependencies.py` (pip bootstrap) |

## Notes

- Eye-tracking data is read through Unreal's generic `EyeTracker` interface, so any OpenXR runtime that implements it should work (tested with Varjo and Meta Quest Pro).
- Set the VRLogger's debug sphere visibility (*Rendering > Visible*) to show/hide the gaze intersection indicator.
- Collision responses on the *Visibility* channel should be set to *Overlap* rather than *Block* if you want gaze traces to record objects behind the first hit.

### Eye-tracking data availability

Unreal's OpenXR eye tracker is built on `XR_EXT_eye_gaze_interaction`, which only provides a single combined gaze pose. *Get Gaze Data* therefore never fills in the fixation point, blinks or pupil size, and *Get Stereo Gaze Data* is not implemented (always returns false). This is an engine limitation and applies to every headset.

| Columns | OpenXR (any headset) | Quest Pro + `VRETLoggerMetaXR` | Varjo + `VRETLoggerVarjo` |
|---|---|---|---|
| GazeOrigin, GazeDir | yes | yes (GazeOrigin corrected, see below) | yes (from OpenXR) |
| Conf | 0/1 tracking flag only | Meta's merged eye confidence | 0/1 tracking flag only |
| LOrigin, LDir, ROrigin, RDir | no (0) | yes | yes |
| LBlink, RBlink | no (F) | yes (from eyelid closure) | yes (eye openness / eye not tracked) |
| LPupil, RPupil | no (0) | no (not exposed by Meta) | yes (mm) |
| FixPoint | no (0) | no (0), use HitPos | yes (Varjo focus distance, 0-2 m) |

With Meta XR enabled, *Get Gaze Data* is served by Meta's own eye tracker, which scales the gaze origin twice. `VRETLoggerMetaXR` replaces it with the midpoint between the eyes.

## References

- Llanes-Jurado, J.; Marín-Morales, J.; Guixeres, J.; Alcañiz, M. *Development and Calibration of an Eye-Tracking Fixation Identification Algorithm for Immersive Virtual Reality.* Sensors 2020, 20, 4956.
