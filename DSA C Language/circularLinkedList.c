#include<stdio.h>
#include<stdlib.h>
struct clist{
    int data;
    struct clist *next;
};
struct clist *start = NULL;
void push(int item){
    if(start == NULL){
        start = (struct clist *)malloc(sizeof(struct clist));
        start->data = item;
        start->next = start;
    }
    else{
        struct clist *ptr1 = start;
        while(ptr1->next != start){
            ptr1 = ptr1->next;
        }
        struct clist *newNode = (struct clist *)malloc(sizeof(struct clist));
        ptr1->next = newNode;
        newNode->next = start;
        newNode->data = item;
    }
}
int insertFirst(int item){
    if(start == NULL){
        printf("Error 404 found");
    }
    else {
        struct clist *ptr1 = start;
        while(ptr1->next != start){
            ptr1 = ptr1->next;
        }
        struct clist *newNode = (struct clist *)malloc(sizeof(struct clist));
        newNode->data = item;
        newNode->next = start;
        start = newNode;
        ptr1->next = start;
    }
}
void insertAtNthPosition(int item, int index){
    if(start ==  NULL){
        printf("Error in Insertion");
    }
    else{

        struct clist *newNode = (struct clist *)malloc(sizeof(struct clist));
        newNode->data = item;
        struct clist *temp = start;
        if(index == 0){
            struct clist *ptr1 = start;
            while(ptr1->next != start){
                ptr1 = ptr1->next;
            }
            newNode->next = start;
            start = newNode;
            ptr1->next = start;
        }
        else{
            int i = 0;
            while(i < index - 1){
                i++;
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}
int delFirst(){
    int item = -1;
    struct clist *tail = start;
    while(tail->next != start){
        tail = tail->next;
    }
    item = start->data;
    start = start->next;
    tail->next = start;
    return item;
}
int delLast(){
    int item = -1;
    struct clist *tail = start;
    while(tail->next->next != start){
        tail = tail->next;
    }
    item = tail->next->data;
    tail->next = start;
    return item;
}
void display(){
    if(start==NULL)
    {
        printf("Empty list\n ");
    }
    else
    {
        struct clist *ptr= start;
        while(ptr->next != start){
            printf("%d ", ptr->data);
            ptr = ptr -> next;
        }
        printf("%d ", ptr->data);
    }
}
int main(){
    push(43);
    push(56);
    push(12);
    push(76);
    insertFirst(99);
 //   display();
 //   printf("\n");
 //   int a = delFirst();
 //   printf("%d\n", a);
 //   display();
//    int b = delLast();
 //   printf("\n%d\n", b);
  //  display();
 //   printf("\n");
    insertAtNthPosition(23, 0);
    display();


}




