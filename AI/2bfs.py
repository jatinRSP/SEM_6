import numpy as np

n = int(input("Enter number of nodes: "))

# crate n * n array with all 0

graph = np.zeros((n, n), dtype=int)

# create edges

for i in range(n):
    print(f"Enter neighbors of node {i} (space separated): ")
    neighbors = list(map(int, input().split()))
    for neighbor in neighbors:
        graph[i][neighbor] = 1
        graph[neighbor][i] = 1

# print entire matrix
    
print("Graph:")
print(graph)

# bfs

openL = []
closeL = []

startNode = int(input("Enter start node: "))
targetNode = int(input("Enter target node: "))

openL.append(startNode)

print("open: ", openL)
print("close: ", closeL)
print("-----------------------------------------------")

while openL:
    currentNode = openL.pop(0)

    closeL.append(currentNode)

    if currentNode == targetNode:
        print("Path:", " -> ".join(str(node) for node in closeL))
        break

    for neighbor in range(n):
        if graph[currentNode][neighbor] == 1 and neighbor not in closeL and neighbor not in openL:
            openL.append(neighbor)

    print("open: ", openL)
    print("close: ", closeL)
    print("-----------------------------------------------")