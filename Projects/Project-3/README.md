## PROJECT 3: Graph Modeling and Graph Algorithms
###Matthew Kramer [U20891900]

This code has been successfully compiled using GCC 4.4.7 on a Scientific Linux 6.3 client from CIRCE at USF.

Ensure all files for the project are placed in a single directory, including the input file for the program, which should be named 'input.txt' for proper execution.

To compile, use the included makefile by executing the `make` command or manually by using `g++ -Wall -o maze Source.cpp Cell.cpp`, both in the working directory for the project.

The program is compiled into an executable named 'maze' which may be run once the program is compiled.

When complete, the results of the algorithm will be stored in the 'output.txt' file.

Sample terminal output from compilation and execution can be seen below.

```
[kramerm@login5 Maze]$ make
g++ -Wall -o maze Source.cpp Cell.cpp
[kramerm@login5 Maze]$ ./maze

3 maze instances defined.

Maze #1:
5 levels, 4 rows, and 4 columns.
Starting at (0, 3, 3)
Ending at (4, 0, 0)
Solved in 50 steps.

Maze #2:
3 levels, 3 rows, and 3 columns.
Starting at (0, 0, 0)
Ending at (2, 2, 2)
Solved in 22 steps.

Maze #3:
5 levels, 10 rows, and 10 columns.
Starting at (1, 1, 8)
Ending at (3, 7, 1)
Solved in 247 steps.

  / _ \
\_\(_)/_/
 _//"\\_
  /   \
```
