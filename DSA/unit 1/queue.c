#include<stdio.h>
#include<stdlib.h>
#define max 50

int insert(int [],int);
int delete(int [],int,int);
void display(int [],int,int);

int main(){
    int queue[max];
    int choice;
    int front = -1,rear = -1;

    do{
        printf("\nEnter Choice:\n1 -> Insert\n2 -> Delete\n3 -> Display\n4 -> exit\n  -> ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(rear == -1){
                    front++;
                }
                rear = insert(queue, rear);
                break;
            case 2:
                front = delete(queue, front, rear);
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                exit(0);
        }
    }while(1);


    return 0;
}

int insert(int queue[],int rear){
    int value;
    printf("Enter value: ");
    scanf("%d",&value);

    if(rear==max-1){ printf("Queue is overflow"); }
    else{
        rear++;
        queue[rear] = value;
    }

    return rear;
}



int delete(int queue[], int front, int rear){
    if(front==-1 || front == rear+1){ printf("queue is Underflow"); }
    else{
        printf("Deleted element is %d ",queue[front]);
        front++;
    }
    
    return front;
}


void display(int queue[],int front, int rear){
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}