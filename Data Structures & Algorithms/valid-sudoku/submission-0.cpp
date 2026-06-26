class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9],column[9],sq[9];
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.')continue;
                if(row[i].find(board[i][j])!=row[i].end() ||
                column[j].find(board[i][j])!=column[j].end() ||
                sq[(i/3)*3 + (j/3)].find(board[i][j])!=sq[(i/3)*3 + (j/3)].end()) return false;

                row[i].insert(board[i][j]);
                column[j].insert(board[i][j]);
                sq[(i/3)*3 + (j/3)].insert(board[i][j]);
            }
        }
        return true;
    }
};
