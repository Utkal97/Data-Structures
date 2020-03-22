#include<bits/stdc++.h>
#include "MaxHeapClass_int.h"

using namespace std;

int main() {

    MaxHeap heap(8);

    heap.Enqueue(1);
    heap.Enqueue(5);
    heap.Enqueue(3);
    heap.Enqueue(8);
    heap.Enqueue(2);
    heap.Enqueue(7);
    heap.Enqueue(6);
    heap.printHeap();
    cout<<heap.getMax()<<endl;

    heap.Dequeue();
    heap.printHeap();
    heap.Dequeue();
    heap.printHeap();
    heap.Dequeue();
    heap.printHeap();

    return 0;
}
