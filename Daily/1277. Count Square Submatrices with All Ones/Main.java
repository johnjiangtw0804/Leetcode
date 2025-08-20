class Solution {
    public int countSquares(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] dp = new int[m][n];
        // 這裡有個很屌的地方。 Math.min(dp[i-1][j] dp[i][j-1] dp[i-1][j-1]) 約束了 dp[i][j]
        // 這三個 dp 狀態，where dp[i][j] 是以這個點為右下角所能畫出最大的正方形
        int counter = 0;
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 1) {
                dp[0][j] = 1;
                counter++;
            }
        }

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 1) {
                dp[i][0] = 1;
                counter++;
            }
        }
        if (dp[0][0] == 1) {
            counter--;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    continue;
                }
                dp[i][j] = Math.min(dp[i-1][j], Math.min(dp[i][j-1],dp[i-1][j-1])) +1;
                counter += dp[i][j];
            }
        }
        return counter;
    }
}
