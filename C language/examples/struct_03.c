#include <stdio.h>
#include <string.h>

// Define Point struct for coordinates
struct Point {
    int x;
    int y;
};

// Define Character struct with a nested Point
struct Character {
    char name[50];
    int health;
    struct Point position; // Nested struct
};

// Function to move a character to a new position
void moveCharacter(struct Character *c, int newX, int newY) {
    c->position.x = newX; // Update x coordinate
    c->position.y = newY; // Update y coordinate
}

// Function to print all characters in the party
void printParty(struct Character party[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Character: %s, Health: %d, Position: (%d, %d)\n",
               party[i].name, party[i].health,
               party[i].position.x, party[i].position.y);
    }
}

int main() {
    // Create an array of 3 characters
    struct Character party[3] = {
        {"Alice", 100, {0, 0}}, // Initialize name, health, and position
        {"Bob", 80, {2, 3}},
        {"Charlie", 90, {1, 1}}
    };

    // Print initial party
    printf("Initial party:\n");
    printParty(party, 3);

    // Move Alice to (5, 5)
    moveCharacter(&party[0], 5, 5);

    // Print party after moving Alice
    printf("After moving Alice:\n");
    printParty(party, 3);

    return 0;
}
