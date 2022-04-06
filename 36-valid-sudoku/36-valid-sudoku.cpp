class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<int>>allRows(9, vector<int>(10)),allColumns(9, vector<int>(10)),allBoxes(9, vector<int>(10));
        
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.') continue;
                int temp = board[i][j] - '0';
                allRows[i][temp]++;
                allColumns[j][temp]++;
                
                if(i <= 2){
                    int boxId = j/3;
                    allBoxes[boxId][temp]++;
                }
                else if(i > 2 and i <= 5){
                    int boxId = 3 + j/3;
                    allBoxes[boxId][temp]++;
                }else{
                    int boxId = 6 + j/3;
                    allBoxes[boxId][temp]++;
                }
            }
        }
        
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 10; ++j)
            if(allRows[i][j] > 1 or allColumns[i][j] > 1 or allBoxes[i][j] > 1) return false;
        }
        return true;
        
        
    }
};

/*

row col box

012 012  0
012 345  1
012 678  2

345 012  3
345 345  4
345 678  5

678 012  6
678 345  7
678 678  8
*/