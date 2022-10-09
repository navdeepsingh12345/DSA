#include<stdio.h>
#include<stdlib.h>
#define max 50

typedef struct  node{
    int value;
    int priority;
}node;



int insert(node queue[],int front, int rear){
    int value,priority,i=0,loc=0;
    printf("Enter value: ");
    scanf("%d",&value);
    printf("Enter Priority: ");
    scanf("%d", &priority);

    if(rear==max-1){ printf("Queue is overflow"); }
    else{
        if(rear == -1 || queue[rear].priority < priority){
            rear++;
            queue[rear].value = value;
            queue[rear].priority = priority;
        }
        else{
            for(i=rear; i>=front; i--){
                if(queue[i].priority < priority){
                    break;
                }
            }
            loc = i;

            for(i = rear; i>loc; i--){
                queue[i+1] = queue[i];
            }
            queue[loc+1].priority = priority;
            queue[loc+1].value = value;
            rear++;
        }
    }
    return rear;
}

int delete(node queue[],int front, int rear){
    if(front==-1 || front == rear+1){ printf("queue is Underflow"); }
    else{
        printf("Deleted element is: %d",queue[front].value);
        front++;
    }
    return front;
}

void display(node queue[], int front ,int rear){
    for(int i=front; i<=rear; i++){
        printf("%d ",queue[i].value);
    }
}

int main(){
    int choice;
    int front= -1,rear = -1;
    node queue[max];

    do{
        printf("\nEnter Choice:\n1 -> insert\n2 -> delete\n3 -> Display\n4 -> Exit\n  -> ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                rear = insert(queue, front ,rear);
                if(front == -1){
                    front++;
                }
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