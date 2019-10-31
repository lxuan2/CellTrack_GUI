# CellTrack_GUI
This repo contains all draft Qt GUI code for CellTrack
# CellTrack_GUI for python version
## Prerequisite for running the app

1. Install `K-Lite_Codec`: 
    Since the player in the app does not contain a decoder, you may have to install `K-Lite_Codec`.` 
It is probably not necessary, if you already have other decoder on your computer.

    `K-Lite_Codec_Pack_1508_Basic.exe` has been included in release `others.zip`. Note that for installation 
preference you need to choose `Movies & TV app`. The image, `intstallNote.PNG`, shows this in release `others.zip`.
2. Install `python 3.7`:
    Download `python 3.7` installer from [www.python.org](https://www.python.org) based on your computer system. 
On Windows, make sure that you select `Add to PATH` and `Disable path length limit`. After installation, 
please reboot the computer.
3. Install `opencv-python`, `scipy` and `scikit-image` package
    In terminal, use command `pip3 install opencv-python`, `pip3 install scipy` and 
`pip3 install scikit-image`

## General Interface for communicating with CellTrack_GUI
There are serveral assumptions about what you have:
    1. A python script 
    2. Serval parameters that you want to pass it to your python script. 
    3. Use `print()` function to return results. (The app reads results line by line.)

In following paragraphs, above assumptions  are explained in order.
1. A python script : The python environment is based on the system python 3 environment. 
                                Therefore, please install the opencv or other packages in system level.
2. Serval parameters that you want to pass it to your python script:
    The good thing about this GUI is that you can customize the parameters that you want to pass. 
    In the `userData.json`, define your parameters ( or parameter set) in the `Template` Object with type string or double.
    Later you can instance the parameter set for each video as an object in `HiddenVariable` array. Here is an example.

Assume you want to pass `maxSize` and `minSize` to your python script.
For step 1, you define
```
"Template": {
    "filename": "",
    "maxSize": 0,
    "minSize": 0
}
```
For step 2, you instance the template for a specific video, `cycto.avi` and `v.avi`.
```
"HiddenVariable": [
    {
        "filename": "cycto.avi",
        "maxSize": 100,
        "minSize": 100.1
    },
    {
        "filename": "v.avi",
        "maxSize": 2.2222,
        "minSize": 100.14444
    }
 ]
```
For step 3, you load video in the GUI, choose your script and click start analysis. Later, you see the return result from Log Tab.

The command that the GUI execute: `python yourScript.py videoPath videoName "Here are your customized parameters"`
Hint: `test.py` has been provided in release `others.zip`

### Note: 
1. The types in the `Template` are limited to `string` and `double`. 
2. `Template` has to have `filename` defined in it, since the GUI uses the file name to match videos and corresponding param.
3. Kind reminder: careful with comma symbol in json file. The last object doesn't have comma at the end.
4. It is recommanded you modify the `userData.json` in folder instead of creating a new one.
3. Use `print()` function to return results. (The app reads results line by line):
Making sure the first thing you print is the full path for result video. The GUI checks that file and loads it into the player. Other results are read and printed line by line in Log Tab.

