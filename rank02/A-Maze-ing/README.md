*This project has been created as part of the 42 curriculum by sechavez, akheiral*

# A-Maze-ing

## Description:

This project involves building a maze generator and solver, it should take in a configuration file that dictates how everything needs to be handled and then work accordingly. For the bonus, we chose to implement the animation for drawing the maze as well as solving it, in addition to adding a mini game that allows users to control a character within the bounds of the maze.

An output file will then be generated showcasing the maze in hexadecimal format, as well as entry/exit coordinates and instructions in NSEW showing the best path to solving the maze.

We chose an object-oriented approach for the maze, its 2D-list consisting of Cells. Each Cell holds different attributes allowing us to distinguish between walls, protected cells in the 42 pattern, the exit and entrance. All of this culminates in the MazeGenerator class. 

### Algorithm

We chose to use Depth First Search backtracking to create and solve the maze, it is a tree-based algorithm that checks all possible options carving a path, until it runs into a dead end at which it backtracks to a previous checkpoint to check a different path and so on and so forth. 

We used DFS because it is commonly used and this generation makes it so the mazes are always perfect. We had to specifically break the maze after generation because of this.

The generation of the maze is mostly randomized, we are told to allow users the capability regenerate the same maze using a seed, this is done by using the random library.

### Advanced Features:

*   **Maze Generation Animation**: When generating a new maze, the generation is animated. You are able to watch the maze generate in real time.
*   **Randomized Maze Color Rotation**: Rotating the maze's colors will rotate through random colors.
*   **Playable Maze**: You are able to play through the maze yourself.

## Intructions:

### Compilation:

To compile and run this project, run the following commands within the project directory:
```bash
make install
```
```bash
make run
```

### Running the program:

The config file must be structured and formatted as follows:

| Key | Description | Example |
| :--- | :--- | :--- |
| **WIDTH** | Maze width (number of cells) | `WIDTH=20` |
| **HEIGHT** | Maze height | `HEIGHT=15` |
| **ENTRY** | Entry coordinates (x,y) | `ENTRY=0,0` |
| **EXIT** | Exit coordinates (x,y) | `EXIT=19,14` |
| **OUTPUT_FILE** | Output filename | `OUTPUT_FILE=maze.txt` |
| **PERFECT** | Is the maze perfect? | `PERFECT=True` |
| **SEED** | Used to create a unique maze | `PERFECT=True` |

```ini
# a_maze_ing configuration
WIDTH=20
HEIGHT=20
ENTRY=0,0
EXIT=19,19
OUTPUT_FILE=maze.txt
PERFECT=True
# Optional
SEED=42
```

The following utilities can also be run:
* `make clean` Removes the python artifacts.
* `make lint` Runs flake8 and mypy with flags.
* `make debug` Runs the python debugger.

## Code Reusability:

Our project is compiled as a library and can be imported into any python file when installed with pip. From there, you can call any class or function from within the library.

## Team & Project Management:

### Roles & Deliverables:

* Make config.txt handler - *akheiral*
* Finish Maze Generator perfect and imperfect - *akheiral*
* Finish Maze solver - *sechavez*
* Finish Output maker - *sechavez*
* Finish Makefile - *akheiral*, *sechavez*
* Finish README.md - *akheiral*, *sechavez*

### Anticipated Planning & Timeline Evolution:

We divided the work between both of us, first prioritizing getting everything to work, which went pretty smoothly. However, our anticipated planning evolved when we ran into a few small issues that we had to iron out later down the line when we were making the scripts reusable and arranging them into proper object-oriented classes.

### Retrospective (What worked well & What could be improved):

Dividing the work made things a bit smooth at first. However, again, a few issues did arise when we started trying to organize the code collectively. There weren't any big structural issues, just some troublesome small bugs we had to face and fix when hooking our individual components together. In the future, aligning our exact class data formats earlier would prevent these integration bugs.

### Tools Used:

We used GitHub to store a public version of the repository that we could easily access outside of the physical 42 clusters, and we coded the project mainly within VS Code.

## Resources:

### References

* [Amazing resource for maze generation algorithms](https://professor-l.github.io/mazes/)
* [In-depth guide to DFS for maze generation](https://medium.com/@nacerkroudirrandomized-depth-first-search-algorithm-for-maze-generation-fb2d83702742)


### Use of AI

AI assisted us in:
* Clarifying and solidifying various concepts within the project
* Finding bugs