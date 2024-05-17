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
            else if (e == -1)
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
    if (rsum == -3 || csum == -3 || d1 == -3 || d2 == -3)
        return -1;
    else if (rsum == 3 || csum == 3 || d1 == 3 || d2 == 3)
        return 1;
    else
        return 0;
}

int main()
{
    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "For each turn, enter row and column number (1 to 3)." << endl;
    cout << "To exit, enter 0 & 0" << endl;
    cout << "    1 | 2 | 3" << endl;
    cout << " 1  _ | _ | _" << endl;
    cout << " 2  _ | _ | _" << endl;
    cout << " 3  _ | _ | _" << endl;

    bool flag = true;
    int turn = -1;
    for (int i = 1; i <= 9;)
    {
        int r, c;
        cout << "Enter Row & Column for " << ((turn == 1) ? "X" : "O") << ":";
        cin >> r >> c;
        if(r == 0 || c == 0)
        {
            cout << "Exited."<<endl;
            return 0;
        }
        else if(r < 0 || c < 0 || r > 3 || c > 3)
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
        else
        {
            arr[r][c] = turn;
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
    }
    cout << "Stalemate" << endl;
}