//Dewey Schoenfelder
#include <algorithm>

/**
 * Optimized QuickSort (in-place).
 * Tail-call optimization: Uses a loop to avoid recursion on the larger partition (O(log n) stack).
 * Median-of-three pivot to handle sorted input better.
 */
void quickSort(int arr[], int low, int high) {
    while (low < high) {
        // Median-of-three pivot selection
        int mid = low + (high - low) / 2;
        if (arr[mid] < arr[low]) std::swap(arr[mid], arr[low]);
        if (arr[high] < arr[low]) std::swap(arr[high], arr[low]);
        if (arr[mid] < arr[high]) std::swap(arr[mid], arr[high]);
        int pivot = arr[high];
        
        // Partition
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] <= pivot) {
                std::swap(arr[++i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int p = i + 1;
        
        // Recurse on smaller part first, loop on larger part
        if (p - low < high - p) {
            quickSort(arr, low, p - 1);
            low = p + 1;
        } else {
            quickSort(arr, p + 1, high);
            high = p - 1;
        }
    }
}

// Convenience wrapper
void quickSort(int arr[], int n) {
    quickSort(arr, 0, n - 1);
}
