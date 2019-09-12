/* 
Problem: A thief finds much more loot than his bag can fit. Help him to find the most valuable combination of items, 
assuming that any fraction of a loot item can be put into his bag.


Input:
First Line: n, capacity that thief can take. 
Next n lines: Values and Weights

Output: Maximal value of fractions of items that fit into the knapsack.
*/

#include <iostream>
#include <vector>
#include <algorithm> 
#include <iomanip>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  int n = weights.size();
  double value = 0.0;
  vector<double> values_per_weight(n);
  for (int i=0; i < n; i++) {
    values_per_weight[i] = values[i] / double(weights[i]);
  }

  while (capacity != 0) {
      int max_value_index = distance(values_per_weight.begin(), max_element(values_per_weight.begin(), values_per_weight.end()));
      if (weights[max_value_index] == 0) {
          break;
      }
      if (weights[max_value_index] <= capacity) {
          //If item fits into knapsack take all of it. 
          capacity = capacity - weights[max_value_index];
          value =  value + values[max_value_index];
          weights[max_value_index] = 0;
          values[max_value_index] = 0;
          
      } else {
          //Otherwise take so much as  to fill the knapsack. 
          value = value + (values_per_weight[max_value_index] * capacity);
          weights[max_value_index] = weights[max_value_index] - capacity;
          values[max_value_index] = values[max_value_index] -  (values_per_weight[max_value_index] * capacity);
          capacity = capacity - capacity;
      }
      
      //Update weights and values after each iteration. 
      n = weights.size();
      for (int i=0; i < n; i++) {
            values_per_weight[i] = values[i] / double(weights[i]);
        }
  }
  //return total value taken by theif.
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);
  std::cout << std::setprecision(4) << std::fixed;
  std::cout << optimal_value << std::endl;
  return 0;
}
