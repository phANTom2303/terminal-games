#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>


using namespace std;
int board[11][11] = {{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,}};

vector<int> snake = {33, 32, 31};

void place_berry()
{

    // AI Generated Code begins
    random_device rd;                       // obtain a random seed
    mt19937 gen(rd());                      // seed the random number generator
    uniform_int_distribution<> dis_i(1, 9); // distribution for x (1-13)
    uniform_int_distribution<> dis_j(1, 9); // distribution for y (1-18)
    int i = dis_i(gen);
    int j = dis_j(gen);
    // AI Generated code ends

    if (board[i][j] == 0)
        board[i][j] = 999;
    else
        place_berry();
}

void place_snake()
{
    int head_i = snake[0] / 10;
    int head_j = snake[0] % 10;
    board[head_i][head_j] = 99;

    for (int i = 1; i < snake.size() - 1; i++)
    {
        int piece_i = snake[i] / 10;
        int piece_j = snake[i] % 10;
        board[piece_i][piece_j] = 1;
    }

    int tail = snake[snake.size() - 1];
    int tail_i = tail / 10;
    int tail_j = tail % 10;
    board[tail_i][tail_j] = -99;
}

void render()
{
    cout << endl;
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            int e = board[i][j];
            if (e == -1)
            {
                if (i == 0 || i == 10)
                    cout << "-";
                else
                    cout << "|";
            }
            else if (e != 0 && e != -1)
            {
                if (e == 99)
                    cout << "H";
                if (e == -99)
                    cout << "T";
                if (e == 1)
                    cout << "#";
                if (e == 999)
                    cout << "0";
            }
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int  move_snake(char move)
{
    //'U' = up, 'D' = down , 'L' = left, 'R' = right
    int newhead = snake[0];
    switch (move)
    {
    case 'U':
    case 'u':
        newhead -= 10;
        break;

    case 'D':
    case 'd':
        newhead += 10;
        break;

    case 'L':
    case 'l':
        newhead -= 1;
        break;

    case 'R':
    case 'r':
        newhead += 1;
        break;

    default:
        return 0;
    }

    int new_head_i = newhead / 10;
    int new_head_j = newhead % 10;

    if (board[new_head_i][new_head_j] != 0 && board[new_head_i][new_head_j] != 999)
    {
        cout << "Oops, You collided. Game Over" << endl;
        render();
        return -1;
    }

    int grow_flag = 0;
    if (board[new_head_i][new_head_j] == 999)
    {
        snake.push_back(0);
        grow_flag = 1;
    }

    int tail = snake[snake.size() - 1];
    int tail_i = tail / 10;
    int tail_j = tail % 10;
    board[tail_i][tail_j] = 0;

    for (int i = snake.size() - 1; i > 0; i--)
        snake[i] = snake[i - 1];
    snake[0] = (new_head_i * 10) + new_head_j;
    place_snake();

    if (grow_flag == 1)
        place_berry();

    return 1;
}

int main()
{
    cout << "Welcome to Snake Xenxia!" << endl;
    cout << "Enter the following to move the snake : " << endl;
    cout << " 'U' = up" << endl
         << " 'D' = down" << endl
         << " 'L' = left" << endl
         << " 'R' = right" << endl;
    cout << "Enter anything else to Exit." << endl;
    place_snake();
    place_berry();
    render();
    while (true)
    {
        string input;
        cout << "Enter : ";
        cin >> input;
        int status = move_snake(input.at(0));
        if (status == 1)
            render();
        else if(status == -1)
            break;
        else
        {
            char cnf;
            cout << "Sure you wanna exit (Y/n) : ";
            cin >> cnf;
            if (cnf == 'Y' || cnf == 'y')
            {
                cout << "Exited." << endl;
                break;
            }
        }
    }
}