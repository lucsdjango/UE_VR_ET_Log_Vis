

import pathlib
import pandas as pd
import os
from IDT_alg_VR_centred import IDTVR
import unreal
import numpy as np
import glob

eas = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
levelLibrary = unreal.EditorLevelLibrary()
assetLibrary = unreal.EditorAssetLibrary()

CONE_TAG = "VRETFixationCone"
CONE_INDEX_TAG_PREFIX = "VRETFixationConeIndex_"
CONE_RADIUS_FRACTION = 0.3 # cone base radius relative to the radius of the fixation sphere it starts from

def deleteExistingVisualizations():

    visActors = unreal.GameplayStatics().get_all_actors_of_class( levelLibrary.get_editor_world(),assetLibrary.load_blueprint_class('/VRETLogger/ETVisualization.ETVisualization'))
    for visActor in visActors:
        eas.destroy_actor(visActor)

    fixActors = unreal.GameplayStatics().get_all_actors_of_class( levelLibrary.get_editor_world(),assetLibrary.load_blueprint_class('/VRETLogger/Fixation.Fixation'))
    for fixActor in fixActors:
        eas.destroy_actor(fixActor)

    # Attached cones are not destroyed with their parent visualization actor.
    for actor in eas.get_all_level_actors():
        if any(str(tag) == CONE_TAG for tag in actor.tags):
            eas.destroy_actor(actor)


def getConeIndex(actor):

    for tag in actor.tags:
        if str(tag).startswith(CONE_INDEX_TAG_PREFIX):
            return int(str(tag)[len(CONE_INDEX_TAG_PREFIX):])
    return None


def updateFixationCone(coneActor, startFix, endFix):

    # Cone from the surface of the start sphere (wide base) to the surface of the next sphere (narrow tip),
    # shown only while both fixations are shown, with the same material (and colour/opacity) as the start sphere.
    startSphere = startFix.get_component_by_class(unreal.StaticMeshComponent)
    endSphere = endFix.get_component_by_class(unreal.StaticMeshComponent)
    coneComponent = coneActor.static_mesh_component

    visible = startSphere.is_visible() and endSphere.is_visible()
    coneComponent.set_visibility(visible)
    if not visible:
        return

    startPos = startSphere.get_world_location()
    endPos = endSphere.get_world_location()
    startRadius = startSphere.static_mesh.get_bounds().box_extent.x * startSphere.get_world_scale().x
    endRadius = endSphere.static_mesh.get_bounds().box_extent.x * endSphere.get_world_scale().x

    offset = endPos - startPos
    gap = offset.length() - startRadius - endRadius
    if gap <= 0:
        # Spheres overlap, nothing to connect.
        coneComponent.set_visibility(False)
        return

    direction = offset.normal()
    coneBounds = coneComponent.static_mesh.get_bounds()
    baseRadius = startRadius * CONE_RADIUS_FRACTION
    scale = unreal.Vector(baseRadius / coneBounds.box_extent.x, baseRadius / coneBounds.box_extent.y, gap / (2 * coneBounds.box_extent.z))
    rotation = unreal.MathLibrary.make_rot_from_z(direction) # engine cone tip points along +Z
    center = startPos + direction * (startRadius + gap / 2)
    pivotOffset = unreal.Transform(unreal.Vector(0,0,0), rotation, scale).transform_location(coneBounds.origin)

    coneActor.set_actor_scale3d(scale)
    coneActor.set_actor_location_and_rotation(center - pivotOffset, rotation, False, False)
    coneComponent.set_material(0, startSphere.get_material(0))


def spawnFixationCones(visActor, fixations):

    coneMesh = assetLibrary.load_asset('/Engine/BasicShapes/Cone')
    for i in range(len(fixations) - 1):
        coneActor = levelLibrary.spawn_actor_from_class(unreal.StaticMeshActor, unreal.Vector(0,0,0))
        coneComponent = coneActor.static_mesh_component
        coneComponent.set_mobility(unreal.ComponentMobility.MOVABLE)
        coneComponent.set_static_mesh(coneMesh)
        coneComponent.set_collision_profile_name('NoCollision')
        coneActor.set_editor_property('tags', [unreal.Name(CONE_TAG), unreal.Name(CONE_INDEX_TAG_PREFIX + str(i))])
        coneActor.attach_to_actor(visActor, visActor.get_actor_label(), unreal.AttachmentRule.KEEP_WORLD, unreal.AttachmentRule.KEEP_WORLD, unreal.AttachmentRule.KEEP_WORLD, False)
        updateFixationCone(coneActor, fixations[i], fixations[i + 1])


def updateFixationCones(visActor):

    fixations = visActor.get_editor_property('Fixations')
    for actor in visActor.get_attached_actors():
        index = getConeIndex(actor)
        if index is not None and index + 1 < len(fixations):
            updateFixationCone(actor, fixations[index], fixations[index + 1])


def getLatestInputFile():

    list_of_files = glob.glob(unreal.Paths.project_content_dir() + "VRETLogs/" + "*.tsv") # * means all if need specific format then *.csv
    latest_file = max(list_of_files, key=os.path.getctime)
    path_parts = latest_file.split("\\") 
    return path_parts[-1]

def getLatestOutputFile():

    list_of_files = glob.glob(unreal.Paths.project_content_dir() + "VRETLogs/withCalculatedFixations/" + "*.tsv") # * means all if need specific format then *.csv
    latest_file = max(list_of_files, key=os.path.getctime)
    path_parts = latest_file.split("\\") 
    return path_parts[-1]

def readETData(fileName, time_th, disp_th, freq_th, useFocal):

    # delete existing fixation objects in scene
    print("Time threshold: %1f dispersion threshold: %2f freq threshold: %3f" % (time_th, disp_th, freq_th)) 
    
    deleteExistingVisualizations()
    
    df_et = pd.read_csv(unreal.Paths.project_content_dir() + "VRETLogs/" + fileName, sep="\t",index_col=False )
    df_et = df_et.iloc[:,:-1] #drop empty column
    
    df_et = df_et[(df_et["Valid"] == "T")]
    
    
    start_time = df_et["time"].iloc[0]
    print(start_time)
    df_et["time"] = df_et["time"] - start_time
    
    
    # head pos and gaze origin should be identical
    df_et[['head_pose_x','head_pose_y','head_pose_z']] = df_et['GazeOrigin'].str.split(',',expand=True).astype(float)
    df_et[['head_rot_x','head_rot_y','head_rot_z', 'head_rot_w']] = df_et['HeadRot'].str.split(',',expand=True).astype(float)
    
    if (useFocal):
        df_et[['et_x','et_y','et_z']] = df_et['FixPoint'].str.split(',',expand=True).astype(float)
    else:
        df_et[['et_x','et_y','et_z']] = df_et['HitPos'].str.split(',',expand=True).astype(float)

    print("Shape", df_et.shape)
    print("Columns", df_et.columns)

    #IDTVR(time_th=0.15, disp_th=1, freq_th=50)
    
    idt_vr = IDTVR(time_th=time_th, disp_th=disp_th, freq_th=freq_th)

    df_et_w_fixations = idt_vr.fit_compute(df_et.copy(deep=True), time="time",)
    df_et_w_fixations['diff'] = df_et_w_fixations['class_disp'].diff()
    df_et_w_fixations['newFixation'] = df_et_w_fixations['diff'].abs() #df_et_w_fixations['diff'] == -1).astype(int)
    df_et_w_fixations['fixationIdx'] = df_et_w_fixations['newFixation'].cumsum()
    
    df_et_w_fixations = df_et_w_fixations.iloc[1:]
    
    basename, ext = fileName.rsplit(".", maxsplit=1)
    new_file_name =  basename + "_w_fixations." + ext 
    
    outDir = unreal.Paths.project_content_dir() + "VRETLogs/withCalculatedFixations/"
    pathlib.Path(outDir).mkdir(parents=True, exist_ok=True)
    
    df_et_w_fixations.to_csv(outDir+new_file_name, sep="\t") 
    
    return new_file_name

    
    
def visualizeFixations(fileName):
 
    deleteExistingVisualizations()
 
    visActor = levelLibrary.spawn_actor_from_class(assetLibrary.load_blueprint_class('/VRETLogger/ETVisualization.ETVisualization'), unreal.Vector(0,0,0))
    
    times = visActor.get_editor_property('times')
    gazePositions = visActor.get_editor_property('GazePositions')
    headPositions = visActor.get_editor_property('HeadPositions')
    headRoations = visActor.get_editor_property('HeadRotations')
    
    fixations = visActor.get_editor_property('Fixations')   
    
    outDir = unreal.Paths.project_content_dir() + "VRETLogs/withCalculatedFixations/"
    
    df_et_w_fixations = pd.read_csv(outDir + fileName, sep="\t",index_col=False )
    print("Shape", df_et_w_fixations.shape)
    print("Columns", df_et_w_fixations.columns)
    
    
    for index, row in df_et_w_fixations.iterrows():
        times.append(row['time'])
        gazePositions.append(unreal.Vector(row['et_x'],row['et_y'],row['et_z']))
        headPositions.append(unreal.Vector(row['head_pose_x'],row['head_pose_y'],row['head_pose_z']))
        headRoations.append(unreal.Quat(row['head_rot_x'],row['head_rot_y'],row['head_rot_z'],row['head_rot_w']))
        
    
    
    saccsAndFixes = df_et_w_fixations[(df_et_w_fixations["diff"] != 0)]
    saccsAndFixes['fixOrSacc'] = np.where(saccsAndFixes['diff'] > 0, "Saccade", "Fixation")
    saccsAndFixes['duration'] = 0-saccsAndFixes['time'].diff(-1) # time difference next row
    
    df2 = df_et_w_fixations[['fixationIdx','et_x', 'et_y', 'et_z']].copy()
    #df2['fixationIdx'] = df2['fixationIdx'].astype('category',copy=False)
    
    meanFixations = df2.groupby('fixationIdx', as_index=False).mean()
    print(meanFixations)
    
    for index, row in meanFixations.iterrows():
        saccsAndFixes['et_x'][index] = row['et_x']
        saccsAndFixes['et_y'][index] = row['et_y']
        saccsAndFixes['et_z'][index] = row['et_z']
    
    saccsAndFixes['dX'] = 0-saccsAndFixes['et_x'].diff(-1) 
    saccsAndFixes['dY'] = 0-saccsAndFixes['et_y'].diff(-1) 
    saccsAndFixes['dZ'] = 0-saccsAndFixes['et_z'].diff(-1) 
    saccsAndFixes['distance'] = np.sqrt(saccsAndFixes['dX']**2 + saccsAndFixes['dY']**2 + saccsAndFixes['dZ']**2)
    
    for index, row in saccsAndFixes.iterrows():
        if (row['fixOrSacc'] == "Saccade"):
            continue
        fixActor = levelLibrary.spawn_actor_from_class(assetLibrary.load_blueprint_class('/VRETLogger/Fixation.Fixation'), unreal.Vector(row['et_x'],row['et_y'],row['et_z']))
        fixActor.set_actor_scale3d(unreal.Vector(row['duration'],row['duration'],row['duration']).multiply_float(0.5))
        fixActor.attach_to_actor(visActor, visActor.get_actor_label(), unreal.AttachmentRule.KEEP_RELATIVE, unreal.AttachmentRule.KEEP_RELATIVE, unreal.AttachmentRule.KEEP_RELATIVE, False)
        fixActor.set_editor_property("Time", row['time'])
        fixActor.set_editor_property("Duration", row['duration'])
        fixations.append(fixActor)

    spawnFixationCones(visActor, fixations)

    print("Shape", meanFixations.shape)
    
    #print("Shape", saccsAndFixes.shape)
    #print("Columns", saccsAndFixes.columns)
    #print(meanFixations['et_x'])
    return visActor

def scrub(value, visActor):


    
    
    
    
    times = visActor.get_editor_property('times')
    gazePositions = visActor.get_editor_property('GazePositions')
    headPositions = visActor.get_editor_property('HeadPositions')
    
    idx = len(times) * value;
    
    
    
    visActor.call_method("SetHeadAndGazePos", args=(idx,))
    visActor.call_method("UpdateVisibility", args=(times[idx],))
    updateFixationCones(visActor)

    
    levelLibrary.editor_invalidate_viewports()
    
    return times[idx]
    
    
    
    