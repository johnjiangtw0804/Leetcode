class Solution {
    public int numberOfPairs(int[][] points) {
        int res = 0;
        Arrays.sort(points, (int[] a, int[] b) -> {
            // 由大的開始
            if (a[0] == b[0]) {
                return Integer.compare(b[1], a[1]);
            }
            return Integer.compare(a[0], b[0]);
        });
        for (int i = 0; i < points.length; i++) {
            int[] p1 = points[i];
            int lower = Integer.MIN_VALUE;
            int upper = p1[1];
            for (int j = i + 1; j < points.length; j++) {
                int[] p2 = points[j];
                if (p1[1] < p2[1]) {
                    continue;
                }
                // 如果 p2 的 y 比較上來 => 我們要
                if (p2[1] > lower || p2[1] > upper) {
                    res++;
                }
                lower = Math.max(lower, p2[1]);
            }
        }
        return res;
    }
}
