class Node: 
    def __init__(self, state = None, heuristic = None, target = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]):
        self.state = state
        self.heuristic = self.calculateHeuristic(target)

    def calculateHeuristic(self, target):
        self.heuristic = 0
        for i in range(3):
            for j in range(3):
                if self.state[i][j] != target[i][j]:
                    self.heuristic += 1

    def up(self):
        # Move white space up
        newState = Node([row[:] for row in self.state], self.heuristic)
        if newState.state[0][0] == 0 or newState.state[0][1] == 0 or newState.state[0][2] == 0:
            return None
        
        for i in range(3):
            for j in range(3):
                if newState.state[i][j] == 0 and i < 2:
                    newState.state[i][j] = newState.state[i + 1][j]
                    newState.state[i + 1][j] = 0
                
        newState.calculateHeuristic(target)
        return newState

    def down(self):
        # Move white space down
        newState = Node([row[:] for row in self.state], self.heuristic)
        if newState.state[2][0] == 0 or newState.state[2][1] == 0 or newState.state[2][2] == 0:
            return None
        
        for i in range(3):
            for j in range(3):
                if newState.state[i][j] == 0 and i > 0:
                    newState.state[i][j] = newState.state[i - 1][j]
                    newState.state[i - 1][j] = 0
                
        newState.calculateHeuristic(target)
        return newState

    def left(self):
        # Move white space left
        newState = Node([row[:] for row in self.state], self.heuristic)
        if newState.state[0][0] == 0 or newState.state[1][0] == 0 or newState.state[2][0] == 0:
            return None
        
        for i in range(3):
            for j in range(3):
                if newState.state[i][j] == 0 and j < 2:
                    newState.state[i][j] = newState.state[i][j + 1]
                    newState.state[i][j + 1] = 0
                
        newState.calculateHeuristic(target)
        return newState

    def right(self):
        # Move white space right
        newState = Node([row[:] for row in self.state], self.heuristic)
        if newState.state[0][2] == 0 or newState.state[1][2] == 0 or newState.state[2][2] == 0:
            return None
        
        for i in range(3):
            for j in range(3):
                if newState.state[i][j] == 0 and j > 0:
                    newState.state[i][j] = newState.state[i][j - 1]
                    newState.state[i][j - 1] = 0
                
        newState.calculateHeuristic(target)
        return newState
    
    def printNode(self):
        # Print in the format of the 8-puzzle
        for row in self.state:
            print(row)



# 8-puzzle

target = Node([[1, 2, 3], [4, 5, 6], [7, 8, 0]])
start = Node([[0, 1, 2], [3, 4, 5], [6, 7, 8]])

openL = []
closeL = []
path = []

openL.append(start)

print("open: ", openL)

while openL:
    # Sort open list by heuristic
    openL.sort(key=lambda x: x.heuristic)
    currentNode = openL.pop(0)
    currentNode.printNode()

    closeL.append(currentNode)
    if currentNode.state == target.state:
        print("Goal reached")
        break
    else:
        up = currentNode.up()
        down = currentNode.down()
        left = currentNode.left()
        right = currentNode.right()
        if up not in closeL and up not in openL:
            openL.append(up)
        if down not in closeL and down not in openL:
            openL.append(down)
        if left not in closeL and left not in openL:
            openL.append(left)
        if right not in closeL and right not in openL:
            openL.append(right)