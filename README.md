# Hardwere
1. Arduino Nano Every
2. 74LS595 8-bit shift register SIPO (Serial In Parallel Out)

# Direction conversion

Every motor have 2 directions and a full breakes position and need 2 inputs to select the direction, so we can translate it into a 2 bits value.

Legend | direction
------ | ---------
10 | FWD
01 | BKW
00 | Stop

In order to set the directions of 4 motors we can work with a 1 byte value (8-bit).
If we take into account the use of 4 mechanum wheels, 10 directions are possible.

Direction | M1M2 M3M4 | Decimal
--------- | --------- | -------
N | 1010 1010 | 170
NE | 1000 0010 | 130
E | 1001 0110 | 150
SE | 0001 0100 | 20
S | 0101 0101 | 85
SO | 0100 0001 | 65
O | 0110 1001 | 105
NO | 0010 1000 | 40
ROT R | 1001 1001 | 153
ROT L | 0110 0110 | 102

