#include <bits/stdc++.h>
using namespace std;

const char carrier = 'A';
const char battleship = 'B';
const char cruiser = 'C';
const char submarine = 'S';
const char destroyer = 'D';

struct player
{
  int board[10][10] = {0};
  int totalShips = 5;

  int car_health = 5;
  int batt_health = 4;
  int cru_health = 3;
  int sub_health = 3;
  int des_health = 2;

  int moves = 0;
  int hits = 0;
  int misses = 0;

} p[2];

bool validateIndices(int x, int y)
{
  if (x >= 0 && x <= 9 && y >= 0 && y <= 9)
    return true;
  else
    return false;
}
int getShipLength(char ship)
{
  switch (ship)
  {
  case 'A':
    return 5;

  case 'B':
    return 4;

  case 'C':
    return 3;

  case 'S':
    return 3;

  case 'D':
    return 2;
  }
  return 0;
}

string getShipName(char ship)
{
  switch (ship)
  {
  case 'A':
    return "Aircraft Carrier";

  case 'B':
    return "Battleship";

  case 'C':
    return "Cruiser";

  case 'S':
    return "Submarine";

  case 'D':
    return "Destroyer";
  }
  return "No Ship";
}

void render(int player)
{
  cout << endl;
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (p[player].board[i][j] == 0)
        cout << "O ";
      else if (p[player].board[i][j] == 1)
        cout << "\033[31mC\033[0m ";
      else if (p[player].board[i][j] == 2)
        cout << "\033[32mA\033[0m ";
      else if (p[player].board[i][j] == 10)
        cout << "\033[32mA\033[0m ";
    }
    cout << endl;
  }
  cout << endl;
}

void cleanUp(int player)
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (p[player].board[i][j] == 1 || p[player].board[i][j] == 2)
        p[player].board[i][j] = 0;
    }
  }
}

void setUpShip(char ship, int p)
{
  string shipName = getShipName(ship);
  int shipLen = getShipLength(ship);

  int xi, yi;
  cout << "Enter initial X and Y coords : ";
  cin >> xi >> yi;

  cout << "Entered Position :  ( " << xi << " , " << yi << " )" << endl;
  cout << "Available Postions : " << endl;

  int total = 0;

  for (int i = 0; i < shipLen; i++)
  {
  }
}

void setupCarrier(int player)
{
  int xi, yi, xf, yf;
  bool flag = false;
  while (!flag)
  {
    cout << "Enter position of one end of your ship : ";
    cin >> xi >> yi;
    flag = validateIndices(xi, yi);
    if (!flag)
      cout << "Invalid Input, enter again " << endl;
  }

  p[player].board[xi][yi] = 1;
  if (xi + 4 < 10)
    p[player].board[xi + 4][yi] = 2;
  if (xi - 4 >= 0)
    p[player].board[xi - 4][yi] = 2;
  if (yi + 4 < 10)
    p[player].board[xi][yi + 4] = 2;
  if (yi - 4 >= 0)
    p[player].board[xi][yi - 4] = 2;

  cout << "chosen spot : " << xi << " " << yi;
  cout << "available spots " << endl;
  render(player);

  flag = false;
  while (!flag)
  {
    cout << "Enter your choice : ";
    cin >> xf >> yf;
    flag = validateIndices(xf, yf);
    if (!flag)
      cout << "Invalid Input, enter again " << endl;
  }

  if (xi == xf)
  {
    if (yi < yf)
      for (int i = yi; i <= yf; i++)
        p[player].board[xi][i] = 10;
    else
      for (int i = yf; i >= yi; i--)
        p[player].board[xi][i] = 10;
  }
  else
  {
    if (xi < xf)
      for (int i = xi; i <= xf; i++)
        p[player].board[i][yi] = 10;
    else
      for (int i = xf; i >= xi; i--)
        p[player].board[i][yi] = 10;
  }
  cleanUp(player);
  render(player);
}

int main()
{
  setupCarrier(0);
}
