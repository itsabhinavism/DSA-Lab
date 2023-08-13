#include <iostream>

// Function to check if a number is prime
bool isPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Function to calculate the sum of prime elements in an array
int sumOfPrimes(int *arr, int size)
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
    std::cout << "Enter size of the array: ";
    std::cin >> size;

    // Dynamically allocate memory for the array
    int *arr = new int[size];

    std::cout << "Enter array elements: ";
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    // Calculate the sum of prime elements in the array
    int sum = sumOfPrimes(arr, size);
    std::cout << "Sum = " << sum << std::endl;

    // Deallocate the memory for the array
    delete[] arr;

    return 0;
}
