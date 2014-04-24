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

DistanceBased::DistanceBased() {

}

DistanceBased::DistanceBased(string name, int id) {

}

void DistanceBased::readInfo(string filename) {

}

bool DistanceBased::searchStop(string name) const {
    return false;
}

void DistanceBased::removeStop(string stopname) {

}

list<string> DistanceBased::findDestinations(string ori, double fare) const {
    list<string> l;
    return l;
};


// Add the rest of the implementation here

