#include "Transport.h"
#include "DistanceBased.h"
#include "FlatFare.h"
#include "Railway.h"
#include "Bus.h"
#include "CableCar.h"

/* calling findDestinations for all objects */
void findAllDestinations(ostream& os, const vector<Transport*> transports, string origin, double fare)
{
    os << "\n------ From \"" << origin << "\" with fare $" << fare << " ------" << endl;
    for (unsigned i=0; i<transports.size(); i++)
    {
        if (transports[i]->searchStop(origin))
        {
            list<string> result = transports[i]->findDestinations(origin, fare);
            if (result.size()!=0)
            {
                os << "For " << transports[i]->getName() << endl;
                for (list<string>::const_iterator it = result.begin(); it!=result.end(); it++)
                {
                    os << " --> " << *it ;
                }
                os << endl;
            }
        }
    }
}

/* calling findFare method of the DistanceBased objects and getFare for the FlatFare objects */
void findAllFares(ostream& os, string ori, string des, const vector<Transport*> transports, const vector<string> transType)
{
    for (unsigned i=0; i<transports.size(); i++)
    {
        os << "\n----- For " << transports[i]->getName() << " (Id: " << transports[i]->getId() << ") ------" << endl;
        int valid = 0;
        if (transports[i]->searchStop(ori)) {
            os << ori << " exists\n";
            valid++;
        } else {
            os << ori << " does not exists\n";
        }
        if (transports[i]->searchStop(des)) {
            os << des << " exists\n";
            valid++;
        } else {
            os << des << " does not exists\n";
        }
        if (valid==2) {
            if ((transType[i] == "r") || (transType[i] == "b")) {
                DistanceBased* temp = (DistanceBased*)transports[i];
                os << "Fare: " << temp->findFare(ori, des) << endl;
            }
            else if ((transType[i] == "f") || (transType[i] == "c"))
            {
                FlatFare* temp = (FlatFare*)transports[i];
                os << "Fare: " << temp->getFare() << endl;
                if (transType[i] == "c") {
                    CableCar* temp = (CableCar*)transports[i];
                    os << "Fare: " << temp->getRoundTripFare() << endl;
                }
            }
        }
    }
}

/* creating objects */
Transport* readInput(ostream& os, istream& is, string type)
{
    if ((type != "r") && (type != "b") && (type != "f") && (type != "c"))
    {
        return (NULL);
    }
    string name="", filename="";
    int id=0;
    os << "TransportName: ";
    getline(is, name);
    os << "ID: ";
    is >> id;
    is.ignore();
    os << "File: ";
    getline(is, filename);

    Transport* temp;
    if (type == "r") {
        temp = new Railway(name, id, filename);
    } else if (type == "b") {
        temp = new Bus(name, id, filename);
    } else if (type == "f") {
        double fare=0.0;
        os << "SingleTripFare: ";
        is >> fare;
        is.ignore();
        temp = new FlatFare(name, id, fare, filename);
    } else if (type == "c") {
        double sfare=0.0, rfare=0.0;
        os << "SingleTripFare: ";
        is >> sfare;
        is.ignore();
        os << "RoundTripFare: ";
        is >> rfare;
        is.ignore();
        temp = new CableCar(name, id, sfare, rfare, filename);
    }
    return temp;
}

/* checking copy constructor & assignment operator & equal-to operator
*/
template <class T>
bool checkTransportEqual(T sysi, T sysj)
{
    T x, y;
    x = sysi;
    y = sysj;
    return (x==y);
}

/* check if any transport is the same as another.
   If the same, modify one by incrementing the id by 1 and add the word " new" to the TransportName
*/
void checkEqual(ostream& os, const vector<Transport*> system, const vector<string> systemType)
{
    bool same = false;
    for (unsigned i=0; i<system.size(); i++)
        for (unsigned j=i+1; j<system.size(); j++) {
            same = false;
            if (systemType[i] == systemType[j])
            {
                if (systemType[i] == "r") {
                    same=checkTransportEqual<Railway>(*(Railway *)system[i], *(Railway *)system[j]);
                }
                else if (systemType[i] == "b") {
                    same=checkTransportEqual<Bus>(*(Bus *)system[i], *(Bus *)system[j]);
                }
                else if (systemType[i] == "f") {
                    same=checkTransportEqual<FlatFare>(*(FlatFare *)system[i], *(FlatFare *)system[j]);
                }
                else if (systemType[i] == "c") {
                    same=checkTransportEqual<CableCar>(*(CableCar *)system[i], *(CableCar *)system[j]);
                }
            }
            if (same) {
                os << "Transport " << i << " is equal to transport " << j << endl;
                system[j]->setId(system[j]->getId()+1);
                system[j]->setName(system[j]->getName()+" new");
                os << "Transport name of transport " << j << " is changed to \"" << system[j]->getName() << "\"" << endl;
                os << "ID of transport " << j << " is changed to " << system[j]->getId() << endl;
            }
        }
}

int main(int argc, char** argv)
{
    streambuf* buf;
    ofstream of;
    if (argc > 1) {
        of.open(argv[1]);
        buf = of.rdbuf();
    } else {
        buf = std::cout.rdbuf();
    }
    ostream out(buf);

    vector<Transport*> system;
    vector<string> systemType;
    string option="";

    while (option != "q")
    {
        out << ">>> Menu: q:quit, n:new transport, p:printInfo, l:readInfo, a:findDestinations&searchStop, f:findFare&getFare, r:removeStop, u:equalTo&Assignment\n";
        out << ">>> Command: ";
        getline(cin, option);

        if (option == "n")
        {
            out << "\n====== Adding new transport ======\n";
            string type="";
            out << "Enter the type of transport (r:Railway, b:Bus, f:flatfare, c:cablecar):";
            getline(cin, type);
            Transport* temp = readInput(out, cin, type);
            if (temp != NULL) {
                system.push_back(temp);
                systemType.push_back(type);
            }
            out << "No. of tranports in system: " << system.size() << endl;

        } else if (option == "p") {
            out << "\n====== Printing all transports ======\n";
            for (unsigned i=0; i<system.size(); i++) {
                out << "------ Transport " << i << " ------\n";
                (system[i])->printInfo(out);
            }
        } else if (option == "l") {
            out << "\n===== Reading input file ======\n";
            int index=0;
            out << "Transport index(0-" << system.size() << "): ";
            cin >> index;
            cin.ignore();
            string filename = "";
            out << "File: ";
            getline(cin, filename);
            system[index]->readInfo(filename);

        } else if (option == "a") {
            double fare = 0.0;
            out << "\n====== Finding all destinations ======\n";
            string ori = "";
            out << "Origin: ";
            getline(cin, ori);
            out << "Fare: ";
            cin >> fare;
            cin.ignore();
            findAllDestinations(out, system, ori, fare);
        } else if (option == "f") {
            out << "\n====== Finding fare ======\n";
            string ori="", des="";
            out << "Origin: ";
            getline(cin, ori);
            out << "Destination: ";
            getline(cin, des);
            findAllFares(out, ori, des, system, systemType);
        } else if (option == "r") {
            out << "\n====== Removing stops ======\n";
            string stop = "";
            out << "stopname: ";
            getline(cin, stop);
            out << "\n------ removing " << stop << " ------\n";
            for (unsigned i=0; i<system.size(); i++)
                if (system[i]->searchStop(stop))
                    system[i]->removeStop(stop);
        } else if (option == "u") {
            out << "\n====== Checking Duplicates ======\n";
            checkEqual(out, system, systemType);
        }

        out << "\n\n";
    }
    return 0;
}