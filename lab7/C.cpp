#include <iostream>
#include <array>
#include <climits>
using namespace std;
void merge(int arr[], int left[], int lsize, int right[], int rsize) {
    int i = 0, j = 0, k = 0;
    
    while (i < lsize && j < rsize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < lsize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rsize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int size){
   
    if(size<=1){
        return;
    }
    int lsize=size/2, rsize=size-lsize; //2 3
    int left[lsize], right[rsize];
    for(int i=0; i<size; i++){
        if(i<lsize){
            left[i]=arr[i];
        }
        else{
            right[i-lsize]=arr[i];
        }
    }
    mergeSort(left, lsize);
    mergeSort(right, rsize);
    merge(arr, left, lsize, right, rsize);
    return; 
}
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
void arrayInput(int arr[], int n)
{
    for(int i = 0 ; i < n;i++){
        cin >> arr[i];
    }
}
int main(){
    int n,n2;
    cin >> n;
    cin >> n2;
    int a[n];
    int b[n2];
    int c[min(n,n2)];
    int k = 0;
    for(int i = 0 ; i < n;i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < n2;i++){
        cin >> b[i];
    }
    // heapSort(a,n);
    // heapSort(b,n2);
    for(int i=0;i<n;i++){
        for(int j=0;j<n2;j++){
            if(a[i]==b[j]){
                c[k] = a[i];
                k++;
                b[j] = INT_MIN;
                break;
            }
        }
    }
    mergeSort(c,k);
    printArray(c,k);
    return 0;
}