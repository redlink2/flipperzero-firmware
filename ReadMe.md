# Flipper Zero Redlinked Firmware
### Quick Start:

```bash
git clone --recursive https://github.com/redlink2/flipperzero-redlinked.git
```

## Differences from the original firmware

<details>
<summary>Show Changes Made From Orginal Firmware</summary>

### Plugins:
- [RF Remix (jimilinuxguy + ESurge, Redlink2)](https://github.com/ESurge/flipperzero-firmware-unirfremix)
- [Touch Tunes Remote (jimilinuxguy)](https://github.com/jimilinuxguy/flipperzero-universal-rf-remote/tree/028d615c83f059bb2c905530ddb3d4efbd3cbcae/applications/jukebox)
- [Spectrum Analyzer (jolcese)](https://github.com/jolcese/flipperzero-firmware/tree/spectrum/applications/spectrum_analyzer)
- [Clock (CompaqDisc, RogueMaster, Redlink2)](https://gist.github.com/CompaqDisc/4e329c501bd03c1e801849b81f48ea61)
- [WAV Player (Zlo)](https://github.com/flipperdevices/flipperzero-firmware/tree/zlo/wav-player)
- [Tetris (jeffplang)](https://github.com/jeffplang/flipperzero-firmware/tree/tetris_game/applications/tetris_game)
- [Flappy Bird (DroomOne)](https://github.com/DroomOne/flipperzero-firmware/tree/dev/applications/flappy_bird)
- [Zombiez (Dooskington)](https://github.com/Dooskington/flipperzero-zombiez)
- [Dice Roller (RogueMaster)](https://github.com/RogueMaster/flipperzero-firmware-wPlugins/tree/unleashed/applications/dice)

### Custom Icons:
- [Clock](https://github.com/redlink2/flipperzero-redlinked/tree/dev/assets/icons/MainMenu/Clock_14)
- [Music Player](https://github.com/redlink2/flipperzero-redlinked/tree/dev/assets/icons/MainMenu/MusicPlayer_14)
- [Snake Game](https://github.com/redlink2/flipperzero-redlinked/tree/dev/assets/icons/MainMenu/Snake_14)
- [Spectrum Analyzer](https://github.com/redlink2/flipperzero-redlinked/tree/dev/assets/icons/MainMenu/SpectrumAnalyzer_14)
- [Tetris Game](https://github.com/redlink2/flipperzero-redlinked/tree/dev/assets/icons/MainMenu/Tetris_14)
- [UniRFRemix](https://github.com/redlink2/flipperzero-redlinked/tree/dev/assets/icons/MainMenu/UniversalRF_14)
- [About Logo](https://github.com/redlink2/flipperzero-redlinked/blob/dev/assets/icons/About/Redlink2_128_64.png)

### Menu Changes:
- [Custom Games Submenu](https://github.com/redlink2/flipperzero-redlinked/blob/dev/applications/loader/)

### Dolphin Dialog Changes:
- [L1_TV](https://github.com/redlink2/flipperzero-redlinked/blob/dev/assets/dolphin/internal/manifest.txt)
- [L1_Laptop](https://github.com/redlink2/flipperzero-redlinked/blob/dev/assets/dolphin/external/L1_Laptop_128x51/meta.txt)
- [L1_Read Books](https://github.com/redlink2/flipperzero-redlinked/blob/dev/assets/dolphin/external/L1_Read_books_128x64/meta.txt)
- [L1_Sleep](https://github.com/redlink2/flipperzero-redlinked/blob/dev/assets/dolphin/external/L1_Sleep_128x64/meta.txt)
- [L1_Waves](https://github.com/redlink2/flipperzero-redlinked/blob/dev/assets/dolphin/external/L1_Waves_128x50/meta.txt)

</details>

## Build Instructions

<details>
<summary>Show Build Instructions</summary>

### Clone the repo with:

```bash
git clone --recursive https://github.com/redlink2/flipperzero-redlinked.git

cd flipperzero-redlinked
```

### Build a docker container with:

```bash
sudo docker-compose up -d
```

### Clean existing assets with:

```bash
sudo docker-compose exec dev make -C assets clean
```

### Then create the assets with:

```bash
sudo docker-compose exec dev make -C assets all
```

### And compile the firmware with:

```bash
sudo docker-compose exec dev make
```

### The compiled firmware can be found in the `/dist/f7/` directory.

#### Be sure to flash stock firmware to the Flipper before flashing the redlinked firmware.

</details>
<details>
<summary>Adding your universal_rf_map file to the flipper</summary>

#### Firstly make sure your universal_rf_map file looks like this:

```
Filetype: Flipper SubGhz RAW File
Version: 1
UP: /any/subghz/Tesla_AM270.sub
DOWN: /any/subghz/Tesla_AM650.sub
LEFT: /any/subghz/10bit_210mhz.sub
RIGHT: /any/subghz/10bit-300mhz.sub
OK: /any/subghz/HandicapDoor.sub
```

##### You can edit the file names after /any/subghz/ to be any file ending in .sub that you have in the subghz folder on the external SD card.
###### Be aware that /any/ means SD or internal flash. Be cautious when changing it.

#### Then copy the file to the /ext/subghz/assets/ directory:

##### Using qFlipper:

```
1. Open qFlipper
2. Plug in your Flipper
3. Open the "File manager" tab (the third tab from the left)
4. Navigate to the /ext/subghz/assets/ directory
5. Right-click and select "Upload here"
6. Navigate to the universal_rf_map file and select upload
```

</details>

<details>
<summary>Adding music to your Flipper</summary>

#### Using the WAV Player

###### The WAV player can only play WAV files that are BitExact, 8-bit stereo, 2-channel, unsigned, with no headers, 48k PCM.

##### Convert your mp3 to a playable WAV file with:

```
ffmpeg -i input.mp3 -c:a pcm_u8 -fflags +bitexact -flags:a +bitexact -ac 2 -ar 48k output.wav
```

##### where "input.mp3" is the mp3 file you want to convert and "output.wav" is the name of the output file.

##### Then add the WAV files to your Flipper's SD card:

###### using qFlipper:

```
1. Open qFlipper
2. Plug in your Flipper
3. Open the "File manager" tab (the third tab from the left)
4. Navigate to the /ext/ directory
    // if there is no wav_player folder, create one
    4a. Right-click and select "New Folder"
    4b. Name the new folder "wav_player"
5. Navigate to the wav_player/ folder and select "Upload here"
6. Navigate to the .wav files you want and select upload
```

#### Using the Music Player

###### the music player can play RTTTL files, and FMF files.

##### Then add the music files to your Flipper's SD card:

###### using qFlipper:

```
1. Open qFlipper
2. Plug in your Flipper
3. Open the "File manager" tab (the third tab from the left)
4. Navigate to the /ext/ directory
    // if there is no music_player folder, create one
    4a. Right-click and select "New Folder"
    4b. Name the new folder "music_player"
5. Navigate to the music_player/ folder and select "Upload here"
6. Navigate to the music files you want and select upload
```

</details>

## Credits

### Firmware:
- [FlipperDevices](https://github.com/flipperdevices/flipperzero-firmware)
- [Eng1n33r](https://github.com/Eng1n33r/flipperzero-firmware)
- [MuddledBox](https://github.com/MuddledBox/flipperzero-firmware)
- [Wetox-Team](https://github.com/wetox-team/flipperzero-firmware)

### Plugins:
- [RF Remix (jimilinuxguy + ESurge, Redlink2)](https://github.com/ESurge/flipperzero-firmware-unirfremix)
- [Touch Tunes Remote (jimilinuxguy)](https://github.com/jimilinuxguy/flipperzero-universal-rf-remote/tree/028d615c83f059bb2c905530ddb3d4efbd3cbcae/applications/jukebox)
- [Spectrum Analyzer (jolcese)](https://github.com/jolcese/flipperzero-firmware/tree/spectrum/applications/spectrum_analyzer)
- [Clock (CompaqDisc, RogueMaster, Redlink2)](https://gist.github.com/CompaqDisc/4e329c501bd03c1e801849b81f48ea61)
- [WAV Player (Zlo)](https://github.com/flipperdevices/flipperzero-firmware/tree/zlo/wav-player)

### Games:
- [Tetris (jeffplang)](https://github.com/jeffplang/flipperzero-firmware/tree/tetris_game/applications/tetris_game)
- [Flappy Bird (DroomOne)](https://github.com/DroomOne/flipperzero-firmware/tree/dev/applications/flappy_bird)
- [Zombiez (Dooskington)](https://github.com/Dooskington/flipperzero-zombiez)
- [Dice Roller (RogueMaster)](https://github.com/RogueMaster/flipperzero-firmware-wPlugins/tree/unleashed/applications/dice)

### Additional Community Credits:

- [UberGuidoZ's Flipper Resources](https://github.com/UberGuidoZ/Flipper)
- [Flipper-IRDB](https://github.com/UberGuidoZ/Flipper-IRDB)
- [Flipper RTTTL Files](https://github.com/neverfa11ing/FlipperMusicRTTTL)
- [Touch Tunes](https://github.com/jimilinuxguy/flipperzero-touchtunes)
- [MuddledBox SubGHz Files](https://github.com/MuddledBox/FlipperZeroSub-GHz)
- [FlipperAmiibo](https://github.com/Gioman101/FlipperAmiibo)
- [Amiibo2Flipper](https://github.com/Lucaslhm/AmiiboFlipperConverter)
- [Flipper Cases](https://github.com/MuddledBox/FlipperZeroCases)