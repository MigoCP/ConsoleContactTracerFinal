#include <iostream>
#include <list>
#include <queue>
#include "ContactTree.h"

using namespace std;

int main() {
    cout << "\n*********************** Tree Creation ***********************\n\n";
    // Create a new ContactTree with a root node
    ContactTree<string> tree("000");

    // Add some contacts; assume "Patient0" has directly infected "Patient1" and "Patient2"
    cout << "\n*********************** Tree Population ***********************\n";
    tree.AddContact("000", "001");
    tree.AddContact("000", "002");

    // Add more contacts, "Patient1" infects "Patient3" and "Patient4"
    tree.AddContact("001", "003");
    tree.AddContact("001", "004");

    // Display specific contact details
    cout << "\n*********************** Contact Displaying ***********************\n";
    tree.DisplayContact("001");

    // Trace the source of infection for "Patient3"
    cout << "\n*********************** Source Tracing ***********************\n";
    tree.TraceSource("003");

    // Print all contact cases from "Patient1"
    cout << "\n*********************** All Contact Cases from Patient 001 ***********************\n";
    tree.PrintContactCases("001");

    // Print the entire contact tree
    cout << "\n*********************** Printing Entire Contact Tree ***********************\n";
    cout << "\nPrinting the entire Contact Tree:" << endl;
    tree.PrintContactTree();

    // Print hierarchical tree
    cout << "\n*********************** Printing Hierarchical Tree ***********************\n";
    tree.PrintHierarchicalTree();

    return 0;
}
