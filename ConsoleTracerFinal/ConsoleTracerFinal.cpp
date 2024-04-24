#include <iostream>
#include <list>
#include <queue>
#include "ContactTree.h"
#include "CustomQueue.h"

using namespace std;

int main() {

    std::cout << "Welcome To Our Singly Linked List Queue Implementation!\n";

    MyQueue* myList = new MyQueue();
    cout << "Size of the List " << myList->GetSize() << endl;

    cout << "Return if List is empty or not: " << myList->IsEmpty() << endl;

    myList->Display();
    cout << endl;

    myList->Enqueue(3);
    myList->Enqueue(2);
    myList->Enqueue(8);

    myList->Display();
    cout << endl;

    myList->Dequeue();
    myList->Display();
    cout << endl;

    myList->Enqueue(7);

    myList->Display();
    cout << endl;

    myList->Dequeue();
    myList->Display();
    cout << endl;

    /////////////////////////////////////////////////////////////////////////////

    cout << "\n*********************** String Tree Creation ***********************\n\n";
    // Create a new ContactTree with a root node
    ContactTree<string> stringTree("000");

    // Add some contacts; assume "Patient0" has directly infected "Patient1" and "Patient2"
    cout << "\n*********************** Tree Population ***********************\n";
    stringTree.AddContact("000", "001");
    stringTree.AddContact("000", "002");

    // Add more contacts, "Patient1" infects "Patient3" and "Patient4"
    stringTree.AddContact("001", "003");
    stringTree.AddContact("001", "004");

    // Display specific contact details
    cout << "\n*********************** Contact Displaying ***********************\n";
    stringTree.DisplayContact("001");

    // Trace the source of infection for "Patient3"
    cout << "\n*********************** Source Tracing ***********************\n";
    stringTree.TraceSource("003");

    // Print all contact cases from "Patient1"
    cout << "\n*********************** All Contact Cases from Patient 001 ***********************\n";
    stringTree.PrintContactCases("001");

    // Print the entire contact tree
    cout << "\n*********************** Printing Entire Contact Tree ***********************\n";
    cout << "\nPrinting the entire Contact Tree:" << endl;
    stringTree.PrintContactTree();

    // Print hierarchical tree
    cout << "\n*********************** Printing Hierarchical Tree ***********************\n";
    stringTree.PrintHierarchicalTree();

    //////////////////////////////////////////////////////////////////////////////////////////////

    cout << "\n*********************** Float Tree Creation ***********************\n\n";
    // Create a new ContactTree with a root node
    ContactTree<float> floatTree(0.0f);

    // Add some contacts; assume "Patient0" has directly infected "Patient1" and "Patient2"
    cout << "\n*********************** Tree Population ***********************\n";
    floatTree.AddContact(0.0f, 1.0f);
    floatTree.AddContact(0.0f, 2.0f);

    // Add more contacts, "Patient1" infects "Patient3" and "Patient4"
    floatTree.AddContact(1.0f, 3.0f);
    floatTree.AddContact(1.0f, 4.0f);

    // Display specific contact details
    cout << "\n*********************** Contact Displaying ***********************\n";
    floatTree.DisplayContact(0.0f);

    // Trace the source of infection for "Patient3"
    cout << "\n*********************** Source Tracing ***********************\n";
    floatTree.TraceSource(3.0f);

    // Print all contact cases from "Patient1"
    cout << "\n*********************** All Contact Cases from Patient 001 ***********************\n";
    floatTree.PrintContactCases(1.0f);

    // Print the entire contact tree
    cout << "\n*********************** Printing Entire Contact Tree ***********************\n";
    cout << "\nPrinting the entire Contact Tree:" << endl;
    floatTree.PrintContactTree();

    // Print hierarchical tree
    cout << "\n*********************** Printing Hierarchical Tree ***********************\n";
    floatTree.PrintHierarchicalTree();

    return 0;
}
