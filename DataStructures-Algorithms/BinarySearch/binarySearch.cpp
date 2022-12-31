#include <iostream>


int binarySearch(int* arr,int size,int x){
int l=0;
int r=size-1;
int mid;
//l = minumum index , r = maximum index

while(l<=r){
mid=(l+r)/2;

if(arr[mid]==x){
return mid;
}
if(arr[mid]<x){
l=mid+1;
}
if(arr[mid]>x){
r=mid-1;
}

}
return -1;
}



int main(){
int arr[]={1,3,5,7,9,11,30,50,91,131,231,331,666,669};
	int length = sizeof(arr)/sizeof(arr[0]);
	std::cout<<binarySearch(arr,length,331);

return 0;
}