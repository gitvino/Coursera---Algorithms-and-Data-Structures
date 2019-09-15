# python3
import sys


def compute_min_refills(distance, tank, stops):
    # write your code here
    stops.insert(0,0)
    stops.append(distance)

    n = len(stops)
    last_refill = 0
    current_refill = 0
    num_refills = 0
    
    while (current_refill < n-1):
        last_refill = current_refill
        while(current_refill < n-1 and (stops[current_refill+1] - stops[last_refill] <= tank)):
            current_refill += 1
        if (last_refill == current_refill): 
            return -1
        if (current_refill < n-1):
            num_refills += 1
    return num_refills

if __name__ == '__main__':
    distance =  int(input())
    tank = int(input())
    _ = int(input())
    stops = list(int(x) for x in input().split())
    print(compute_min_refills(distance, tank, stops))
