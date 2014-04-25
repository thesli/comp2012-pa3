/* FlatFare.h
 * - the header file for the class declaration of FlatFare 
 */

#ifndef _FLATFARE_H
#define _FLATFARE_H

#include "Transport.h"

class FlatFare: public Transport {
protected:
    double singleTripFare;
    vector<string> stops;
public:
    FlatFare();
    FlatFare(string name,int id,double fare);
    FlatFare(string name,int id,double fare,string filename);
    FlatFare(const FlatFare& other);
    bool operator==(const FlatFare& other) const;
    FlatFare& operator=(const FlatFare& other);
    double getFare() const;
    void readInfo(string filename);

    virtual void printInfo(ostream &os) const;

    virtual bool searchStop(string name) const;

    virtual void removeStop(string stopname);

    virtual list<string> findDestinations(string ori, double fare) const;
};

#endif
