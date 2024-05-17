#include <bits/stdc++.h>
using namespace std;
int change = 1;
int board[100] = {0, 0, 117, 0, -22, 0, 0, 0, 0, 0,
                  130, 127, 0, 0, -20, -28, -34, 017, 0, 0,
                  -114, 139, -105, 0, 0, 0, 0, 011, -115, 0,
                  010, -46, 0, -70, -116, 161, 0, -51, 0, 02,
                  158, 0, 0, 0, 0, 154, -131, 0, 0, 0,
                  0, -137, 0, 0, 045, 0, 0, -81, 040, 0,
                  0, 035, 0, 0, 0, 0, 0, 0, 0, 193,
                  -133, 0, 0, 0, 0, 0, 183, -94, -98, 0,
                  0, -157, 0, 76, 196, 0, 0, 0, 0, 0,
                  0, 0, 0, 69, -177, 0, 84, 0, -178, 0};

struct player
{
    int pos;
    char piece;
    bool win_state;
};

player p[2];

void default_values()
{
    for (int i = 0; i < 2; i++)
    {
        p[i].pos = 0;
        p[i].piece = (i == 0) ? '@' : '&';
        p[i].win_state = false;
    }
}

void playerRender(int place)
{

    if (place == p[0].pos && place == p[1].pos)
        cout << "B";
    else if (place == p[0].pos)
        cout << p[0].piece;
    else if (place == p[1].pos)
        cout << p[1].piece;
    else
        cout << " ";
}

void placeRender(int i, int j)
{
    int val = (i * 10) + j;
    if (board[val] == 0)
        cout << "_";
    else
    {
        if (board[val] >= 100)
            cout << "L"; // L = Ladder
        else if (board[val] > 0)
            cout << "T"; // T = Top of a ladder
        else if (board[val] <= -100)
            cout << "S"; // S = Snake
        else if (board[val] < 0)
            cout << "E"; // E = End of a snake
    }
    playerRender(val);
    cout << "  ";
}

void render()
{
    cout << endl;
    for (int i = 9; i >= 0; i--)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < 10; j++)
                placeRender(i, j);
            cout << endl;
            for (int j = 0; j < 10; j++)
                cout << i << j << "  ";
        }
        else
        {
            for (int j = 9; j >= 0; j--)
                placeRender(i, j);
            cout << endl;
            for (int j = 9; j >= 0; j--)
                cout << i << j << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

int rollDice()
{
    // Seed the random number generator with current time
    srand(time(0));

    // Generate random number between 0 and RAND_MAX (implementation-defined)
    int random_number = rand();

    // Restrict the range to 1-6 using modulo (%) and add 1
    return (random_number % 6) + 1;
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

void positionUpdate(int p_num, int dice)
{
    int newpos = p[p_num].pos + dice;
    if (newpos == 99)
    {
        cout << "Player " << ((p_num == 0) ? "1" : "2") << " wins!" << endl;
        p[p_num].win_state = true;
    }
    else if (newpos < 99)
    {
        p[p_num].pos = newpos;
        cout << "Player " << ((p_num == 0) ? "1" : "2") << " moves to  " << p[p_num].pos << endl;
    }
    else
        cout << "You rolled extra, better luck next turn." << endl;
}

void jumpPlayer(int p_num)
{
    int value = board[p[p_num].pos];
    if (value >= 100 || value <= -100)
    {
        int destination = abs(value) % 100;
        if (value >= 100)
            cout << "You landed on a ladder to : " << destination << endl;
        else
            cout << "Uh Oh, A snake snake cought you, You will go to " << destination << endl;

        p[p_num].pos = destination;
        render();
    }
}

int main()
{
    string input;
    cout << "Welcome to Snakes and ladders!" << endl;
    cout << "Overview: " << endl;
    cout << "L = Ladder" << endl;
    cout << "T = Top of a ladder" << endl;
    cout << "S = Snake" << endl;
    cout << "E = End of a snake" << endl;
    cout << "@ = Player 1" << endl;
    cout << "& = Player 2" << endl;
    cout << "B = Both Players at same spot." << endl;
    cout << "-----------------------------------" << endl;
    cout << "Keep Pressing Enter to progress the game." << endl;
    cout << "Press any other key to exit." << endl;
    cout << "-----------------------------------" << endl;
    cout << "Press enter to begin...";
    getline(cin, input);
    int turn = 0;
    if (input.empty())
    {
        default_values();
        render();
        while (p[0].win_state == false && p[1].win_state == false)
        {
            cout << "Press enter to roll Dice for Player " << ((turn == 0) ? "1" : "2") << "...";
            getline(cin, input);
            if (input.empty() == false)
            {
                bool confirm = exit_confirmation();
                if (confirm)
                    return 0;
            }
            int dice = rollDice();
            cout << "Player " << ((turn == 0) ? "1" : "2") << " rolled a " << dice << endl;
            positionUpdate(turn, dice);
            render();
            if (board[p[turn].pos] != 0)
                jumpPlayer(turn);
            turn = (turn == 0) ? 1 : 0;
        }
    }
}