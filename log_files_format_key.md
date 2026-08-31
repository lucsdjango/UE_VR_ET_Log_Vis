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
