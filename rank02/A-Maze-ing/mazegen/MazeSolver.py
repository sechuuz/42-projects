from .OutputHandler import OutputHandler
from .Cell import Cell


class MazeSolver:
    '''This class contains all the methods required to solve the maze'''
    def __init__(self, maze: list[list[Cell]], conf: dict) -> None:
        '''Initializes the maze solver with the maze and configuration'''
        self.maze = maze
        self.rows = conf["HEIGHT"] * 2 + 1
        self.cols = conf["WIDTH"] * 2 + 1
        self.start = (conf["ENTRY"][1] * 2 + 1, conf["ENTRY"][0] * 2 + 1)
        self.end = (conf["EXIT"][1] * 2 + 1, conf["EXIT"][0] * 2 + 1)
        self.visited: set[tuple[int, int]] = set()
        self.output = OutputHandler(conf["OUTPUT_FILE"])

    def solve(self, output_handler: OutputHandler) -> list[list[Cell]]:
        '''This is responsible for solving the maze and saving the path'''
        self.search(self.start[0], self.start[1], output_handler)
        self.output.save_solution_path()
        return self.maze

    def search(self, r: int, c: int, output_handler: OutputHandler) -> bool:
        '''This is a recursive backtracking method that finds the exit'''
        if (r, c) == self.end:
            self.maze[r][c].solution = True
            return True

        self.visited.add((r, c))
        self.maze[r][c].searching = True

        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        for dr, dc in dirs:
            nr = r + dr
            nc = c + dc
            wall_r = r + dr
            wall_c = c + dc
            if (0 <= nr < self.rows and 0 <= nc < self.cols) and \
                (nr, nc) not in self.visited and \
                not self.maze[nr][nc].wall and \
                    not self.maze[wall_r][wall_c].wall:
                self.visited.add((wall_r, wall_c))
                if self.search(nr, nc, output_handler):
                    self.maze[r][c].solution = True
                    self.maze[r][c].searching = False
                    self.output.add_move(dr, dc)
                    return True

        self.maze[r][c].searching = False
        return False
