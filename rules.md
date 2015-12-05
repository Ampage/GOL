Transitions
===========
1. Any live cell with fewer than two live neighbours dies, as if caused by under?population.
2. Any live cell with two or three live neighbours lives on to the next generation.
3. Any live cell with more than three live neighbours dies, as if by over?population.
4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
« STARTED »

Simulations
===========
Run the simulation for 5 rounds. At the end of each round, one of the MPI processes should create a file with the state
of the cells (state1.txt, state2.txt, state3.txt, state4.txt, state5.txt). Live cells should be represented with a capital
O and dead cells with a capital X.
« STARTED »

Board Size
==========
The “board” is 40 cells wide by 80 cells high. This should allow you to send the data between processes easily.
« DONE »

Processes
=========
You should use 16 MPI processes. Each process should handle a 40 cell wide by 5 cell high area.
« NOT YET STARTED »

File Read
=========
The initial configuration (which cells are dead and which cells are live) should be read in from a file called initial_config.txt.
Again, X means dead, O means love. The file will have 80 lines, each with 41 characters (41 because of the new line character!).
« ALMOST DONE »