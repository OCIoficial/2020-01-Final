import random
import sys

random.seed(str(sys.argv))

m = int(sys.argv[2])
n = int(sys.argv[3])
k = float(sys.argv[4])

t0 = float(sys.argv[5]) if len(sys.argv) > 5 else 1
tf = float(sys.argv[6]) if len(sys.argv) > 6 else M * N

print(m, n)
print(k)

for i in range(k):
  print(
    random.randint(t0, tf),
    random.randint(1, M),
    random.randint(1, N)
  )
