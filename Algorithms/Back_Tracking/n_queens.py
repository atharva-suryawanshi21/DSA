
n = int(input("Enter the no. of queens : "))

x = [-1]*n


def place(k, i):
    for j in range(0, k):
        if (x[j] == i) or (abs(j-k) == abs(x[j] - i)):
            return False
    return True


def nQueens(k, n):
    for i in range(0, n):
        if place(k, i):
            x[k] = i
            if k == n-1:
                print(f"Columns to be occupied (columns start from 0): {x}")
            else:
                nQueens(k+1, n)


nQueens(0, n)
