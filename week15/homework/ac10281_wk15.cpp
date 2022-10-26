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
            :head(nullptr), size(0)
        { }
        LinkedList(const LinkedList& rhs)
            :head(nullptr), size(0)
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
                size++;
                return;
            }

            Node<T>* temp = head;

            while (temp->get_next() != nullptr)
            {
                temp = temp->get_next();
            }

            temp->set_next(new_node);
            size++;
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
        T pop_back()
        {
            if (isEmpty())
            {
                cout << "Error! Illegal operation; List is already empty, exiting now";
                exit(1);
            }

            int _data;

            if (head->get_next() == nullptr) 
            {
                _data = head->get_data();
                head = nullptr;
                return _data;
            }           

            Node<T>* temp_curr = head;
            Node<T>* temp_prev = nullptr;
            while (temp_curr->get_next() != nullptr)
            {
                temp_prev = temp_curr;
                temp_curr = temp_curr->get_next();
            }

            _data = temp_curr->get_data();
            temp_prev->set_next(nullptr);
            delete temp_curr;

            --size;
            return _data;
        }
        T pop_front()
        {
            if(isEmpty())
            {
                cout << "Error! Illegal operation; List is already empty, exiting now";
                exit(1);
            }

            int _data = head->get_data();
            Node<T>* temp = head;
            head = temp->get_next();
            temp->set_next(nullptr);
            delete temp;
            --size;
            return _data;
        }
        T removeFromHead()
        {
            return 0;

        }
        bool isEmpty() const { return head == nullptr;}
        void clear()
        {
            if (isEmpty())
            {
                return;

            }
            
            Node<T>* temp = nullptr;
            while (head->get_next() != nullptr)
            {
                temp = head;
                head = head->get_next();
                temp->set_next(nullptr);
                delete temp;
            }

            size = 0;
        }

        int get_size() const
        {
            return size;
        }

private:
    Node<T>* head;
    unsigned int size;

};
  
// Function to delete the
// node at given position
int main()
{
    LinkedList<int> linky;
    linky.push_back(10);
    linky.push_back(50);
    linky.push_front(5);
    cout << linky.pop_back() << '\n';
    cout << linky.pop_front() << '\n';
    cin.get();

}