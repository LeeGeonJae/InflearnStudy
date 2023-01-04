#include <iostream>
#include <algorithm>

const int ITEM_COUNT = 4;
const int MAX_WEIGHT = 6;

struct Item {
    int weight;
    int price;
};

bool compareByPrice(const Item& i1, const Item& i2) {
    return i1.price > i2.price;
}

int main() {
    Item items[ITEM_COUNT] = {
        {4, 8},
        {3, 5},
        {2, 3},
        {1, 1}
    };

    // Sort the items by price in descending order
    std::sort(items, items + ITEM_COUNT, compareByPrice);

    int totalWeight = 0;
    int totalPrice = 0;

    // Add items to the bag as long as there is room
    for (int i = 0; i < ITEM_COUNT; i++) {
        if (totalWeight + items[i].weight <= MAX_WEIGHT) {
            totalWeight += items[i].weight;
            totalPrice += items[i].price;
        }
    }

    std::cout << "Total weight: " << totalWeight << std::endl;
    std::cout << "Total price: " << totalPrice << std::endl;

    return 0;
}