#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    // Check the dimensions of the board
    if (board.size() != 9 || board[0].size() != 9) {
        return false;
    }

    // Check rows
    for (int i = 0; i < 9; i++) {
        set<char> rowSet;
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.' && rowSet.count(board[i][j]) == 1) {
                return false;
            }
            rowSet.insert(board[i][j]);
        }
    }

    // Check columns
    for (int j = 0; j < 9; j++) {
        set<char> colSet;
        for (int i = 0; i < 9; i++) {
            if (board[i][j] != '.' && colSet.count(board[i][j]) == 1) {
                return false;
            }
            colSet.insert(board[i][j]);
        }
    }

    // Check 3x3 sub-boxes
    for (int box = 0; box < 9; box++) {
        set<char> subBoxSet;
        for (int i = box / 3 * 3; i < box / 3 * 3 + 3; i++) {
            for (int j = box % 3 * 3; j < box % 3 * 3 + 3; j++) {
                if (board[i][j] != '.' && subBoxSet.count(board[i][j]) == 1) {
                    return false;
                }
                subBoxSet.insert(board[i][j]);
            }
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    bool result = isValidSudoku(board);
    if (result) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
