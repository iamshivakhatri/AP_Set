#include <iostream>
#include <fstream>
#include "mySet.h"
#include "OrderedSet.h"

/**
 Shiva khatri
  -
 *
 */
using namespace std;
// Determine if SetType is a mySet
template<typename SetType>
bool isMySet(const SetType& set) {
    return is_same<SetType, mySet>::value;
}

// Function to perform operations on both mySet and OrderedSet objects
template<typename SetType>
void performOperations(SetType& S1, SetType& S2, SetType& S3, SetType& S4, SetType& S5, SetType& S6) {
    // Perform operations common to both mySet and OrderedSet objects
    S3 = S1.Union(S2);
    S4 = S1.Intersection(S2);
    S5 = S1.Difference(S2);
    string setType;
    if (isMySet(S1)) {
        setType = "MySet S"; // For mySet
    }else {
        setType = "OrderedSet OS"; // Unknown type
    }

    cout << setType << "3 Contents" << endl; // Print after operations
    cout << "After UNION Operation of " << setType << "1 and " << setType << "2" << endl;
    cout << setType << "3 Contents" << endl;
    cout << "----------------" << endl;
    cout << S3 << endl;
    cout << setType << "1 Contents" << endl;
    cout << "----------------" << endl;
    cout << S1 << endl;
    cout << setType << "2 Contents" << endl;
    cout << "----------------" << endl;
    cout << S2 << endl;

    cout << "After INTERSECTION Operation of " << setType << "1 and " << setType << "2" << endl;
    cout << setType << "4 Contents" << endl;
    cout << "----------------" << endl;
    cout << S4 << endl;
    cout << setType << "1 Contents" << endl;
    cout << "----------------" << endl;
    cout << S1 << endl;
    cout << setType << "2 Contents" << endl;
    cout << "----------------" << endl;
    cout << S2 << endl;

    cout << "After DIFFERENCE Operation of " << setType << "1 and " << setType << "2" << endl;
    cout << setType << "5 Contents" << endl;
    cout << "----------------" << endl;
    cout << S5 << endl;
    cout << setType << "1 Contents" << endl;
    cout << "----------------" << endl;
    cout << S1 << endl;
    cout << setType << "2 Contents" << endl;
    cout << "----------------" << endl;
    cout << S2 << endl;


    // Test equivalence using the == operator defined for the SetType
    S6 = S1.Union(S3);
    cout << "S3 and S6 ARE " << (S3 == S6 ? "" : "NOT ") << "EQUAL" << endl;
    cout << "S1 and S6 ARE " << (S1 == S6 ? "" : "NOT ") << "EQUAL" << endl;
}

int main() {
    // Declare appropriate variables for mySet
    mySet S1, S2, S3, S4, S5, S6;

    // Prompt the user for a path to an input file
    string inputFilePath1, inputFilePath2, inputFilePath3, inputFilePath4;
    cout << "Please enter a path to an input file: ";
    cin >> inputFilePath1;

    // Open the first input file
    ifstream inputFile1(inputFilePath1);
    if (!inputFile1.is_open()) {
        cout << "Error: Unable to open input file " << inputFilePath1 << endl;
        return 1;
    }

    // Read integers from the first input file and insert into S1
    int num;
    while (inputFile1 >> num) {
        S1.addelt(num);
    }
    inputFile1.close();

    // Prompt the user for a path to a second input file
    cout << "Please enter a path to a second input file: ";
    cin >> inputFilePath2;

    // Open the second input file
    ifstream inputFile2(inputFilePath2);
    if (!inputFile2.is_open()) {
        cout << "Error: Unable to open input file " << inputFilePath2 << endl;
        return 1;
    }

    // Read integers from the second input file and insert into S2
    while (inputFile2 >> num) {
        S2.addelt(num);
    }
    inputFile2.close();

    // Print out the contents of S1, S2, and S3
    cout << "BEFORE OPERATIONS" << endl;
    cout << "MySet S1 Contents" << endl;
    cout << "----------------" << endl;
    cout << S1 << endl;
    cout << "MySet S2 Contents" << endl;
    cout << "----------------" << endl;
    cout << S2 << endl;
    cout << "MySet S3 Contents" << endl;
    cout << "----------------" << endl;
    if (S3.isempty()) {
        cout << "Set is EMPTY" << endl;
    } else {
        cout << S3 << endl;
    }

    // Perform operations for mySet
    performOperations(S1, S2, S3, S4, S5, S6);

    // Prompt user for a path to a third input file
    cout << "Please enter a path to a third input file: ";
    cin >> inputFilePath3;

    // Open the third input file
    ifstream inputFile3(inputFilePath3);
    if (!inputFile3.is_open()) {
        cout << "Error: Unable to open input file " << inputFilePath3 << endl;
        return 1;
    }

    // Read integers from the third input file and attempt to add them to S1
    while (inputFile3 >> num) {
        bool result = S1.addelt(num);
        if (result) {
            cout << num << " was successfully added to S1" << endl;
        } else {
            cout << num << " ALREADY PRESENT IN S1" << endl;
        }
    }
    inputFile3.close();

    // Print the updated contents of S1 after adding elements from the third input file
    cout << "S1 AFTER ADDITION of elements" << endl;
    cout << "MySet S1 Contents" << endl;
    cout << "----------------" << endl;
    cout << S1 << endl;

    // Prompt for file path and open a fourth file for input
    cout << "Please enter a path to a fourth input file: ";
    cin >> inputFilePath4;

    // Open the fourth input file
    ifstream inputFile4(inputFilePath4);
    if (!inputFile4.is_open()) {
        cout << "Error: Unable to open input file " << inputFilePath4 << endl;
        return 1;
    }

    // Read integers from the fourth input file and attempt to delete them from S1
    while (inputFile4 >> num) {
        bool result = S1.deleteelt(num);
        if (result) {
            cout << num << " was successfully deleted from S1" << endl;
        } else {
            cout << num << " NOT FOUND" << endl;
        }
    }
    inputFile4.close();

    // Print the updated contents of S1 after deleting elements from the fourth input file
    cout << "S1 AFTER DELETION of elements" << endl;
    cout << "MySet S1 Contents" << endl;
    cout << "----------------" << endl;
    cout << S1 << endl;

    // Repeat all operations for OrderedSet objects
    // Declare appropriate variables for OrderedSet
    OrderedSet OS1, OS2, OS3, OS4, OS5, OS6;

    // Prompt the user for a path to an input file
    cout << "Please enter a path to an input file: ";
    cin >> inputFilePath1;

    // Open the first input file
    ifstream inputFile5(inputFilePath1);
    if (!inputFile5.is_open()) {
        cout << "Error: Unable to open input file " << inputFilePath1 << endl;
        return 1;
    }

    // Read integers from the first input file and insert into OS1
    while (inputFile5 >> num) {
        OS1.addelt(num);
    }
    inputFile5.close();

    // Prompt the user for a path to a second input file
    cout << "Please enter a path to a second input file: ";
    cin >> inputFilePath2;

    // Open the second input file
    ifstream inputFile6(inputFilePath2);
    if (!inputFile6.is_open()) {
        cout << "Error: Unable to open input file " << inputFilePath2 << endl;
        return 1;
    }

    // Read integers from the second input file and insert into OS2
    while (inputFile6 >> num) {
        OS2.addelt(num);
    }
    inputFile6.close();

    // Print out the contents of OS1, OS2, and OS3
    cout << "BEFORE OPERATIONS" << endl;
    cout << "OrderedSet OS1 Contents" << endl;
    cout << "----------------" << endl;
    cout << OS1 << endl;
    cout << "OrderedSet OS2 Contents" << endl;
    cout << "----------------" << endl;
    cout << OS2 << endl;
    cout << "OrderedSet OS3 Contents" << endl;
    cout << "----------------" << endl;
    if (OS3.isempty()) {
        cout << "Ordered Set is EMPTY" << endl;
    } else {
        cout << OS3 << endl;
    }

    // Perform operations for OrderedSet
    performOperations(OS1, OS2, OS3, OS4, OS5, OS6);



    // Prompt user for a path to a third input file
    cout << "Please enter a path to a third input file: ";
    cin >> inputFilePath3;

    // Open the third input file
    ifstream inputFile7(inputFilePath3);
    if (!inputFile7.is_open()) {
        cout << "Error: Unable to open input file " << inputFilePath3 << endl;
        return 1;
    }

    // Read integers from the third input file and attempt to add them to OS1
    while (inputFile7 >> num) {
        bool result = OS1.addelt(num);
        if (result) {
            cout << num << " was successfully added to OS1" << endl;
        } else {
            cout << num << " ALREADY PRESENT IN OS1" << endl;
        }
    }
    inputFile7.close();

    // Print the updated contents of OS1 after adding elements from the third input file
    cout << "OS1 AFTER ADDITION of elements" << endl;
    cout << "OrderedSet OS1 Contents" << endl;
    cout << "----------------" << endl;
    cout << OS1 << endl;

    // Prompt for file path and open a fourth file for input
    cout << "Please enter a path to a fourth input file: ";
    cin >> inputFilePath4;

    // Open the fourth input file
    ifstream inputFile8(inputFilePath4);
    if (!inputFile8.is_open()) {
        cout << "Error: Unable to open input file " << inputFilePath4 << endl;
        return 1;
    }

    // Read integers from the fourth input file and attempt to delete them from OS1
    while (inputFile8 >> num) {
        bool result = OS1.deleteelt(num);
        if (result) {
            cout << num << " was successfully deleted from OS1" << endl;
        } else {
            cout << num << " NOT FOUND" << endl;
        }
    }
    inputFile8.close();

    // Print the updated contents of OS1 after deleting elements from the fourth input file
    cout << "OS1 AFTER DELETION of elements" << endl;
    cout << "OrderedSet OS1 Contents" << endl;
    cout << "----------------" << endl;
    cout << OS1 << endl;

    cout << "PROGRAM COMPLETE" << endl;

    return 0;
}
