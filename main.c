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
int FindLength(struct Node* headNode) {

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
    int listLen = FindLength(headNode);

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

    //FindLength to the middle
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
    int listLen = FindLength(headNode);

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
    int listLen = FindLength(headNode);

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

struct Node *DeleteEnd(struct Node *headNode){
    int deleteIndex = FindLength(headNode);


    struct Node *tempNode = headNode;

    for (int i = 0; i < deleteIndex - 2; i++){
        tempNode = tempNode-> next;
    }

    tempNode->next = NULL;
    free(tempNode);

    return headNode;

}


int Traverse(struct Node *headNode, int puidKey){
    struct Node *tempNode = headNode;
    while (tempNode != NULL) {
        if (tempNode->puid == puidKey) {
            return 0;
        }

        tempNode=tempNode->next;
    }
    return -1;

}

int LookUpByIndex (struct Node *headNode, int index) {
    struct Node *tempNode = headNode;

    if (FindLength(headNode) < index - 1) {
        return -1;
    }

    for(int i = 0; i < index; i++) {
        tempNode=tempNode->next;
    }
    return tempNode->puid;

}

void PrintList (struct Node *headNode) {

    struct Node *tempNode = headNode;
    while (tempNode != NULL) {
        printf("[ %i ]-->", tempNode->puid);
        tempNode=tempNode->next;
    }
    printf("NULL\n");
    printf("Length of list: %i\n", FindLength(headNode));
}

int main() {


    printf("\nCreating a List With One Element (1111)\n");
    printf("=======================================\n");
    struct Node *mainNode = CreateListNode("Pranav", "Bhusari", 18, 1111);
    PrintList(mainNode);

    printf("\nInserting an Element to the Front (3333)\n");
    printf("========================================\n");
    InsertFront(mainNode, "Oscar", "Wang", 22, 3333);
    PrintList(mainNode);

    printf("\nInserting an Element to the Middle (2222)\n");
    printf("=========================================\n");
    InsertMiddle(mainNode, "Rubbert", "Kim", 18, 2222);
    PrintList(mainNode);

    printf("\nInserting an Element to the End (4444)\n");
    printf("======================================\n");
    InsertEnd(mainNode, "Brenda", "Brewer", 4444, 18);
    PrintList(mainNode);

    // Why are the deletion functions call by value??????
    printf("\nDeleting an Element at the Front (1111)\n");
    printf("========================================\n");
    mainNode = DeleteFront(mainNode);
    PrintList(mainNode);

    printf("\nDeleting an Element at the End ()\n");
    printf("========================================\n");
    DeleteEnd(mainNode);
    PrintList(mainNode);

    printf("\nInserting An Element to the Front\n");
    printf("=================================\n");
    InsertFront(mainNode, "ASD", "QWE", 23, 6900);
    PrintList(mainNode);

    printf("\nTraversing to the PUID 6900   \n");
    printf("=================================\n");
    printf("Result (0 is succsessful): %i\n", Traverse(mainNode, 6900));
    printf("Result (0 is succsessful): %i\n", Traverse(mainNode, 2232));

    printf("\nLooking Up By Index           \n");
    printf("=================================\n");
    printf("The PUID of the #%i index is:%i\n", 1   ,LookUpByIndex(mainNode, 1));
    printf("The PUID of the #%i index is:%i\n", 500 ,LookUpByIndex(mainNode, 500));

}