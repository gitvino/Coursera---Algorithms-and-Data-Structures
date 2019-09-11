/* 

Problem: The goal in this problem is to find the minimum number of coins needed to change the input value (an integer) into coins with denominations 1, 5, and 10.

Input: The input consists of a single integer m.

Output: Output the minimum number of coins with denominations 1, 5, 10 that changes m.

*/

#include <iostream>

using namespace std; 

int get_change(int m) {
  
  int count = 0;
  count = count + (m / 10); 
  m = m % 10;
  count = count + (m / 5); 
  m = m % 5;
  count = count + (m / 1); 
  return count;
}


int main() {
  int m;
  cin >> m;
  cout << get_change(m) << endl;
}