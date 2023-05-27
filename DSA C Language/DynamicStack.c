#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *top = NULL;
void push(int item){
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->data = item;
    if(top == NULL){
        top = ptr;
        ptr->next = NULL;

    }else {
        ptr -> next = top;
        top = ptr;
    }
}
void add(){
    printf("Enter the element to be Added\n");
    int num;
    scanf("%d", &num);
    push(num);
    printf("Number Added");
}
int pop(){
    int item = -1;
    if(top == NULL){
        printf("Stack Underflow");
    }
    else
    {
        struct stack *ptr = top;
        while(ptr->next->next != NULL)
        {
            ptr = ptr -> next;
        }
        item = ptr->next->data;
        ptr->next = NULL;
    }
    return item;
}
void del(){
    int num = pop();
    printf("Number deleted is: ");
    printf("%d",num);
}
void print(){
    struct stack *temp = top;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp -> next;
    }
}

int main(int op){
    do{

        printf("\nDynamic Stack Operation\n");
        printf("1. add\n");
        printf("2. delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &op);
        if(op == 1) add();
        else if(op == 2) del();
        else if(op == 3) print();
        else if(op == 4) break;
    }while(op != 0);

}
