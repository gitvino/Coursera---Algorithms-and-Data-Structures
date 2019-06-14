//
//  06_ Last_Digit_Sum_Fibonacci.cpp
//  Coursera-CPP
//
//  Created by Vinoth on 13/6/19.
//  Copyright © 2019 Vinoth. All rights reserved.
//

#include <iostream>
using namespace std;

long long fibonacci(long long x) {
   //long long reduced_x = x % 3;
    long long current, previous;
   
    previous = 0;
    current = 1;
    
    if (x <= 1) {
        return x;
    }
    for (int i= 0; i < x-1; ++i) {
        long long temp_previous = previous;
        previous = current;
        current = (temp_previous + current) % 10;
    }
    
    return current;
}

int main() {
    long long n;
    //cout << "Input: \n";
    cin >> n;
    long long result  = 0;
    int reduced_n = n % 60;
    long long sum_last_digit = (fibonacci(reduced_n+2) - 1);
    if (sum_last_digit < 0) {
        result = 10 + sum_last_digit;
    } else {
        result = sum_last_digit % 10;
    }
    cout << result;
    return 0;
    
}
