#include "defs.h"

int main(int argc, char *argv[])
{
    // Initialize a random seed for the random number generators
    srand(time(NULL));

    // You may change this code; this is for demonstration purposes
    BuildingType building;
    GhostType ghost;

    // Initialize the building
    initBuilding(&building);

    // Initialize the ghost
    

    populateRooms(&building);
    initGhost(&ghost, &building);
    printf("The ghosts room is now in: ");
    printRoom(ghost.room);
    ghostMove(&ghost);
    printf("The ghosts room is now in: ");
    printRoom(ghost.room);
    ghostMove(&ghost);
    printf("The ghosts room is now in: ");
    printRoom(ghost.room);
    ghostMove(&ghost);
    printf("The ghosts room is now in: ");
    printRoom(ghost.room);
    ghostMove(&ghost);
    printf("The ghosts room is now in: ");
    printRoom(ghost.room);
    ghostMove(&ghost);
    printf("The ghosts room is now in: ");
    printRoom(ghost.room);
    ghostMove(&ghost);

    printBuilding(&building);
    cleanupRoomList(&building.rooms);

    return 0;
}


/*
  Function:  randInt
  Purpose:   returns a pseudo randomly generated number, 
             in the range min to (max - 1), inclusively
       in:   upper end of the range of the generated number
   return:   randomly generated integer in the range [min, max-1) 
*/
int randInt(int min, int max)
{
    return rand() % (max - min) + min;
}

/*
  Function:  randFloat
  Purpose:   returns a pseudo randomly generated number, 
             in the range min to max, inclusively
       in:   upper end of the range of the generated number
   return:   randomly generated integer in the range [0, max-1) 
*/
float randFloat(float a, float b) {
    // Get a percentage between rand() and the maximum
    // between rand() and RAND_MAX
    float random = ((float) rand()) / (float) RAND_MAX;
    // Scale it to the range we want, and shift it
    return random * (b - a) + a;


}