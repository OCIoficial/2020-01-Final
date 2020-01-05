import random
import sys

# Generates one cube as random and the second as a rotation of the first one


# Rotates cube horizontally
def roth(cube):
    aux = 0
    aux = cube[2]
    cube[2] = cube[3]
    cube[3] = cube[4]
    cube[4] = cube[5]
    cube[5] = aux


# Rotates cube vertically
def rotv(cube):
    aux = 0
    aux = cube[0]
    cube[0] = cube[2]
    cube[2] = cube[1]
    cube[1] = cube[4]
    cube[4] = aux


def main():
    random.seed(sys.argv[1])

    cube1 = [random.randint(0, 6) for _ in range(6)]

    # Copy and rotate randomly 100 times
    cube2 = cube1.copy()
    for _ in range(100):
        if random.choice([True, False]):
            roth(cube2)
        else:
            rotv(cube2)
    print(*cube1)
    print(*cube2)


main()
