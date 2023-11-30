# ctrlx_nanotec
Demo example of an app for ctrlX Core in combination with CANopen-USB adapter from Nanotec. It creates an API in the datalayer from which the user can switch between stop mode and velocity mode with a desired target velocity. \
This project was born as a demo example for an autonomous mobile robot developped at OST Rapperswill Hochschule. 

## Development details
Office: Bosch Rexroth Schweiz
Author: Raul Cruz-Oliver \
Main contact email: raul.cruz.oliver@gmail.com \
Alternative contact email: stefan.luna@boschrexroth.ch \
Date: November 2023 \
Place: Buttikon Schwyz, Swtizerland \
License: MIT

## Easy Start-up. How to build and snap the app?
This is a C++ project, therefore the code first need to be compiled (i.e. generate the binaries) and then packed in the so-called snap file, which will then installed in ctrlX OS. 

### 1. Build the source code
In this project the source coude is compiled and installed with cmake. For detailed information about it please refer to the official website ___

In short, cmake define where the source files are, and which depencies are needed for compiling the code that will result in a executable. You can have a look at the CMakeLists.txt file in this documment to have an idea of how this type of files look like. If you want to learn to write your own CMakeLists.txt file the best option is to follow the official tutorial ___

In order to get you easily started, batch files with the neccesary commands to build the code have been set: "builildCode_arm64.sh" and "buildCode_amd64.sh". They respectively build and install the code for processing architectures aarch64-linux-gnu and x86_64-linux-gnu.

Just as a hint for beginners, CtrlX Core X3 and Raspberry Pi are examples of devices with aarch64 (also known as arm64), whereas CtrlX Core Virtual, CtrlX Core X7 and probably the laptop where you are reading this document are devices with x86_64 (also known as amd64).

To launch the build and install process simply call the file from a console in the root directoy of this project:

```bash
./buildCode_arm64.sh     # to build and install for arm64
./buldCode_amd64.sh      # to build and install for amd64
```
You will get the install executable in a new created install folder. If you built for same architecture that your machine as, you could start the executable with the following commands:

```bash
./install/ctrlx_nanotec_arm64    # if you built for arm64
./install/ctrlx_nanotec_amd64    # if you built for amd64
```
however, this specific example is designed to work inside a ctrlX OS device and it will simply stop. 
 
### 2. Pack in a snap
Once you have the built code, you can pack it. The packing process is defined in a file called snapcraft.yalm, placed inside the folder /snap. If you want to know more about snapcraft process, please read the next section in this document.

The whole snapcraft process has been simplified for you with a simply call 

## What is snapcraft?
Snapcraft is a technology from canonical that packs an app in a single file that contains all the dependencies needed for the app to run. Since CtrlX OS is based on ubuntu core, snapcraft has been chosen by Bosch Rexroth as the way to deploy apps. \

For more information about it, please refer to the offical website of snapcraft ___



