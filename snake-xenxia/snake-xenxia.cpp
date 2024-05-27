#include <iostream>
#include <vector>
using namespace std;
int board[15][20] = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
                     {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};

vector<int> snake = {33, 32, 31};

void place_snake()
{
    int head_i = snake[0]/10;
    int head_j = snake[0]%10;
    board[head_i][head_j] = 99;

    for(int i = 1; i < snake.size() - 1; i ++)
    {
        int piece_i = snake[i]/10;
        int piece_j = snake[i]%10;
        board[piece_i][piece_j] = 1;
    }

    int tail = snake[snake.size() - 1];
    int tail_i = tail / 10;
    int tail_j = tail % 10;
    board[tail_i][tail_j] = -99;
}

void render()
{
    place_snake();
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            int e = board[i][j];
            if (e == -1)
            {
                if (i == 0 || i == 14)
                    cout << "-";
                else
                    cout << "|";
            }
            else if (e  != 0 && e != -1)
            {
                if(e == 99)
                    cout << "H";
                if(e == -99)
                    cout << "T";
                if(e == 1)
                    cout << "#";
        
            }
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;
    }
}

bool move_snake(char move)
{
    //'U' = up, 'D' = down , 'L' = left, 'R' = right
    int new_head_i = snake[0]/10;
    int new_head_j = snake[0]%10;
    switch (move)
    {
    case 'U':
        new_head_i -= 1;
        break;

    case 'D':
        new_head_i += 1;
        break;

    case 'L':
        new_head_j -= 1;
        break;

    case 'R':
        new_head_j += 1;
        break;

    default:
        return false;
    }
    
    int tail = snake[snake.size() - 1];
    int tail_i = tail / 10;
    int tail_j = tail % 10;
    board[tail_i][tail_j] = 0;

    
    for(int i = snake.size() - 1; i > 0; i --)
        snake[i] = snake[i - 1];
    snake[0] = (new_head_i*10) + new_head_j;

    
    return true;
}

// bool move_snake(char move)
// {
//     //'U' = up, 'D' = down , 'L' = left, 'R' = right
//     int new_head_i = head_i;
//     int new_head_j = head_j;
//     switch (move)
//     {
//     case 'U':
//         new_head_i -= 1;
//         break;

//     case 'D':
//         new_head_i += 1;
//         break;

//     case 'L':
//         new_head_j -= 1;
//         break;

//     case 'R':
//         new_head_j += 1;
//         break;

//     default:
//         return false;
//     }

//     board[new_head_i][new_head_j] = (head_i * 10) + head_j;

//     int iterator = board[head_i][head_j];
//     while (true)
//     {
//         int pos_i = iterator / 10;
//         int pos_j = iterator % 10;
//         if (board[pos_i][pos_j] == -7)
//         {
//             board[pos_i][pos_j] = 0;
//             break;
//         }
//         else
//         {
//             iterator = board[pos_i][pos_j];
//         }
//     }
//     render();
//     return true;
// }

int main()
{
    render();
    while(true)
    {
        char input;
        cout << "Enter : ";
        cin >> input;
        bool status = move_snake(input);
        if(status)
            render();
        else
            break;
    }
}