#include <iostream>
using namespace std;
void statusBars(int hp, int totHp, int ssHp, int totssHp, int fuel, int totFuel)
{
    string arr[3] = {"Health:", "Space Suit Health:", "Fuel tank:"};
    int val[3] = {hp, ssHp, fuel};
    int max[3] = {totHp, totssHp, totFuel};
    double percent;
    for (int i = 0; i < 3; i++)
    {
        percent = double(val[i]) / max[i] * 100;
        cout << arr[i] << endl;
        for (int j = 1; j <= 20; j++)
        {
            if (percent >= j * 5)
            {
                cout << "_";
            }
            else
            {
                cout << " ";
            }
        }
        cout << " " << percent << "%" << endl;
    }
}

int main()
{
    statusBars(40, 100, 14, 20, 200000, 400000);
}