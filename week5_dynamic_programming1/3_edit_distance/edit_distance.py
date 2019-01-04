# Uses python3
def edit_distance(a, b):
    #write your code here
    T = [[float("inf")]*(len(b)+1) for _ in range(len(a)+1)]  
    for i in range(len(a)+1):
        T[i][0] = 0
    for j in range(len(b)+1):
        T[0][j] = 0
    for i in range(1,len(a)+1):
        for j in range(1,len(b)+1):
            diff = 0
            if (a[i-1] == b[j-1]):
                T[i][j] =  T[i-1][j-1] + 1
            else:
                T[i][j] = max(T[i][j-1],T[i-1][j])
            
            
    return T[len(a)][len(b)]

if __name__ == "__main__":
    print(edit_distance(input(), input()))
