#include "defs.h"


/*
    Function: cleanupRoomList()
     Purpose: Cleanup the data in the master list of rooms, the neighbour LIST but not the nodes or data and the room node
*/
void cleanupRoomList(RoomListType* roomList) {
    RoomNodeType* roomNode = roomList->head;
    RoomNodeType* next = NULL;

    // Loop thru all nodes
    while(roomNode != NULL) {

        // Set next so we don't lose pointer
        next = roomNode->next;
        cleanupNeighbourList(roomNode->room->neighbours); // Cleanup the neighbour nodes
        free(roomNode->room->neighbours); // Free the neighbour list
        cleanupEvidenceList(roomNode->room->evidence); // Cleanup the evidence

        //EVENTUAL WE NEED TO FUCKING FREE THE HUNTERS.

        free(roomNode->room->evidence); // Free the evidence list
        free(roomNode->room); // Free the room struct
        free(roomNode); // Free the room node
        roomNode = next; 
    }
}

/*
    Function: cleaupEvidenceList()
    Purpose: clean data and nodes for each evidence node in the list
        in: evList() - pointer to the ev list
*/
void cleanupEvidenceList(EvidenceListType* evList) {
    EvidenceNodeType* evNode = evList->head;
    EvidenceNodeType* next = NULL;
    while(evNode != NULL) {
        next = evNode->next;
        free(evNode->data);
        free(evNode);
        evNode = next;
    }
}

/*
    Function: cleanupNeighbourList()
    Purpose: clean data and nodes for each neighbour node in the list
        in: roomList - pointer to the room list
*/

void cleanupNeighbourList(RoomListType* roomList) {
    RoomNodeType* roomNode = roomList->head;
    RoomNodeType* next = NULL;
    while(roomNode != NULL) {
        next = roomNode->next;
        free(roomNode);
        roomNode = next;
    }
}