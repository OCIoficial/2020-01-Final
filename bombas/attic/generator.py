import random
import sys

random.seed(str(sys.argv))

m = int(sys.argv[2])
n = int(sys.argv[3])
k = int(sys.argv[4])

t0 = int(sys.argv[5]) if len(sys.argv) > 5 else 1
tf = int(sys.argv[6]) if len(sys.argv) > 6 else m * n

print(m, n)
print(k)

for i in range(k):
  turn = random.randint(t0, tf)
  while True:
    row, col = random.randint(1, m), random.randint(1, n)
    if (row, col) != (1, 1) and (row, col) != (m, n):
      break

  print(turn, row, col)
