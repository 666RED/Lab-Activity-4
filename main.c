#include <stdio.h>
#include <stdlib.h>

struct queueNode{
    char data;
    struct queueNode *nextPtr;
};

typedef struct queueNode queueNode;

void printQueue(queueNode*);
int isEmpty(queueNode*);
char dequeue(queueNode**, queueNode**);
void enqueue(queueNode**, queueNode**, char);
void instructions();

int main(){
    queueNode* headPtr = NULL;
    queueNode* tailPtr = NULL;
    int choice;
    char data;
    instructions();

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    while (choice != 3){
        switch(choice){
            case 1: {
                printf("Enter an alphabet: ");
                scanf("\n%c", &data);
                enqueue(&headPtr, &tailPtr, data);
                printQueue(headPtr);
                break;
            }

            case 2: {
                if(!isEmpty(headPtr)){
                    data = dequeue(&headPtr, &tailPtr);
                    printf("%c has been dequeued.\n", data);
                }
                printQueue(headPtr);
                break;
            }

            default: {
                printf("Invalid choice.\n\n");
                instructions();
                break;
            }
        }
        printf("Enter your menu choice: ");
        scanf("%d", &choice);
     }

    printf("End of main program.\n ");
    return 0;
}

void instructions(){
    printf("\nEnter choice:\n"
     "1 to add item to the queue\n"
     "2 to remove item from the queue\n"
     "3 to end program\n");
}

void enqueue(queueNode** headPtr, queueNode** tailPtr, char value){
    queueNode* newPtr = (queueNode*)malloc(sizeof(queueNode));
    if (newPtr != NULL){
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        if(isEmpty(*headPtr)){
            *headPtr = newPtr;
        }else{
            (*tailPtr)->nextPtr = newPtr;
        }
        *tailPtr = newPtr;
    }else{
        printf("%c is not inserted. No memory available", value);
    }
}

char dequeue(queueNode** headPtr, queueNode** tailPtr){
    char value;
    queueNode* tempPtr;

    value = (*headPtr)->data;
    tempPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;

    if(*headPtr == NULL){
        *tailPtr = NULL;
    }
    free(tempPtr);
    return value;
}

int isEmpty(queueNode* headPtr){
    return (headPtr == NULL);
}

void printQueue(queueNode* currPtr){
    if(currPtr == NULL){
        printf("The queue is empty.\n\n");
    }else{
        printf("The queue is:\n");

        while(currPtr != NULL){
            printf("%c -->",currPtr->data);
            currPtr = currPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}
