#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board_Sudoku(9, vector<int>(9));
int cnt = 0;

bool isValid(int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (board_Sudoku[row][i] == num || board_Sudoku[i][col] == num)
            return false;
    }

    int sr = (row / 3) * 3;
    int sc = (col / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board_Sudoku[sr + i][sc + j] == num)
                return false;
        }
    }

    return true;
}

void solveSudoku()
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board_Sudoku[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isValid(row, col, num))
                    {
                        board_Sudoku[row][col] = num;
                        solveSudoku();
                        board_Sudoku[row][col] = 0;
                    }
                }
                return;
            }
        }
    }
    cnt++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (auto &row : board_Sudoku)
        for (auto &cell : row)
            cin >> cell;
    solveSudoku();
    cout << cnt << '\n';
    return 0;
}
