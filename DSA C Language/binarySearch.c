#include<stdio.h>

int binarySearch(int arr[], int x,int n,int *c){
    int s = 0;
    int m;
    int e = n - 1;

    while(s <= e){
        *c=*c+1;
        m = (s + e)/2;

        if(x > arr[m]){
            s = m + 1;
        }else if(x < arr[m]){
            e = m-1;
        }else{
            return m;
        }
    }
    return -1;
}
int linearSearch(int arr[], int x, int n, int *c){
    for(int i = 0 ; i < n ; i++){
        *c = *c + 1;
        if(x == arr[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int a,x,pos,pos1, count = 0;
    //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr[1000];

    for(int i = 0 ; i< 1000 ;i++){
        arr[i]=i+1;
    }
    for(int i = 0 ; i < 1000 ;i++){

        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Enter the number to search:\n");
    scanf("%d",&x);
    //pos1= linearSearch(arr,x ,1000 ,&count);
    pos= binarySearch(arr,x ,1000 ,&count);
    printf("\nPosition : %d\n",pos);
    printf("Count = %d\n",count);
}
