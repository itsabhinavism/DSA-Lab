#include <iostream>
using namespace std;
struct Complex {
    double real;
    double imaginary;
};

Complex addComplex(const Complex& num1, const Complex& num2) {
    Complex sum;
    sum.real = num1.real + num2.real;
    sum.imaginary = num1.imaginary + num2.imaginary;
    return sum;
}

void multiplyComplex(const Complex* num1, const Complex* num2, Complex* result) {
    result->real = (num1->real * num2->real) - (num1->imaginary * num2->imaginary);
    result->imaginary = (num1->real * num2->imaginary) + (num1->imaginary * num2->real);
}

int main() {
    Complex num1, num2, result;
    int choice;

    cout << "Enter complex number 1 (real imaginary): ";
    cin >> num1.real >> num1.imaginary;

    cout << "Enter complex number 2 (real imaginary): ";
    cin >> num2.real >> num2.imaginary;

    do {
        cout << "\nMENU" << std::endl;
        cout << "1. Addition" << std::endl;
        cout << "2. Multiplication" << std::endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                result = addComplex(num1, num2);
                cout << "Sum = " << result.real << "+" << result.imaginary << "i" << std::endl;
                break;
            case 2:
                multiplyComplex(&num1, &num2, &result);
                cout << "Product = " << result.real << "+" << result.imaginary << "i" << std::endl;
                break;
            default:
                cout << "Invalid choice." << std::endl;
                break;
        }
    } while (choice == 1 || choice == 2);

    return 0;
}
