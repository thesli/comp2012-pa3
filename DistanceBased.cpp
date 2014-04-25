/* DistanceBased.cpp
 * - the source file for the implementation of the methods of DistanceBased class
 */


#include "DistanceBased.h"

using namespace std;

/* printing the info of the transport */
void DistanceBased::printInfo(ostream& os) const { 
       os << "Name: " << transportName<< endl;
       os << "ID: " << id << endl;
       printFares(os);
}

DistanceBased::DistanceBased() : Transport() {

}

DistanceBased::DistanceBased(string name, int id) : Transport(name,id) {

}

void DistanceBased::readInfo(string filename) {
    // it looks like nothing you actually need to do here...
}

bool DistanceBased::searchStop(string name) const {
    return false;
}

void DistanceBased::removeStop(string stopName) {

}


// Add the rest of the implementation here

