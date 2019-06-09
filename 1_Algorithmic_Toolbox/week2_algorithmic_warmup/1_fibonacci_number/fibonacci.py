# Uses python3
def calc_fib_naive(n):
    if (n <= 1):
        return n
    return calc_fib_naive(n - 1) + calc_fib_naive(n - 2)

def calc_fib_faster(n):
	results = []
	results.append(0)
	results.append(1)
	for index in range(2,n+1):
		print(index)
		results.append(results[index-1] + results[index-2])
	print(results)
	return results[n]


n = int(input())
print(calc_fib_faster(n))