#include <iostream>
using namespace std;
int arr[3][3];
void render()
{
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char c;
            int e = arr[i][j];
            if (e == 0)
                c = ' ';
            else if (e == 10)
                c = 'O';
            else
                c = 'X';
            cout << c << ((j < 2) ? " │ " : "");
        }
        cout << endl << ((i < 2) ? "──┼───┼──" : "") << endl;
    }
}

int check(int arr[][3], int r, int c)
{
    int rsum = 0, csum = 0, d1 = 0, d2 = 0;
    for (int i = 0; i < 3; i++)
    {
        rsum += arr[r][i];
        csum += arr[i][c];
        d1 += arr[i][i];
        d2 += arr[i][2 - i];
    }
    if (rsum == 30 || csum == 30 || d1 == 30 || d2 == 30)
        return -1;
    else if (rsum == 3 || csum == 3 || d1 == 3 || d2 == 3)
        return 1;
    else
        return 0;
}

// bot stuff V
bool winCheck(int arr[][3], int r, int c)
{
    int rsum = 0, csum = 0, d1 = 0, d2 = 0;
    for (int i = 0; i < 3; i++)
    {
        rsum += arr[r][i];
        csum += arr[i][c];
        d1 += arr[i][i];
        d2 += arr[i][2 - i];
    }
    if (rsum == 2 || csum == 2)
        return true;
    if (d1 == 2 && ((r == 0 && c == 0) || (r == 2 && c == 2)))
        return true;
    if (d2 == 2 && ((r == 0 && c == 2) || (r == 2 && c == 0)))
        return true;
    return false;
}

bool winBlockCheck(int arr[][3], int r, int c)
{
    int rsum = 0, csum = 0, d1 = 0, d2 = 0;
    for (int i = 0; i < 3; i++)
    {
        rsum += arr[r][i];
        csum += arr[i][c];
        d1 += arr[i][i];
        d2 += arr[i][2 - i];
    }
    if (rsum == 20 || csum == 20)
        return true;
    if (d1 == 20 && ((r == 0 && c == 0) || (r == 2 && c == 2)))
        return true;
    if (d2 == 20 && ((r == 0 && c == 2) || (r == 2 && c == 0)))
        return true;
    return false;
}

bool optimal(int arr[][3], int r, int c)
{
    int rsum = 0, csum = 0, d1 = 0, d2 = 0;
    for (int i = 0; i < 3; i++)
    {
        rsum += arr[r][i];
        csum += arr[i][c];
        d1 += arr[i][i];
        d2 += arr[i][2 - i];
    }
    if (rsum == 1 || csum == 1)
        return true;
    if (d1 == 1 && ((r == 0 && c == 0) || (r == 2 && c == 2)))
        return true;
    if (d2 == 1 && ((r == 0 && c == 2) || (r == 2 && c == 0)))
        return true;
    return false;
}

bool blockCheck(int arr[][3], int r, int c)
{
    int rsum = 0, csum = 0, d1 = 0, d2 = 0;
    for (int i = 0; i < 3; i++)
    {
        rsum += arr[r][i];
        csum += arr[i][c];
        d1 += arr[i][i];
        d2 += arr[i][2 - i];
    }
    if (rsum >= 10 || csum >= 10)
        return true;
    if (d1 >= 10 && ((r == 0 && c == 0) || (r == 2 && c == 2)))
        return true;
    if (d2 >= 10 && ((r == 0 && c == 2) || (r == 2 && c == 0)))
        return true;
    return false;
}

int bot()
{
    if (arr[1][1] == 0)
    {
        arr[1][1] = 1;
        return 22;
    }
    else
    {
        int score[3][3] = {1, 0, 1, 0, 0, 0, 1, 0, 1};
        int max = -1;
        int max_row = -1, max_col = -1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                score[i][j] = ((arr[i][j] != 0) ? -1 : score[i][j]);
                if (arr[i][j] == 0)
                {
                    if (winCheck(arr, i, j))
                    {
                        arr[i][j] = 1;
                        return ((i + 1) * 10) + (j+1);
                    }
                    if (winBlockCheck(arr, i, j))
                        score[i][j] += 100;
                    if (optimal(arr, i, j))
                        score[i][j] += 10;
                    if (blockCheck(arr, i, j))
                        score[i][j] += 1;

                    if (score[i][j] > max)
                    {
                        max = score[i][j];
                        max_row = i;
                        max_col = j;
                    }
                }
            }
        }
        return ((max_row + 1) * 10) + (max_col+1);
    }
}
// bot stuff ^

int main()
{
    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "You play first with O and bot plays with X." <<endl;
    cout << "For each turn, enter row and column number (1 to 3)." << endl;
    cout << "To exit, enter 0 & 0" << endl;
    cout << "    1 | 2 | 3" << endl;
    cout << " 1  _ | _ | _" << endl;
    cout << " 2  _ | _ | _" << endl;
    cout << " 3  _ | _ | _" << endl;

    bool flag = true;

    int turn = -1;
    // turn = -1: "O" : 10
    // turn = 1: "X" : 1

    for (int i = 1; i <= 9;)
    {
        int r, c;
        if (turn == -1)
        {
            cout << "Enter Row & Column for O :";
            cin >> r >> c;
            if (r == 0 || c == 0)
            {
                cout << "Exited." << endl;
                return 0;
            }
            else if (r < 0 || c < 0 || r > 3 || c > 3)
            {
                cout << "Invalid Input, Enter again." << endl;
                continue;
            }
            r--;
            c--;
            if (arr[r][c] != 0)
            {
                cout << "Place alrady occupied, try another input." << endl;
                continue;
            }
        }
        else
        {
            cout << "X's Turn : " << endl;
            int coords = bot();
            r = (coords / 10) - 1;
            c = (coords % 10) - 1;
        }
        arr[r][c] = ((turn == 1)?1:10);
        render();
        int res = check(arr, r, c);
        if (res != 0)
        {
            cout << ((res == 1) ? "X" : "O") << " wins" << endl;
            return 0;
        }
        turn *= -1;
        i++;
    }
    cout << "Stalemate" << endl;
}