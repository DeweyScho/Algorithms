//Dewey Schoenfelder
#include <vector>
#include <algorithm>
#include <thread>

const int THRESHOLD = 1000;
static std::vector<int> temp;  // Shared buffer to avoid repeated allocations

// Merge function: merge sorted [l, mid) and [mid, r)
void mergeSortMerge(int arr[], int l, int mid, int r) {
    int i = l, j = mid, k = l;
    while (i < mid && j < r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i < mid) { temp[k++] = arr[i++]; }
    while (j < r) { temp[k++] = arr[j++]; }
    // Copy merged range back into original array
    for (int p = l; p < r; ++p) {
        arr[p] = temp[p];
    }
}

// Parallel merge sort using std::thread
void parallelMergeSort(int arr[], int l, int r) {
    if (r - l <= 1) return;
    if (r - l < THRESHOLD) {
        // For small arrays, do a regular sort
        std::sort(arr + l, arr + r);
    } else {
        int mid = (l + r) / 2;
        // Sort halves in parallel: spawn one thread for left half
        std::thread t(parallelMergeSort, arr, l, mid);
        parallelMergeSort(arr, mid, r);
        t.join();
        // Merge the two sorted halves
        mergeSortMerge(arr, l, mid, r);
    }
}

// Public API to call merge sort
void mergeSort(int arr[], int n) {
    temp.resize(n); // allocate once
    parallelMergeSort(arr, 0, n);
}
