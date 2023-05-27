#include<stdio.h>
void linearSearch(int arr[], int element, int n){
    int flag = 0;
    for(int i = 0 ; i < n ; i++){
        if(element == arr[i]){
            flag = 1;
        }

    }
    if(flag == 1){
        printf("true");
    }
    else {
        printf("false");
    }

}
int main(){
    int arr[] = {1, 2, 3, 45, 6};
    linearSearch(arr, 7, 5);

}
