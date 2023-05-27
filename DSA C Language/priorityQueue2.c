#include<stdio.h>
#include<stdlib.h>
struct pqueue{
    int data;
    int pr;
    struct pqueue *next;
};
struct pqueue *start = NULL;
void push(int item , int p){
    struct pqueue *ptr = (struct pqueue *)malloc(sizeof(struct pqueue));
    ptr->data = item;
    ptr->pr = p;
    ptr->next = NULL;
    if(start == NULL || p > start->pr){
        ptr->next = start;
        start = ptr;
    }
    else{
        struct pqueue *temp = start;
        while(temp->next != NULL && temp->next->pr>=p){
            temp=temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
}
void display(){
    struct pqueue * ptr = start;
    while(ptr!=NULL){
        printf("%d:", ptr->data);
        printf("%d ", ptr->pr);
        ptr = ptr->next;
    }
}
int main(){
    push(34, 8);
    push(67, 2);
    push(78, 6);
    display();
}
