#include <iostream>
#include <climits>
#include <cmath>

using namespace std;
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[],int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for(int i = 0 ; i < n - 1 ;i++){
        swap(arr[0],arr[n- i - 1]);
        heapify(arr, n - i - 1 , 0);
    }
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
    heapSort(a,n);
    int min = INT_MAX;
    for(int i = 0 ; i < n - 1; i++){
        if(a[i+1] - a[i] < min){
            min = a[i+1] - a[i];
        }
    }
    for(int i = 0 ; i < n - 1; i++){
        if(a[i+1] - a[i] == min){
            cout << a[i] << ' ' << a[i+1] << ' ';
        }
    }
    return 0;
}