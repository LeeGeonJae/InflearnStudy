#include <iostream>
#include <ctime>
#include <cstdlib>

const int MAP_SIZE = 10;
const int PLAYER_START_X = 1;
const int PLAYER_START_Y = 1;

struct Coordinate {
    int x;
    int y;
};

int main() {
    // Seed the random number generator
    srand(time(0));

    Coordinate player = { PLAYER_START_X, PLAYER_START_Y };
    Coordinate goal;

    // Generate a random goal location
    goal.x = rand() % MAP_SIZE;
    goal.y = rand() % MAP_SIZE;

    while (player.x != goal.x || player.y != goal.y) {
        if (player.x < goal.x) {
            player.x++;
        }
        else if (player.x > goal.x) {
            player.x--;
        }
        if (player.y < goal.y) {
            player.y++;
        }
        else if (player.y > goal.y) {
            player.y--;
        }

        std::cout << "Player moved to: (" << player.x << ", " << player.y << ")" << std::endl;
    }

    std::cout << "Player reached the goal!" << std::endl;

    return 0;
}