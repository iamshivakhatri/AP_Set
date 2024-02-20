#ifndef MYSET_H
#define MYSET_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class mySet {
protected:
    vector<int> elts;
    int size;

public:
    mySet();
    bool isempty() const;
    bool isfound(int x) const;
    bool addelt(int x);
    bool deleteelt(int x);
    int getsize() const;
    void setsize(int s);
    vector<int> getelts() const;
    void setelts(const vector<int>& elements);
    mySet Union(const mySet& S) const;
    mySet Intersection(const mySet& S) const;
    mySet Difference(const mySet& S) const;
    bool operator==(const mySet& other) const;
    friend ostream& operator<<(ostream& ost, const mySet& S);
};

#endif // MYSET_H
