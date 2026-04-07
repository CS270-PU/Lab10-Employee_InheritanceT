//******************************************************************************
// File name:    HourlyEmployee.cpp
// Author:       CS, Pacific University
// Class:        CS270
// Purpose:      Implementation of HourlyEmployee
//******************************************************************************

#include "HourlyEmployee.h"

// default constructor
HourlyEmployee::HourlyEmployee ()
  : Employee (), mdHourlyWage (0.0), mdHoursWorked (0.0) {
}

// parameterized constructor
HourlyEmployee::HourlyEmployee (const std::string& rcName,
                                const std::string& rcSSN,
                                double dHourlyWage,
                                double dHoursWorked)
  : Employee (rcName, rcSSN),
    mdHourlyWage (dHourlyWage),
    mdHoursWorked (dHoursWorked) {
}

// getters
double HourlyEmployee::getHourlyWage () const {
  return mdHourlyWage;
}

double HourlyEmployee::getHoursWorked () const {
  return mdHoursWorked;
}

double HourlyEmployee::getWeeklyPay () const {
  return mdHourlyWage * mdHoursWorked;
}

// write
void HourlyEmployee::write (std::ostream& rcOutStream) const {
  Employee::write(rcOutStream);
  rcOutStream << "Hourly Wage: " << mdHourlyWage << std::endl;
  rcOutStream << "Hours Worked: " << mdHoursWorked << std::endl;
  rcOutStream << "Weekly Pay: " << getWeeklyPay() << std::endl;
}

// read
bool HourlyEmployee::read (std::istream& rcInStream) {
  bool bSuccess = true;

  if (!Employee::read(rcInStream)) {
    bSuccess = false;
  }
  else if (!(rcInStream >> mdHourlyWage)) {
    bSuccess = false;
  }
  else if (!(rcInStream >> mdHoursWorked)) {
    bSuccess = false;
  }

  return bSuccess;
}