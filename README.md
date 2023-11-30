# ctrlx_nanotec
Demo example of an app for ctrlX Core in combination with CANopen-USB adapter from Nanotec. It creates an API in the datalayer from which the user can switch between stop mode and velocity mode with a desired target velocity. 

This project was born as a demo example for an autonomous mobile robot developped at OST Rapperswill Hochschule. 

## Development details
Office: Bosch Rexroth Schweiz \
Author: Raul Cruz-Oliver \
Main contact email: raul.cruz.oliver@gmail.com \
Alternative contact email: stefan.luna@boschrexroth.ch \
Date: November 2023 \
Place: Buttikon Schwyz, Swtizerland \
License: MIT

## Easy Start-up. 
This is a C++ project, therefore the code first need to be compiled (i.e. generate the binaries) and then packed in the so-called snap file, which will then installed in ctrlX OS. 

### 0. Clone this repository in your local system
This example is designed for Ubuntu 22.04 x86_64 Desktop. The "cmake" process that would be used has been designed for a Linux machine, and moreover Snapcraft is a technology from Canonical (the developers of Ubuntu). If you want to develop apps for the ctrlX ecosystem, you must mandatory work in a Ubuntu 22.04 OS, no matter if it is a virtual machine or a native installation. 

Open a terminal, it will be started in your home directory. This is the best place to clone this repository. Simply enter:

```bash
git clone https://github.com/rcruzoliver/ctrlx_nanotec
```
When during this document we refer to the root directory we mean the ~/ctrlx_nanotec directory. To go in it from the home directory, simply enter: 
```bash
cd ctrlx_nanotec
```

### 1. Install the neccesary tools in your system
Verify you have installed the general libraries required for this project, for both arm64 and amd64. You can run the following commands:

```bash
# for amd64 (your host system)
sudo apt-get update 
sudo apt-get install libssl-dev

# for arm64
sudo dpkg --add-architecture arm64
sudo apt-get update
sudo apt-get install libc6-dev-arm64-cross libssl-dev:arm64
```
In particual the project is using pthread, ssl and crypto. They must be installed in /usr/lib/<aarch64-linux-gnu|x86_64-linux-gnu>. Hint, look for a file called "lib<lib_name>.so"

### 2. Build the source code
In this project the source coude is compiled and installed with cmake. For detailed information about it please refer to the official website https://cmake.org/cmake/help/latest/ 

In short, cmake define where the source files are, and which depencies are needed for compiling the code that will result in a executable. You can have a look at the CMakeLists.txt file in this documment to have an idea of how this type of files look like. If you want to learn to write your own CMakeLists.txt file the best option is to follow the official tutorial https://cmake.org/cmake/help/latest/guide/tutorial/index.html

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
 
### 3. Pack in a snap
Once you have the built code, you can pack it. The packing process is defined in a file called snapcraft.yalm, placed inside the folder /snap. If you want to know more about snapcraft process, please read the next section in this document.

The whole snapcraft process has been simplified for you with a simply call to the batch file "createSnap.sh"
```bash
./createSnap.sh   # if only works if the build for arm64 has been run before
```
The snapcraft.yalm is cofigured to pack an app for arm64. If you want to pack the app for amd64 you will need to manually change a couple or things in the snapcraft.yalm. They are indicated with an arrow and a "CHANGE IF NEEDED" comment.

```yalm
architectures:
   - build-on: [amd64]
     build-for: [amd64]  ### <------ CHANGE IF NEEDED
```
```yalm
apps:
  ctrlx-nanotec:
    command: ./ctrlx_nanotec_amd4 ### <------ CHANGE IF NEEDED
    plugs:
      - file-handler
      - network
      - serial-port
      - raw-usb
      - hardware-observe
    daemon: simple
    passthrough:
      restart-condition: always
      restart-delay: 10s
```
Then you would need to build the code for amd64 with "buildCode_amd64.sh" and then pack the snap with "createSnap.sh".

After running the process to create the snap you will get a file called "ctrlx-nanotec_2.2.0_arm64.snap" if you followed the process for arm64 or "ctrlx-nanotec_2.2.0_amd64.snap" if you followed the process for amd64.

This .snap file can be directly intalled in CtrlX Core from the Apps menu. Just as a reminder, since this new app you just built has not been signed, you need to allow the intallation from "unknown sources" in your device.

PHOTO HOW TO ENABLE THIS

## What is snapcraft?
Snapcraft is a technology from Canonical that packs an app in a single file that contains all the dependencies needed for the app to run. Since CtrlX OS is based on ubuntu core, snapcraft has been chosen by Bosch Rexroth as the way to deploy apps. In particular ctrlx OS 2.xx is based on core22 (same as Ubuntu Desktop 22.04). For more information about snapacraft, please refer to the offical website of snapcraft https://snapcraft.io/.

The packaging process is defined in the snapcraft.yalm file, placed in this project in the folder snap/. Let's understand what should you write in there. 

There are four main blocks in such file: 
- metadata: information about the app name, version, etc.
- parts: actual compiled code, libraries, etc. that are going to be included in the snap
- apps: how the executables are exposed to the user
- others: plugs, layouts, etc.

Let's now break go understand each part:

#### metadata

```yalm
name: ctrlx-nanotec
version: "2.2.0"
grade: stable
summary: Datalayer interface for Nanotec CANopen-USB adapter
description: This app creates an API in the ctrlX OS datalayer to control the operation of a stepper motor via a serial interface. Author -- Raul Cruz-Oliver. Email -- raul.cruz.oliver@gmail.com
base: core22
confinement: strict
architectures:
   - build-on: [amd64]
     build-for: [arm64]  ### <------ CHANGE IF NEEDED
```
In this section is important to remark that the confinement must be strict for apps that would be installed in the ctrlX Core. Also the section about architectures must be explicitly specified, it is importat to understand that this is only an instruction for the snapcraft process, you still need to pack binaries that are compiled for the architecture you want as target. Having this part in the snapcraft.yalm, but having wrong binaries, or having the right binaries, but not this section, will always result in a corrupted snpacraft process. 

#### parts

```yalm
parts:
  compiled:
    plugin: dump
    source: ./install

  nanotec-lib:
    plugin: dump
    source: ./lib/nanotec
    organize:
      '*': lib/

  commDatalayer-lib:
    plugin: dump
    source: ./lib/commDatalayer
    organize:
      '*': lib/
```

In this project we are only using the dump plugin, this plugin simply copy the files we specify inside the snap. When working with a C++ project this plugin is the one that makes more sense, since it is easier to build the code manually, and then just dump it inside our snap. There are other options for plugins in which the source code is compiled during the snapcraft process, you can find more information in the official documentation.

As you can see from the snipped above, we have three parts in this project:

- compiled : it simply the executable we generated during our building process
- nanotec-lib: they are the libraries provided by nanotec. They are used for handling the communication with the serial device.
- commDatalayer-lib: they are the libraries provided by ctrlX. They are used for handling the communication with the data layer.

It is important to understand that the libraries must be included in a directory lib/ inside the snap, all together, not divided in subfolders. This indicating the right "source" and then "oganize" tag. 

Looking in the source for the libraries one can see that there are two folders: "aarch64-linux-gnu" and "x86_64-linux-gnu", corresponding repectvley to arm64 and amd64 architectures. This structure must be respected inside the lib/ directory of the snap.

In short, the way it is defined in the snapcraft.yalm basically means merging the "aarch64-linux-gnu" from nanotec with the one from commDatalayer. Similary with "x86_64-linux-gnu".

This way of organizing the libraries inside the snap is mandatory, otherwise the executables will not find the dependencies. 

NOTE: To be strict, it would be only neccesary to include the libraries for the architecture we are building. However, with the aim of making this example easier, it has decided to always dump both of them.

#### apps
```yalm
apps:
  ctrlx-nanotec:
    command: ./ctrlx_nanotec_arm64 ### <------ CHANGE IF NEEDED
    plugs:
      - file-handler
      - network
      - serial-port
      - raw-usb
      - hardware-observe
    daemon: simple
    passthrough:
      restart-condition: always
      restart-delay: 10s
```

Although it is not neccesary, if you only have one app, you should call it with the same name as the whole snap. In short, it is because matching names make the start of the specific app inside the snap easier because you do not need to specify the name.

This section of the snapcraft is telling snapcraft what to call when we start the application. Specifically in this example it is starting the executable we have dumped in. 

After the command that would be call, we find the definition of plugs that our app will have available. Each plug will be respectively connected with a slot from the host system. 

NOTE: The connection of a specfic plug and the corresponding slot is not always automatically enable by default in ctrlX Core. This is due to safety reasons. If you want to learn more about it, you need a ssh connection to the ctrlX Core. 

The last part of the snipped is simply telling the app to start automatically if it does not exits after a 10 seconds; it will restart the app it it died. It is the way to proceed with snaps running in the ctrlX core since, here, we do not have another way to start them. The snaps are supposed to be looping infinitely. Bear this in mind when designing your application.

#### others

```yalm
# linters (dis/enable linter verbose, comment out if want to enable)
lint:
  ignore:
    - classic 
    - library

# Layouts (system directories mapping in snap directories)
layout:
  /var/tmp:
    bind: $SNAP_DATA/var/tmp

# plugs (interface: slot->plug)
plugs:
  file-handler:
    interface: system-files
    write: 
     - /var/tmp
  datalayer:
    interface: content
    content: datalayer
    target: $SNAP_DATA/.datalayer
```

Linters are just tools that inform the developer about the running process, for instance warning about missing dependencies. So as to make the snapcraft clear, we have disable the verbosity of such linters.

Snaps are fully confined and therefore do not have access to anything from outside. In the case of this specific program, the library from nanotec wants to write log files in the /var/tmp directory in our system, with a layout we map such system directory to one inside the snap. 

And finally, there is a sections about plugs. Apps can include plugs that are already defined from snapcraft, like network or serial-port. However, we can also generate our own custom ones, as it is the case with file-handlr and datalayer in this example. Once they are defined, they can be included.