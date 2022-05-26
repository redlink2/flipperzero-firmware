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

#### Be sure to flash stock firmware to the Flipper before flashing the redlinked firmware for the first time.

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