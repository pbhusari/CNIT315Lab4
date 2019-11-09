#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char *firstName;
    char *lastName;
    int puid;
    int age;
    struct Node *next;
};

//returns the length of the linked list
int Traverse(struct Node* headNode) {

    int len = 0;

    struct Node *tempNode = headNode;
    while (tempNode != NULL) {
        tempNode = tempNode->next;
        len++;
    }
    return len;

}


struct Node* CreateListNoNodes() {
    struct Node* start;
    return start;
};

struct Node* CreateListNode(firstName, lastName, age, puid){
    struct Node * headNode =  CreateListNoNodes();
    headNode = (struct Node*) malloc (sizeof (struct Node));
    headNode->firstName = firstName;
    headNode->lastName = lastName;
    headNode->puid = puid;
    headNode->age = age;
    headNode->next = NULL;
    return headNode;
}

// Assuming that the last element is defined as the front element
struct Node* InsertFront (struct Node * headNode, char *firstName, char *lastName, int puid, int age){
    struct Node * newNode = CreateListNode(firstName, lastName, puid, age);
    headNode->next = newNode;
    return headNode;
}



struct Node* InsertMiddle(struct Node *headNode, char *firstName, char * lastName, int puid, int age){
    int listLen = Traverse(headNode);

    //Find the middle
    int insertIndex;

    if (listLen == 0) {
        insertIndex = 0;
    }
    else if (listLen % 2 == 1) {
        insertIndex = (listLen - 1)/2;
    }
    else {
        insertIndex = listLen/2;
    }

    //Traverse to the middle
    struct Node *tempNode = headNode;
    for (int i=0; i < insertIndex - 1; i++){
        tempNode = tempNode->next;
    }

    //Actually inserting the stuff
    struct Node *newNode = CreateListNode(firstName, lastName, puid, age);
    newNode->next = tempNode->next;
    tempNode->next = newNode;

    return headNode;

}

struct Node *InsertEnd(struct Node *headNode, char *firstName, char * lastName, int puid, int age){
    int listLen = Traverse(headNode);

    struct Node *tempNode = headNode;

    for (int i=0; i < listLen - 1; i++){
        tempNode = tempNode->next;
    }


    struct Node *newNode = CreateListNode(firstName, lastName, age, puid);
    tempNode->next=newNode;
}

struct Node *DeleteFront (struct Node *headNode) {

    struct Node *tempNode = headNode;
    headNode = headNode->next;
    free(tempNode);

    return headNode;

}

struct Node *DeleteMiddle (struct Node *headNode) {
    int listLen = Traverse(headNode);

    //Find the middle
    int deleteIndex;

    if (listLen == 0) {
        deleteIndex = 0;
    }
    else if (listLen % 2 == 1) {
        deleteIndex = (listLen - 1)/2;
    }
    else {
        deleteIndex = listLen/2;
    }

    struct Node *tempNode = headNode;

    for (int i = 0; i < deleteIndex; i++){
        tempNode = tempNode-> next;
    }

    struct Node *swapNode = tempNode->next;
    tempNode->next;
    swapNode->next = NULL;

    return headNode;


}

int main() {

    int a = 0;

    struct Node *mainNode = CreateListNode("Pranav", "Bhusari", 18, 1111);

    a = Traverse(mainNode);

    InsertFront(mainNode, "Oscar", "Wang", 20, 3333);

    a = Traverse(mainNode);

    InsertMiddle(mainNode, "Rubbert", "Kim", 18, 2222);

    a = Traverse(mainNode);

    InsertEnd(mainNode, "Brenda", "Brewer", 18, 4444);

    a = Traverse(mainNode);

    // Why are the deletion functions call by value??????
    mainNode = DeleteFront(mainNode);

    a = Traverse(mainNode);

    mainNode = DeleteMiddle(mainNode);

    a = Traverse(mainNode);

}