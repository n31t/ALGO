#include <iostream>
#include <array>
using namespace std;
void bubbleSort(int arr[], int size){
    while(size!=0){
        for(int i=0; i<size-1; i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        size--;
    }
    return;
}