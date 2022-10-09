#include<stdio.h>
#include<stdlib.h>
#define max 50

int push(int [],int);
int pop(int [],int);
void display(int [],int);

int main(){
    int stack[max];
    int choice;
    int top = -1;

    do{
        printf("\nEnter Choice:\n1 -> Push\n2 -> Pop\n3 -> Display\n4 -> exit\n  -> ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                top = push(stack, top);
                break;
            case 2:
                top = pop(stack, top);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                exit(0);
        }
    }while(1);


    return 0;
}

int push(int stack[],int top){
    int value;
    printf("Enter value: ");
    scanf("%d",&value);

    if(top==max-1){ printf("Stack overflow"); }
    else{
        top++;
        stack[top] = value;
    }

    return top;
}



int pop(int stack[], int top){

    if(top==-1){ printf("Stack Underflow"); }
    else{
        printf("Deleted element is %d ",stack[top]);
        top--;
    }

    return top;
}


void display(int stack[],int top){
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
}