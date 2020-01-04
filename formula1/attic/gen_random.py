import math
import random
import sys


def generate_sorted_array(N, maxi):
    """Generates a sorted array of size `N` where the first element is 0 and the last element is `maxi`."""
    arr = [0]
    for _ in range(N - 1):
        arr.append(random.randint(0, maxi))
    return sorted(arr)


def diffs(arr):
    """Returns the array of differences."""
    output = [0]
    for i in range(1, len(arr)):
        output.append(arr[i] - arr[i - 1])
    return output


def inv(y):
    i = int((-1 + math.sqrt(1 + 8 * y)) / 2)
    j = int(y - (i * (i + 1)) / 2)
    return (j, i)


def main():
    random.seed(sys.argv[1])

    N = int(sys.argv[2])
    Q = int(sys.argv[3])
    maxi = int(sys.argv[4])

    # We don't want queries between the same positions, thus, we skip the diagonal.
    MAXQ = (N * (N - 1)) // 2

    assert N >= 2
    assert 0 < Q <= MAXQ

    print(N, Q)
    arr = diffs(generate_sorted_array(N, maxi))
    print(' '.join(str(i) for i in arr))

    for q in random.sample(range(MAXQ), Q):
        (a, b) = inv(q)
        # `inv` considers the diagonal so we add 1 to b.
        # In `inv` positions start from 0 but in the statement positions start from 1, so we add 1 to both.
        a += 1
        b += 2
        assert 1 <= a < b <= N
        print(a, b)


main()
