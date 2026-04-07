#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <string>
#include <iostream>
#include "Employee.h"

class HourlyEmployee : public Employee {
public:
  HourlyEmployee ();
  HourlyEmployee (const std::string& rcName, const std::string& rcSSN,
                  double dHourlyWage, double dHoursWorked);

  double getHourlyWage () const;
  double getHoursWorked () const;
  double getWeeklyPay () const;

  void write (std::ostream& rcOutStream) const;
  bool read (std::istream& rcInStream);

private:
  double mdHourlyWage;
  double mdHoursWorked;
};

#endif