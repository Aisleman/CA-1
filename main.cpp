#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct Employee
{
    int employeeId;
    string name;
    string department;
    int age;
    double salary;
};

void getEmployeesFromCSV(const string& filename, vector<Employee> &employees)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error: file not found" << endl;
        return;
    }

    string line;
    bool firstLine = true;

    while (getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue;;
        }

        stringstream ss(line);
        Employee employee;
        string value;

        getline(ss, value, ','); employee.employeeId = stoi(value);
        getline(ss, employee.name, ',');
        getline(ss, employee.department, ',');
        getline(ss, value, ','); employee.age = stoi(value);
        getline(ss, value, ','); employee.salary = stod(value);

        employees.push_back(employee);
    }
    file.close();
}
void display(const vector<Employee> &employees)
{
    cout << "Employee List" << endl;
    cout << left << setw(10) << "ID"
                 << setw(20) << "Name"
                 << setw(20) << "Department"
                 << setw(10) << "Age"
                 << setw(10) << "Salary" << endl;
    cout << string(70, '-') << endl;

    for (const auto& employee : employees)
    {
        cout << left << setw(10) << employee.employeeId
                     << setw(20) << employee.name
                     << setw(20) << employee.department
                     << setw(10) << employee.age
                     << setw(10) << employee.salary << endl;
        cout << string(70, '-') << endl;
    }
}

void searchByAge(const vector<Employee> &employees, int age)
{
    for (const Employee &employee : employees)
    {
        if (employee.age == age)
        {
            cout << "Employee ID: " << employee.employeeId << endl;
            cout << "Name: " << employee.name << endl;
            cout << "Department: " << employee.department << endl;
            cout << "Age: " << employee.age << endl;
            cout << "Salary: " << employee.salary << endl;
            cout << endl;
        }
    }

}
int main()
{
    vector<Employee> employees;
    getEmployeesFromCSV("employee.csv", employees);
    display(employees);
}