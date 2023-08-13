#include <iostream>
using namespace std;
bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int sumOfPrimeElements(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        if (isPrime(arr[i]))
        {
            sum += arr[i];
        }
    }
    return sum;
}

int main()
{
    int size;

    cout << "Enter size of the array: ";
    cin >> size;

    int *arr = new int[size];

    std::cout << "Enter array elements: ";
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    int primeSum = sumOfPrimeElements(arr, size);
    std::cout << "Sum = " << primeSum << std::endl;

    delete[] arr;

    return 0;
}
