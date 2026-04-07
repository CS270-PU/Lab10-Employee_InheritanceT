#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "../include/Employee.h"
#include "../include/HourlyEmployee.h"
#include "../include/SalariedEmployee.h"

int main () {
  int nStatus = 0;

  Employee cEmployee;
  HourlyEmployee cHourlyEmployee;
  SalariedEmployee cSalariedEmployee;

  std::vector<HourlyEmployee> cHourlyEmployeeList;
  std::vector<SalariedEmployee> cSalariedEmployeeList;

  std::string cName, cSSN;

  // ----- Employee test -----
  std::cout << "Enter name (single word): ";
  std::cin >> cName;

  std::cout << "Enter SSN: ";
  std::cin >> cSSN;

  cEmployee = Employee (cName, cSSN);

  std::cout << "\nEmployee entered:\n";
  cEmployee.write (std::cout);

  // ----- HourlyEmployee test -----
  std::cout << "\nEnter hourly employee (name ssn wage hours): ";
  if (!cHourlyEmployee.read (std::cin)) {
    std::cout << "Input error\n";
    nStatus = 1;
  }
  else {
    std::cout << "\nHourlyEmployee entered:\n";
    cHourlyEmployee.write (std::cout);
  }

  // ----- SalariedEmployee test -----
  if (0 == nStatus) {
    std::cout << "\nEnter salaried employee (name ssn salary): ";
    if (!cSalariedEmployee.read (std::cin)) {
      std::cout << "Input error\n";
      nStatus = 1;
    }
    else {
      std::cout << "\nSalariedEmployee entered:\n";
      cSalariedEmployee.write (std::cout);
    }
  }

  // ----- Read in all employee information from file -----
  if (0 == nStatus) {
    std::ifstream rcInFile ("data/employee_data.txt");

    if (!rcInFile) {
      std::cout << "Error opening file\n";
      nStatus = 1;
    }
    else {
      char cType;

      while (0 == nStatus && rcInFile >> cType) {
        if ('H' == cType) {
          HourlyEmployee cHourlyEmployeeFromFile;

          if (!cHourlyEmployeeFromFile.read (rcInFile)) {
            std::cout << "Error reading hourly employee\n";
            nStatus = 1;
          }
          else {
            cHourlyEmployeeList.push_back (cHourlyEmployeeFromFile);
          }
        }
        else if ('S' == cType) {
          SalariedEmployee cSalariedEmployeeFromFile;

          if (!cSalariedEmployeeFromFile.read (rcInFile)) {
            std::cout << "Error reading salaried employee\n";
            nStatus = 1;
          }
          else {
            cSalariedEmployeeList.push_back (cSalariedEmployeeFromFile);
          }
        }
        else {
          std::cout << "Invalid employee type\n";
          nStatus = 1;
        }
      }
    }
  }

  // ----- Report totals after all data has been read -----
  if (0 == nStatus) {
    int nHourlyEmployees = cHourlyEmployeeList.size ();
    int nSalariedEmployees = cSalariedEmployeeList.size ();
    int nTotalEmployees = nHourlyEmployees + nSalariedEmployees;

    std::cout << "\nTotals:\n";
    std::cout << "Total Employees: " << nTotalEmployees << std::endl;
    std::cout << "Hourly Employees: " << nHourlyEmployees << std::endl;
    std::cout << "Salaried Employees: " << nSalariedEmployees << std::endl;
  }

  // ----- Use range based for loops to output total weekly pay -----
  double dTotalPayroll = 0.0;

  for (const HourlyEmployee& cHourlyEmployee : cHourlyEmployeeList) {
    dTotalPayroll += cHourlyEmployee.getWeeklyPay ();
  }

  for (const SalariedEmployee& cSalariedEmployee : cSalariedEmployeeList) {
    dTotalPayroll += cSalariedEmployee.getWeeklyPay ();
  }

  std::cout << std::fixed << std::setprecision (2);
  std::cout << "Total Weekly Payroll: $" << dTotalPayroll << std::endl;

  // ----- Top weekly earner -----
  double dTopWeeklyPay = 0.0;
  std::string cTopEmployeeName = "";
  std::string cTopEmployeeType = "";

  for (const HourlyEmployee& cHourlyEmployee : cHourlyEmployeeList) {
    if (cHourlyEmployee.getWeeklyPay () > dTopWeeklyPay) {
      dTopWeeklyPay = cHourlyEmployee.getWeeklyPay ();
      cTopEmployeeName = cHourlyEmployee.getName ();
      cTopEmployeeType = "Hourly";
    }
  }

  for (const SalariedEmployee& cSalariedEmployee : cSalariedEmployeeList) {
    if (cSalariedEmployee.getWeeklyPay () > dTopWeeklyPay) {
      dTopWeeklyPay = cSalariedEmployee.getWeeklyPay ();
      cTopEmployeeName = cSalariedEmployee.getName ();
      cTopEmployeeType = "Salaried";
    }
  }

  std::cout << "Top Weekly Earner: " << cTopEmployeeName << std::endl;
  std::cout << "Employee Type: " << cTopEmployeeType << std::endl;
  std::cout << "Weekly Pay: " << dTopWeeklyPay << std::endl;

  return nStatus;
}