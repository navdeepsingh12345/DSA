#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
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
    newNode->data = data;
    newNode->next = NULL;

    if(head==NULL){
        head = newNode;
        head->next = head;
    }
    else{
        struct node *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
    }
    
    return head;

}

void display(struct node *head){
    struct node *temp = head;
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp != head);
}