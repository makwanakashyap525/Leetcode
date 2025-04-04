
    #include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, map<char, int>> row, col, box;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch == '.') continue;

                int boxIndex = (i / 3) * 3 + (j / 3);

                row[i][ch]++;
                col[j][ch]++;
                box[boxIndex][ch]++;

                if (row[i][ch] > 1 || col[j][ch] > 1 || box[boxIndex][ch] > 1) {
                    return false;
                }
            }
        }

        return true;
    }
};
