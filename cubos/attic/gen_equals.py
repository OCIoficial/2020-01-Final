import random
import sys

# Generates two equal cubes

random.seed(sys.argv[1])

cube = [random.randint(0, 6) for _ in range(6)]
print(*cube)
print(*cube)
