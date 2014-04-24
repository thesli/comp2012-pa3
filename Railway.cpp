/* Railway.cpp
 * - the source file for the implementation of the methods of Railway class
 */

#include "Railway.h"

// Add the implementation of the methods here

Railway::Railway() {

}

Railway::Railway(string name, int id, string filename) {

}

Railway::Railway(string name, int id) {

}

Railway::Railway(const Railway &other) {

}

Railway::~Railway() {

}

bool Railway::operator ==(const Railway &other) const {
    return false;
}

Railway &Railway::operator = (const Railway &other) {
    Railway r;
    return r;
};

int Railway::searchStopIndex(string stop) const {
    return 0;
}

void Railway::printFares(ostream &os) const {

}

double Railway::findFare(string ori, string des) const {
    return 0;
}
