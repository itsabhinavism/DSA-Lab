#include <iostream>
using namespace std;
void compareNumbers(int *num1, int *num2)
{
    if (*num1 < *num2)
    {
        cout << *num1 << " is smaller than " << *num2 << endl;
    }
    else if (*num1 > *num2)
    {
        cout << *num2 << " is smaller than " << *num1 << endl;
    }
    else
    {
        cout << "Both numbers are equal." << endl;
    }
}

int main()
{
    int num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    compareNumbers(&num1, &num2);

    return 0;
}
