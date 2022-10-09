#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *previous;
    struct node *next;
};

struct node *insert(struct node *);
void display(struct node *);

int main(){
    int choice;
    struct node *head = NULL;
    do{
        printf("\nEnter Choice:\n1 -> Insert\n2 -> Display\n3 -> exit\n  -> ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                head = insert(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                exit(0);
        }
    }while(1);
    return 0;
}


struct node *insert(struct node *head){
    int data;
    printf("Enter Data: ");
    scanf("%d",&data);

    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->previous = NULL;
    newNode->data = data;
    newNode->next = NULL;

    if(head==NULL){
        head = newNode;
    }
    else{
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        newNode->previous = temp;
        temp->next = newNode;
    }
    
    return head;

}

void display(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}