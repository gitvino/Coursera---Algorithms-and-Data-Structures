# Uses python3
import sys
import unittest

def get_number_of_inversions(a, b, left, right):
    number_of_inversions = 0
    if left < right:
        mid = (left + right) // 2
        number_of_inversions += get_number_of_inversions(a, b, left, mid)
        number_of_inversions += get_number_of_inversions(a, b, mid + 1, right)
        #write your code here
        number_of_inversions += merge(a,b,left, mid, right)
    return number_of_inversions

def merge(a, b, left, mid, right):
    i = left
    j = mid + 1 
    k = left
    inv_count = 0

    while i <= mid and j <= right: 
        
        # There will be no inversion if arr[i] <= arr[j] 
        if a[i] <= a[j]: 
            b[k] = a[i] 
            k += 1
            i += 1
        else:
            b[k] = a[j]
            inv_count += (mid-i + 1) 
            k += 1
            j += 1
    
    # Copy the remaining elements of left subarray into temporary array 
    while i <= mid: 
        b[k] = a[i] 
        k += 1
        i += 1
  
    # Copy the remaining elements of right subarray into temporary array 
    while j <= right: 
        b[k] = a[j] 
        k += 1
        j += 1
  
    # Copy the sorted subarray into Original array 
    for loop_var in range(left, right + 1): 
        a[loop_var] = b[loop_var] 
    return inv_count

def getNaiveInvCount(arr, n):   
    inv_count = 0
    for i in range(n): 
        for j in range(i + 1, n): 
            if (arr[i] > arr[j]): 
                inv_count += 1
    return inv_count 

class TestInversionCount(unittest.TestCase):

    def test_inversionCount(self):
        self.assertEqual(get_number_of_inversions([2,3,9,2,9], [0,0,0,0,0], 0, 4), getNaiveInvCount([2,3,9,2,9], 5))
        self.assertEqual(get_number_of_inversions([1, 20, 6, 4, 5], [0,0,0,0,0], 0, 4), getNaiveInvCount([1, 20, 6, 4, 5], 5))
        self.assertEqual(get_number_of_inversions([9, 8, 7, 3, 2, 1], [0,0,0,0,0,0], 0, 5), getNaiveInvCount([9, 8, 7, 3, 2, 1], 6))

if __name__ == '__main__':
    unittest.main()
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    b = n * [0]
    print(get_number_of_inversions(a, b, 0, len(a)-1))
    #print(getNaiveInvCount(a, n))