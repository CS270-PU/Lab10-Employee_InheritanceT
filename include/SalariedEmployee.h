#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include <iostream>
#include "Employee.h"

class SalariedEmployee : public Employee {
public:
  SalariedEmployee ();
  SalariedEmployee (const std::string& rcName,
    const std::string& rcSSN,
    double dSalary);

  double getSalary () const;
  double getWeeklyPay () const;

  void write (std::ostream& rcOutStream) const;
  bool read (std::istream& rcInStream);

private:
  double mdSalary;
};

#endif