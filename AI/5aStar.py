start = [
    [8, 7, 6],
    [5, 4, 3],
    [2, 1, 0]
]

target = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 0]
]

class State:
    def __init__(self, puzzle, heuristic=None):
        self.puzzle = puzzle
        self.heuristic = heuristic

    def calculateHeuristic(self, target):
        self.heuristic = 0
        for i in range(3):
            for j in range(3):
                if self.puzzle[i][j] != target[i][j]:
                    self.heuristic += 1

    def up(self):
        newState = [row[:] for row in self.puzzle]
        for i in range(3):
            for j in range(3):
                if newState[i][j] == 0 and i < 2:
                    newState[i][j] = newState[i + 1][j]
                    newState[i + 1][j] = 0
                    return newState

    def down(self):
        newState = [row[:] for row in self.puzzle]
        for i in range(3):
            for j in range(3):
                if newState[i][j] == 0 and i > 0:
                    newState[i][j] = newState[i - 1][j]
                    newState[i - 1][j] = 0
                    return newState

    def left(self):
        newState = [row[:] for row in self.puzzle]
        for i in range(3):
            for j in range(3):
                if newState[i][j] == 0 and j < 2:
                    newState[i][j] = newState[i][j + 1]
                    newState[i][j + 1] = 0
                    return newState

    def right(self):
        newState = [row[:] for row in self.puzzle]
        for i in range(3):
            for j in range(3):
                if newState[i][j] == 0 and j > 0:
                    newState[i][j] = newState[i][j - 1]
                    newState[i][j - 1] = 0
                    return newState

    def printPuzzle(self):
        for row in self.puzzle:
            print(row)
        print()


def bfs(start, target):
    openL = []
    closeL = []

    start.calculateHeuristic(target)  # Calculate heuristic for initial state
    openL.append(start)

    print("open: ", openL)

    while openL:
        # sort openL based on heuristic
        openL.sort(key=lambda x: x.heuristic)
        currentState = openL.pop(0)
        closeL.append(currentState)

        if currentState.puzzle == target:
            print("Path:")
            for state in closeL:
                state.printPuzzle()
            break

        for nextState in [currentState.up(), currentState.down(), currentState.left(), currentState.right()]:
            if nextState not in closeL and nextState not in openL:
                newState = State(nextState)
                newState.calculateHeuristic(target)
                openL.append(newState)

    else:
        print("Path not found!")


startState = State(start)
bfs(startState, target)
