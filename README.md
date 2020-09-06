# Filler
Player for a competitive map filling game.  Macos only

## Goal
The purpose of this project is to write a competitive AI to place more random objects on a playing board than the opponent.

In this game, players are provided with a playing board and starting location. On alternating turns, each player is given the updated game board with the opponent's most recent piece placement, and given a random piece shape to place on the board. The piece must be placed according to rules:
• The new piece must overlap one and only one grid unit of the current player's existing sprawl.
• The placement coordinates must set the piece such that none of the piece overlaps the oppenent's sprawl nor overflows the playing board boundaries.

The game is won not by covering the most area on the playing board (piece size and shape is completely random), but by whichever player can place the most pieces. Therefore, the strategy is to be able to fill the board in such a way that traps the opponent and prevents them from any further legal placements.

Installation
------------
Run 'make'

Usage
-----
`./filler_vm -f path [-i | -p1 path | -p2 path] [-s | -q | -t time]`
* -f: use a map file (required)
* -p1: use filler binary as a first player
* -p2: use filler binary as a second player

### Example
`./filler_vm -f maps/map00 -p1 players/hde-ghel.filler -p2 players/abanlin.filler`
```
launched players/hde-ghel.filler
$$$ exec p1 : [players/hde-ghel.filler]
launched players/abanlin.filler
$$$ exec p2 : [players/abanlin.filler]
.
.
.
Plateau 15 17:
    01234567890123456
000 XXXXXXXXXXXXXXXX.
001 XXXXXXXXXXXXXXXX.
002 XXXXXXXXXXXXXxXX.
003 XXXXXXXXXXXXXx...
004 .OOOOOX..XX......
005 ....OOXXXXX......
006 .....OOOOXXX.....
007 ...O.OOOOOOXXXO..
008 ..OO.OO.OOOOOXOOO
009 ...OOOOOO..OOXXOO
010 .....OOOOOOOOOXOO
011 ......OO.OOOOOXOO
012 .......O.OOOOXXOO
013 .......OOOOOOOOOO
014 ...........OOOOOO
Piece 1 2:
**
<got (O): [7, 14]
.
.
.
== O fin: 97
== X fin: 65
```
