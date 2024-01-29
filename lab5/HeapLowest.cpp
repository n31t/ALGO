#include <iostream>
#include <algorithm>

using namespace std;

struct Heap {
    int *a;
    int capacity;
    int size;

    int parent (int i) {
        return (i-1)/2;
    }
    int left (int i) {
        return i*2 + 1;
    }
    int right (int i) {
        return i*2 + 2;
    }
    void heapUp (int i) {
        int p = parent(i);
        if (i > 0 && a[i] < a[p]) {
            swap(a[i], a[p]);
            heapUp(p);
        }
    }
    void heapDown (int i) {
        int l = left(i);
        int r = right(i);
        int min = i;
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
    void add (int x) {
        a[size] = x;
        size++;
        heapUp(size-1);
    }

    void cut_min () {
        a[0] = a[size-1];
        size = max(0, size - 1);
        heapDown(0);
    }
    
    Heap (int x) {
        this->a = new int[x];
        this->size = 0;
        this->capacity = x;
    }
};

int main() {


    return 0;
}
