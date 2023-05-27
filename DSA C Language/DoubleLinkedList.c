#include<stdio.h>
#include<stdlib.h>
struct dlist{
    int data;
    struct dlist *prev;
    struct dlist *next;

};
int c = 0;
struct dlist *start = NULL;
void insert_end(int item){
    if(start == NULL){
        start = (struct dlist *)malloc(sizeof(struct dlist));
        start->data = item;
        start->next = NULL;
        start-> prev = NULL;
    }
    else {
        struct dlist *ptr = start, *ptr1, *ptr2;
        while(ptr->next != NULL){
            ptr = ptr -> next;
        }
        ptr1 = ptr;
        ptr2 = (struct dlist *)malloc(sizeof(struct dlist));
        ptr2->data = item;
        ptr1->next = ptr2;
        ptr2->prev = ptr1;
        ptr2->next = NULL;
    }
    c++;
}
void insert_first(int item){
    struct dlist *newNode = (struct dlist *)malloc(sizeof(struct dlist));
    newNode->data = item;
    newNode->prev = NULL;
    newNode->next = start;
    start->prev = newNode;
    start = newNode;
    c++;
}
void insertAtNthPosition(int item, int index){

    if(start ==  NULL){
        printf("Error in Insertion");
    }
    else{
        int a = size();
        struct dlist *newNode = (struct dlist *)malloc(sizeof(struct dlist));
        newNode->data = item;
        if(index == 0){
            newNode->next = start;
            newNode->prev = NULL;
            start->prev = newNode;
            start = newNode;
            c++;
        }
        else if(index < a){
            int i = 0;
            struct dlist *temp = start;
            while(i < index - 1 && temp->next != NULL){
                i++;
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
            c++;
        }
        else{
            struct dlist *ptr = start, *ptr1, *ptr2;
            while(ptr->next != NULL){
                ptr = ptr -> next;
            }
            ptr1 = ptr;
            ptr2 = (struct dlist *)malloc(sizeof(struct dlist));
            ptr2->data = item;
            ptr1->next = ptr2;
            ptr2->prev = ptr1;
            ptr2->next = NULL;
            c++;
        }
    }
}
int delete_first(){
    if(start == NULL){
        printf("Error in Deletion");
    }
    else{
    int item = start->data;
    start = start->next;
    start->prev = NULL;
    return item;
    }
    c--;
}
int delete_end(){
    int item = -1;
    if(start == NULL){
        printf("Error in Deletion");
    }
    else {
        struct dlist *ptr = start, *p;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        item = ptr->data;
        p = ptr;
        p = p->prev;
        p->next = NULL;
        //ptr->next = NULL;
    }
    return item;
    c--;
}
int size(){
    return c;
}
void display(){
    struct dlist *ptr = start;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void display_reverse(){
    struct dlist *ptr = start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    struct dlist *ptr1 = ptr;
    while(ptr1 != NULL){
        printf("%d ", ptr1->data);
        ptr1 = ptr1->prev;
    }
}
int main(){

  //  insert_end(97);
    insert_end(34);
    insert_first(69);
    insert_end(27);
    insert_first(67);
    insertAtNthPosition(98, 2);
    insertAtNthPosition(93, 89);
//    printf("\n");
    display();
    printf("\n");
 //   display_reverse();
   // printf("%d", size());
   // printf("\n");
    //printf("%d ", delete_first());
    int l = delete_end();
    printf("%d ", l);
    printf("\n");
    display();

}
