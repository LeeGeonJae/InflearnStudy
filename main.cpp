#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 10;
const int NUM_OBSTACLES = 15;

// Array to store the locations of the obstacles
int obstacles[NUM_OBSTACLES][2];

// Function to generate the random goal location
void generateGoal() {
    int x, y;
    bool validLocation;

    do {
        // Generate a random location for the goal
        x = rand() % MAP_WIDTH;
        y = rand() % MAP_HEIGHT;

        // Check if the location is not an obstacle
        validLocation = true;
        for (int i = 0; i < NUM_OBSTACLES; i++) {
            if (x == obstacles[i][0] && y == obstacles[i][1]) {
                validLocation = false;
                break;
            }
        }
    } while (!validLocation);

    // Set the goal location
    int goal[2] = { x, y };
}

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate the obstacles
    // ...

    // Generate the goal location
    generateGoal();

    return 0;
}