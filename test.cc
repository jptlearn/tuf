#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Item {
  int weight;
  int value;
};

bool compare(Item A, Item B) {
  double r1 = (double)A.value / A.weight;
  double r2 = (double)B.value / B.weight;
  return r1 > r2;
}

double knapSack(vector<Item>& items, int maxWeight) {
  sort(items.begin(), items.end(), compare);
  double maxProfit = 0.0;
  int currentWeight = 0;
  for (auto item : items)
  {
    if(currentWeight + item.weight <= maxWeight){
      maxProfit += item.value;
      currentWeight += item.weight;
    }
    else
    {
      int remainingWeight = maxWeight - currentWeight;
      maxProfit += (item.value) * ((double)remainingWeight / item.weight);
      break;
    }
  }
  return maxProfit;
}

int
main()
{
  vector<Item> items = {{2, 10}, {4, 30}, {5, 25}, {3, 30}};
  int maxWeight = 8;
  cout << "Max profit from the knapsack problem is: " << knapSack(items, maxWeight) << endl;

  return 0;
}