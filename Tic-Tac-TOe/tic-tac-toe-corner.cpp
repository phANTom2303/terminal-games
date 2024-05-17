#include <iostream>
using namespace std;
int arr[3][3];
void render()
{
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
            cout << c << ((j < 2) ? " | " : "");
        }
        cout << endl;
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

int scoreFinder(int arr[][3], int r, int c)
{
    int rsum = 0, csum = 0, d1 = 0, d2 = 0;
    int s = 0;
    for (int i = 0; i < 3; i++)
    {
        rsum += arr[r][i];
        csum += arr[i][c];
        d1 += arr[i][i];
        d2 += arr[i][2 - i];
    }
    // for winning condition, return directly:
    if (rsum == 2 || csum == 2)
        return 1000;
    else if (d1 == 2 && r == c)
        return 1000;
    else if (d2 == 2 && (r + c == 2))
        return 1000;

    // for other conditions, evaluate first, then return.
    // checking to block player's victory:
    if (rsum == 20)
        s += 100;
    if (csum == 20)
        s += 100;
    if (d1 == 20 && r == c)
        s += 100;
    if (d2 == 20 && (r + c == 2))
        s += 100;

    // checking for 2 space + 1 X:
    if (rsum == 1)
        s += 10;
    if (csum == 1)
        s += 10;
    if (d1 == 1 && (r == c))
        s += 10;
    if (d2 == 1 &&  (r + c == 2))
        s += 10;

    // checking for blocking:
    if (rsum >= 10)
        s += 1;
    if (csum >= 10)
        s += 1;
    if (d1 >= 10 && (r == c))
        s += 2;
    if (d2 >= 10 &&  (r + c == 2))
        s += 2;

    return s;
}

int bot(int turn)
{
    int score[3][3] = {{1, 0, 1}, {0, 2, 0}, {1, 0, 1}};
    int max = -1;
    int max_row = -1, max_col = -1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            score[i][j] = ((arr[i][j] != 0) ? -1 : score[i][j]);
            if (arr[i][j] == 0)
            {
                score[i][j] += scoreFinder(arr, i, j);
                if (score[i][j] >= 1000)
                    return ((i + 1) * 10) + (j + 1);
            }
            else
            {
                // proximity score for corner opening.
                if (turn == 2)
                {
                    if (i == 0 && j == 0)
                        score[i + 2][j] += 5;
                    else if (i == 0 && j == 2)
                        score[i + 2][j] += 5;
                    else if (i == 2 && j == 0)
                        score[i - 2][j] += 5;
                    else if (i == 2 && j == 2)
                        score[i - 2][j] += 5;
                }
            }
        }
    }
    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 3; j ++)
        {
            if(score[i][j] > max)
            {
                max = score[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }
    return ((max_row + 1) * 10) + (max_col + 1);
}
// bot stuff ^

int main()
{
    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "You play first with O and bot plays with X." << endl;
    cout << "For each turn, enter row and column number (1 to 3)." << endl;
    cout << "To exit, enter 0 & 0" << endl;
    cout << "    1 | 2 | 3" << endl;
    cout << " 1  _ | _ | _" << endl;
    cout << " 2  _ | _ | _" << endl;
    cout << " 3  _ | _ | _" << endl;

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
            int coords = bot(i);
            r = (coords / 10) - 1;
            c = (coords % 10) - 1;
        }
        arr[r][c] = ((turn == 1) ? 1 : 10);
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