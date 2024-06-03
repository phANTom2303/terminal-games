#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

vector<vector<int>> board = {{0, 0, 0, 0},
                             {0, 2, 0, 0},
                             {2, 0, 2048, 0},
                             {0, 2, 0, 0}};

string line = "";
string topLine = " ┌──────┬──────┬──────┬──────┐";
string midLine = " ├──────┼──────┼──────┼──────┤";
string bottomLine = " └──────┴──────┴──────┴──────┘";

void buildLine()
{
    for (int i = 1; i <= 31; i++)
        line = line + "─";
}
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
             << ((i<3)?midLine:bottomLine) 
             << endl;
    }
}

int main()
{
    buildLine();
    render();
    return 0;
}