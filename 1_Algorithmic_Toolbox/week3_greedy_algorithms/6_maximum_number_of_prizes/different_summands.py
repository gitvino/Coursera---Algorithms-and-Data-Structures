# Uses python3

import sys

def optimal_summands(n):
    summands = []
    k = 1 
    if (n <= 2*k):
        summands.append(n)
        return summands
    while(n > 2*k):
        summands.append(k)
        n = n-k
        k += 1
    summands.append(n)
    return summands

if __name__ == '__main__':
    n = int(input())
    summands = optimal_summands(n)
    print(len(summands))
    for x in summands:
        print(x, end=' ')
