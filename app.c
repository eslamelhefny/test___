#include<stdio.h>
void swap(int * a, int *b){
    *a = *a ^ *b ;
    *b = *a ^ *b ;
    *a = *a ^ *b ;
}
void sort(int arr[], int size){

    for(int i = 0;i<size-2;i++){
        int min = i;
    for(int j = i+1;j<size;j++){
        if(arr[j]<arr[min]){
            min = j;        
        }
    }
    swap(&arr[i],&arr[min]);
    }
}
void print_array(int arr[], int size){

    for(int i = 0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    puts("\n");
}
int main(){
int arr[]={3,5,10,11,22,8,1};
sort(arr,7);
print_array(arr,7);

    return 0 ; 
}