import random
import sys

random.seed(sys.argv[1])

start = [str(random.randint(0, 9)) for _ in range(4)]
end = [str(random.randint(0, 9)) for _ in range(4)]
print(' '.join(start))
print(' '.join(end))
