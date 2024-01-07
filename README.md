This is a side-scrolling runner inspired by [the original Dino Run game](https://en.wikipedia.org/wiki/Dino_Run).

It uses the [libnds](https://github.com/devkitPro/libnds) library to interface with peripherals in C. The game logic is primarily handled in C++.

# Setup

1. Install devkitpro
    - [for OSX and Linux](https://github.com/devkitPro/pacman/releases)
    - [for Windows](https://github.com/devkitPro/installer/releases/tag/v3.0.3)
2. Run make in the root dir to build the Dino_Run.nds file
3. Run the .nds file on an emulator like [desmume](https://desmume.org/download/) or on an [R4 cartridge with a microSD card and physical DS](https://en.wikipedia.org/wiki/R4_cartridge)
# Peripherals and features used

## Timers and Interrupts
- The physics is updated 60 times a second, based on the state of jumping + applied gravity

## Graphics and Sprites
- The background is initialized with tile mode using the main engine since it consists of solid colours
- The dino sprite is used as the main character, taking up another VRAM bank

## Keypad
- Press up or A to start the game/make the sprite jump

## Touchscreen
- TODO: once enough

## Sound
- Game music handled with the [Maxmod library](https://maxmod.devkitpro.org/)

Other Resources used:
- [Sound file library](https://modarchive.org/index.php?request=view_by_license&query=publicdomain)

Interesting things I found on the way:
- [Basic Pitch (Audio to MIDI AI)](https://basicpitch.spotify.com/)