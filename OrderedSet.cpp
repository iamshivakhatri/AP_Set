#include "OrderedSet.h"

// Constructor to convert mySet object into OrderedSet object
OrderedSet::OrderedSet(const mySet& S) {
    size = S.getsize();
    elts = S.getelts();
}

// Overridden Intersection method to return OrderedSet object
OrderedSet OrderedSet::Intersection(const OrderedSet& OS) {
    mySet ms = mySet::Intersection(OS);
    OrderedSet temp = OrderedSet(ms);
    temp.SortSet();
    return temp;
}

// Overridden Union method to return OrderedSet object
OrderedSet OrderedSet::Union(const OrderedSet& OS) {
    mySet ms = mySet::Union(OS);
    OrderedSet temp = OrderedSet(ms);
    temp.SortSet();
    return temp;
}

// Overridden Difference method to return OrderedSet object
OrderedSet OrderedSet::Difference(const OrderedSet& OS) {
    mySet ms = mySet::Difference(OS);
    OrderedSet temp = OrderedSet(ms);
    temp.SortSet();
    return temp;
}

// Overridden addelt method to ensure elements are in order
bool OrderedSet::addelt(int x) {
    bool added = mySet::addelt(x);
    if (added) {
        SortSet();
    }
    return added;
}

// Function to sort the elts vector
void OrderedSet::SortSet() {
    sort(elts.begin(), elts.end());
}

// Overloaded << operator as a friend function
ostream& operator<<(ostream& ost, const OrderedSet& OS) {
    ost << "{ ";
    int count = 0;
    for (int val : OS.elts) {
        ost << val;
        count++;
        if (count % 10 == 0) {
            ost << endl;
        } else if (count != OS.size) {
            ost << ", ";
        }
    }
    ost << " }";
    return ost;
}
