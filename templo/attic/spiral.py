import queue
import random
import sys

m = int(sys.argv[2])
n = int(sys.argv[3])
pattern = sys.argv[4]

bombs = []

grid = [[1e6 for i in range(n + 2)] for j in range(m + 2)]

for i in range(m + 2):
  grid[i][0] = 0
  grid[i][n + 1] = 0

for j in range(n + 2):
  grid[0][j] = 0
  grid[m + 1][j] = 0

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
      bombs.append((1, mi + 1, ni + j))
      bombs.append((1, mf - 1, nf - j))
      grid[mi + 1][ni + j] = 0
      grid[mf - 1][nf - j] = 0
    mi += 2
    mf -= 2
    o = not o
  else:
    if nf - ni <= 3:
      break
    for i in range(0, mf - mi):
      bombs.append((1, mi + i, nf - 1))
      bombs.append((1, mf - i, ni + 1))
      grid[mi + i][nf - 1] = 0
      grid[mf - i][ni + 1] = 0
    ni += 2
    nf -= 2
    o = not o


# block-center: Block center space, will make an unpassable grid
if pattern == "block-center":
  for i in range((m - 1) // 2, (m + 4) // 2):
    for j in range((n - 1) // 2, (n + 4) // 2):
      bombs.append((1, i, j))


# block-past: Block cells just behind the right route
# block-over: Previous case with a 1 turn offset, will make an unpassable grid
if pattern in ["block-past", "block-over"]:
  offset = {
    "block-past": 1,
    "block-over": 0
  }[pattern]
  bfs = queue.Queue()
  bfs.put((1, 1, 1))
  while not bfs.empty():
    turn, row, col = bfs.get()
    if grid[row][col] <= turn:
      continue
    grid[row][col] = turn
    bfs.put((turn + 1, row + 1, col))
    bfs.put((turn + 1, row - 1, col))
    bfs.put((turn + 1, row, col + 1))
    bfs.put((turn + 1, row, col - 1))

  for row in range(1, m + 1):
    for col in range(1, n + 1):
      if (row, col) != (1, 1) and (row, col) != (m, n) and 0 < grid[row][col] < m * n:
        bombs.append((grid[row][col] + offset, row, col))

print(m, n)
print(len(bombs))
for turn, row, col in bombs:
  print(turn, row, col)
