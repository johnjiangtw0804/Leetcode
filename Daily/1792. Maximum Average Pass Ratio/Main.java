import java.util.*;

class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        PriorityQueue<double[]> pq = new PriorityQueue<>((double[] a, double[] b) -> {
            return Double.compare(b[3], a[3]);
        });

        for (int[] c : classes) {
            double pass = c[0];
            double total = c[1];

            double increased = ((pass + 1.0) / (total + 1.0)) - (pass / total);
            // pass total extra increased
            pq.offer(new double[] { pass, total, 0, increased });
        }
        while (extraStudents > 0) {
            double[] c = pq.poll();
            // System.out.println(c[0] + " " + c[1] + " " + c[3] ) ;
            double extra = c[2] + 1;
            double increased = ((c[0] + extra + 1) / (c[1] + extra + 1)) -
                    ((c[0] + extra) / (c[1] + extra));
            pq.offer(new double[] { c[0], c[1], extra, increased });
            extraStudents--;
        }
        double res = 0;
        double pqSize = classes.length;
        while (pq.size() > 0) {
            double[] temp = pq.poll();
            res += (temp[0] + temp[2]) / (temp[1] + temp[2]);
        }

        return res / pqSize;
    }
}
