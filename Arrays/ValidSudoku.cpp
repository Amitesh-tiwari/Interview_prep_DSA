Problem Statement
Determine if a 9 x 9 Sudoku board is valid. 
Only the filled cells need to be validated according 
to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain 
the digits 1-9 without repetition.

//Firstly, we will create three vectors of row,column and of sub-boxes of bool type with size 9 and initialize them with false.
//Then we will iterate over the board and check if the cell is empty or not.
//If the cell is not empty then we will get the number from the cell and subtract 1 from it to get the index of the number in the vector.
//Then we will calculate the index of the sub-boxes by using the formula i/3*3+j/3.
//Then we will check if the number is already present in the row,column or sub-boxes then we will return false.

//code
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> sub(9, vector<bool>(9, false));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                int num = c - '0' - 1;
                int k = i / 3 * 3 + j / 3;
                if (row[i][num] || col[j][num] || sub[k][num]) {
                    return false;
                }
                row[i][num] = true;
                col[j][num] = true;
                sub[k][num] = true;
            }
        }
        return true;
    }
};