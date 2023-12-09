class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(std::vector<std::vector<char>>& board) {
        // Iterate through each row of the board
        for (int row = 0; row < 9; ++row) {
            // Iterate through each column of the board
            for (int col = 0; col < 9; ++col) {
                // Check if the current cell is empty
                if (board[row][col] == '.') {
                    // Try placing a digit from '1' to '9'
                    for (char digit = '1'; digit <= '9'; ++digit) {
                        // Check if the current digit placement is valid
                        if (isValid(board, row, col, digit)) {
                            // Place the digit in the current cell
                            board[row][col] = digit;
                            
                            // Recursively try to solve the updated board
                            if (solve(board)) {
                                return true; // If a solution is found, return true
                            }

                            // If the current placement doesn't lead to a solution, backtrack
                            board[row][col] = '.'; // Undo the current placement
                        }
                    }
                    
                    // If no valid digit is found for the current cell, backtrack further
                    return false;
                }
            }
        }

        // If all cells are filled, the Sudoku is solved
        return true;
    }

    // Check if the current digit placement is valid
    bool isValid(const std::vector<std::vector<char>>& board, int row, int col, char digit) {
        // Check if the digit is not already in the current row, column, and 3x3 subgrid
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == digit || board[i][col] == digit || 
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == digit) {
                return false; // If the digit is already present, return false
            }
        }
        // If the digit is not found in the current row, column, and subgrid, return true
        return true;
    }
};