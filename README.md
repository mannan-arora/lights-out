## Lights Out
### Summary
- Lights Out consists of an *n* × *n* grid of cells, each of which can be either on or off. When the game begins, an initial configuration of on and off cells must be specified.
-  Once the cells are configured, the player chooses a cell and turns it on if it is off, and off if it is on. In response the four neighbouring cells (to the north, south, east, and west) all switch configurations between off and on as well. The object of the game is to get all of the cells turned off.
-  This game was implemented using the observer design pattern

### Commands
`new n` Creates a new *n* × *n* grid. If a previous grid was already active, it is destroyed and replaced with the new one.

`init` Enters initialization mode where the cell at coordinates *x* *y* are set On. The coordinates -1 -1 end initalization mode.

`game g` Starts a new game with *g* number of moves.

`switch x y` Switches the cell at coordinate *x*, *y* to on or off.

### Demo
The following is a sample execution of the program run with a 5 × 5 grid.
```
new 5
init
1 2
2 2
3 2
-1 -1
.....
..X..
..X..
..X..
.....
3 moves left
switch 2 2
.....
.....
.X.X.
.....
.....
2 moves left
switch 3 1
.....
.....
...X.
XXX..
.X...
1 move left
switch 3 3
.....
.....
.....
XX.XX
.X.X.
0 moves left
Lost
```
