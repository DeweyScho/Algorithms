//Dewey Schoenfelder
/**
 * Matrix Chain Multiplication DP (O(n^3) time).
 * Uses bottom-up DP table; uses plain arrays for data locality.
 */
public class MatrixChainMultiplication {
    /**
     * Computes minimum multiplication cost for a chain of matrices with given dimensions.
     * dims.length = n+1 for n matrices (matrix i is dims[i] x dims[i+1]).
     */
    public static int minMultiplicationCost(int[] dims) {
        int n = dims.length - 1;
        int[][] dp = new int[n][n];
        // dp[i][j] = 0 for i==j (single matrix)
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = Integer.MAX_VALUE;
                // Partition at k
                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
}
