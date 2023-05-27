#include<stdio.h>
#include<stdlib.h>
struct pqueue{
    int info;
    int pr;
    struct pqueue *next;
};
struct pqueue *front = NULL;
void add(int item, int p){
    struct pqueue *ptr = (struct pqueue *)malloc(sizeof(struct pqueue));
    ptr->info = item;
    ptr->pr= p;
    ptr->next = NULL;
    if(front == NULL  || p > front->pr){
        ptr->next = front;
        front = ptr;
    }
    else
    {
        struct pqueue *q = front;
        while( q->next != NULL && q->next->pr >= p){
            q = q -> next;
        }
        ptr->next = q->next;
        q->next = ptr;

    }
}

int pop(){
    int item = -1;
    if(front == NULL){
        printf("Underflow");
    }
    else{
        struct pqueue *ptr = front;
        while(ptr->next->next != NULL){
            ptr = ptr->next;
        }
        item = ptr->next->info;
        ptr->next = NULL;
    }
    return item;
}
void del(){
    printf("Item deleted id: ");
    int a = pop();
    printf("%d\n", a);
}
void print(){
    struct pqueue *ptr = front;
    printf("Front -> ");
    while(ptr != NULL){

        printf("%d:",ptr->info);
        printf("%d -> ",ptr->pr);

        ptr = ptr->next;
    }
    printf(" NULL\n");
}
void main(){
    add(43, 3);
    add(65, 8);
    add(54, 7);
    print();
}


