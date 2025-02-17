// The greedy method for solving the Knapsack problem applies when dealing with the fractional Knapsack
// problem (where you can take fractions of items). It is not optimal for the 0/1 Knapsack problem because
// it doesn't always provide the best solution.
// In the fractional Knapsack, we aim to maximize the value-to-weight ratio by always picking the item with
// the highest ratio first

// Greedy Strategy:
// 1. Calculate the value-to-weight ratio for each item: ratio = value/weight
// 2. Sort the items by their ratios in descending order
// 3. Pick items greedily: Take the full item if it fits, otherwise take the fractional part to fill the 
// remaining capacity.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent the item with value and weight
struct Item {
  int value;
  int weight;
};

bool compare(Item a, Item b) {
  double r1 = (double)a.value / a.weight;
  double r2 = (double)b.value / b.weight;
  return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> items) {
  // Sort items by value-weight ratio in descending order
  sort(items.begin(), items.end(), compare);

  double maxValue = 0.0; // To store the maximum value
  int currentWeight = 0; // Track the current weight of the knapsack

  for (const Item& item : items) {
    if (currentWeight + item.weight <= W) {
      // If the item can be taken fully
      currentWeight += item.weight;
      maxValue += item.value;
    } else {
      // Take the fractional part of the item
      int remainingCapacity = W - currentWeight;
      maxValue += item.value * ((double)remainingCapacity / item.weight);
      break; // The knapsack is full
    }
  }
  return maxValue;
}

int main() {
  int W = 50; // Maximum weight capacity of the Knapsack
  vector<Item> items = {{60, 10}, {100, 20}, {120, 30}}; // {value, weight} for each item

  cout << "Maximum value in the knapsack: " << fractionalKnapsack(W, items) << endl;

  return 0;
}


