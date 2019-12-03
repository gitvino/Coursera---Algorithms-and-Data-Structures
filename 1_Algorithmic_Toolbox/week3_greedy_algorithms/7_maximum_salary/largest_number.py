#Uses python3

import sys
import operator

def largest_number(inputDigits):
    #write your code here
    result = []
    while (len(inputDigits) > 0):
        maxDigit = min(inputDigits)
        for eachDigit in inputDigits:
            if isGreaterOrEqual(eachDigit, maxDigit):
                maxDigit = eachDigit
        result.append(maxDigit)
        inputDigits.remove(maxDigit)     
    return ''.join(str(x) for x in result)

def isGreaterOrEqual(digit, maxDigit):
   return int(str(digit)+str(maxDigit)) >= int(str(maxDigit)+str(digit))

if __name__ == '__main__':
    input = sys.stdin.read()
    data = input.split()
    data_list = [int(x) for x in data[1:]]
    print(largest_number(data_list))
    
