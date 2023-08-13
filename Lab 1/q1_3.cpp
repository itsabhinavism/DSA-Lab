#include <iostream>
using namespace std;

struct Employee
{
    string name;
    string designation;
    double basicSalary;
    double hraPercentage;
    double daPercentage;
    double grossSalary;
};

void calculateGrossSalary(Employee &emp)
{
    double hraAmount = emp.basicSalary * (emp.hraPercentage / 100);
    double daAmount = emp.basicSalary * (emp.daPercentage / 100);
    double grossSalary = emp.basicSalary + hraAmount + daAmount;
    emp.grossSalary = grossSalary;
}

int main()
{
    int numEmployees;

    cout << "Enter no. of employees: ";
    cin >> numEmployees;

    Employee employees[numEmployees];

    for (int i = 0; i < numEmployees; ++i)
    {
        cout << "Enter employee " << i + 1 << " information:" << endl;
        cout << "Name: ";
        cin >> employees[i].name;
        cout << "Designation: ";
        cin >> employees[i].designation;
        cout << "Basic Salary: ";
        cin >> employees[i].basicSalary;
        cout << "HRA %: ";
        cin >> employees[i].hraPercentage;
        cout << "DA %: ";
        cin >> employees[i].daPercentage;

        calculateGrossSalary(employees[i]);
    }

    cout << "Employee Information:" << endl;
    for (int i = 0; i < numEmployees; ++i)
    {
        cout << "Name: " << employees[i].name << endl;
        cout << "Designation: " << employees[i].designation << endl;
        cout << "Basic Salary: " << employees[i].basicSalary << endl;
        cout << "HRA %: " << employees[i].hraPercentage << "%" << endl;
        cout << "DA %: " << employees[i].daPercentage << "%" << endl;
        cout << "Gross Salary: " << employees[i].grossSalary << endl
             << endl;
    }

    return 0;
}
