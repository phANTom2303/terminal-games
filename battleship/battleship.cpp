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

void renderBoard(int player)
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

void clearBoard(int player)
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

// void setUpShip(char ship, int p)
// {
//   string shipName = getShipName(ship);
//   int shipLen = getShipLength(ship);

//   int initialX, initialY;
//   cout << "Enter initial X and Y coords : ";
//   cin >> initialX >> initialY;

//   cout << "Entered Position :  ( " << initialX << " , " << initialY << " )" << endl;
//   cout << "Available Postions : " << endl;

//   int total = 0;

//   for (int i = 0; i < shipLen; i++)
//   {
//   }
// }

void setupCarrier(int player)
{
  int initialX, initialY, finalX, finalY;
  bool flag = false;
  while (!flag)
  {
    cout << "Enter position of one end of your ship : ";
    cin >> initialX >> initialY;
    flag = validateIndices(initialX, initialY);
    if (!flag)
      cout << "Invalid Input, enter again " << endl;
  }

  p[player].board[initialX][initialY] = 1;

  int verticalMovement[] = {-1, 0, 1, 0};
  int horizontalMovement[] = {0, 1, 0, -1};
  int direction = 0; // 0 -> top 1 -> right 2 -> bottom 3 -> left

  vector<int> directions;
  if (initialY - 4 >= 0) // top
    directions.push_back(0);
  if (initialX + 4 < 10) // right
    directions.push_back(1);
  if (initialY + 4 < 10) // bottom
    directions.push_back(2);
  if (initialX - 4 >= 0) // left
    directions.push_back(3);

  for (int j = 0; j < directions.size(); j++)
  {
    direction = directions[j];
    flag = true;
    for (int i = 1; i < 5; i++)
    {
      int x_coord = initialX + (i * verticalMovement[direction]);
      int y_coord = initialY + (i * horizontalMovement[direction]);
      if (p[player].board[x_coord][y_coord] != 0)
      {
        flag = false;
        break;
      }
    }

    if (flag)
      p[player].board[initialX + 4][initialY] = 2;
  }

  cout << "chosen spot : " << initialX << " " << initialY;
  cout << "available spots " << endl;
  renderBoard(player);

  flag = false;
  while (!flag)
  {
    cout << "Enter your choice : ";
    cin >> finalX >> finalY;
    flag = validateIndices(finalX, finalY);
    if (!flag)
      cout << "Invalid Input, enter again " << endl;
  }

  // horizontal movement
  if (initialX == finalX)
  {
    cout << "horizontal" << endl;
    if (finalY < initialY)
      // left
      direction = 3;
    else // right
      direction = 1;
  }
  else
  {
    cout << "vertical" << endl;
    if (finalX < initialX) // up
      direction = 0;
    else // down
      direction = 2;
  }

  for (int i = 0; i < 5; i++)
  {
    int x_coord = initialX + (i * verticalMovement[direction]);
    int y_coord = initialY + (i * horizontalMovement[direction]);
    p[player].board[x_coord][y_coord] = 10;
  }
  clearBoard(player);
  renderBoard(player);
}

int main()
{
  setupCarrier(0);
}
