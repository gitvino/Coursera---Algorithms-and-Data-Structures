# Uses python3
import sys

def binary_search(a, left, right, x):
    if right >= left:
        mid = left + (right - left)//2
        if a[mid] == x:
            return mid
        if x < a[mid]:
            return binary_search(a, left, mid-1, x)
        if x > a[mid]:
            return binary_search(a, mid+1, right, x)
    else:
        return -1

def linear_search(a, x):
    for i in range(len(a)):
        if a[i] == x:
            return i
    return -1

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    m = data[n + 1]
    a = data[1 : n + 1]
    for x in data[n + 2:]:
        # replace with the call to binary_search when implemented
        print(binary_search(a, 0, len(a)-1, x), end = ' ')
    #print(binary_search([3,5,7,8,10], 0, 4, 10))
