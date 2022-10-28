// C++ program for the above approach
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
  
class Customer
{
public:
    Customer()
        :price(0), name("")
    {}
    Customer(double new_price, string new_name)
        :price(new_price), name(new_name)
    {}
    bool operator==(const Customer& rhs)
    {
        return (price == rhs.price && name == rhs.name);
    }
    bool operator<(const Customer& rhs)
    {
        return (price < rhs.price);
    }
    bool operator>(const Customer& rhs)
    {
        return (price > rhs.price);
    }
    bool operator<=(const Customer& rhs)
    {
        return (price <= rhs.price);
    }
    bool operator>=(const Customer& rhs)
    {
        return (price >= rhs.price);
    }
    friend ostream& operator<<(ostream& outs, const Customer& customer)
    {
        outs << "Name: " << customer.name << '\n';
        outs << "Price: " << customer.price << "\n\n";
        return outs;
    }

public:
    double price;
    string name;


};

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
                ++size;
                return;
            }

            Node<T>* temp = head;

            while (temp->get_next() != nullptr)
            {
                temp = temp->get_next();
            }

            temp->set_next(new_node);
            ++size;
        }
        void push_front(T new_data)
        {
            Node<T>* new_node = new Node<T>(new_data);

            if (isEmpty())
            {
                head = new_node;
                ++size;
                return;
            }
            new_node->set_next(head);
            head = new_node;
            ++size;

        }
        T pop_back()
        {
            if (isEmpty())
            {
                cout << "Error! Illegal operation; List is already empty, exiting now";
                exit(1);
            }

            T _data;

            if (head->get_next() == nullptr) 
            {
                _data = head->get_data();
                head = nullptr;
                --size;
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
        void insert_after(unsigned int loc, T new_data)
        {
            if (loc < 0)
                cout << "ERROR: Location must be greater than 0;";
            if (loc >= size)
                cout << "ERROR: Location must be less than size. If placing in last location, index is size - 1";
            if (loc == 0)
                push_front(new_data);
            if (loc == size - 1)
                push_back(new_data);
            
            Node<T>* new_node = new Node<T>(new_data);
            Node<T>* temp_curr = head;
            for (size_t i = 0; i < loc; ++i)
            {
                temp_curr = temp_curr->get_next();
            }

            Node<T>* temp_next = temp_curr->get_next();
            temp_curr->set_next(new_node);
            new_node->set_next(temp_next);
            ++size;
        }
        void insert_before(unsigned int loc, T new_data)
        {
            if (loc < 0)
                cout << "ERROR: Location must be greater than 0;";
            if (loc >= size)
                cout << "ERROR: Location must be less than size. If placing in last location, index is size - 1";
            if (loc == 0)
                push_front(new_data);
            if (loc == size - 1)
                push_back(new_data);
            Node<T>* new_node = new Node<T>(new_data);
            Node<T>* temp_curr = head;
            for (size_t i = 0; i < loc; ++i)
            {
                temp_curr = temp_curr->get_next();
            }


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

            head = nullptr;

            size = 0;
        }

        void push_in_asc_order(Node<T>* node)
        {
            if (isEmpty())
                push_front(node);
            
            Node<T>* temp = head;

            for (size_t i = 0; i < size; i++)
            {
                if (node.get_data() <= 
            }

        }

        int get_size() const
        {
            return size;
        }

        void print_list() const
        {
            if (isEmpty())
                return;

            Node<T>* temp = head;
            for (size_t i = 0; i < size; ++i)
            {
                cout << "@: " << i << '\n';
                cout << "Data: " << temp->get_data() << '\n';
                temp = temp->get_next();
            }

            if (temp != nullptr)
            {
                cout << "ERROR: This should be end of list. Check the print_list() member function";
                exit(1);
            }
        }

private:
    Node<T>* head;
    unsigned int size;

};
  
LinkedList<Customer> process_data_file(ifstream& data_file);
void remove_white_space(string& line);
// Function to delete the
// node at given position
int main()
{

    ifstream data_file;

    data_file.open("data.txt");

    if (data_file.fail())
    {
        cout << "Error opening file. Check file first.";
        exit(1);
    }

    LinkedList<Customer> customer_data = process_data_file(data_file);
    cout << customer_data.get_size();
    customer_data.print_list();
//    Node<Customer> customer = customer_data.pop_back();



}

LinkedList<Customer> process_data_file(ifstream& data_file)
{
    LinkedList<Customer> processed_data;

    double price = 0;
    string name = "";
    Customer new_customer;
    while (!data_file.eof())
    {
        data_file >> price;
        getline(data_file, name);
        new_customer.price = price;
        new_customer.name = name;
        processed_data.push_front(new_customer);
       // cout << "Price: " << price << '\n';
       // cout << "Name: " << name << '\n';
       // cout << "Space:" << name[name.size()] << "| " << '\n';
       // cout << '\n';
       // int space = name.find_first_not_of('\t');
       // cout << "Space Location: " << space << "\n\n";
    }

    return processed_data;
}
void remove_white_space(string& line)
{
    if (line.empty())
        return;
    
    int begin = 0;
    int end = line.size();
}

void test_linked_list()
{
    LinkedList<int> linky;
    linky.push_back(10);
    linky.push_back(50);
    linky.push_front(5);
    cout << linky.pop_back() << '\n';
    cout << linky.pop_front() << '\n';
    linky.clear();
    cout << linky.get_size() << '\n';
    linky.print_list();
    linky.push_back(50);
    linky.push_back(8);
    linky.push_back(0);
    linky.print_list();
    linky.insert_after(1, 15);
    linky.print_list();

    cin.get();
}