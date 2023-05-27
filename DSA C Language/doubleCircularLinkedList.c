#include<stdio.h>
#include<stdlib.h>
struct dclist{
    int data;
    struct dclist *prev;
    struct dclist *next;
};
struct dclist *start = NULL;
void push(int item){
    if(start == NULL){
        start = (struct dclist *)malloc(sizeof(struct dclist));
        start->data = item;
        start->next = start;
        start->prev = start;
    }
    else{
        struct dclist *temp = start;
        while(temp->next != start){
            temp = temp->next;
        }
        struct dclist *newNode = (struct dclist *)malloc(sizeof(struct dclist));
        newNode->data = item;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = start;
    }

}
void insertFirst(int item){
    struct dclist *temp = start;
    while(temp->next != start){
        temp = temp->next;
    }
    struct dclist *newNode = (struct dclist *)malloc(sizeof(struct dclist));
    newNode->data = item;
    newNode->next = start;
    start->prev = newNode;
    start = newNode;
    temp->next = start;
}
void insertAtNthPosition(int item, int index){
    if(start ==  NULL){
        printf("Error in Insertion");
    }
    else{
        if(index == 0){
            struct dclist *temp = start;
            while(temp->next != start){
                temp = temp->next;
            }
        struct dclist *newNode = (struct dclist *)malloc(sizeof(struct dclist));
        newNode->data = item;
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
        temp->next = start;
        }
        else{
            struct dclist *newNode = (struct dclist *)malloc(sizeof(struct dclist));
            newNode->data = item;
            int i = 0;
            struct dclist *temp = start;
            while(i < index - 1){
                i++;
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}
int deletelast(){
    if(start == NULL){
        printf("Invalid Deletion");
    }
    else {
        int item = -1;
        struct dclist *ptr = start;
        while(ptr->next->next != start){
            ptr = ptr->next;
        }
    item = ptr->next->data;
    ptr->next = start;
    }
}
void display(){
    if(start == NULL){
        printf("Empty List");
    }
    else{

    struct dclist *ptr = start;
    while(ptr->next != start){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d ", ptr->data);
    }
}
int main(){
    push(45);
    push(67);
    push(23);
    push(32);
    push(43);
    push(56);
    insertFirst(69);
    insertFirst(91);
    insertAtNthPosition(12, 12);
    display();
    printf("\n");
    deletelast();
    display();
}
