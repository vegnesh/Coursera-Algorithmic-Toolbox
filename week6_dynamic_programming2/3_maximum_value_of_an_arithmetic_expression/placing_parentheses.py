# Uses python3
from math import inf

def evalt(a, b, op):
    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    elif op == '*':
        return a * b
    else:
        assert False


def min_and_max(m, M, op, i, j):
    maxv = -inf
    minv = inf
    

    for k in range(i, j):
        a = evalt(M[i][k],m[k+1][j],op[k])
        b = evalt(m[i][k],m[k+1][j],op[k])
        c = evalt(M[i][k],M[k+1][j],op[k])
        d = evalt(m[i][k],M[k+1][j],op[k])

        minv = min(minv, a, b, c, d)
        maxv = max(maxv, a, b, c, d)

    return (minv, maxv)




def get_maximum_value(dataset):
    #write your code here
    n = len(dataset)
    ops = dataset[1:len(dataset):2]
    di = dataset[0:len(dataset) + 1:2]
    n = len(di)
    m = [[0]*n for _ in range(n)]
    M = [[0]*n for _ in range(n)]
    for i in range(n):
        m[i][i] = int(di[i])
        M[i][i] = int(di[i])

    for s in range(1, n):
        for i in range(n - s):
            j = i + s
            m[i][j], M[i][j] = min_and_max(m, M, ops, i, j)
    return M[0][n - 1]




if __name__ == "__main__":
    print(get_maximum_value(input()))
