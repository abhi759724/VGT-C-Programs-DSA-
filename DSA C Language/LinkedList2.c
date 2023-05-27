#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};
struct node *start = NULL;
void addNode(int item)
{

    if(start == NULL)
    {
        start = (struct node *)malloc(sizeof(struct node));
        start->info = item;
        start->next = NULL;
    }
    else
    {
        struct node *ptr1 = start;
        while(ptr1->next != NULL){
            ptr1 = ptr1->next;
        }
        struct node *ptr2 = (struct node *)malloc(sizeof(struct node));
        ptr2->info = item;
        ptr2->next = NULL;
        ptr1->next = ptr2;
    }
}
void add(){
    printf("Enter the element to be added\n");
    int num;
    scanf("%d", &num);
    addNode(num);
    printf("Number Added\n");
}
void insert_first(int element){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if(start == NULL){
        printf("Invalid Insertion");
    }
    else
    {
        ptr->info = element;
        ptr->next = start;
        start = ptr;
    }
}
void insert(){
    int num;
    printf("Enter the element to insert\n");
    scanf("%d", &num);
    insert_first(num);
    printf("Item inserted");
}
void insertRandomly(int element, int index){

    if(start == NULL){
        printf("Invalid Insertion");
    }
    else if(index==0){
        struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
        ptr1->info = element;
        ptr1->next = start;
        start = ptr1;
    }
    else{
        int count = 0;
        struct node *temp = start;
        while(count < index - 1 && temp->next != NULL){
            count++;
            temp = temp->next;
        }
        if(temp->next!= NULL){
            struct node *ptr = (struct node *)malloc(sizeof(struct node));
            ptr->info = element;
            ptr->next = temp->next;
            temp->next = ptr;
        }
    }
}
void insert2(){
    int num;
    printf("Enter the element to insert\n");
    scanf("%d", &num);
    int index;
    printf("Enter the index number\n");
    scanf("%d", &index);
    insertRandomly(num, index);
    printf("Item inserted");
}


void delete_first(){
    struct node *ptr = start;
    ptr = NULL;
    start = start->next;
}

void delete_end(){
    struct node *ptr = start;
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    ptr -> next = NULL;
}

void display_list1(){
    struct node *temp = start;
    while(temp != NULL){
            printf("%d ",temp->info);
        temp = temp -> next;
    }
}

int main(){

   int op;
   do{
    printf("\nLinked List Operations\n");
    printf("1. Add Element\n");
    printf("2. delete first Element\n");
    printf("3. delete last Element\n");
    printf("4. insert item on first position\n");
    printf("5. insert item on random position\n");
    printf("6. Display_list\n");
    scanf("%d", &op);
    if(op == 1) add();
    else if(op == 2) delete_first();
    else if(op == 3) delete_end();
    else if(op == 4) insert();
    else if(op == 5) insert2();
    else if(op == 6) display_list1();
   }while(op!=0);



}


