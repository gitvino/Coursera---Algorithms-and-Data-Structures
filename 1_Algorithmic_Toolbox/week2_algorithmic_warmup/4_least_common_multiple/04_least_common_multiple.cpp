//
//  4_least_common_multiple.cpp
//  Coursera-CPP
//
//  Created by Vinoth on 11/6/19.
//  Copyright © 2019 Vinoth. All rights reserved.
//

#include <iostream>

long long lcm_naive(int a, int b) {
    for (long l = 1; l <= (long long) a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;
    
    return (long long) a * b;
}

//log(ab)
int gcd_euclidean(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd_euclidean(b, a%b);
}


int main() {
    int a, b;
    std::cin >> a >>  b;
    long long gcd = (long long) gcd_euclidean(a,b);
    long long lcm = (a/gcd)*b;
    std::cout <<"\n" << lcm << "\n";
    return 0;
}
