/* Transport.cpp
 * - the source file for the implementation of the methods of Transport class
 */

#include "Transport.h"

// Add your implementation below

Transport::Transport() {
    this->id = 0;
    this->transportName = "";
}

Transport::Transport(string name, int id) {
    this->transportName = name;
    this->id = id;
}

Transport::~Transport() {

}

void Transport::setName(string name) {
    this->transportName = name;
}

void Transport::setId(int n) {
    this->id = n;
}

string Transport::getName() const {
    return this->transportName;
}

int Transport::getId() const {
    return this->id;
}
