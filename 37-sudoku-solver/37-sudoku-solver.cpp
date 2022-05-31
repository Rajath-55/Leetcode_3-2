class Solution {
public:
    
    bool isValid(vector<vector<char>> &board, int x, int y, char toPut){
        int drow = x - x%3, dcol = y - y%3;
        
        for(int i = 0; i < 9; ++i){
            if(board[i][y] == toPut || board[x][i] == toPut) return false;
        }
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j)
            if(board[i + drow][j + dcol] == toPut) return false;
        }
        return true;
    }
    
    bool backtrack(vector<vector<char>>&board, int i, int j){
        //if rows end return true
        if(i == 9) return true;
        // if cols end solve for next row
        if(j == 9) return backtrack(board, i + 1, 0);
        if(board[i][j] != '.') return backtrack(board, i, j + 1);
        
        for(char c = '1'; c <= '9'; ++c){
            if(isValid(board, i, j, c)){
                board[i][j] = c;
                if(backtrack(board, i, j + 1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
};