#include <iostream>
#include "../include/Employee.h"
#include "../include/HourlyEmployee.h"

int main () {
  Employee cEmployee;

  std::string cName, cSSN;

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

  return 0;
}