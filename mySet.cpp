
#include "mySet.h"
#include "mySet.h"

using namespace std;

mySet::mySet() : size(0) {}

bool mySet::isempty() const {
    return size == 0;
}

bool mySet::isfound(int x) const {
    return find(elts.begin(), elts.end(), x) != elts.end();
}

bool mySet::addelt(int x) {
    if (!isfound(x)) {
        elts.push_back(x);
        size++;
        return true;
    }
    return false;
}

bool mySet::deleteelt(int x) {
    auto it = find(elts.begin(), elts.end(), x);
    if (it != elts.end()) {
        elts.erase(it);
        size--;
        return true;
    }
    return false;
}

int mySet::getsize() const {
    return size;
}
// Setter for size
void mySet::setsize(int s) {
    size = s;
}



// Getter for elts
vector<int> mySet::getelts() const {
    return elts;
}

void mySet::setelts(const vector<int>& elements) {
    elts = elements;
}

mySet mySet::Union(const mySet& S) const {
    mySet temp = *this;
    for (int val : S.elts) { // Iterating through the right hand set
        if (!temp.isfound(val)) {
            temp.addelt(val);
        }
    }
    return temp;
}

mySet mySet::Intersection(const mySet& S) const {
    mySet temp;
    for (int val : elts) {
        if (S.isfound(val)) {
            temp.addelt(val);
        }
    }
    return temp;
}

mySet mySet::Difference(const mySet& S) const {
    mySet temp;
    for (int val : elts) {
        if (!S.isfound(val)) {
            temp.addelt(val);
        }
    }
    return temp;
}

bool mySet::operator==(const mySet& other) const {
    if (size != other.size) {
        return false;
    }
    vector<int> temp1 = elts;
    vector<int> temp2 = other.elts;
    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());
    return temp1 == temp2;
}

ostream& operator<<(ostream& ost, const mySet& S) {
    ost << "{ ";
    int count = 0;
    for (auto it = S.elts.rbegin(); it != S.elts.rend(); ++it) {
        ost << *it;
        count++;
        if (count % 10 == 0) {
            ost << endl;
        } else if (count != S.size) {
            ost << ", ";
        }
    }
    ost << " }";
    return ost;
}
