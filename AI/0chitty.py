import math

def movementCount():
    movementCount = int(input("Enter number of movements: "))
    
    if movementCount < 0:
        print("Invalid input")
        return movementCount()
    else:
        return movementCount

def movement():
    movement = input("Enter direction and steps: ").split(" ")
    
    if len(movement) != 2:
        print("Invalid input")
        return movement()
    else: 
        diraction =  movement[0].upper()
        steps = int(movement[1])

        if diraction not in ['UP', 'DOWN', 'LEFT', 'RIGHT']:
            print("Invalid input")
            return movement()

        return diraction, steps
    
def calculateDistance(x,y):
    distance = math.sqrt((x-0)**2 + (y-0)**2)
    return distance

def main():
    x, y  = 0, 0
    movements = movementCount()

    for i in range(movements):
        d, s = movement()

        if d == 'UP':
            y += s
        elif d == 'DOWN':
            y -= s
        elif d == 'LEFT':
            x -= s
        elif d == 'RIGHT':
            x += s

    print(round(calculateDistance(x,y)))

if __name__ == "__main__":
    main()