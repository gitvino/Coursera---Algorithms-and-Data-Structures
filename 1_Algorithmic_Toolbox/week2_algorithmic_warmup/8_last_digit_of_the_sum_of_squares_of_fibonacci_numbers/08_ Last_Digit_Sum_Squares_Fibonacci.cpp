//
//  08_ Last_Digit_Sum_Squares_Fibonacci.cpp
//  Coursera-CPP
//
//  Created by Vinoth on 14/6/19.
//  Copyright © 2019 Vinoth. All rights reserved.
//

#include <iostream>

using namespace std;

int sum_of_fibonacci_square(int x) {
    
    int previous = 0;
    int current = 1;
    int sum_fib_sqr_x = 0;
    int fib_square_x = 0;
    
    if (x <=1 ) {
        return x;
    }
    for (int i = 0; i <= x-1 ; ++i) {
        
        fib_square_x = (current * current) % 10;
        sum_fib_sqr_x = (sum_fib_sqr_x + fib_square_x) % 10;
        
        int temp_previous = previous;
        previous = current;
        current = (temp_previous + current) % 10;
        
    }
    return sum_fib_sqr_x;
}

int main() {
    long long n;
    cin >> n;
    int reduced_n = n % 30;
    int sum_fib_squ = sum_of_fibonacci_square(reduced_n);
    cout << sum_fib_squ;
    return 0;
    
}
