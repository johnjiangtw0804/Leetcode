class Solution {
    public boolean isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        return (n & -n) == n; // right most bit & with itself == itself, 因為只有一個 1 in binary format
    }
}
