#ifndef ORDEREDSET_H
#define ORDEREDSET_H

#include "mySet.h"

class OrderedSet : public mySet {
public:
    OrderedSet() = default; // Default constructor

    // Second constructor to convert mySet object into OrderedSet object
    OrderedSet(const mySet& S);

    // Overridden Intersection method to return OrderedSet object
    OrderedSet Intersection(const OrderedSet& OS);

    // Overridden Union method to return OrderedSet object
    OrderedSet Union(const OrderedSet& OS);

    // Overridden Difference method to return OrderedSet object
    OrderedSet Difference(const OrderedSet& OS);

    // Overridden addelt method to ensure elements are in order
    bool addelt(int x) ;

    // Function to sort the elts vector
    void SortSet();

    // Overloaded << operator as a friend function
    friend ostream& operator<<(ostream& ost, const OrderedSet& OS);
};

#endif // ORDEREDSET_H
