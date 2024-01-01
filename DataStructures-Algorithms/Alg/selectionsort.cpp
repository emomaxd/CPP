#include <iostream>

void swap(int* x,int* y){
    int t=*x;
    *x=*y;
    *y=t;
}

void sort(int arr[],int l){
    int i,j,min;
    std::cout<<"length : "<<l<<std::endl;
    
    for(i=0;i<l-1;i++){
        min=i;
        for(j=i+1;j<l;j++)
        if(arr[j]<arr[min])
            min=j;

        if(min!=i)
            swap(&arr[min],&arr[i]);
    }

    
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        std::cout << arr[i] << " ";
    
}

int main(){
    int arr[]={3,1,555,32,12,31,54,67,21,23,17,18,15,35,34,33};
    int length=sizeof(arr)/sizeof(arr[0]);
    sort(arr,length);
    printArray(arr,length);
    
    return 0;
}