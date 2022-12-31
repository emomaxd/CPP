#include <iostream>

void swap(int* x,int* y){
    int t=*x;
    *x=*y;
    *y=t;
}
void printArray(int* arr,int l){
    for(int i=0;i<l;i++){
        std::cout<<arr[i]<<" ";
    }
}
void sort(int* arr,int l){
    for(int i=0;i<l-1;i++)
        for(int j=0;j<l-1;j++)
            if(arr[j]>arr[j+1])
            swap(&arr[j],&arr[j+1]);
}
int main(){
    int arr[]={3,1,555,32,12,31,54,67,21,23,17,18,15,35,34,33};
    int length=sizeof(arr)/sizeof(arr[0]);
    sort(arr,length);
    printArray(arr,length);

    return 0;
}