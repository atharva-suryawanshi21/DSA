'''
Find whether the nodes of G can be colored
in such a way that no two adjacent nodes have same color
'''

G = [
    [0, 1, 1, 0],
    [1, 0, 0, 1],
    [1, 0, 0, 1],
    [0, 1, 1, 0]
]

n = len(G)
m = int(input("Enter the no. distinct colors : "))

x = [0]*n


def mColoring(k):
    while (True):

        nextValue(k)
        if x[k] == 0:
            return
        if k == n-1:
            print(x)
        else:
            mColoring(k+1)


def nextValue(k):

    while (True):
        x[k] = (x[k] + 1) % (m+1)

        if x[k] == 0:
            return
        j = 0
        for j in range(0, n):
            if (G[j][k] == 1) and (x[j] == x[k]):
                break

        if j == n-1:
            return


mColoring(0)
