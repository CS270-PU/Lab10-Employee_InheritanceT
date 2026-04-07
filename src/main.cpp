#include <iostream>
#include "../include/Employee.h"
#include "../include/HourlyEmployee.h"
#include "../include/SalariedEmployee.h"

int main () {
  Employee cEmployee;

  std::string cName, cSSN;

    // ----- Employee test -----
  std::cout << "Enter name (single word): ";
  std::cin >> cName;

  std::cout << "Enter SSN: ";
  std::cin >> cSSN;

  cEmployee = Employee(cName, cSSN);

  std::cout << "\nEmployee entered:\n";
  cEmployee.write(std::cout);

  // ----- HourlyEmployee test -----
  HourlyEmployee cHourly;

  std::cout << "\nEnter hourly employee (name ssn wage hours): ";
  if (!cHourly.read(std::cin)) {
    std::cout << "Input error\n";
    return 1;
  }

  std::cout << "\nHourlyEmployee entered:\n";
  cHourly.write(std::cout);

  // ----- SalariedEmployee test -----
SalariedEmployee cSalaried;

std::cout << "\nEnter salaried employee (name ssn salary): ";
if (!cSalaried.read(std::cin)) {
  std::cout << "Input error\n";
  return 1;
}

std::cout << "\nSalariedEmployee entered:\n";
cSalaried.write(std::cout);

  return 0;
}