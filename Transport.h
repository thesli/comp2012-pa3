/* Transport.h
 * - the header file for the class declaration of Transport
 */

#ifndef _TRANSPORT_H
#define _TRANSPORT_H

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <fstream>

using namespace std;

class Transport {
  protected:
   /* data members */
   string transportName;
   int id;

  public:
   /* methods */
   /* constructors */
   Transport();

   Transport(string name, int id);

   virtual ~Transport();

   /* set the transportName by name */
   void setName(string name);

   /* set the id by n */
   void setId(int n);

   /* get the transportName */
   string getName() const;

   /* get the id */
   int getId() const;

   /* read the info from a file */
   virtual void readInfo(string filename) = 0;

   /* print the info to the output stream, os */
   virtual void printInfo(ostream& os) const = 0;

   /* return true if the name is one of the stops; otherwise, return false */
   virtual bool searchStop(string name) const = 0;

   /* remove the stop and its fares */
   virtual void removeStop(string stopname) = 0;

   /* given the origin, ori, find all destinations that can be travelled along the route
      which cost less than the fare given */  
   virtual list<string> findDestinations(string ori, double fare) const = 0;
};

#endif
