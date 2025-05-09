//Dewey Schoenfelder
/**
 * Heap Sort (in-place, iterative).
 * Optimization: Builds the heap in-place to use O(1) extra space and uses iterative sift-down to avoid recursion.
 * Branch prediction: loop conditions are simple to predict.
 */
public class HeapSort {
    public static void sort(int[] arr) {
        int n = arr.length;
        // Build max heap (bottom-up)
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        // Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--) {
            // Move current root (max) to end
            int tmp = arr[0];
            arr[0] = arr[i];
            arr[i] = tmp;
            // Heapify reduced heap
            heapify(arr, i, 0);
        }
    }
    
    // Iterative heapify (sift-down) to avoid recursion overhead
    private static void heapify(int[] arr, int heapSize, int root) {
        while (true) {
            int largest = root;
            int left = 2 * root + 1;
            int right = 2 * root + 2;
            // Find largest among root and children
            if (left < heapSize && arr[left] > arr[largest]) {
                largest = left;
            }
            if (right < heapSize && arr[right] > arr[largest]) {
                largest = right;
            }
            if (largest != root) {
                // Swap root and largest child
                int tmp = arr[root];
                arr[root] = arr[largest];
                arr[largest] = tmp;
                // Continue sifting down the child now
                root = largest;
            } else {
                break;
            }
        }
    }
}
