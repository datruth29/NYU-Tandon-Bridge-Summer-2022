// C++ program for the above approach
#include <iostream>
using namespace std;
  
// Node class to represent
// a node of the linked list.
template <class T>
class Node {
public:
	Node(T new_data = T(), Node<T>* new_next = nullptr)
		:data(new_data), next(new_next)
	{}
	T get_data() const
	{
		return data;
	}
	Node<T>* get_next() const
	{
		return next;
	}
    void set_data(T new_data)
    {
        data = new_data;
    }
    void set_next(Node<T>* new_next)
    {
        next = new_next;
    }

private:
	T data;
	Node<T>* next;
};

// Linked list class to
// implement a linked list.

template <class T>
class LinkedList {
    public:
        LinkedList()
            :head(nullptr)
        { }
        LinkedList(const LinkedList& rhs)
            :head(nullptr)
        {
            *this = rhs;
        }

        LinkedList<T>& operator=(const LinkedList<T>& rhs);
        ~LinkedList() { clear();}
        
        void push_back(T new_data)
        {
            Node<T>* new_node = new Node<T>(new_data);

            if (isEmpty())
            {
                head = new_node;
                return;
            }

            Node<T>* temp = head;

            while (temp->get_next() != nullptr)
            {
                temp = temp->get_next();
            }

            temp->set_next(new_node);
        }
        void push_front(T new_data)
        {
            Node<T>* new_node = new Node<T>(new_data);

            if (isEmpty())
            {
                head = new_node;
                return;
            }
            new_node->set_next(head);
            head = new_node;

        }
        T removeFromHead()
        {
            return 0;

        }
        bool isEmpty() const { return head == nullptr;}
        void clear()
        {
            return;
        }

        int size() const
        {
            return 0;
        }

private:
    Node<T>* head;

};
  
// Function to delete the
// node at given position
int main()
{
    LinkedList<int> linky;
    linky.push_back(10);
    linky.push_back(50);
    linky.push_front(5);
    cin.get();

}