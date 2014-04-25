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

void Bus::printFares(ostream &os) const {
    list<StopData> target = this->stopNamesFares;
    for(auto i = target.begin(); i != target.end();i++){
        os << i->getName() << "," << i->getFare() << "\n";
    }
}

double Bus::findFare(string ori, string des) const {
    double oriFare = 0;
    double desFare = 0;
    for(auto i = this->stopNamesFares.begin() ; i != this->stopNamesFares.end();i++){
        if(i->getName()==ori){
            oriFare = i->getFare();
        }
        if(i->getName()==des){
            desFare = i->getFare();
        }
    }
    return (oriFare > desFare) ? oriFare : desFare;
}

bool Bus::searchStop(string name) const {
    for(auto i = this->stopNamesFares.begin(); i != this->stopNamesFares.end() ; i++){
        if(i->getName()==name){
            return true;
        }
    }
    return false;
}

list<string> Bus::findDestinations(string ori, double fare) const {
    list<string> lst;
    for(auto i = this->stopNamesFares.begin() ; i != this->stopNamesFares.end() ; i++){
        if(i->getFare()<=fare && i->getFare() != 0 ){
            lst.push_back(i->getName());
        }
    }
    return lst;
}


void Bus::readInfo(string filename) {
    DistanceBased::readInfo(filename);
    ifstream ifs(filename);
    string temp;
    getline(ifs,temp);
    int numOfStation = atoi(temp.c_str());
    int currentStation = 0;
    while(currentStation<numOfStation){
        getline(ifs,temp);
        string stationName;
        string fareString;
        for(auto i = temp.begin(); i != temp.end();i++){
            if(*i ==','){
                i++;
                for(;i!=temp.end();i++){
                    fareString.push_back(*i);
                }
                break;
            }
            stationName.push_back(*i);
        }
        StopData sd;
        sd.setFare(atof(fareString.c_str()));
        sd.setName(stationName);
        this->stopNamesFares.push_back(sd);
        currentStation++;
    }
    ifs.close();
}

Bus::Bus() {

}

Bus::Bus(string name, int id) : DistanceBased(name,id) {

}

Bus::Bus(string name, int id, string filename) : DistanceBased(name, id) {
    this->readInfo(filename);
}

Bus::Bus(const Bus &other) {
    this->stopNamesFares = other.stopNamesFares;
    this->id = other.id;
    this->transportName = other.transportName;
}

Bus::~Bus() {

}

bool Bus::operator ==(const Bus &other) const {
    return
        this->stopNamesFares == other.stopNamesFares &&
        this->id == other.id &&
        this->transportName == other.transportName;
}

Bus &Bus::operator = (const Bus &other) {
    Bus b(other);
    return b;
}

void Bus::removeStop(string stopname) {
    DistanceBased::removeStop(stopname);
    for(auto i = this->stopNamesFares.begin(); i != this->stopNamesFares.end() ; i++){
        if(i->getName()==stopname){
            this->stopNamesFares.erase(i);
        }
    }
}