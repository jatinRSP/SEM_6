import copy

a1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
a2 = copy.deepcopy(a1)
a2[0][0] = 0

print(a1)
print(a2)