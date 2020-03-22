#include<bits/stdc++.h>

using namespace std;

class MaxHeap {
    private:
        int *heap;
        int size;
        int capacity;

        int parent(int ind) {
            return (ind-1)/2;
        }

        int getLeftChild(int ind) {
            int left = 2*ind + 1;
            if(0<left && left<size)
                return left;
            return -1;
        }

        int getRightChild(int ind) {
            int right = 2*ind + 2;
            if(0<right && right<size)
                return right;
            return -1;
        }
    
        void swap(int a, int b) {
            if(0<=a && a<=size && 0<=b && b<=size) {
                int temp = heap[a];
                heap[a] = heap[b];
                heap[b] = temp;
            }
            return;
        }
    public:
        MaxHeap(int cap) {
            capacity = cap;
            size = 0;
            heap = (int *)malloc(sizeof(int)*capacity);
            if(heap)
                printf("Heap created with size :%d\n",capacity);
            return;
        }

        void heapify(int index) {

            int parent_ind = parent(index);
            while(index>0 && heap[index] > heap[parent_ind]) {

                swap(parent_ind, index);

                index = parent_ind;
                parent_ind = parent(index);
            }

            return;
        }

        void Enqueue(int value) {
            if(size<capacity) {
                heap[size] = value;
                heapify(size);
                size++;
            }
            else
                printf("Couldn't push %d to Max heap. Capacity reached.\n",value);
            return;
        }

        int Dequeue() {
            if(size == 0)
                return -1;
            
            int max = heap[0];
            heap[0] = heap[size-1];
            size--;

            int index = 0, leftChild = getLeftChild(index), 
                rightChild = getRightChild(index), max_index;
            while(index>=0 && index<size && (leftChild > 0 || rightChild > 0)) {
                max_index = index;

                if(leftChild!=-1 && heap[leftChild] > heap[max_index])
                    max_index = leftChild;
                if(rightChild!=-1 && heap[rightChild] > heap[max_index])
                    max_index = rightChild;
                
                if(max_index != index) {
                    swap(max_index, index);
                    index = max_index;
                    leftChild = getLeftChild(index);
                    rightChild = getRightChild(index);
                }
                else
                    break;
            }
            return max;
        }

        int getMax() {
            if(size>0)
                return heap[0];
            return INT_MIN;
        }

        int getSize() {
            return size;
        }

        void printHeap() {
            printf("Size= %d, Heap : ", size);
            for(int i=0;i<size;i++) {
                cout<<heap[i]<<" ";
            }
            cout<<endl;
            return;
        }
};