w = [10, 20, 30, 40]
n = len(w)
x = [0]*n
m = 50


def SumOfSub(s, k, r):
    # Left child, i.e include w[k] element in sum
    x[k] = 1

    if s + w[k] == m:
        print(x)
        # to convert all elements after index k to zero in array x
        x[k:] = [0]*(n-k)
    elif k != n-1:         # so that w[k+1] does not go out of bound
        if (s + w[k] + w[k+1] <= m):
            SumOfSub(s+w[k], k+1, r-w[k])

    # Right child, i.e. do not include w[k] element in sum
    if k == n-1:           # so that w[k+1] does not go out of bound
        if (s + r - w[k] >= m):
            x[k] = 0
            SumOfSub(s, k+1, r-w[k])
    else:
        if (s + r - w[k] >= m) and (s + w[k+1] <= m):
            x[k] = 0
            SumOfSub(s, k+1, r-w[k])


SumOfSub(0, 0, sum(w))
