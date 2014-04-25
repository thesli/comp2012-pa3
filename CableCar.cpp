/* CableCar.cpp
 * - the source file for the implementation of the methods of CableCar class
 */

#include "CableCar.h"

// Add the implementation of the methods here

CableCar::CableCar() : FlatFare(){

}

CableCar::CableCar(string name, int id, double sfare, double rfare) : FlatFare(name,id,sfare){
    this->roundTripFare = rfare;
}

CableCar::CableCar(string name, int id, double sfare, double rfare, string filename) : FlatFare(name,id,sfare) {
    this->roundTripFare = rfare;
    this->readInfo(filename);
}

CableCar::CableCar(const CableCar &other) {
    this->stops = other.stops;
    this->roundTripFare = other.roundTripFare;
    this->singleTripFare = other.singleTripFare;
    this->transportName = other.transportName;
    this->id = other.id;
}

CableCar::~CableCar() {

}

bool CableCar::operator ==(const CableCar &other) const {
    return
            this->stops == other.stops &&
            this->roundTripFare == other.roundTripFare &&
            this->singleTripFare == other.singleTripFare &&
            this->transportName == other.transportName &&
            this->id == other.id;
}

CableCar &CableCar::operator =(const CableCar &other) {
    CableCar c(other);
    return c;
}

double CableCar::getRoundTripFare() const {
return this->roundTripFare;
}

void CableCar::printInfo(ostream &os) const {
//    FlatFare::printInfo(os);
    os << "Name: " << this->transportName << "\n";
    os << "ID: " << this->id << "\n";
    os << "Single Trip Fare: " << this->singleTripFare << "\n";
    os << "Round Trip Fare: " << this->roundTripFare << "\n";
    for(auto i = this->stops.begin(); i != this->stops.end() ; i++){
        os << *i << "\n";
    }
}

list<string> CableCar::findDestinations(string ori, double fare) const {
    bool isValidName = this->searchStop(ori);
    list<string> lst;
    return lst;
}
