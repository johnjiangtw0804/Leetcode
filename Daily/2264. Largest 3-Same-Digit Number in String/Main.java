class Solution {
    public String largestGoodInteger(String num) {
        char[] s = num.toCharArray();
        char best = 0; // 0 代表尚未找到；實際字元都 >= '0' (48)

        for (int i = 0; i + 2 < s.length; i++) {
            char c = s[i];
            if (c == s[i + 1] && c == s[i + 2]) { // 連續三個一樣
                if (c > best)
                    best = c; // 更新最大 digit
            }
        }

        return best == 0 ? "" : String.valueOf(best).repeat(3);
    }
}
