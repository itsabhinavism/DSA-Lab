#include <iostream>
#include <vector>
using namespace std;

void comparenumbers(int num1, int num2, bool *IsNum1Smaller, bool *IsNum2Smaller)
{
    if (num1 < num2)
    {
        *IsNum1Smaller = true;
        *IsNum2Smaller = false;
    }

    else if (num2 > num1)
    {
        *IsNum1Smaller = false;
        *IsNum2Smaller = true;
    }

    else
    {
        *IsNum1Smaller = false;
        *IsNum2Smaller = false;
    }
}

int main()
{
    int num1, num2;
    bool IsNum1Smaller = false, IsNum2Smaller = false;
    cout << "Enter two numbers -\n";
    cin >> num1 >> num2;

    comparenumbers( num1, num2,&IsNum1Smaller, &IsNum2Smaller);
    if (IsNum1Smaller)
    {
        cout << num1 << " is smaller than " << num2<<"." << endl;
    }

    else if (IsNum2Smaller)
    {
        cout << num2 << " is smaller than " << num1 <<"."<< endl;
    }
    else
    {
        cout << "Both numbers are equal." << endl;
    }

    return 0;
}