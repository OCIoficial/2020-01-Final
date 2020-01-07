import random
import sys

m = int(sys.argv[2])
n = int(sys.argv[3])
s = int(sys.argv[4])

k = 0

print(m, n)

bombs = ""

mi = 1
mf = m
ni = 1
nf = n
o = True

while True:
  if o:
    if mf - mi <= 3:
      break
    for j in range(0, nf - ni):
      bombs += "{} {} {}\n".format(1, mi + 1, nf - j)
      bombs += "{} {} {}\n".format(1, mf - 1, ni + j)
      k += 2
    mi += 2
    mf -= 2
    o = not o
  else:
    if nf - ni <= 3:
      break
    for i in range(0, mf - mi):
      bombs += "{} {} {}\n".format(1, mi + i, ni + 1)
      bombs += "{} {} {}\n".format(1, mf - i, nf - 1)
      k += 2
    ni += 2
    nf -= 2
    o = not o

if s:
  for i in range((m - 1) // 2, (m + 4) // 2):
    for j in range((n - 1) // 2, (n + 4) // 2):
      bombs += "{} {} {}\n".format(1, i, j)
      k += 1

print(k)
print(bombs[:-1])
