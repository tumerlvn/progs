#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

struct Item final {
  int weight;
  int value;
};

double get_max_knapsack_value(int capacity, std::vector <Item> items) {
  double value = 0.0;
  for(int i = 1; i < items.size(); i++) {
      for (int j = i - 1; j >= 0 && static_cast <double>(items[j + 1].value)/items[j + 1].weight < static_cast <double>(items[j].value)/items[j].weight; j--)
          std::swap(items[j+1], items[j]);
  }
  for(int i = items.size() - 1; i >= 0; i--){
      if(capacity > items[i].weight){
          capacity -= items[i].weight;
          value += items[i].value;
      }else{
          value += items[i].value * (static_cast <double>(capacity) / items[i].weight);
          break;
      }
  }
  return value;
}

int main(void) {
  int number_of_items;
  int knapsack_capacity;
  std::cin >> number_of_items >> knapsack_capacity;
  std::vector <Item> items(number_of_items);
  for (int i = 0; i < number_of_items; i++) {
    std::cin >> items[i].value >> items[i].weight;
  }

  double max_knapsack_value = get_max_knapsack_value(knapsack_capacity, std::move(items));

  std::cout.precision(10);
  std::cout << max_knapsack_value << std::endl;
  return 0;
}
