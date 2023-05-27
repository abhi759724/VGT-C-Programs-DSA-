#include<stdio.h>
#include<stdlib.h>
struct queue{
    int data;
    struct queue *next;
};
struct queue *rear = NULL;
struct queue *front = NULL;
void pushElement(int item){
    struct queue *ptr = (struct queue *)malloc(sizeof(struct queue));
        ptr->data = item;
        ptr->next = NULL;
    if(front == NULL && rear == NULL){
        front = ptr;
        rear = ptr;
    }
    else if(front != NULL)
    {
        rear->next = ptr;
        rear = ptr;
    }
}
void add_in_queue(){
    printf("Enter the element to be Added\n");
    int num;
    scanf("%d", &num);
    pushElement(num);
    printf("Number Added");
}
int popEl(){
    int item = -1;
    if(rear == NULL){
        printf("Queue is Empty");
    }
    else {
        struct queue *ptr = front;
        item = front->data;
        front = front->next;
    }
    return item;
}
void delete_in_queue(){
    int num = popEl();
    printf("Number deleted is: ");
    printf("%d",num);
}
void show_rear(){
    printf("rear Element is: ");
    printf("%d", rear->data);
}
void show_front(){
    printf("front Element is: ");
    printf("%d", front->data);
}
void show_queue(){
    struct queue *ptr = front;
    while(ptr != NULL){
        printf("%d->",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}
int main(int op){
    do{
        printf("\nDynamic Queue Operation\n");
        printf("1. add\n");
        printf("2. delete\n");
        printf("3. show front\n");
        printf("4. show rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        scanf("%d", &op);
        if(op == 1) add_in_queue();
        else if(op == 2) delete_in_queue();
        else if(op == 3) show_front();
        else if(op == 4) show_rear();
        else if(op == 5) show_queue();
        else if(op == 6) break;
    }while(op <= 6);
}

