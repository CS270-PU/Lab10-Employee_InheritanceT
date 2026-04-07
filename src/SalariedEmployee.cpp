#include "SalariedEmployee.h"

// default constructor
SalariedEmployee::SalariedEmployee ()
  : Employee (), mdSalary (0.0) {
}

// parameterized constructor
SalariedEmployee::SalariedEmployee (const std::string& rcName,
                                    const std::string& rcSSN,
                                    double dSalary)
  : Employee (rcName, rcSSN), mdSalary (dSalary) {
}

// getters
double SalariedEmployee::getSalary () const {
  return mdSalary;
}

double SalariedEmployee::getWeeklyPay () const {
  return mdSalary / 52.0;
}

// write
void SalariedEmployee::write (std::ostream& rcOutStream) const {
  Employee::write(rcOutStream);
  rcOutStream << "Salary: " << mdSalary << std::endl;
  rcOutStream << "Weekly Pay: " << getWeeklyPay() << std::endl;
}

// read
bool SalariedEmployee::read (std::istream& rcInStream) {
  bool bSuccess = true;

  if (!Employee::read(rcInStream)) {
    bSuccess = false;
  }
  else if (!(rcInStream >> mdSalary)) {
    bSuccess = false;
  }

  return bSuccess;
}