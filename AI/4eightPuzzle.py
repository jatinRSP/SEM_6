import numpy as np

# create 3*3 matrix for start state and get input from user

startState = np.zeros((3, 3), dtype=str)
for i in range(3):
    for j in range(3):
        startState[i][j] = input(f"Enter value for cell ({i}, {j}): ")

# create 3*3 matrix for target state
        
targetState = np.array([['1', '2', '3'], ['4', '5', '6'], ['7', '8', '0']])

# print start and target state

print("Start state:")
print(startState)
print("Target state:")
print(targetState)

# possible moves

def up(state):
    newState = np.copy(state)
    for i in range(3):
        for j in range(3):
            if newState[i][j] == ' ' and i > 0:
                newState[i][j] = newState[i-1][j]
                newState[i-1][j] = ' '
                return newState
            
def down(state):
    newState = np.copy(state)
    for i in range(3):
        for j in range(3):
            if newState[i][j] == ' ' and i < 2:
                newState[i][j] = newState[i+1][j]
                newState[i+1][j] = ' '
                return newState
            
def left(state):
    newState = np.copy(state)
    for i in range(3):
        for j in range(3):
            if newState[i][j] == ' ' and j > 0:
                newState[i][j] = newState[i][j-1]
                newState[i][j-1] = ' '
                return newState
            
def right(state):
    newState = np.copy(state)
    for i in range(3):
        for j in range(3):
            if newState[i][j] == ' ' and j < 2:
                newState[i][j] = newState[i][j+1]
                newState[i][j+1] = ' '
                return newState
            
# bfs
            
def bfs():
    openL = []
    closeL = []
    path = []
    
    openL.append(startState)
    
    print("open: ", openL)
    
    while openL:
        currentState = openL.pop(0)
        
        closeL.append(currentState)
        
        if np.array_equal(currentState, targetState):
            print("Path:")
            for state in path:
                print(state)
            break
        
        for nextState in [up(currentState), down(currentState), left(currentState), right(currentState)]:
            if nextState is not None and not np.array_equal(nextState, currentState) and not np.array_equal(nextState, closeL) and not np.array_equal(nextState, openL):
                openL.append(nextState)
                path.append((currentState, nextState))
                
    else:
        print("Path not found!")

bfs()