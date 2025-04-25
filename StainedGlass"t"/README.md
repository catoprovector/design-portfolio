# stained glass "t"

This multi-material lighting sculpture was created for Lily's Prototyping Lab at Utrecht University. Installed above the lab entrance as the letter **"t"** in “Proto,” the piece combines upcycled electronics, stained glass-inspired design, and custom dynamic lighting. It highlights themes of reuse, precision fabrication, and layered visual design.

## Project Overview

The sculpture reuses components from discarded electronics, embedding them in epoxy resin tiles arranged in a hexagonal grid. Inspired by stained glass windows and sustainability, the piece is both decorative and functional, housing custom-programmed LEDs that produce constantly shifting color patterns.

## Build Process

- **Tile Design**: Old circuit boards and components were embedded into hexagonal epoxy tiles. Molds were created by vacuum forming over 3D printed blanks.
- **Structure**: A honeycomb-patterned front face and solid back panel were laser cut from sandblasted plexiglass. Custom-sized tile edge pieces were cut to fit precisely.
- **Lighting**: The interior holds two zones of RGB LED strips (12V), spaced between tiles. These are controlled by a Seeed Studio XIAO SAMD21 board running an Arduino sketch that randomly changes brightness and timing per channel, producing an ever-changing array of colors.
- **Assembly**: Tiles were glued to the back panel, and the sides were formed with bent plexiglass strips. A removable top piece is secured with 3D printed clips for access to the electronics.
- **Mounting**: The sculpture mounts to the wall via offset hangers, also 3D printed from translucent PLA.

## Files

- `Photos/` – Process and installation photos  
- `Code/` – Arduino sketch for LED control  
- `CAD/` – 3D models for the tile blanks, clips, and hangers  
- `LaserCutFiles/` – Honeycomb grid and back panel DXFs
