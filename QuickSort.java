//Dewey Schoenfelder
/**
 * Optimized QuickSort with tail-call elimination and median-of-three pivot.
 * Tail recursion removed: always recurse on smaller partition and loop on larger (reducing stack depth to O(log n)).
 * Uses median-of-three pivot to improve performance on sorted inputs (reduces worst-case behavior).
 */
public class QuickSort {
    public static void sort(int[] arr) {
        quickSort(arr, 0, arr.length - 1);
    }
    
    private static void quickSort(int[] arr, int low, int high) {
        while (low < high) {
            // Median-of-three pivot selection
            int mid = low + (high - low) / 2;
            if (arr[mid] < arr[low]) swap(arr, low, mid);
            if (arr[high] < arr[low]) swap(arr, low, high);
            if (arr[mid] < arr[high]) swap(arr, mid, high);
            // Now arr[high] holds the pivot value
            int pivot = arr[high];
            
            // Partition
            int i = low - 1;
            for (int j = low; j < high; j++) {
                if (arr[j] <= pivot) {
                    swap(arr, ++i, j);
                }
            }
            swap(arr, i + 1, high);
            int p = i + 1;
            
            // Tail-call elimination: recurse on smaller part, loop on larger
            if (p - low < high - p) {
                quickSort(arr, low, p - 1);
                low = p + 1; // loop for remaining part
            } else {
                quickSort(arr, p + 1, high);
                high = p - 1; // loop continues
            }
        }
    }
    
    private static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
