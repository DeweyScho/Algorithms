//Dewey Schoenfelder
#include <algorithm>

/**
 * Heap Sort (in-place).
 * Builds a max-heap in-place, then repeatedly extracts the max.
 * Uses iterative heapify to avoid recursion.
 */
void heapify(int arr[], int heapSize, int root) {
    while (true) {
        int largest = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        if (left < heapSize && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < heapSize && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != root) {
            std::swap(arr[root], arr[largest]);
            root = largest;
        } else {
            break;
        }
    }
}

void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }
    // Extract elements from heap
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
