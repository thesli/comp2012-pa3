#include "Transport.h"
#include "DistanceBased.h"
#include "FlatFare.h"
#include "Railway.h"
#include "Bus.h"
#include "CableCar.h"

using namespace std;

int main(int argc,const char* arv[]){
    Railway r;
    r.readInfo("railway_mtr1.txt");
    r.printFares(cout);
    list<string> lst = r.findDestinations("Tin Hau Station", 5.0);
    for(auto i = lst.begin();i != lst.end();i++){
        cout << *i << endl;
    }
    return 0;
}