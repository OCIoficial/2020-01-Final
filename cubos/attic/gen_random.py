import random
import sys

# Generates two cubes at random

random.seed(sys.argv[1])

print(*[random.randint(0, 6) for _ in range(6)])
print(*[random.randint(0, 6) for _ in range(6)])
