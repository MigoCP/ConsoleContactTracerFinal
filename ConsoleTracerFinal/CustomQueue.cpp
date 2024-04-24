#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    //Node(int data)
    //{
    //    this->data = data;
    //    this->next = nullptr;
    //}

};

class MyQueue
{
private:
    Node* front;
    Node* rear;
    int size;

public:
    MyQueue()
    {
        this->front = nullptr;
        this->rear = nullptr;
        this->size = 0;
    }

    bool IsEmpty()
    {
        return this->size == 0;
    }

    int GetSize()
    {
        return this->size;
    };

    void Enqueue(int elem)
    {
        Node* temp = new Node();//(elem);
        temp->data = elem;
        temp->next = nullptr;
        if (this->rear == nullptr)
        {
            this->front = this->rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
        this->size++;
    }

    void Dequeue()
    {
        if (IsEmpty())
        {
            cout << "The list is empty.";
        }
        else
        {
            Node* temp = front;
            front = front->next;
            delete temp;
            this->size--;
        }
    }

    void Display()
    {
        cout << "Queue elements: ";
        if (IsEmpty())
        {
            cout << "There is nothing to display.\n The queue is empty";
        }
        else
        {
            for (Node* p = front; p != nullptr; p = p->next) {
                cout << p->data << " ";
            }
        }
        cout << endl;
    }
};
int main()
{

    std::cout << "Welcome To Our Queue Implementation!\n";

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
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
