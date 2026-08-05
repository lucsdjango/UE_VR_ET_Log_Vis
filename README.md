# VRETLogger — VR Eye-Tracking Logger & Visualizer

Unreal Engine plugin for logging eye-tracking and head-tracking data from a VR headset to TSV files, computing fixations with a VR-centred I-DT algorithm, and replaying/visualizing the recorded gaze data in the editor. Also includes a spectator camera pawn for observing VR sessions from the desktop.

Developed and tested with Unreal Engine 5.7.

## Installation

1. Copy the `VRETLogger` folder into your project's `Plugins/` directory (create it if it does not exist).
2. Open the project. If you installed a source-only copy, accept the prompt to rebuild the plugin module (requires a C++ toolchain; a prebuilt copy needs no compiler).
3. Enable the plugin under **Edit > Plugins > Virtual Reality > VR Eye-Tracking Logger** if it is not already enabled, and restart the editor. The required *Python Editor Script Plugin* and *Editor Scripting Utilities* plugins are enabled automatically.
4. Enable an OpenXR eye-tracking source for your headset (e.g. *OpenXR Eye Tracker* plugin).
5. To see the plugin's blueprints in the Content Browser, enable **Settings > Show Plugin Content**. They are under `Plugins/VRETLogger Content/`.

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
- The processed file is written to `Content/VRETLogs/withCalculatedFixations/`.
- Click **Visualize Fixations**: an `ETVisualization` actor appears in the level with blue spheres (fixations) as children. Scrub the slider to replay head movement, gaze intersection point, and fixations; pressing Play replays in real time.

## Spectator camera

The `VRSpectator` pawn (under `VRSpectator/` in the plugin content) renders a separate desktop view while a user is in the headset. Place it in the level; its Enhanced Input mapping context (`IMC_VRSpectator`) lets you fly the camera, adjust FOV, and toggle modes from mouse/keyboard.

## Components

| Component | Type | Purpose |
|---|---|---|
| `TSVLogger` | C++ actor | Column/row-based TSV file logging, callable from blueprints |
| `VRLogger` | C++ actor | Registers tracking columns, performs gaze line traces against the scene |
| `VRETLogging` | Blueprint actor | Polls eye tracker each tick and feeds the loggers; checks tracking is available; start delay |
| `LogTest` | Blueprint actor | Example of logging custom variables with TSVLogger |
| `ETVisualization` / `Fixation` | Blueprint actors | Replay visualization of recorded gaze and fixation data |
| `FixationsVisualizationWidgetBlueprint` | Editor Utility Widget | UI for fixation computation and visualization, drives the Python scripts |
| `Content/Python/` | Python | `VrEtVisualizer.py` (editor-side processing/visualization), `IDT_alg_VR_centred.py` (I-DT fixation algorithm), `InstallDependencies.py` (pip bootstrap) |
| `VRSpectator` | Blueprint pawn | Desktop spectator camera for VR sessions |

## Notes

- Eye-tracking data is read through Unreal's generic `EyeTracker` interface, so any OpenXR runtime that implements it should work (tested with Varjo and Meta Quest Pro).
- Set the VRLogger's debug sphere visibility (*Rendering > Visible*) to show/hide the gaze intersection indicator.
- Collision responses on the *Visibility* channel should be set to *Overlap* rather than *Block* if you want gaze traces to record objects behind the first hit.

## References

- Llanes-Jurado, J.; Marín-Morales, J.; Guixeres, J.; Alcañiz, M. *Development and Calibration of an Eye-Tracking Fixation Identification Algorithm for Immersive Virtual Reality.* Sensors 2020, 20, 4956.
