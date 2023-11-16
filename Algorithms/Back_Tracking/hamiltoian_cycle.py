'''
Let G be a graph,
find hamiltonian cycle
[start from any vertex,
travel through all the vertices
(each vertex once only)
and finally back to the first vertex]
'''

G = [
    [0, 1, 1, 1],
    [1, 0, 1, 0],
    [1, 1, 0, 1],
    [1, 0, 1, 0]
]

n = len(G)
x = [0]*n


def Hamiltonian(k):
    while (True):
        nextValue(k)
        if x[k] == 0:
            return

        if k == n-1:
            print(x)
        else:
            Hamiltonian(k+1)


def nextValue(k):
    while (True):
        x[k] = (x[k] + 1) % (n+1)
        if x[k] == 0 or k == 0:
            return

        j = 0
        if G[x[k]-1][x[k-1]-1] != 0:  # has edge
            for j in range(0, k):   # excluding k-1
                if x[j] == x[k]:
                    break

            if j == k-1:
                if (k < n-1) or (k == n-1 and G[x[n-1]-1][x[0]-1] != 0):
                    return


Hamiltonian(0)
