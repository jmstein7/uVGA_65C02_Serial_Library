# uVGA_65C02_Serial_Library
A uVGA III/II Library for Text and Graphics via a Serial Connection

This is a 65C02 and 65C816 Library for 4D Systems Serial Environement for Picaso based modules, including uVGA III and II. 
For the moment, I have only completed routines for the TEXT and GRAPHICS commands, along with PEEK and POKE. I will be adding
in more command categories over time.

This library provides constants and routines for the 65C02 and 65C816 (and 65C265) based processors and demonstrates how to use them, 
to ease communication with Picaso based modules when using the module configured for Serial. Please refer to the 4D Systems 
website, namingly the Workshop 4 Product Page, for documentation regarding Workshop 4, and its environments.

The picaso_constants.inc file has ZP/DP addressses as well as constants.

The picaso_graphics.65816.asm demonstrates some basic uses of the library along with some basic 'C02 string and buffer routines.
You will need to adjust these for your system.

The picaso_routines.inc contains the main library of routines.

This library requires a Picaso module connected to a 65Cxx system via an ACIA serial connection. 

The FAT16 commands are a WIP, still under development. The text and graphics commands are tested and working. 

Feel free to contact me through the 6502 forum: http://forum.6502.org/memberlist.php?mode=viewprofile&u=3597

N.B. I use Retro Assembler on Visual Studio Code: https://enginedesigns.net/retroassembler

