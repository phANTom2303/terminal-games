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
        cout << "Player placed = " << player << endl;
    }
    return final_pos;
}

int row_freq(int row, int col, int player)
{
    // int player = board[row][col];
    col = col -1;
    int count = 1;
    int right_count = 0;
    cout << "Player = " << player << endl;
    for (int i = col + 1; i < 7; i++) // count to the right of the player
    {
        
        if (board[row][i] != player)
            break;
        right_count  += 1;
        cout << "Current place = " << board[row][i] << " rc = " << right_count << endl;
    }
    cout <<   "Count to the right = " << right_count << endl;
    int left_count = 0;
    for (int i = col - 1; i >= 0; i--) // counting to the left of player
    {
        if (board[row][i] != player)
            break;
        left_count += 1;
        cout << "Current place = " << board[row][i] << " lc = " << left_count << endl;
    }
    cout << "Count to the left = " << left_count << endl;
    return count + right_count + left_count;
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
        int rc = row_freq(place_status,input,turn);
        cout << "Row Freq = " <<rc << endl;
        turn = turn * -1;
        i++;
    }
}