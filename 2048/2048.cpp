#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <random>

using namespace std;

vector<vector<int>> board = {{0, 0, 0, 0},
                             {0, 0, 0, 0},
                             {0, 0, 0, 0},
                             {0, 0, 0, 0}};

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

vector<int> shiftRowLeft(vector<int> &arr)
{
    int lastPos = 0;
    for (int i = 0; i < 4; i++)
    {
        int e = arr[i];
        if (e != 0)
        {
            arr[lastPos] = arr[i];
            if (lastPos != i)
                arr[i] = 0;
            lastPos++;
        }
    }
    return arr;
}

void shiftLeft()
{
    for (int i = 0; i < 4; i++)
        board[i] = shiftRowLeft(board[i]);
}

void shiftUp()
{

    for (int j = 0; j < 4; j++)
    {
        int lastPos = 0;
        for (int i = 0; i < 4; i++)
        {
            int e = board[i][j];
            if (e != 0)
            {
                board[lastPos][j] = board[i][j];
                if (lastPos != i)
                    board[i][j] = 0;
                lastPos++;
            }
        }
    }
}

void shiftDown()
{
    for (int j = 0; j < 4; j++)
    {
        int lastPos = 3;
        for (int i = 3; i >= 0; i--)
        {
            int e = board[i][j];
            if (e != 0)
            {
                board[lastPos][j] = board[i][j];
                if (lastPos != i)
                    board[i][j] = 0;
                lastPos--;
            }
        }
    }
}

void mergeUp()
{
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][j] == board[i + 1][j])
            {
                board[i][j] *= 2;
                board[i + 1][j] = 0;
            }
        }
    }
}

void mergeDown()
{
    for (int j = 0; j < 4; j++)
    {
        for (int i = 3; i > 0; i--)
        {
            if (board[i][j] == board[i - 1][j])
            {
                board[i][j] *= 2;
                board[i - 1][j] = 0;
            }
        }
    }
}

void mergeLeft()
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

void mergeRight()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 3; j > 0; j--)
        {
            if (board[i][j] == board[i][j - 1])
            {
                board[i][j] *= 2;
                board[i][j - 1] = 0;
            }
        }
    }
}

bool exit_confirmation()
{
    string input;
    cout << "Confirm exit ?(Press Enter to confirm)";
    getline(cin, input);
    if (input.empty())
    {
        cout << "Exited." << endl;
        return false;
    }
    else
        return true;
}

bool input()
{
    char inp;
    cout << "Enter : ";
    cin >> inp;
    switch (inp)
    {
    case 'U':
    case 'u':
        shiftUp();
        mergeUp();
        shiftUp();
        break;

    case 'D':
    case 'd':
        shiftDown();
        mergeDown();
        shiftDown();
        break;

    case 'L':
    case 'l':
        shiftLeft();
        mergeLeft();
        shiftLeft();
        break;

    case 'R':
    case 'r':
        shiftRight();
        mergeRight();
        shiftRight();
        break;

    default:
        return exit_confirmation();
    }
    return true;
}
int main()
{
    cout << "Welcome to 2048!" << endl
         << "Controls are :" << endl
         << " 'U' = Move Up" << endl
         << " 'D' = Move Down" << endl
         << " 'L' = Move Left" << endl
         << " 'R' = Move Right" << endl
         << "Enter Anything else to exit." << endl;
    bool gameState = true;
    while (gameState)
    {

        spawnNumber();
        render();
        gameState = input();
    }
}