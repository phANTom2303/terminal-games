#include <iostream>
#include <vector>
using namespace std;

vector<int> arr = {0,5, 0, 3, 0, 2, 4, 0};

void shiftRight()
{
    int lastPos = arr.size() - 1;
    for(int i = arr.size() - 1; i>=0; i--)
    {
        int e = arr[i];
        if(e != 0)
        {
            arr[lastPos] = arr[i];
            if(lastPos != i)
                arr[i] = 0;
            lastPos--;
        }
    }
}

void display()
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    display();
    shiftRight();
    display();
}
