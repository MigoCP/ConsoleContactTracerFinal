#pragma once
#include <iostream>
#include <list>

using namespace std;

template<typename T>
struct TreeNode
{
    T data;
    int directContacts = 0;
    int totalCases = 1;
    TreeNode* parent;
    list<TreeNode<T>*> children;

    TreeNode(const T& dataValue) { data = dataValue; parent = nullptr; }
    TreeNode(TreeNode* parentPtr, const T& dataValue)
    { 
        data = dataValue;
        parent = parentPtr; 
        parentPtr->children.push_back(this); // Append this object to the children
                                             // list of its parent           
    };
};

