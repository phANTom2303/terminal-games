#include <bits/stdc++.h>
using namespace std;

int arr[10][10] = {0};
void render()
{
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] == 0)
                cout << "O ";
            else if (arr[i][j] == 1)
                cout << "\033[31mC\033[0m ";
            else if (arr[i][j] == 2)
                cout << "\033[32mA\033[0m ";
        }
        cout << endl;
    }
    cout << endl;
}

void setupCarrier()
{
    int xi, yi, xf, yf;
    cout << "Enter position of one end of your ship : ";
    cin >> xi >> yi;

    arr[xi][yi] = 1;
    if (xi + 4 < 10)
        arr[xi + 4][yi] = 2;
    if (xi - 4 >= 0)
        arr[xi - 4][yi] = 2;
    if (yi + 4 < 10)
        arr[xi][yi + 4] = 2;
    if (yi - 4 >= 0)
        arr[xi][yi - 4] = 2;

    cout << "chosen spot : " << xi << " " << yi;
    cout << "available spots " << endl;
    render();
    cout << "Enter your choice : ";
    cin >> xf >> yf;
}
int main()
{
    setupCarrier();
}