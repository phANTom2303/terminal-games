#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <random>

using namespace std;

vector<vector<int>> board = {{4, 2, 0, 2},
                             {0, 2, 2, 0},
                             {2, 2, 2, 2},
                             {32, 2, 4, 8}};

string topLine = " ┌──────┬──────┬──────┬──────┐";
string midLine = " ├──────┼──────┼──────┼──────┤";
string bottomLine = " └──────┴──────┴──────┴──────┘";

string getNumberSpacing(int n)
{
    string res = to_string(n);
    int len = res.length();
    for (int i = 1; i <= 4 - len; i++)
        res = " " + res;
    return res;
}

void render()
{
    cout << topLine << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << " │ ";
        for (int j = 0; j < 4; j++)
        {
            int element = board[i][j];
            string num = (element == 0) ? "    " : getNumberSpacing(element);
            cout << num << " │ ";
        }
        cout << endl
             << ((i < 3) ? midLine : bottomLine)
             << endl;
    }
}

void spawnNumber()
{
    // AI Generated Code begins
    random_device rd;  // obtain a random seed
    mt19937 gen(rd()); // seed the random number generator
    uniform_int_distribution<> dis_i(0, 3);
    uniform_int_distribution<> dis_j(0, 3);
    uniform_int_distribution<> dis_odds(1, 10);
    int i = dis_i(gen);
    int j = dis_j(gen);
    int odds = dis_odds(gen);
    // AI Generated code ends

    if (board[i][j] == 0)
    {
        int num = (odds <= 9) ? 2 : 4;
        board[i][j] = num;
    }
    else
        spawnNumber();
}

vector<int> shiftRowRight(vector<int> &arr)
{
    int lastPos = arr.size() - 1;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int e = arr[i];
        if (e != 0)
        {
            arr[lastPos] = arr[i];
            if (lastPos != i)
                arr[i] = 0;
            lastPos--;
        }
    }
    return arr;
}

void shiftRight()
{
    for (int i = 0; i < 4; i++)
        board[i] = shiftRowRight(board[i]);
}

void mergeHorizontal()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == board[i][j + 1])
            {
                board[i][j] *= 2;
                board[i][j + 1] = 0;
            }
        }
    }
}
int main()
{
    render();
    shiftRight();
    render();
    mergeHorizontal();
    render();
    shiftRight();
    render();
    return 0;
}