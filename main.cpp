#include <iostream>
#include <algorithm>

const int ITEM_COUNT = 4;
const int MAX_WEIGHT = 6;

struct Item {
    int weight;
    int price;
};

bool compareByPrice(const Item& i1, const Item& i2) {
    return (float)i1.price / (float)i1.weight > (float)i2.price / (float)i2.weight;
}

int main() {
    Item items[ITEM_COUNT] = {
        {4, 6}, // Item 1: A knife weighing 4 is 6 won.
        {3, 5}, // Item 2: An old item with a weight of 3 for 5 won.
        {2, 3}, // Item 3: Apple with a weight of 2 for 3 won.
        {1, 1}  // Item 4: 1 won fork.
    };

    // Sort the items by price in descending order
    std::sort(items, items + ITEM_COUNT, compareByPrice);

    int totalWeight = 0;
    int totalPrice = 0;

    // Add as many copies of each item as possible
    for (int i = 0; i < ITEM_COUNT; i++) {
        while (totalWeight + items[i].weight <= MAX_WEIGHT) {
            totalWeight += items[i].weight;
            totalPrice += items[i].price;
        }
    }

    std::cout << "Total weight: " << totalWeight << std::endl;
    std::cout << "Total price: " << totalPrice << std::endl;

    return 0;
}