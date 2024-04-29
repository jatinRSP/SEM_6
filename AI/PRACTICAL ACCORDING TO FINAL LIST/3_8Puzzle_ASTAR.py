# Define class which contain 3*3 matrix as well as heuristic and other functions

# Heuristic is how many tiles are not well placed in the matrix

class Node:
    def __init__(self, state, heuristic=0):
        self.state = state
        self.heuristic = heuristic

    def calculateHeuristic(self, target):
        for i in range(3):
            for j in range(3):
                if self.state[i][j] != target[i][j]: # Not equal means not well placed
                    self.heuristic += 1

    def printState(self):
        for i in range(3):
            for j in range(3):
                print(self.state[i][j], end=" ")
            print()
        print()

        print("Heuristic:", self.heuristic)

        print("-------------------------------")


def main():

    print("Enter the start state: ")
    start = []
    for i in range(3):
        start.append(list(map(int, input().split())))
    startNode = Node(start)


    print("Enter the target state: ")
    target = []
    for i in range(3):
        target.append(list(map(int, input().split())))

    startNode.calculateHeuristic(target)
    
    print("---------------------LETS PERFOM A* ALGORITHM---------------------")

    openL = []
    closeL = []

    openL.append(startNode)

    while openL:
        # Sort open list based on heuristic
        openL.sort(key=lambda x: x.heuristic)

        currentNode = openL.pop(0)
        
        closeL.append(currentNode)

        currentNode.printState()

        if currentNode.state == target:
            print("Path:", " -> ".join(str(node.state) for node in closeL))
            break

        # Generate all possible states

        for i in range(3):
            for j in range(3):
                if currentNode.state[i][j] == 0:
                    x, y = i, j
                    break

        # Move up
        if x > 0:
            newState = [row[:] for row in currentNode.state]
            newState[x][y], newState[x-1][y] = newState[x-1][y], newState[x][y]

            newNode = Node(newState)
            newNode.calculateHeuristic(target)

            if newNode not in closeL:
                openL.append(newNode)

        # Move down
        if x < 2:
            newState = [row[:] for row in currentNode.state]
            newState[x][y], newState[x+1][y] = newState[x+1][y], newState[x][y]

            newNode = Node(newState)
            newNode.calculateHeuristic(target)

            if newNode not in closeL:
                openL.append(newNode)

        # Move left
        if y > 0:
            newState = [row[:] for row in currentNode.state]
            newState[x][y], newState[x][y-1] = newState[x][y-1], newState[x][y]

            newNode = Node(newState)
            newNode.calculateHeuristic(target)

            if newNode not in closeL:
                openL.append(newNode)

        # Move right
        if y < 2:
            newState = [row[:] for row in currentNode.state]
            newState[x][y], newState[x][y+1] = newState[x][y+1], newState[x][y]

            newNode = Node(newState)
            newNode.calculateHeuristic(target)

            if newNode not in closeL:
                openL.append(newNode)

if __name__ == "__main__":
    main()