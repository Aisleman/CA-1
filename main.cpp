#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct Employee
{
    int id;
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

        getline(ss, value, ','); employee.id = stoi(value);
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
        cout << left << setw(10) << employee.id
                     << setw(20) << employee.name
                     << setw(20) << employee.department
                     << setw(10) << employee.age
                     << setw(10) << employee.salary << endl;
        cout << string(70, '-') << endl;
    }
}

int searchByID(const vector<Employee> &employees, int id)
{
    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void displayEmployeeByID(const vector<Employee> &employees, int id)
{
    int index = searchByID(employees, id);
    if (index == -1)
    {
        cout << "Employee not found" << endl;
    }
    else
    {
        cout << "Employee Information" << endl;
        cout << left << setw(10) << "ID"
                     << setw(20) << "Name"
                     << setw(20) << "Department"
                     << setw(10) << "Age"
                     << setw(10) << "Salary" << endl;
        cout << string(70, '-') << endl;

        cout << left << setw(10) << employees[index].id
                     << setw(20) << employees[index].name
                     << setw(20) << employees[index].department
                     << setw(10) << employees[index].age
                     << setw(10) << employees[index].salary << endl;
        cout << string(70, '-') << endl;
    }
}

map<string, int> countByDepartment(const vector<Employee> &employees)
{
    map<string, int> departmentCount;
    for (const auto& employee : employees)
    {
        departmentCount[employee.department]++;
    }
    return departmentCount;
}

void displayDepartmentCount(const map<string, int> &departmentCount)
{
    cout << "Department Count" << endl;
    cout << left << setw(20) << "Department"
                 << setw(10) << "Count" << endl;
    cout << string(30, '-') << endl;

    for (const auto& [department, count] : departmentCount)
    {
        cout << left << setw(20) << department
                     << setw(10) << count << endl;
        cout << string(30, '-') << endl;
    }
}

void displayByDepartment(const vector<Employee> &employees, const string& department)
{
    cout << "Employee List by Department" << endl;
    cout << left << setw(10) << "ID"
                 << setw(20) << "Name"
                 << setw(20) << "Department"
                 << setw(10) << "Age"
                 << setw(10) << "Salary" << endl;
    cout << string(70, '-') << endl;

    for (const auto& employee : employees)
    {
        if (employee.department == department)
        {
            cout << left << setw(10) << employee.id
                         << setw(20) << employee.name
                         << setw(20) << employee.department
                         << setw(10) << employee.age
                         << setw(10) << employee.salary << endl;
            cout << string(70, '-') << endl;
        }
    }
}

void displayStatsByAge(const vector<Employee> &employees, Employee& youngest, Employee& oldest)
{
    if (employees.empty())
    {
        cout << "No employees found" << endl;
    }

    youngest = employees[0];
    oldest = employees[0];
    int totalAge = 0;

    for (const auto& employee : employees)
    {
        totalAge += employee.age;
        if (employee.age < youngest.age)
        {
            youngest = employee;
        }
        if (employee.age > oldest.age)
        {
            oldest = employee;
        }
    }

    cout << "Oldest Employee" << endl;
    cout << "ID: " << oldest.id
         <<", Name: " << oldest.name
         << ", Department: " << oldest.department
         << ", Age: " << oldest.age
         << ", Salary: " << oldest.salary << endl;

    cout << "Youngest Employee" << endl;
    cout << "ID: " << youngest.id
         <<", Name: " << youngest.name
         << ", Department: " << youngest.department
         << ", Age: " << youngest.age
         << ", Salary: " << youngest.salary << endl;

    cout << "Average Age: " << totalAge / employees.size() << endl;
}

vector<Employee> searchEmployeesByName(const vector<Employee> &employees, const string& name)
{
    vector<Employee> result;
    for (const auto& employee : employees)
    {
        if (employee.name == name)
        {
            result.push_back(employee);
        }
    }
    return result;
}

void displaySearchResults(const vector<Employee> &employees, const vector<Employee> &result)
{
    if (result.empty())
    {
        cout << "No employees found" << endl;
        return;
    }
    else {
        cout << "Search Results" << endl;
        cout << left << setw(10) << "ID"
                     << setw(20) << "Name"
                     << setw(20) << "Department"
                     << setw(10) << "Age"
                     << setw(10) << "Salary" << endl;
        cout << string(70, '-') << endl;

        for (const auto& employee : result)
        {
            cout << left << setw(10) << employee.id
                         << setw(20) << employee.name
                         << setw(20) << employee.department
                         << setw(10) << employee.age
                         << setw(10) << employee.salary << endl;
            cout << string(70, '-') << endl;
        }
    }
}

void sortEmployeesBySalary(vector<Employee> &employees)
{
    sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
        return a.salary < b.salary;
    });
}

void displaySortedEmployees(const vector<Employee> &employees)
{
    cout << "Employee List Sorted by Salary" << endl;
    cout << left << setw(10) << "ID"
                 << setw(20) << "Name"
                 << setw(20) << "Department"
                 << setw(10) << "Age"
                 << setw(10) << "Salary" << endl;
    cout << string(70, '-') << endl;

    for (const auto& employee : employees)
    {
        cout << left << setw(10) << employee.id
                     << setw(20) << employee.name
                     << setw(20) << employee.department
                     << setw(10) << employee.age
                     << setw(10) << employee.salary << endl;
        cout << string(70, '-') << endl;
    }
}
int main()
{
    vector<Employee> employees;
    getEmployeesFromCSV("employee.csv", employees);
    display(employees);
    displayEmployeeByID(employees, searchByID(employees, 17));
    displayDepartmentCount(countByDepartment(employees));
    displayByDepartment(employees, "HR");
    Employee youngest, oldest;
    displayStatsByAge(employees, youngest, oldest);
    displaySearchResults(employees, searchEmployeesByName(employees, "John"));
    sortEmployeesBySalary(employees);
    displaySortedEmployees(employees);
    return 0;
}