'''
Description:
This project involves building a maze generator and solver, it should take in
a configuration file that dictates how everything needs to be handled and then
work accordingly. For the bonus, we chose to implement the animation for
drawing the maze as well as solving it, in addition to adding a mini game that
allows users to control a character within the bounds of the maze.

Basic usage example:
from mazegen.Maze import MazeGenerator

config = {
    "WIDTH": 15,
    "HEIGHT": 10,
    "ENTRY": (0, 0),
    "EXIT": (14, 9),
    "OUTPUT_FILE": None,
    "PERFECT": True,
    "SEED": 42
}

generator = MazeGenerator(config)
generator.generate_maze()
generator.draw_maze()

Solution Path Example:
from mazegen.MazeSolver import MazeSolver
generator = MazeSolver(maze, config).solve(output_handler)
generator.draw_maze(show_solution=True)
'''

from .Maze import MazeGenerator # noqa
from .PlayMaze import PlayMaze # noqa
from .OutputHandler import OutputHandler # noqa
from .MazeSolver import MazeSolver # noqa
from .process_config import read_config # noqa
