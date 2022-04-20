#include <stdio.h>
#include <stdlib.h>

struct stackNode{
    int data;
    struct stackNode *nextPtr;
};

typedef struct stackNode stackNode;

void push(stackNode**, int);
int pop(stackNode**);
int isEmpty(stackNode*);
void printStack(stackNode*);
void instructions();

int main(){
    stackNode* stackPtr = NULL;
    int choice, value;
    instructions();

    printf("Enter your menu choice: ");
    scanf("%d", &choice);

    while (choice != 3){
        switch(choice){
            case 1:{
                printf("Enter an integer: ");
                scanf("%d", &value);
                push(&stackPtr, value);
                printStack(stackPtr);
                break;
            }
            case 2:{
                if (isEmpty(stackPtr)){
                    printf("The popped value is %d.\n", pop(&stackPtr));
                }
                printStack(stackPtr);
                break;
            }
            default:{
                printf("Invalid choice.\n\n");
                instructions();
                break;
            }
        }
        printf("Enter your menu choice: ");
        scanf("%d",&choice);
     }

    printf("End of main program.\n ");
    return 0;
}

void instructions(){
    printf("\nEnter choice:\n"
     "1 to push a value on the stack\n"
     "2 to pop a value off the stack\n"
     "3 to end program\n");
}

void push(stackNode **head, int info){
    stackNode* newPtr = (stackNode*)malloc(sizeof(stackNode));

    if(newPtr != NULL){
        newPtr->data = info;
        newPtr->nextPtr = *head;
        *head = newPtr;
    }else{
        printf("%d is not inserted. No memory available.\n",info);
    }
}

int pop(stackNode **head){
    stackNode* tempPtr = *head;
    int popValue;

    popValue = tempPtr->data;
    *head = (*head)->nextPtr;
    free(tempPtr);
    return popValue;
}

void printStack(stackNode* head){
    if(head == NULL){
        printf("The stack is empty.\n\n");
    }else{
        printf("The stack is:\n");
        while(head != NULL){
            printf("%d -->", head->data);
            head = head->nextPtr;
        }
        printf("NULL\n\n");
    }
}

int isEmpty(stackNode* head){
    return head != NULL;
}
