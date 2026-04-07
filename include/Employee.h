#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
public:
  Employee ();
  Employee (const std::string& rcName, const std::string& rcSSN);

  std::string getName () const;
  std::string getSSN () const;

  void write (std::ostream& rcOutStream) const;
  bool read (std::istream& rcInStream);

private:
  std::string mcName, mcSSN;
};

#endif