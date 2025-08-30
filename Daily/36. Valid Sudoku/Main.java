import java.util.*;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        HashMap<Integer, HashSet<Character>> row2Nums = new HashMap<>();
        HashMap<Integer, HashSet<Character>> col2Nums = new HashMap<>();
        HashMap<Integer, HashSet<Character>> grid2Nums = new HashMap<>();

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                row2Nums.putIfAbsent(i, new HashSet<>());
                col2Nums.putIfAbsent(j, new HashSet<>());
                if (board[i][j] == '.') {
                    continue;
                }
                if (row2Nums.get(i).contains(board[i][j]) ||
                        col2Nums.get(j).contains(board[i][j])) {
                    return false;
                }
                row2Nums.get(i).add(board[i][j]);
                col2Nums.get(j).add(board[i][j]);
            }
        }

        for (int i = 0; i < board.length - 2; i += 3) {
            for (int gridNum = 0; gridNum < 3; gridNum++) {
                for (int j = i; j < i + 3; j++) {
                    for (int k = gridNum * 3; k < gridNum * 3 + 3; k++) {
                        grid2Nums.putIfAbsent(i * 3 + gridNum, new HashSet<>());
                        if (board[j][k] == '.') {
                            continue;
                        }
                        if (grid2Nums.get(i * 3 + gridNum).contains(board[j][k])) {
                            return false;
                        }
                        grid2Nums.get(i * 3 + gridNum).add(board[j][k]);
                    }
                }
            }
        }

        return true;
    }
}
