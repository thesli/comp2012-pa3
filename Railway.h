/* Railway.h
 * - the header file for the class declaration of Railway
 */

#ifndef _RAILWAY_H
#define _RAILWAY_H

#include "DistanceBased.h"

class Railway:public DistanceBased {

    // Add the data member and methods here
protected:
    vector<string> stopNames;
    vector< vector<double> > fares;
    int searchStopIndex(string stop) const;

public:
    Railway();
    Railway(string name,int id,string filename);
    Railway(string name,int id);
    Railway(const Railway& other);
    ~Railway();
    bool operator==(const Railway& other) const;
    Railway& operator=(const Railway& other);

    virtual void printFares(ostream &os) const;

    virtual double findFare(string ori, string des) const;
};

#endif
