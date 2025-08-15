class Solution {
    public boolean isPowerOfFour(int n) {
        class Solution {
            public boolean isPowerOfFour(int n) {
                // 1 4 16 64
                // 1 100 10000 1 000 000
                // 0101 0101 0101 0101 0101 0101 0101 0101
                int mask = 5 << 0 | 5 << 4 | 5 << 8 | 5 << 12 | 5 << 16 | 5 << 20 | 5 << 24 | 5 << 28;
                // 64 + 16 => 80
                // 5*2^4
                // 0001000 => 1111000 => n
                if ((-n & n) != n) {
                    return false;
                }
                return (mask & n) != 0;
            }
        }
    }
}
