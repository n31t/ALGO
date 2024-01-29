#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Heap {
    long long int *a;
    long long int capacity;
    long long int size;

    long long int parent (long long int i) {
        return (i-1)/2;
    }
    long long int left (long long int i) {
        return i*2 + 1;
    }
    long long int right (long long int i) {
        return i*2 + 2;
    }
    void heapUp (long long int i) {
        long long int p = parent(i);
        if (i > 0 && a[i] < a[p]) {
            swap(a[i], a[p]);
            heapUp(p);
        }
    }
    void heapDown (long long int i) {
        long long int l = left(i);
        long long int r = right(i);
        long long int min = i;
        if (l < size && a[l] < a[min]) {
            min = l;
        }
        if (r < size && a[r] < a[min]) {
            min = r;
        }
        if (min != i) {
            swap(a[i], a[min]);
            heapDown(min);
        }
    }
    void add (long long int x) {
        a[size] = x;
        size++;
        heapUp(size-1);
    }

    void cut_min () {
        a[0] = a[size-1];
        size = max((long long)0, size - 1);
        heapDown(0);
    }
    
    Heap (long long int x) {
        this->a = new long long int[x];
        this->size = 0;
        this->capacity = x;
    }
};
int main() {
    long long int n, q;
    cin >> q;
    cin >> n;
    long long int capacity = n;
    Heap heap(capacity);
    long long sum = 0;

    // Consume any extraneous characters in the input stream
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (long long int i = 0; i < q; i++) {
        string str;
        getline(cin, str); // Read a whole line including spaces

        // Process the line
        if (str == "print") {
            sum = 0;
            if (heap.size == 0) {
                cout << '0' << endl;
            } else {
                for (long long int j = 0; j < heap.size; j++) {
                    sum += heap.a[j];
                }
                cout << sum << endl;
            }
        } else if (str == "insert") {
            long long int num;
            cin >> num;
            if (heap.size == n) {
                heap.cut_min();
                heap.add(num);
            } else {
                heap.add(num);
            }
        }
    }
}

// 6 4
// print
// insert 9
// insert 6
// print
// insert 10
// print