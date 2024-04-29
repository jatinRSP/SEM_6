m = int(input("Enter capacity of first jug: "))
n = int(input("Enter capacity of second jug: "))
d = int(input("Enter desired amount: "))
print()


startState = (0,0)
targetState = [(d,0),(0,d)]

def mFull(state):
    return (m, state[1])

def nFull(state):
    return (state[0], n)

def mEmpty(state):
    return (0, state[1])

def nEmpty(state):
    return (state[0], 0)

def mToN(state):
    if state[0] + state[1] <= n:
        return (0, state[0] + state[1])
    else:
        return (state[0] - (n - state[1]), n)
    
def nToM(state):
    if state[0] + state[1] <= m:
        return (state[0] + state[1], 0)
    else:
        return (m, state[1] - (m - state[0]))
    
def printPath(path):
    print("Path:")
    for state in path:
        print(state)

def bfs():
    openL = []
    closeL = []

    openL.append(startState)

    print("open:  ", openL)
    print("close: ", closeL)
    print("-----------------------------------------------")
    

    while openL:
        currentState = openL.pop(0)

        closeL.append(currentState)

        if currentState[0] == d or currentState[1]==d:
            printPath(closeL)
            break

        for nextState in [mFull(currentState), nFull(currentState), mEmpty(currentState), nEmpty(currentState), mToN(currentState), nToM(currentState)]:
            if nextState not in closeL and nextState not in openL:
                openL.append(nextState)
                print("open:  ", openL)
                print("close: ", closeL)
                print("-----------------------------------------------")

    else:
        print("Path not found!")

bfs()