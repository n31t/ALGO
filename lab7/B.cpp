#include <iostream>
#include <array>
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
    int n;
    cin >> n;
    int a[n];
    arrayInput(a,n);
    int n2;
    cin >> n2;
    int b[n2];
    int c[n+n2];
    arrayInput(b,n2);
    merge(c,a,n,b,n2);
    // mergeSort(c,n2+n);
    printArray(c,n2+n);

}