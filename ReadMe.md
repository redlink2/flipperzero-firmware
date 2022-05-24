# Flipper Zero Unleashed Firmware

<a href="https://ibb.co/5Fgtgmg"><img src="https://i.ibb.co/rsRTRYR/image.png" alt="image" border="0"></a>(https://discord.gg/58D6E8BtTU)

<a href="https://ibb.co/wQ12PVc"><img src="https://i.ibb.co/wQ12PVc/fzCUSTOM.png" alt="fzCUSTOM" border="0"></a>

Welcome to [Flipper Zero](https://flipperzero.one/)'s Custom Firmware repo!
Our goal is to make any features possible in this device without any stupid limitations! Please help us realize emulation for all dynamic (rolling codes) protocols and brute-force app!

# Clone the Repository

You should clone with 
```shell
$ git clone --recursive https://github.com/Eng1n33r/flipperzero-firmware.git
```

# Clone the Repository

You should clone with 
```shell
$ git clone --recursive https://github.com/Eng1n33r/flipperzero-firmware.git
```

# Update firmware

[Get Latest Firmware from Update Server](https://github.com/Eng1n33r/flipperzero-firmware)

Flipper Zero's firmware consists of two components:

- Core2 firmware set - proprietary components by ST: FUS + radio stack. FUS is flashed at factory and you should never update it.
- Core1 Firmware - HAL + OS + Drivers + Applications.

They both must be flashed in order described.

## With STLink

### Core1 Firmware

Prerequisites:

- Linux / macOS
- Terminal
- [arm-gcc-none-eabi](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)
- openocd

One liner: `make flash`

### Core2 flashing procedures

Prerequisites:

- Linux / macOS
- Terminal
- STM32_Programmer_CLI (v2.5.0) added to $PATH

One liner: `make flash_radio`

## With USB DFU 

1. Download latest [Firmware](https://github.com/Eng1n33r/flipperzero-firmware/releases)

2. Reboot Flipper to Bootloader
 - Press and hold `← Left` + `↩ Back` for reset 
 - Release `↩ Back` and keep holding `← Left` until blue LED lights up
 - Release `← Left`
<!-- ![Switch to DFU sequence](https://habrastorage.org/webt/uu/c3/g2/uuc3g2n36f2sju19rskcvjzjf6w.png) -->

3. Run `dfu-util -D full.dfu -a 0`

# Build with Docker

## Prerequisites

1. Install [Docker Engine and Docker Compose](https://www.docker.com/get-started)
2. Prepare the container:

 ```sh
 docker-compose up -d
 ```

## Compile everything

```sh
docker-compose exec dev make
```

Check `dist/` for build outputs.

Use **`flipper-z-{target}-full-{suffix}.dfu`** to flash your device.

If compilation fails, make sure all submodules are all initialized. Either clone with `--recursive` or use `git submodule update --init --recursive`.

# Build on Linux/macOS

## macOS Prerequisites

Make sure you have [brew](https://brew.sh) and install all the dependencies:
```sh
brew bundle --verbose
```

## Linux Prerequisites

### gcc-arm-none-eabi

```sh
toolchain="gcc-arm-none-eabi-10.3-2021.10"
toolchain_package="$toolchain-$(uname -m)-linux"

wget -P /opt "https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/$toolchain_package.tar.bz2"

tar xjf /opt/$toolchain_package.tar.bz2 -C /opt
rm /opt/$toolchain_package.tar.bz2

for file in /opt/$toolchain/bin/* ; do ln -s "${file}" "/usr/bin/$(basename ${file})" ; done
```

### Optional dependencies

- openocd (debugging/flashing over SWD)
- heatshrink (compiling image assets)
- clang-format (code formatting)
- dfu-util (flashing over USB DFU)
- protobuf (compiling proto sources)

For example, to install them on Debian, use:
```sh
apt update
apt install openocd clang-format-13 dfu-util protobuf-compiler
```

heatshrink has to be compiled [from sources](https://github.com/atomicobject/heatshrink).

## Compile everything

```sh
make
```

Check `dist/` for build outputs.

Use **`flipper-z-{target}-full-{suffix}.dfu`** to flash your device.

## Flash everything

Connect your device via ST-Link and run:
```sh
make whole
```

# Links

* Discord: [discord.gg/58D6E8BtTU](https://discord.gg/58D6E8BtTU)
* Website: [flipperzero.one](https://flipperzero.one)
* Kickstarter page: [kickstarter.com](https://www.kickstarter.com/projects/flipper-devices/flipper-zero-tamagochi-for-hackers)
* Forum: [forum.flipperzero.one](https://forum.flipperzero.one/)

# Project structure

- `applications`    - Applications and services used in firmware
- `assets`          - Assets used by applications and services
- `core`            - Furi Core: os level primitives and helpers
- `debug`           - Debug tool: GDB-plugins, SVD-file and etc
- `docker`          - Docker image sources (used for firmware build automation)
- `documentation`   - Documentation generation system configs and input files
- `firmware`        - Firmware source code
- `lib`             - Our and 3rd party libraries, drivers and etc...
- `make`            - Make helpers
- `scripts`         - Supplementary scripts and python libraries home

Also pay attention to `ReadMe.md` files inside of those directories.
# UniRF Remix App
### Integrated into Flipper Zero Unleashed Firmware
------------
### Quick Start

- Grab DFU from [Releases](https://github.com/ESurge/flipperzero-firmware-unifxremix/Relases/latest)
- Flash onto Flipper Zero
- Edit [universal\_rf\_map](https://github.com/ESurge/flipperzero-firmware-unirfremix/blob/dev/assets/resources/subghz/assets/universal_rf_map) and upload to SD card under ```/subghz/assets``` folder
------------
### Custom Import

- UniRFRemix folder has the base code. Use ```unirfremix_app``` for ```applications.c```
- Icons used are located at ```assets/icons/UniRFRemix```
- Animated Icon used is located at ```assets/icons/MainMenu/UniRFRemix_14```
- Follow compilation instructions from [Flipper Devices Flipper Zero Firmware GitHub](https://github.com/flipperdevices/flipperzero-firmware)
------------
### Notes
* ##### App Usage
  - Press a button to send the assigned capture file.
  - Press Back button to set how many repeats the app should send. Capped at 5 repeats.
  - Hold Back button to exit app.
  - Only RAW SubGhz captures are supported currently.
  - No skip function.

* ##### Universal RF Map
  - Backwards compatible with [jimilinuxguy Universal RF Remote](https://github.com/jimilinuxguy/flipperzero-universal-rf-remote) map file. You should be able to use the map file as is with both versions.
  - Recommend that you update the map file to the version included in this repo.
  - File path should not have any spaces or special characters (- and _ excluded).
  - Labels are limited to 12 characters.
    - Why? This is to prevent overlapping elements on screen.
    - For example: If you set your label or file to ```WWWWWWWWWWWWWWW``` you'll be over the screen limits.

* ##### Firmware
  - Code based on the Unleashed firmware
  - I modified the wav_player title in applications.c but that's all.

* ##### Issues
  - If you find any issues, report them. I am not sure I can fix them, but I will try.
------------
### Screenshots
#### Main Menu:
![unirfremix_mainmenu](https://user-images.githubusercontent.com/982575/169637623-bc41cfa5-6433-4198-a970-8fce42691ad7.png)
#### Idle Screen:
- Repeat indictator is located at the bottom right

![unirfremix-idle](https://user-images.githubusercontent.com/982575/169639427-daef6274-2e38-4684-816a-14ba915aa051.png)

#### Sending Screen:
- Button pressed will highlight when sending
- LED indicator will flash

![unirfremix-sending](https://user-images.githubusercontent.com/982575/169639435-74bdeb9e-da58-4ada-b613-8c4f8f89ab46.png)

#### Invalid Map File:
- If you don't have at least one valid file path set in your ```universal_rf_map``` file, you'll see this screen

![unirfremix-invalidmap](https://user-images.githubusercontent.com/982575/169639438-f1b96944-42c4-476c-9fe2-233d174c6262.png)

#### Missing Map File:
- If you don't have the ```universal_rf_map``` file, you'll see this screen

![unirfremix-missingmap](https://user-images.githubusercontent.com/982575/169639439-6414c81a-3de9-4817-b9b5-235130fd0e56.png)

------------
### Backstory
I saw jimilinuxguy post an idea of having a TouchTunes/Jukebox remote app, and it was basically one screenshot and a link to a repo. At the time, I was reading the Hello World plugin tutorial and wanted to give coding a plugin a shot.

Using the Music_Player plugin as a starting point (instead of using the Hello World example) I began the journey. By referencing some of the code in Universal RF Remote app, I started to get a basic idea of how the Flipper Zero device works.

After a few days of coding, I managed to get the app running pretty good. I proceed with a layout change which helped me learn how to create/import images (as icons). Also, I implemented a few ideas/suggestions which were brought up by various users in the Flipper Devices Discord, and this project is now released.

------------
### Credits
- [Jimilinuxguy](https://github.com/jimilinuxguy) for code base reference and the initial idea
- "Red_Link2" for creating the D-Pad animation
- "Shitposter Simulator" for the idea of adding a notification message for flashing the LED
- A bunch of others for convincing me to release this and also for just being generally good people.
