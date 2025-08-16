import java.util.*;

class Solution {
    public int maximum69Number(int num) {
        StringBuilder sb = new StringBuilder(Integer.toString(num));
        for (int i = 0; i < sb.length(); i++) {
            char c = sb.charAt(i);
            if (c == '6') {
                sb.setCharAt(i, '9');
                break;
            }
        }
        return Integer.parseInt(sb.toString());
    }
}
