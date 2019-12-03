import sys

def merge(input, left, right):    
    pivot = input[left]
    j = left
    for i in range(left + 1, right+1):
        if input[i] <= pivot:
            j += 1
            input[i], input[j] = input[j], input[i]
    input[left], input[j] = input[j], input[left]
    return j
    
if __name__ == '__main__':
    input = sys.stdin.read()
    n, *input = list(map(int, input.split()))
    quickSort(input, 0, n-1)
    print(input)
    