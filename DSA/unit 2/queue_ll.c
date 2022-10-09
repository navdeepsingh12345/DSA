#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;



node *insert(node *rear){
    int data;
    printf("Enter data: ");
    scanf("%d",&data);

    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if(rear==NULL){
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    return rear;
}

node *delete(node *front){
    if(front == NULL){
        printf("Queue is underflow");
    }
    else{
        node *temp = front;
        front = front->next;
        printf("Deleted element: %d",temp->data);
        free(temp);
    }
    return front;
}

void display(node *front){
    node *temp = front;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
    int choice;
    node *front = NULL,*rear = NULL;
    do{
        printf("\nEnter Choice:\n1 -> insert\n2 -> delete\n3 -> Display\n4 -> Exit\n  -> ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                rear = insert(rear);
                if(front == NULL){
                    front = rear;
                }
                break;
            case 2:
                front = delete(front);
                break;
            case 3:
                display(front);
                break;
            case 4:
                exit(0);
        }
    }while(1);
    return 0;
}

