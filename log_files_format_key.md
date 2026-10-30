1. [Unlabeled]
   - Row/frame index.
2. time
   - Time in seconds since level started (pressed play in editor).
3. UnixTime
   - Unix time stamp (UTC)
4. FPS
   - Frame rate. Note that the default lower threshold for the fixations detection is 30 fps.
5. HeadPos
   - Tracked head position in world space [X, Y, Z]
6. HeadRot
   - Tracked head orientation in world space (Quaternion).
7. Valid
   - T if valid eyetracking data detected.
8. GazeOrigin
   - Tracked gaze origin position in world space [X, Y, Z], L-R combined (point between eyes). Quest Pro: with Meta XR enabled, the value from Get Gaze Data is wrong (Meta's eye tracker scales it twice), so the VRETLoggerMetaXR plugin replaces it with the midpoint of LOrigin and ROrigin.
9. GazeDir
   - Tracked gaze vector in world space [X, Y, Z], L-R combined.
10. Conf
      - Tracking flag rather than a real confidence: Unreal's OpenXR eye tracker sets 1 when the gaze pose is fully tracked and 0 when it is only estimated. With Meta XR enabled, it is Meta's merged eye confidence instead (close to 1).
11. FixPoint
      - Fixation (focus) point in world space [X, Y, Z]. Not provided by Unreal's OpenXR eye tracker (always 0), use HitPos instead. Varjo: provided by the VRETLoggerVarjo plugin as the point at Varjo's estimated focus distance (0-2 m) along the combined gaze ray, 0 when Varjo has no valid estimate.
12. LBlink
      - T if left eye blink detected, otherwise F. Not provided by Unreal's OpenXR eye tracker (always F). Quest Pro: provided by the VRETLoggerMetaXR plugin (face tracking EyesClosedL weight above `vret.MetaXR.BlinkThreshold`, default 0.5). Varjo: provided by the VRETLoggerVarjo plugin (eye not tracked, or eye openness below `vret.Varjo.BlinkOpennessThreshold`, default 0.2; Varjo marks openness as experimental).
13. RBlink
      - T if right eye blink detected, otherwise F. Same source as LBlink.
14. LPupil
      - Left pupil diameter. Not provided by Unreal's OpenXR eye tracker (always 0). Not available on Quest Pro (Meta does not expose pupil size). Varjo: provided by the VRETLoggerVarjo plugin, estimated diameter in mm, 0 when the pupil is not tracked.
15. RPupil
      - Right pupil diameter. Same as LPupil.
16. LOrigin
      - Left eye position in world space [X, Y, Z]. Not provided by Unreal's OpenXR eye tracker (always 0). Quest Pro: provided by the VRETLoggerMetaXR plugin. Varjo: provided by the VRETLoggerVarjo plugin (0 while the eye is not tracked).
17. LDir
      - Left gaze vector in world space [X, Y, Z]. Same source as LOrigin.
18. ROrigin
      - Right eye position in world space [X, Y, Z]. Same source as LOrigin.
19. RDir
      - Right gaze vector in world space [X, Y, Z]. Same source as LOrigin.
20. HitPos
      - Position of closest intersection of combined gaze vector with object (with collision enabled) in the scene, in world space [X, Y, Z].
21. HitName
      - Name of closest object (with collision enabled) in the scene intersecting with combined gaze vector.
22. head_pose_x
	  - X component of HeadPos column (separated for fixation detection)
23. head_pose_y
	  - Y component of HeadPos column (separated for fixation detection)
24. head_pose_z
      - Z component of HeadPos column (separated for fixation detection)
25. head_rot_x
	  - X component of HeadRot column (separated for fixation detection)
26. head_rot_y
	  - Y component of HeadRot column (separated for fixation detection)
27. head_rot_z
	  - Z component of HeadRot column (separated for fixation detection)
28. head_rot_w
	  - W component of HeadRot column (separated for fixation detection)
29. et_x
	  - X component of HitPos column (separated for fixation detection)
30. et_y
	  - Y component of HitPos column (separated for fixation detection)
31. et_z
	  - Z component of HitPos column (separated for fixation detection)
32. class_disp
      - 1 = fixation, 0 = saccade. Output of [fixation detection algorithm](https://github.com/acw-upv/VR-centred_I-DT_algorithm)
33. diff
      - Difference in class_disp from previous frame. Used internally to calculate fixation indices.
34. newFixation
      - Absolute value of diff. Used internally to calculate fixation indices.
35. fixationIdx
      - Fixation indices. Even intergers for fixations, odd integers for saccades.
      
