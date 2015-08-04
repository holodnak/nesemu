# NESEMU #
_The unnamed NES emulator, also extremely portable._

## News - 03/02/2013 ##
nesemu is back into part-time development!

## News - 04/15/2011 ##
The project is no longer active. Original owner gone until further notice. If your interested in this project, please contact brandonlbradley@gmail.com

## News - 05/05/2009 ##
nesemu2 has begun, nesemu is on the backburner, while pceemu is right beside nesemu2 on the front burners!  nesemu2 is a complete rewrite reusing very little code, focusing on more accurate timing in the cpu, and mid-line updates on the ppu.  i decided it would be too much work to accomplish what i want to do, so the rewrite has begun.  also, there is a new gui being coded, the successor to gui2:  gui3.  portability will also be a goal, also a client/server thing for internet gaming...hopefully...

## Latest News ##
New emulation project started, [PCEEMU](http://code.google.com/p/pceemu/).

## Previous Latest News ##
PS2 support will be removed when the new PPU core is completed.  The core will most likely be too much for the PS2 to handle.  Also, when the new PPU core is put into place, I should have migrated from Matt Conte's APU to blargg's APU.

My motivation for working on this project is strong even with my new side project starting to roll.  Mappers are also at the bottom of my priority list because, honestly, I'm just sick of writing them, tracking down hard to find games, etc...

## Old News ##
I've been secretly working on nesemu with a mini-itx Intel Atom board, not much time to do any real work but the Wii version is now working perfectly without SDL, and some new PPU engine tweaks make less graphics emulation errors.  Dirty iNES headers are now detected, so the correct mapper is loaded now.  Small ROM database is also internal in the code, for a specific few games (notably the VRC mappers).  Splash screen, and probably other things added as well.  Finally, NSF player working great along with a more compatable HLE FDS BIOS.  Not enough work for a new release though...

## Features ##
  * Mega fast on all targets, around 900 FPS on this computer I am writing with.
  * Superb compatability.
  * Awesome mapper support.
  * Amazingly free and open sores, released under GPL v2.

## Supported Targets ##
  * [Win32](TargetWin32.md): Finished.
  * [Linux](BetaLinux.md): Near finished...
  * [OSX](BetaOSX.md): Near finished...
  * [PS2](BetaPS2.md): Near finished...
  * [Wii](BetaWii.md): Near finished...

Linux binary releases will be discontinued, it's too easy to run "make linux".
OSX binaries need to be updated.

## Usage ##
Usage is the same on all platforms, an incomplete but usable ZSNES look alike GUI.  To get started, click _Game_ then _Load_.

![http://ps2.fapexpert.com/usage1.png](http://ps2.fapexpert.com/usage1.png)

Browse directories on the right, files on the left.  This is accomplished by double clicking the directory you want to browse into, or '..' choosing to go to the previous directory.

If the emulator finds any usable images, they will appear on the left.  Single click a file to show its info at the bottom of the load dialog.  Double click a file to load it into the emulator and exit the GUI.

![http://ps2.fapexpert.com/usage2.png](http://ps2.fapexpert.com/usage2.png)

Once the emulator is running the default keys are the same on all PC platforms; PS2 and Wii have nicer controls.

Default keys for PCs:
  * Directional Pad = Arrow Keys
  * Start = S
  * Select = A
  * Button A = X
  * Button B = Z
  * Menu = Escape
  * Fast Forward = 1
  * Disk Flip = F1
  * Save State = F5
  * Load State = F8

Default keys for PS2:
  * Directional Pad = Directional Pad
  * Start = Start
  * Select = Select
  * Button A = Square or Circle
  * Button B = Cross or Triangle
  * Menu = R 2
  * Move Menu Cursor = Left Analog

Default keys for Wii:
  * Classic controller can also be used, keys are perfect with it.
  * Wiimote is being held sideways.
  * Directional Pad = Directional Pad
  * Start = +
  * Select = -
  * Button A = 2
  * Button B = 1
  * Disk Flip = B
  * Menu = A
  * Move Menu Cursor = Flip Wiimote vertically, and use point and click method with B.

There are many GUI options, those will be documented later, before the 'final' release.  Just explore, there is a lot!

## Code Notes ##
The emulator is coded in C, nothing fancy.  It should build under any environment.  I usually use GCC for all targets other than Windows, Visual Studio 2005 with Windows, and KDevelop on Linux.

## PS2 Notes ##
**Feedback is needed on the PS2 port.  If the emulator ISN'T working for you, please either email or post an issue containing the following information:**
  * PS2 kind (either slim or fat).
  * Which devices are in the controller ports.
  * Memory card slot contents (memcard type and manufacturer).
  * Ethernet controller connected? (fat ps2 only)
  * Hard drive connected?
  * Where NESEMU was ran from (network, hard drive, etc.).
  * NESEMU version.

## Bugs ##
Please report all bugs found to the Issues section of this site.

**Your feedback is needed to make the emulator better!**