#include "../include/Employee.h"
#include <iostream>

// default constructor
Employee::Employee () : mcName (""), mcSSN ("") {
}

// parameterized constructor
Employee::Employee (const std::string& rcName,
                    const std::string& rcSSN)
  : mcName (rcName), mcSSN (rcSSN) {
}

// getters
std::string Employee::getName () const {
  return mcName;
}

std::string Employee::getSSN () const {
  return mcSSN;
}

// write to output stream
void Employee::write (std::ostream& rcOutStream) const {
  rcOutStream << "Name: " << mcName << std::endl;
  rcOutStream << "SSN: " << mcSSN << std::endl;
}

// read from input stream
bool Employee::read (std::istream& rcInStream) {
  bool bSuccess = true;

  if (!(rcInStream >> mcName)) {
    bSuccess = false;
  }
  else if (!(rcInStream >> mcSSN)) {
    bSuccess = false;
  }

  return bSuccess;
}