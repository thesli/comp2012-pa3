/* DistanceBased.h
 * - the header file for the class declaration of DistanceBased
 */

#ifndef _DISTANCEBASED_H
#define _DISTANCEBASED_H

#include "Transport.h"

class DistanceBased:public Transport {

   public:
    DistanceBased();
    DistanceBased(string name,int id);
	/* printing the info of the transport */
	virtual void printInfo(ostream& os) const;
	virtual void printFares(ostream& os) const = 0;
    virtual double findFare(string ori,string des) const = 0;
   // Add the data member and methods here 

    virtual void readInfo(string filename);

    virtual bool searchStop(string name) const;

    virtual void removeStop(string stopname);

    virtual list<string> findDestinations(string ori, double fare) const;
};

#endif
