/* FlatFare.cpp
 * - the source file for the implementation of the methods of FlatFare class
 */

#include "FlatFare.h"

// Add the implementation of the methods here
FlatFare::FlatFare() : Transport(){

}

FlatFare::FlatFare(string name, int id, double fare) : Transport(name,id) {
this->singleTripFare = fare;
}

FlatFare::FlatFare(string name, int id, double fare, string filename) : Transport(name,id) {
    this->singleTripFare = fare;
    this->readInfo(filename);
}

FlatFare::FlatFare(const FlatFare &other) {
    this->id = other.id;
    this->transportName = other.transportName;
    this->stops = other.stops;
    this->singleTripFare = other.singleTripFare;
}

bool FlatFare::operator ==(const FlatFare &other) const {
    return
        this->id == other.id &&
        this->transportName == other.transportName &&
        this->stops == other.stops &&
        this->singleTripFare == other.singleTripFare;
}

FlatFare &FlatFare::operator = (const FlatFare &other) {
    FlatFare o(other);
    return o;
}

double FlatFare::getFare() const {
    return this->singleTripFare;
}

void FlatFare::readInfo(string filename) {
    ifstream ifs(filename);
    string temp;
    getline(ifs,temp);
    int numOfStation = atoi(temp.c_str());
    int currentStation = 0;
    while(currentStation<numOfStation){
        getline(ifs,temp);
        this->stops.push_back(temp);
        currentStation++;
    }
    ifs.close();
}

void FlatFare::printInfo(ostream &os) const {
    os << "Name: " << this->transportName << "\n";
    os << "ID: " << this->id << "\n";
    os << "Single Trip Fare: " << this->singleTripFare << "\n";
    for(auto i = this->stops.begin(); i != this->stops.end() ; i++){
        os << *i << "\n";
    }
}

bool FlatFare::searchStop(string name) const {
    return find(this->stops.begin(),this->stops.end(),name) != this->stops.end();
}

void FlatFare::removeStop(string stopname) {
    for(auto i = this->stops.begin(); i != this->stops.end() ; i++){
        if(*i == stopname){
            this->stops.erase(i);
        }
    }
}

list<string> FlatFare::findDestinations(string ori, double fare) const {
    bool isValidName = this->searchStop(ori);
    list<string> lst;
    if(this->singleTripFare<=fare && isValidName){
        for(auto i =  this->stops.begin(); i != this->stops.end();i++){
            lst.push_back(*i);
        }
    }else{
        return lst;
    }
    return lst;
}
