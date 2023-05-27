#include<stdio.h>
#define max 5
int stack[max];
int topIndex = -1;
void push(int item){
    if(topIndex == max -1 ){
        printf("Stack Overflow");
    }
    else
    {
        stack[++topIndex] = item;
    }
}
int pop(){
    int item = -1;
    if(topIndex == -1) {
        printf("Underflow");
    }
    else{
        item = stack[topIndex];
        topIndex = topIndex - 1;
    }
    return item;
}
void display(){
    for(int i = topIndex ; i >=0 ; i--){
        printf("%d ", stack[i]);
    }
}
int main(){
    push(43);
    push(54);
    push(76);
    //printf(pop());
    //a = pop();
    printf("%d\n", pop());
    display();
}
