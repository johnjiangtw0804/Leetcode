import java.util.*;

class Solution {
    public int[] productQueries(int n, int[][] queries) {
        int[] res = new int[queries.length];
        int mod = (int) (1e9 + 7);
        ArrayList<Integer> powers = new ArrayList<>();
        // binary representation
        for (int i = 0; i < 31; i++) {
            if (((n >> i) & 1) == 1) {
                powers.add(i);
            }
        }

        int i = 0;
        long[] prefix = new long[powers.size() + 1];
        for (i = 1; i <= powers.size(); i++) {
            prefix[i] = (powers.get(i - 1) + prefix[i - 1]);
        }
        // [1, 1, 2]
        // prefix[right+1] / prefix[left] => power 互相消減
        i = 0;
        for (int[] query : queries) {
            int left = query[0];
            int right = query[1];
            int pow = (int) (prefix[right + 1] - prefix[left]);
            res[i] = (int) (Math.pow(2, pow) % mod);
            i++;
        }

        return res;
    }
}
