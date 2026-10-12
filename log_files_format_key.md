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
   - Tracked gaze origin position in world space [X, Y, Z], L-R combined (point between eyes).
9. GazeDir
   - Tracked gaze vector in world space [X, Y, Z], L-R combined.
10. Conf
      - Confidence value, 0-1. Seems to always return values close to 1, tested with Quest Pro and Varjo VR-3.
11. FixPoint
      - Fixation point not working (returning zero values) with either Quest Pro or Varjo VR-3.
12. LBlink
      - T if left eye blink detected, otherwise F. Not working (always returning F) with either Quest Pro or Varjo VR-3.
13. RBlink
      - T if right eye blink detected, otherwise F. Not working (always returning F) with either Quest Pro or Varjo VR-3.
14. LPupil
      - Left pupil diameter. Not working (always returning 0) with either Quest Pro or Varjo VR-3.
15. RPupil
      - Right pupil diameter. Not working (always returning 0) with either Quest Pro or Varjo VR-3.
16. LOrigin
      - Left eye position in world space [X, Y, Z]. Not working (always returning 0) with either Quest Pro or Varjo VR-3.
17. LDir
      - Left gaze vector in world space [X, Y, Z]. Not working (always returning 0) with either Quest Pro or Varjo VR-3.
18. ROrigin
      - Right eye position in world space [X, Y, Z]. Not working (always returning 0) with either Quest Pro or Varjo VR-3.
19. RDir
      - Right gaze vector in world space [X, Y, Z]. Not working (always returning 0) with either Quest Pro or Varjo VR-3.
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
