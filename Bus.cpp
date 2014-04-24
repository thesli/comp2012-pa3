/*
 * Bus.cpp 
 * -- the implementation of the StopData class & Bus class
 */

#include "Bus.h"

StopData::StopData(): name(""), fare(0.0) 
{
} 

StopData::StopData(string name, double fare) 
{
      this->name = name;
      this->fare = fare;
}

StopData::StopData(const StopData& other) 
{
      this->name = other.name;
      this->fare = other.fare;
}

string StopData::getName() const 
{   
   return name; 
}
void StopData::setName(string name) 
{ 
   this->name = name; 
}
double StopData::getFare() const 
{ 
   return fare; 
}

void StopData::setFare(double fare) 
{ 
  this->fare = fare; 
}

bool StopData::operator==(const StopData& other) const
{
       if ((name == other.name) && (fare == other.fare))
           return true;
       else
           return false;
}

StopData& StopData::operator=(const StopData& other) 
{
      this->name = other.name;
      this->fare = other.fare;
      return (*this);
}

// Add the implementation of the methods of Bus below

