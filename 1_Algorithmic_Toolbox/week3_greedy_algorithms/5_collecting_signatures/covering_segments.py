# Uses python3
import sys
from operator import attrgetter
from collections import namedtuple

Segment = namedtuple('Segment', 'start end')

def optimal_points(segments):
    #write your code here
    segments = sorted(segments, key=attrgetter('end'))
    slots = []
    for segment in segments:
        not_in_slot = True
        for slot in slots:
            if slot >= segment.start and slot <= segment.end:
                not_in_slot = False
                break
        if not_in_slot:
            slots.append(segment.end)
    return slots


if __name__ == '__main__':
    input = sys.stdin.read()
    n, *data = map(int, input.split())
    segments = list(map(lambda x: Segment(x[0], x[1]), zip(data[::2], data[1::2])))
    points = optimal_points(segments)
    print(len(points))
    for p in points:
        print(p, end=' ')
