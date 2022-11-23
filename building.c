
#include "defs.h"

/*
    Note: While this function is provided, you will likely want
    to modify it to suit your solution. This has been provided
    to give you a starting point to lay out the room connectivity,
    but it is entirely possible that you will want to use different
    data structures to represent the rooms and their connectivity,
    or different function names.

    Not following this function's structure exactly will not result
    in a deduction of points.

    The map that this is recreating is visible in the assignment
    specification, and also available by the original creator here:
    https://steamcommunity.com/sharedfiles/filedetails/?id=2251267947
    
*/
void populateRooms(BuildingType* building) {
    // First, create each room. Perhaps you want to include more data 
    // in the init parameters?
    RoomType* van = calloc(1, sizeof(RoomType));
    initRoom(van, "Van");
    RoomType* hallway = calloc(1, sizeof(RoomType));
    initRoom(hallway, "Hallway");
    RoomType* master_bedroom = calloc(1, sizeof(RoomType));
    initRoom(master_bedroom, "Master Bedroom");
    RoomType* boys_bedroom = calloc(1, sizeof(RoomType));
    initRoom(boys_bedroom, "Boy's Bedroom");
    RoomType* bathroom = calloc(1, sizeof(RoomType));
    initRoom(bathroom, "Bathroom");
    RoomType* basement = calloc(1, sizeof(RoomType));
    initRoom(basement, "Basement");
    RoomType* basement_hallway = calloc(1, sizeof(RoomType));
    initRoom(basement_hallway, "Basement Hallway");
    RoomType* right_storage_room = calloc(1, sizeof(RoomType));
    initRoom(right_storage_room, "Right Storage Room");
    RoomType* left_storage_room = calloc(1, sizeof(RoomType));
    initRoom(left_storage_room, "Left Storage Room");
    RoomType* kitchen = calloc(1, sizeof(RoomType));
    initRoom(kitchen, "Kitchen");
    RoomType* living_room = calloc(1, sizeof(RoomType));
    initRoom(living_room, "Living Room");
    RoomType* garage = calloc(1, sizeof(RoomType));
    initRoom(garage, "Garage");
    RoomType* utility_room = calloc(1, sizeof(RoomType));
    initRoom(utility_room, "Utility Room");

    // Now create a linked list of rooms using RoomNodeType in the Building
    RoomNodeType* van_node = calloc(1, sizeof(RoomNodeType));
    van_node->room = van;
    RoomNodeType* hallway_node = calloc(1, sizeof(RoomNodeType));
    hallway_node->room = hallway;
    RoomNodeType* master_bedroom_node = calloc(1, sizeof(RoomNodeType));
    master_bedroom_node->room = master_bedroom;
    RoomNodeType* boys_bedroom_node = calloc(1, sizeof(RoomNodeType));
    boys_bedroom_node->room = boys_bedroom;
    RoomNodeType* bathroom_node = calloc(1, sizeof(RoomNodeType));
    bathroom_node->room = bathroom;
    RoomNodeType* basement_node = calloc(1, sizeof(RoomNodeType));
    basement_node->room = basement;
    RoomNodeType* basement_hallway_node = calloc(1, sizeof(RoomNodeType));
    basement_hallway_node->room = basement_hallway;
    RoomNodeType* right_storage_room_node = calloc(1, sizeof(RoomNodeType));
    right_storage_room_node->room = right_storage_room;
    RoomNodeType* left_storage_room_node = calloc(1, sizeof(RoomNodeType));
    left_storage_room_node->room = left_storage_room;
    RoomNodeType* kitchen_node = calloc(1, sizeof(RoomNodeType));
    kitchen_node->room = kitchen;
    RoomNodeType* living_room_node = calloc(1, sizeof(RoomNodeType));
    living_room_node->room = living_room;
    RoomNodeType* garage_node = calloc(1, sizeof(RoomNodeType));
    garage_node->room = garage;
    RoomNodeType* utility_room_node = calloc(1, sizeof(RoomNodeType));
    utility_room_node->room = utility_room;

    // Building->rooms might be a linked list structre, or maybe just a node.
    initRoomList(&building->rooms);

    appendRoom(&building->rooms, van_node);
    appendRoom(&building->rooms, hallway_node);
    appendRoom(&building->rooms, master_bedroom_node);
    appendRoom(&building->rooms, boys_bedroom_node);
    appendRoom(&building->rooms, bathroom_node);
    appendRoom(&building->rooms, basement_node);
    appendRoom(&building->rooms, basement_hallway_node);
    appendRoom(&building->rooms, right_storage_room_node);
    appendRoom(&building->rooms, left_storage_room_node);
    appendRoom(&building->rooms, kitchen_node);
    appendRoom(&building->rooms, living_room_node);
    appendRoom(&building->rooms, garage_node);
    appendRoom(&building->rooms, utility_room_node);

    // Now connect the rooms. It is possible you do not need a separate
    // function for this, but it is provided to give you a starting point.
    connectRooms(van, hallway);
    connectRooms(hallway, master_bedroom);
    connectRooms(hallway, boys_bedroom);
    connectRooms(hallway, bathroom);
    connectRooms(hallway, kitchen);
    connectRooms(hallway, basement);
    connectRooms(basement, basement_hallway);
    connectRooms(basement_hallway, right_storage_room);
    connectRooms(basement_hallway, left_storage_room);
    connectRooms(kitchen, living_room);
    connectRooms(kitchen, garage);
    connectRooms(garage, utility_room);
    printBuilding(building);
    cleanupRoomList(&building->rooms);
}

void initRoomList(RoomListType* roomList) {
    roomList->head = NULL;
    roomList->tail = NULL;
}

void initRoom(RoomType* room, char* name) {
    strcpy(room->name, name);
    room->neighbours = (RoomListType*) calloc(1, sizeof(RoomListType));
    room->evidence = (EvidenceListType*) calloc(1, sizeof(EvidenceListType));

    initRoomList(room->neighbours);
    initEvidenceList(room->evidence);

    room->numNeighbours = 0;
}



void appendRoom(RoomListType* roomList, RoomNodeType* roomNode) {
    if (roomList->head == NULL) {
        roomList->head = roomNode;
        roomList->tail = roomNode;
    } else {
        roomList->tail->next = roomNode;
        roomList->tail = roomNode;
    }
}

void connectRooms(RoomType* room1, RoomType* room2) {
    RoomNodeType* node1 = calloc(1, sizeof(RoomNodeType));
    RoomNodeType* node2 = calloc(1, sizeof(RoomNodeType));

    node1->room = room1;
    node2->room = room2;

    appendRoom(room1->neighbours, node2);
    appendRoom(room2->neighbours, node1);
    room1->numNeighbours++;
    room2->numNeighbours++;
}

void initEvidenceList(EvidenceListType* ev) {
    ev->head = NULL;
    ev->tail = NULL;
}

void appendEvidence(EvidenceListType* evList, EvidenceType* ev) {
    EvidenceNodeType* node = calloc(1, sizeof(EvidenceNodeType));
    node->data = ev;

    if (evList->head == NULL) {
        evList->head = node;
        evList->tail = node;
    } else {
        evList->tail->next = node;
        evList->tail = node;
    }
}

void initBuilding(BuildingType* building) {
    building->rooms.head = NULL;
    building->rooms.tail = NULL;
    
}

void initEvidence(EvidenceType** ev, EvidenceClassType et, float value) {
    *ev = calloc(1, sizeof(EvidenceType));
    (*ev)->type = et;
    (*ev)->value = value;
}

void printBuilding(BuildingType* building) {
    RoomNodeType* roomNode = building->rooms.head;
    while (roomNode != NULL) {
        printf("%s\n", roomNode->room->name);
        printNeighbours(roomNode);
        roomNode = roomNode->next;
    }
}

void printNeighbours(RoomNodeType* roomNode) {
    RoomNodeType* neighbourNode = roomNode->room->neighbours->head;
    while (neighbourNode != NULL) {
        printf(" | %s", neighbourNode->room->name);
        
        neighbourNode = neighbourNode->next;
    }
    printf("\nnum neighbours: %d\n", roomNode->room->numNeighbours);
}
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


// void initGhost(int id, GhostEnumType gt, RoomType *r, float like, GhostType
// **ghost){
//     *ghost = (GhostType*) malloc(sizeof(GhostType)); //
//     (*ghost)->id = id;
//     (*ghost)->likelihood = like;
//     (*ghost)->room = r;
//     (*ghost)->ghostType = gt;
// }
