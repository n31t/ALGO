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