#include <iostream>
#include <vector>

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
    

int main(){
    int n,n2;
    cin >> n;
    cin >> n2;
    int a[n];
    int b[n2];
    int c[min(n,n2)];
    int k = 0;
    vector <int> v;
    for(int i = 0 ; i < n;i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < n2;i++){
        cin >> b[i];
    }
    heapSort(a,n);
    heapSort(b,n2);
    for(int i=0;i<n;i++){
        for(int j=0;j<n2;j++){
            if(a[i]==b[j]){
                c[k] = a[i];
                k++;
                b[j] = -99999;
                break;
            }
        }
    }
    heapSort(c,k);
    printArray(c,k);
    return 0;
}