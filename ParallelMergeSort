//Dewey Schoenfelder
import java.util.Arrays;
import java.util.concurrent.RecursiveAction;
import java.util.concurrent.ForkJoinPool;

/**
 * Parallel Merge Sort using ForkJoin framework.
 * Optimization: Uses ForkJoinPool to sort subarrays in parallel (multi-core).
 * A single static temp array is used to avoid repeated allocations (cache-friendly).
 * Also uses a threshold to switch to serial sort for small arrays, reducing overhead.
 */
public class ParallelMergeSort extends RecursiveAction {
    private int[] array;
    private int left, right;
    private static final int THRESHOLD = 1000; // tune as needed
    private static int[] temp; // shared buffer to avoid repeated allocation
    
    public ParallelMergeSort(int[] array, int left, int right) {
        this.array = array;
        this.left = left;
        this.right = right;
    }
    
    @Override
    protected void compute() {
        if (right - left <= THRESHOLD) {
            // Use efficient built-in sort for small array portion to avoid overhead
            Arrays.sort(array, left, right);
        } else {
            int mid = (left + right) >>> 1;
            // Sort halves in parallel
            ParallelMergeSort leftTask = new ParallelMergeSort(array, left, mid);
            ParallelMergeSort rightTask = new ParallelMergeSort(array, mid, right);
            invokeAll(leftTask, rightTask);
            // Merge sorted halves
            merge(left, mid, right);
        }
    }
    
    private void merge(int left, int mid, int right) {
        int i = left, j = mid, k = left;
        // Merge into temp (for locality), then copy back
        while (i < mid && j < right) {
            if (array[i] <= array[j]) {
                temp[k++] = array[i++];
            } else {
                temp[k++] = array[j++];
            }
        }
        while (i < mid) { temp[k++] = array[i++]; }
        while (j < right) { temp[k++] = array[j++]; }
        // Copy merged range back into original array
        System.arraycopy(temp, left, array, left, right - left);
    }
    
    // Public method to invoke parallel merge sort
    public static void sort(int[] arr) {
        temp = new int[arr.length]; // allocate once
        ForkJoinPool.commonPool().invoke(new ParallelMergeSort(arr, 0, arr.length));
    }
}
