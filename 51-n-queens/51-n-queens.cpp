class Solution {
public:
    vector<vector<string>>ans;
    
    bool isValid(int row, int col, vector<string>&board){
        for(int i = row; i >=0; --i){
            if(board[i][col] == 'Q') return false;
        }
        //diagonal 1;
        int i = row, j = col;
        while(i >= 0 and j >= 0){
            if(board[i--][j--] == 'Q') return false;
        }
        i = row;
        j = col;
        while(i >= 0 and j < board.size()){
            if(board[i--][j++] == 'Q') return false;
        }
        return true;
    }
    
    void dfs(vector<string>&board, int row){
        if(row == board.size()) {
            ans.push_back(board);
            return;
        }
        
        for(int i = 0; i < board.size(); ++i){
            if(isValid(row, i, board)){
                board[row][i] = 'Q';
                dfs(board, row + 1);
                //backtrack
                board[row][i] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n, string(n, '.'));
        
        dfs(board, 0);
        return ans;
    }
};