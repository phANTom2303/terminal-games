#include <iostream>
using namespace std;
int board[6][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0}};

void render()
{
    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << " | ";
        for (int j = 0; j < 7; j++)
        {
            if (board[i][j] == 1)
                cout << "R | ";
            else if (board[i][j] == -1)
                cout << "Y | ";
            else
                cout << "_ | ";
        }
        cout << endl;
    }
    cout << endl;
}

int placePlayer(int colNum, int player)
{
    colNum = colNum - 1;
    int final_pos = -1;
    for (int i = 0; i < 6; i++)
    {
        if (board[i][colNum] == 0)
        {
            final_pos = i;
        }
        else
            break;
    }
    if (final_pos >= 0)
    {
        board[final_pos][colNum] = player;
    }
    return final_pos;
}

int row_freq(int row, int col)
{
    int player = board[row][col];
    int count = 1;
    for (int i = col + 1; i < 7; i++) // count to the right of the player
    {
        if (board[row][i] != player)
            break;
        count += 1;
    }

    for (int i = col - 1; i >= 0; i--) // counting to the left of player
    {
        if (board[row][i] != player)
            break;
        count += 1;
    }
    // cout << "Row =" << count << endl;
    return count;
}

int col_freq(int row, int col)
{
    int player = board[row][col];
    int count = 1;
    for (int i = row + 1; i < 6; i++) // count below the player
    {
        // if (board[i][col] == player)
        //     count += 1;
        // else
        //     break;
        if (board[i][col] != player)
            break;
        count += 1;
    }

    for (int i = row - 1; i >= 0; i--) // counting above the player
    {
        if (board[i][col] != player)
            break;
        count += 1;
    }
    // cout << "column =" << count << endl;
    return count;
}

int left_diagonal_freq(int row, int col)
{
    if ((row >= 3 && col <= 2) || (row <= 2 && col >= 4))
        return 0;

    int player = board[row][col];
    int count = 1;
    int i = row + 1;
    int j = col + 1;
    while (board[i][j] == player && i < 6 && j < 7) // counting in bottom right direction
    {
        count += 1;
        i++;
        j++;
    }

    i = row - 1;
    j = col - 1;

    while (board[i][j] == player && i >= 0 && j >= 0) // counting in top left direction
    {
        count += 1;
        i--;
        j--;
    }
    // cout << "left diag =" << count << endl;
    return count;
}

int right_diagonal_freq(int row, int col)
{
    if ((row <= 2 && col <= 2) || (row >= 3 && col >= 4))
        return 0;
    int player = board[row][col];
    int count = 1;
    int i = row + 1;
    int j = col - 1;
    while (board[i][j] == player && i < 6 && j >= 0) // counting in bottom left direction
    {
        count += 1;
        i++;
        j--;
    }

    i = row - 1;
    j = col + 1;

    while (board[i][j] == player && i >= 0 && j < 7) // counting in top right direction
    {
        count += 1;
        i--;
        j++;
    }
    // cout << "right diag" << count << endl;
    return count;
}

bool checkWin(int row, int col)
{
    col = col - 1;//since user input is 1 based indexing, we need to subtract 1
    int row_count = row_freq(row, col);
    int col_count = col_freq(row, col);
    int left_diag_count = left_diagonal_freq(row, col);
    int right_diag_count = right_diagonal_freq(row, col);

    if (row_count == 4 || col_count == 4 || left_diag_count == 4 || right_diag_count == 4)
        return true;
    else
        return false;
}

bool exit_confirmation()
{
    string input;
    cout << "Confirm exit ?(Press Enter to confirm)";
    getline(cin, input);
    if (input.empty())
    {
        cout << "Exited." << endl;
        return true;
    }
    else
        return false;
}

int main()
{

    int turn = 1;
    // 1 = R (red)
    // -1 = Y (yellow)
    for (int i = 1; i <= 42;)
    {
        int input = 0;
        cout << "Player " << ((turn == 1) ? "red (R) " : "yellow (Y) ") << "enter Column Number : ";
        cin >> input;
        if (input == 0)
        {
            bool confirmation = exit_confirmation();
            if (confirmation)
                break;
        }

        if (input < 0 || input > 7)
        {
            cout << "Invalid Input, Enter Again." << endl;
            continue;
        }

        int place_status = placePlayer(input, turn);

        if (place_status == -1)
        {
            cout << "This Column is full, enter another." << endl;
            continue;
        }

        render();
        bool win_status = checkWin(place_status, input);
        if (win_status)
        {
            cout << "Player " << ((turn == 1) ? "red (R) " : "yellow (Y) ") << "Wins!" << endl;
            break;
        }
        turn = turn * -1;
        i++;
    }
}