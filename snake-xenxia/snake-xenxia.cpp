#include <iostream>
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

int head_i = 3;
int head_j = 4;

bool move_snake(char move)
{
    //'U' = up, 'D' = down , 'L' = left, 'R' = right
    int new_head_i = head_i;
    int new_head_j = head_j;
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

    int iterator = board[head_i][head_j];
    while (iterator > 0)
    {
        int pos_i = iterator / 10;
        int pos_j = iterator % 10;
        
    }
}

void render()
{
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
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;
    }
}
int main()
{
    render();
    return 0;
}