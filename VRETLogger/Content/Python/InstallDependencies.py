import unreal
import subprocess
import pkg_resources
import pathlib
import os


print(pathlib.Path().resolve())
print(unreal.Paths.project_content_dir())

PYTHON_INTERPRETER_PATH = unreal.get_interpreter_executable_path()
assert pathlib.Path(PYTHON_INTERPRETER_PATH).exists(), f"Python not found at '{PYTHON_INTERPRETER_PATH}'"

def pip_install(packages):
    # dont show window
    info = subprocess.STARTUPINFO()
    info.dwFlags |= subprocess.STARTF_USESHOWWINDOW
    
    proc = subprocess.Popen(
        [
            PYTHON_INTERPRETER_PATH, 
            '-m', 'pip', 'install', 
            '--no-warn-script-location', 
            *packages
        ],
        startupinfo = info,
        stdout = subprocess.PIPE,
        stderr = subprocess.PIPE,
        encoding = "utf-8"
    )

    while proc.poll() is None:
        unreal.log(proc.stdout.readline().strip())
        unreal.log_warning(proc.stderr.readline().strip())

    return proc.poll()


def installDependencies():
    # Put here your required python packages
    
    #uninstall_pandas()
    #print('sinstalled')

    
    #reinstall_pandas()
    #print('resinstalled')
    
    #checkVersion()
    #print('checked')
    
    required = {'numpy','numba', 'pandas==2.3.3'}
    installed = {pkg.key for pkg in pkg_resources.working_set}
    missing = required - installed

    if len(missing) > 0:
        print(missing)
        #pip_install({'notebook'})
        pip_install(missing)
    else:
        unreal.log("All python requirements already satisfied")
    
    