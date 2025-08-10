import java.util.*;;

class Solution {
    public boolean reorderedPowerOf2(int n) {
        // power of 2?
        // 2^32
        int[] nCounter = new int[10];
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            nCounter[digit]++;
        }
        String target = Arrays.toString(nCounter);
        // System.out.println(target);

        HashSet<String> freq = new HashSet<>();
        for (int i = 0; i < 31; i++) {
            int temp = 1 << i;
            int[] tempFreq = new int[10];
            while (temp > 0) {
                int digit = temp % 10;
                temp /= 10;
                tempFreq[digit]++;
            }
            freq.add(Arrays.toString(tempFreq));
        }

        return freq.contains(target);
    }
}
