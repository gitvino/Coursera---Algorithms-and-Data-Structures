#include <iostream>
#include <cassert>

// The following computes Fibonacci number.
// 1. fibonacci_naive is naive implementation that makes a recursive call. This algorithm is very inefficient because it computes Fibonacci number multiple times. 
// 2. fibonacci_fast is a faster implementation. It stores the fiboanacci series in an array. Instead of a recursive call to compute the previous values, it retrieves previous values from array. 

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    // write your code here
    int results[n];
    results[0] = 0;
    results[1] = 1;
    for (int i = 2; i <= n; i++)
        results[i] = results[i-1] + results[i-2];
    return results[n];
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << fibonacci_naive(n) << '\n';
    test_solution();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
