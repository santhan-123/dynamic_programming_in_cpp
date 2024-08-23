#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent items
struct Item {
    int value;
    int weight;
    double profitWeightRatio; // Profit-to-weight ratio
};

// Comparison function to sort items by profit-to-weight ratio in descending order
bool compare(Item a, Item b) {
    return (a.profitWeightRatio > b.profitWeightRatio);
}

// Function to solve 0/1 knapsack problem using a greedy approach
int knapsackGreedy(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare); // Sort items by profit-to-weight ratio

    int totalValue = 0; // Total value of items in knapsack

    for (const Item& item : items) {
        if (capacity >= item.weight) { // If the item can fit in the knapsack
            totalValue += item.value;
            capacity -= item.weight;
        } else { // If the item cannot fit entirely, take a fraction of it
            totalValue += item.profitWeightRatio * capacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n; // Number of items
    cout << "Enter the number of items: ";
    cin >> n;

    int capacity; // Capacity of knapsack
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;

    vector<Item> items(n); // Vector to store items

    // Input items
    cout << "Enter the value and weight of each item:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << ":\n";
        cin >> items[i].value >> items[i].weight;
        items[i].profitWeightRatio = (double)items[i].value / items[i].weight;
    }

    int maxValue = knapsackGreedy(capacity, items);
    cout << "Maximum value in knapsack: " << maxValue << endl;

    return 0;
}

