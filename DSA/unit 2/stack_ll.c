#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void display(node *top){
    node *temp = top;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

node *push(node *top){
    int data;
    printf("Enter data: ");
    scanf("%d",&data);

    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if(top==NULL){
        top = newNode;
    }
    else{
        newNode->next = top;
        top = newNode;
    }
    return top;
}

node *pop(node *top){
    if(top == NULL){
        printf("stack Underflow");
    }
    else{
        node *temp = top;
        top = top->next;
        printf("Deleted element: %d",temp->data);
        free(temp);
    }
    return top;
}


int main(){
    int choice;
    node *top = NULL;
    do{
        printf("\nEnter Choice:\n1 -> Push\n2 -> Pop\n3 -> Display\n4 -> Exit\n  -> ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                top = push(top);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                exit(0);
        }
    }while(1);
    return 0;
}

