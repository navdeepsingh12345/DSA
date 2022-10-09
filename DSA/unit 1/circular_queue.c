#include<stdio.h>
#include<stdlib.h>
#define max 50



int main(){
    int choice;
    int front= -1,rear = -1;
    int queue[max];

    do{
        printf("\nEnter Choice:\n1 -> insert\n2 -> delete\n3 -> Display\n4 -> Exit\n  -> ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                rear = insert(queue, front, rear);
                if(front == NULL){
                    front = rear;
                }
                break;
            case 2:
                front = delete(queue, front, rear);
                rear = front;
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