import java.util.*;

class Solution {
    static final int MOD = 1_000_000_007;
    public int numberOfWays(int n, int x) {
        powers = buildPowers(n, x);
        dp = new int[powers.length][n+1];
        for (int i = 0; i < powers.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        return DFS(0, n);
    }

    private int[] buildPowers(int n, int x) {
        ArrayList<Integer> list = new ArrayList<>();
        for (long base = 1; base <= n; base++) {
            long product = 1l;
            for (int j = 1; j <= x; j++) {
                product *= base;
                if (product > n) {
                    break;
                }
            }
            if (product > n) {
                break;
            }
            list.add((int)product);
        }
        int[] res = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            res[i] = list.get(i);
        }
        return res;
    }

    int[][] dp;
    int[] powers;
    int DFS(int start, int remain) {
        if (remain == 0) {
            return 1;
        }
        if (remain < 0 || start >= powers.length) {
            return 0;
        }
        if (dp[start][remain] != -1) {
            return dp[start][remain];
        }
        int sum = 0;
        for (int j = start; j < dp.length; j++) {
            if (powers[j] > remain) {
                break;
            }
            sum = (sum + DFS(j+1, (int)(remain - powers[j]))) % MOD;
        }

        return dp[start][remain] = sum;
    }
}
