//Dewey Schoenfelder
#include <vector>
#include <limits>

/**
 * Matrix Chain Multiplication DP (O(n^3) time).
 * Bottom-up dynamic programming with 2D DP table.
 */
int matrixChainOrder(const std::vector<int>& dims) {
    int n = dims.size() - 1;
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    // dp[i][j] = minimum cost for multiplying matrices i..j
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = std::numeric_limits<int>::max();
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[0][n - 1];
}
