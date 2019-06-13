//
//  05_Fibonacci_Number_Again.cpp
//  Fibonacci
//
//  Created by Vinoth on 12/6/19.
//  Copyright © 2019 Vinoth. All rights reserved.
//

#include <iostream>
using namespace std;

long long getPisanoPeriod (long long m) {

    long long previous = 0;
    long long current = 1;
    long long count = 0;
    
    for (int i=0; i <= 10000; i++) {
        if (previous == 0 & current == 1 && count != 0) {
            break;
            
        } else {
            count++;
            long long temp_previous = previous;
            previous = current;
            current = (current + temp_previous) % m;
        }
        
    }
    return count;
}

long long getFibonacci(long long n, long long m) {
    
    if (n <= 1)
        return n;
    
    long long previous = 0;
    long long current = 1;
    
    for (long long i = 0; i < n - 1 ; i++) {
        long long tmp_previous = previous;
        previous = current;
        current =  (tmp_previous + current) % m;
    }
    
    return current;
}

int main() {
  
    long long m, n;
    cin >> n >> m;
    long long pisano_period = getPisanoPeriod(m);
    
    long long modified_n = n % pisano_period;
    long long fib_modified_n = getFibonacci(modified_n,m);
    long long fib_mod_n = fib_modified_n % m;
    cout << fib_mod_n;
    
    return 0;
}
