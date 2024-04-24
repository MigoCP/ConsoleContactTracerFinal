#pragma once
#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

template<typename T>
class ContactTree
{
private:
    TreeNode<T>* root;
    int size;

    // Delete node and all its children (entire tree)
    void DeleteContact(TreeNode<T>* node)
    {
        if (node) // If node is not nullptr
        {
            for (TreeNode<T>* child : node->children) { DeleteContact(child); } // Delete all children with recursion
            delete node;  // Delete the currentElem node after deleting children
        }
    }

public:
    // Default constructor
    ContactTree() 
    { 
        this->root = nullptr; 
        this->size = 0; 
        cout << "Creating tree with no root...\n";
        cout << "Empty tree successfully created!\n" << endl;
    }
    // Parameterized constructor
    ContactTree(const T& rootData) 
    { 
        this->root = new TreeNode<T>(rootData);
        this->size = 1;
        cout << "Creating tree with root in patient " << rootData << "...\n";
        cout << "Tree with root in patient " << rootData << " successfully created!\n" << endl;
    }
    // Destructor
    ~ContactTree() 
    { 
        cout << "Deleting tree with root in patient " << root->data << "...\n";
        DeleteContact(root); 
    }

    bool IsEmpty() { return this->size == 0; }
    int GetSize() { return this->size; }

    // No need for AddPatient0() func because  
    // parameterized constructor takes care of first patient

    void AddContact(const T& id1, const T& id2)
    {
        cout << "\nNew infection of " << id2 << " by patient " << 
            id1 <<  " requested\n";
        cout << "Verifying existence of patient " << id1 << "...\n\n";
        TreeNode<T>* node1 = LookUpContact(id1);

        if (node1)
        {
            TreeNode<T>* node2 = new TreeNode<T>(node1, id2);
            node1->directContacts++;
            node1->totalCases++;
            this->size++;
            cout << "Patient " << id2 << " infected by patient " << node1->data
                << " successfully added\n" << endl;
        }
        else { cout << "Could not add contact. ID of infector not found.\n" << endl; }
    }

    // Get contact with ID by traversing the tree with a Queue data structure
    TreeNode<T>* LookUpContact(const T& searchId)
    {
        // If tree is empty, return immediately
        if (root == nullptr) return nullptr;

        /* The Queue facilitates level order traversal
        by ensuring that nodes are checked in the
        order they are discovered (FIFO). This means
        all nodes at one level are checked completely
        before moving on to the next one */
        cout << "------- Looking Up Patient " << searchId << " --------\n";
        cout << "Tracing tree to find patient " << searchId << "...\n";

        queue<TreeNode<T>*> p;  // Local queue of node pointers
        p.push(root);  // Start with root
        cout << "\tStarting with root patient " << root->data << "...\n";

        while (!p.empty())
        {
            TreeNode<T>* currentElem = p.front();  // Get the front (first-in) node 
            cout << "\tChecking next in queue, patient: " << currentElem->data << endl;  // Debug print
            p.pop();  // Remove the front node from the queue

            if (currentElem->data == searchId) 
            { 
                cout << "Patient " << searchId << " VERIFIED" << endl;  // Debug print
                cout << "------- Looking Up Process Ended --------\n\n";
                return currentElem; 
            } // Return node if match
            else 
            {
                cout << "\tThis patient does not match with searching ID " << searchId << endl;  // Debug print
            }

            // Enqueue all children of the currentElem node (process entire level)
            cout << "\tNow proceeding with the direct contacts of patient " << currentElem->data << endl;  // Debug print
            for (TreeNode<T>* child : currentElem->children)
            { 
                p.push(child); 
                cout << "\tPatient " << child->data << " added to queue" << endl;
            }
        }
        cout << "No patient " << searchId << " found in all the tree" << endl;  // Debug print
        cout << "------- Looking Up Process Started --------\n\n";
        return nullptr;  // Return nullptr if no match found
    }

    // Display using pointer
    void DisplayContact(TreeNode<T>* displayer)
    {
        T parent;
        if (!displayer || !displayer->parent)
        {
            parent = "Unknown (Potentially patient 0)";
        }
        else parent = displayer->parent->data;

        cout << "\nPatient ID " << displayer->data << endl;
        cout << "\tInfected by: Patient " << parent << endl;
        cout << "\tDirect contacts: " << displayer->directContacts << endl;
        cout << "\tTotal cases originated in this patient (including self): " << displayer->totalCases << endl;
        cout << "\tPatients infected: " << endl;
        for (TreeNode<T>* child : displayer->children) { cout << "\t\t- " << child->data << endl; }
        cout << endl;
    }

    // Display using ID
    void DisplayContact(const T& searchId)
    {
        cout << "\nDisplay details of patient " << searchId << " requested\n";
        cout << "Verifying existence of patient " << searchId << "...\n\n";

        TreeNode<T>* p = LookUpContact(searchId);
        if (p) DisplayContact(p);
        else cout << "No contact found" << endl << endl;
    }

    void TraceSource(const T& searchId)
    {
        cout << "\nTracing source for patient " << searchId << " requested\n";
        cout << "Verifying existence of patient " << searchId << "...\n\n";
        TreeNode<T>* currentElem = LookUpContact(searchId);

        // If current element's parent is not nullptr
        if (currentElem && currentElem->parent)
        {
            cout << "Patient " << currentElem->data << " was infected by Patient "
                << currentElem->parent->data << endl;
            DisplayContact(currentElem->parent);
            TraceSource(currentElem->parent); // Use overloaded function to reach root
        }
        else // If not, there's no parent and hence root has been reached
        {
            cout << "Contact Root: " << endl;
            DisplayContact(currentElem);
        }
        return; // end recursion loop 
    }

    // Trace source with pointer without need of verifying existence
    void TraceSource(TreeNode<T>* elem)
    {
        cout << "\nTracing source for Infector of Patient " << elem->data << "\n";
        TreeNode<T>* currentElem = elem;

        // If current element's parent is not nullptr
        if (currentElem && currentElem->parent)
        {
            cout << "Patient " << currentElem->data << " was infected by Patient "
                << currentElem->parent->data << endl;
            DisplayContact(currentElem->parent);
            TraceSource(currentElem->parent); // Use recursion to reach root
        }
        else // If not, there's no parent and hence root has been reached
        {
            cout << "Patient " << currentElem->data << 
                " has an unknown infector and is therefore Patient 0, or root patient" << endl;
            DisplayContact(currentElem);
        }
        return; // end recursion loop 
    }

    void PrintContactCases(const T& searchId)
    {
        cout << "\nDirect contact cases of Patient " << searchId << "\n";
        cout << "Verifying existence of Patient " << searchId << "...\n\n";
        TreeNode<T>* p = LookUpContact(searchId);
        // If id is not null and contact is found
        if (p)
        {
            cout << "\nPatient " << searchId << " has infected the following patients:\n";
            for (TreeNode<T>* directContact : p->children) // Display each child
            { 
                DisplayContact(directContact); 
            } 
            return; // End function
        }
        // Else, let user know no contact was found
        cout << "No contact found with such Id" << endl << endl;
    }

    void PrintContactTree()
    {
        //cout << "\nDirect contact cases of Patient " << elem->medicareId << "\n";
        // If tree is empty, return immediately
        if (IsEmpty()) { cout << "Tree is empty" << endl; return; }

        /* The Queue facilitates level order traversal
        by ensuring that nodes are checked in the
        order they are discovered (FIFO). This means
        all nodes at one level are checked completely
        before moving on to the next one */

        queue<TreeNode<T>*> p;  // Local queue of node pointers
        p.push(root);  // Start with root

        while (!p.empty())
        {
            TreeNode<T>* currentElem = p.front();  // Get the front (first-in) node 
            p.pop();  // Remove the front node from the queue

            DisplayContact(currentElem); // Display current node

            // Enqueue all children of the currentElem node (process entire level)
            for (TreeNode<T>* child : currentElem->children) { p.push(child); }
        }
    }

    void PrintHierarchicalTree(TreeNode<T>* node)
    {
        if (!node) return;  // If node is nullptr, return immediatly

        for (TreeNode<T>* child : node->children) 
        {
            PrintHierarchicalTree(child); // Use recursion on all children
        }

        // After all children have been processed, display the current node
        DisplayContact(node);
    }

    void PrintHierarchicalTree()
    {
        cout << "Printing Hierarchical Tree (Post-Order):" << endl;
        if (IsEmpty()) {
            cout << "Tree is empty." << endl;
            return;
        }
        PrintHierarchicalTree(root);  // Start the recursive traversal from the root
    }
};