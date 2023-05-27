#include<stdio.h>
#define max 5
int queue[max];
int front = -1;
int rear = -1;
void addQueue(int item){
    if((front == 0 && rear == max - 1) || rear+1 == front )
    {
        printf("Stack Overflow");
    }

    else
    {
        if(rear == -1)
        {
            rear = 0;
            front = 0;
        }
        else if(rear == max - 1){
            rear = 0;
        }
        else{
            rear = rear + 1;
        }
        queue[rear] = item;
    }
}
void add(){
    int num;
    printf("Enter the Element: ");

    scanf("%d", &num);
    addQueue(num);
    printf("Element Added\n");
}
int deleteQueue()
{
    int item = -1;
    if(front == -1){
        printf("Stack Underflow");
    }

    else
    {
        item = queue[front];


        if(rear == front)
        {
            front = -1;
            rear = -1;
        }
        else if(front == max -1)
        {
            front = -1;
        }
        else
        {
            front = front + 1;
        }
    }
    return item;

}
void print(){
    for(int i = front ; i <= rear ; i++){
        printf("%d ", queue[i]);
    }
}
void show_rear(){
    if(rear == -1){
        printf("Empty Queue");
    }
    else {
        printf("rear element is: ");
        printf("%d ", queue[rear]);
    }
}
void show_front(){
    if(front == -1){
        printf("Empty Queue");
    }else{
        printf("front element is: ");
        printf("%d ", queue[front]);
    }
}
void main(){

    int op;
    do{
        printf("\nStack Operation\n");
        printf("1. add\n");
        printf("2. deleteQueue\n");
        printf("3. Display\n");
        printf("4. show_rear\n");
        printf("5. show_front\n");
        printf("6. Exit\n");
        scanf("%d", &op);
        if(op == 1){
            add();
        }
        else if(op == 2){
            deleteQueue();
        }
        else if(op == 3){
            print();
        }
        else if(op == 4){
            show_rear();
        }
        else if(op == 4){
            show_front();
        }
        else if(op == 6){
            break;
        }
    }while(1);


}
