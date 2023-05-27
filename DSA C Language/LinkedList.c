#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *start = NULL;
int c = 0;
void push(int item)
{

    if(start == NULL)
    {
        start = (struct node *)malloc(sizeof(struct node));
        start->info = item;
        start->next = NULL;
        c++;
    }
    else
    {
        struct node *ptr1 = start;
        while(ptr1->next != NULL){
            ptr1 = ptr1->next;
        }
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->info = item;
        newNode->next = NULL;
        ptr1->next = newNode;
        c++;
    }
}
void insertAtNthPosition(int item, int index)
{
    int a = size();
    if(start == NULL)
    {
        printf("Invalid Insertion");
    }
    else{
        if(index == 0){
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->info = item;
            newNode->next = start;
            start = newNode;
            c++;
        }
        else if(index < size){
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->info = item;
            int i = 0;
            struct node *temp = start;
            while(i < index - 1 && temp->next != NULL){
                temp = temp->next;
                i++;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            c++;
        }
        else{
            struct node *ptr1 = start;
            while(ptr1->next != NULL){
                ptr1 = ptr1->next;
            }
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->info = item;
            newNode->next = NULL;
            ptr1->next = newNode;
            c++;
        }
    }
}
void insertFirst(int item){
    if(start == NULL){
        printf("Invalid Insersion");
    }
    else{
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->info = item;
        newNode->next = start;
        start = newNode;
    }
    c++;
}
void del_first(){
    int item= -1;
    if(start == NULL){
        printf("Invalid Deletion");
    }

    else{
        struct node *ptr;
        item = ptr->info;
        start = start->next;

    }
    c--;
}
void del_last()
{
    //struct node *ptr;
    if(start == NULL){
        printf("Invalid Deletion");
    }
    else
    {
        struct node *ptr = start;
        while(ptr->next->next != NULL )
        {
            ptr = ptr -> next;
        }
        ptr->next = NULL;
    }
    c--;
}
int size(){
    return c;
}
void display_list()
{
    struct node *ptr = start;

    while(ptr != NULL){
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
}
int main()
{

    push(32);
    insertFirst(11);
    insertAtNthPosition(99, 20);
    push(54);
    push(76);
    push(104);
    display_list();
    printf("\n%d", size());


}
