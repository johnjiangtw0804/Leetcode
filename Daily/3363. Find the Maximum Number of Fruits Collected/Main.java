class Solution {
    int res = 0;
    int n;

    // On^2
    public int maxCollectedFruits(int[][] fruits) {
        this.n = fruits.length;
        int[] person2 = new int[] { 0, n - 1 };
        int[] person3 = new int[] { n - 1, 0 };
        for (int i = 0; i < n; i++) {
            res += fruits[i][i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }
        res += DFS2(person2[0], person2[1], 0, fruits);
        // System.out.println(res);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }
        res += DFS3(person3[0], person3[1], 0, fruits);
        return res;
    }

    int[][] dp = new int[1001][1001];

    private int DFS2(int r, int c, int currentSteps, int[][] fruits) {
        if (r >= n || c >= n || r < 0 || c < 0) {
            return Integer.MIN_VALUE;
        }
        if (currentSteps == n - 1) {
            if (r == n - 1 && c == n - 1) {
                return 0;
            }
            return Integer.MIN_VALUE;
        }
        if (r == c) {
            return Integer.MIN_VALUE;
        }
        if (dp[r][c] != -1) {
            return dp[r][c];
        }
        int max = Integer.MIN_VALUE;
        max = Math.max(max, DFS2(r + 1, c - 1, currentSteps + 1, fruits));
        max = Math.max(max, DFS2(r + 1, c, currentSteps + 1, fruits));
        max = Math.max(max, DFS2(r + 1, c + 1, currentSteps + 1, fruits));
        if (max == Integer.MIN_VALUE) {
            dp[r][c] = Integer.MIN_VALUE;
        } else {
            dp[r][c] = max + fruits[r][c];
        }
        return dp[r][c];
    }

    private int DFS3(int r, int c, int currentSteps, int[][] fruits) {
        if (r >= n || c >= n || r < 0 || c < 0) {
            return Integer.MIN_VALUE;
        }
        if (currentSteps == n - 1) {
            if (r == n - 1 && c == n - 1) {
                return 0;
            }
            return Integer.MIN_VALUE;
        }
        if (r == c) {
            return Integer.MIN_VALUE;
        }
        if (dp[r][c] != -1) {
            return dp[r][c];
        }
        int max = Integer.MIN_VALUE;
        max = Math.max(max, DFS3(r - 1, c + 1, currentSteps + 1, fruits));
        max = Math.max(max, DFS3(r, c + 1, currentSteps + 1, fruits));
        max = Math.max(max, DFS3(r + 1, c + 1, currentSteps + 1, fruits));
        if (max == Integer.MIN_VALUE) {
            dp[r][c] = Integer.MIN_VALUE;
        } else {
            dp[r][c] = max + fruits[r][c];
        }
        return dp[r][c];
    }
}
