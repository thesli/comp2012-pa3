/* Railway.cpp
 * - the source file for the implementation of the methods of Railway class
 */

#include "Railway.h"

// Add the implementation of the methods here

Railway::Railway() : DistanceBased(){

}

Railway::Railway(string name, int id, string filename) : DistanceBased(name,id) {
    this->readInfo(filename);
}

Railway::Railway(string name, int id) : DistanceBased(name,id) {

}

Railway::Railway(const Railway &other) {
    this->id = other.id;
    this->fares = other.fares;
    this->transportName = other.transportName;
    this->stopNames = other.stopNames;
}

Railway::~Railway(){

}

bool Railway::operator ==(const Railway &other) const {
    return
        this->id == other.id &&
        this->fares == other.fares &&
        this->transportName == other.transportName &&
        this->stopNames == other.stopNames;

}

Railway &Railway::operator = (const Railway &other) {
    Railway r(other);
    return r;
};

bool Railway::searchStop(string name) const {
    for(auto i = this->stopNames.begin(); i != this->stopNames.end();i++){
        if(*i==name){
            return true;
        }
    }
    return false;
}

int Railway::searchStopIndex(string stop) const {
    for(int i = 0;i < stopNames.size();i++){
        if(stop.compare(stopNames[i])==0){
            return i;
        }
    }
    return -1;
}

void Railway::printFares(ostream &os) const {
    for(auto i = this->stopNames.begin();i != this->stopNames.end();i++ ){
        os << "\t" << *i;
    }
    os << "\n";
    for(int j = 0;j<this->stopNames.size();j++){
        os << stopNames[j] << "\t";
        for(auto k = this->fares[j].begin();k != this->fares[j].end();k++){
            os << *k << "\t";
        }
        os << "\n";
    }
}

double Railway::findFare(string ori, string des) const {
    int oriIndex = searchStopIndex(ori);
    int desIndex = searchStopIndex(des);
    if(oriIndex!=-1&&desIndex!=-1){
        return fares[oriIndex][desIndex];
    }else{
        return -1;
    }
}

void Railway::readInfo(string filename) {
    DistanceBased::readInfo(filename);
    ifstream ifs(filename);
    string temp;
    getline(ifs,temp);
    int numOfStation = atoi(temp.c_str());
    int currentStation = 0;
    while(currentStation<numOfStation){
        getline(ifs,temp);
        this->stopNames.push_back(temp);
        currentStation++;
    }
    currentStation = 0;
    while(currentStation<numOfStation){
        getline(ifs,temp);
        string bufferNumberString;
        vector<double> stationFareList;
        for(auto i = temp.begin();i!=temp.end();i++){
            if(*i!=' '){
                bufferNumberString.push_back(*i);
            }else{
                stationFareList.push_back(atof(bufferNumberString.c_str()));
                bufferNumberString = "";
            }
        }
        stationFareList.push_back(atof(bufferNumberString.c_str())); //add the last number before end of line.
        this->fares.push_back(stationFareList);
        currentStation++;
    }
    ifs.close();
}

void Railway::removeStop(string stopname) {
    int index = searchStopIndex(stopname);
    stopNames.erase(stopNames.begin()+index);
    fares.erase(fares.begin()+index);
}


list<string> Railway::findDestinations(string ori, double fare) const {
    int index = searchStopIndex(ori);
    list<string> lst;
    vector<double> target = this->fares[index];
    for(int i = 0;i < target.size();i++){
        if(target[i]<=fare){
            if(this->stopNames[i]!= ori){
                lst.push_back(this->stopNames[i]);
            }
        }
    }
    return lst;
}
