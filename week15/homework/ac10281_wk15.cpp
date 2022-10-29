// C++ program for the above approach
#include <iostream>
#include <vector>
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

template <class T>
class LinkedList {
    public:
        LinkedList()
            :head(nullptr), tail(nullptr), size(0)
        { }
        LinkedList(const LinkedList& rhs)
            :head(nullptr), tail(nullptr), size(0)
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
                tail = new_node;
                ++size;
                return;
            }

            tail->set_next(new_node);
            tail = tail->get_next();
            ++size;
        }
        void push_front(T new_data)
        {
            Node<T>* new_node = new Node<T>(new_data);

            if (isEmpty())
            {
                head = new_node;
                tail = new_node;
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
                tail = nullptr;
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
            tail = temp_prev;
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

            T _data = head->get_data();
            if (head == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                Node<T>* temp = head;
                head = temp->get_next();
                temp->set_next(nullptr);
                delete temp;
            }
            --size;
            return _data;
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
            tail = nullptr;

            size = 0;
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

        void insert_asc_order(T data)
        {
            if (isEmpty())
            {
                push_back(data);
                return;
            }

            if (data <= head->get_data())
            {
                push_front(data);
                return;
            }

            if (data >= tail->get_data())
            {
                push_back(data);
                return;
            }


            Node<T>* temp_curr = head->get_next();
            Node<T>* temp_prev = head;
            while (data > temp_curr->get_data())
            {
                temp_prev = temp_curr;
                temp_curr = temp_curr->get_next();
            }

            Node<T>* node = new Node<T>(data);
            temp_prev->set_next(node);
            node->set_next(temp_curr);
            ++size;
        }

private:
    Node<T>* head;
    Node<T>* tail;
    unsigned int size;

};
  
LinkedList<Customer> process_data_file(ifstream& data_file, double& average);
void remove_white_space(string& line);

int main()
{

    ifstream data_file;

    string data_file_name;
    cout << "Enter the filename: ";
    cin >> data_file_name;

    data_file.open(data_file_name);

    if (data_file.fail())
    {
        cout << "Error opening file. Check file name.";
        exit(1);
    }

    double average = 0;
    LinkedList<Customer> customer_data = process_data_file(data_file, average);
    vector<Customer> customers;
    customers.reserve(customer_data.get_size());

    while(!customer_data.isEmpty())
    {
        Customer temp = customer_data.pop_front();

        if (temp.price == average)
        {
            cout << temp.name << ", you don't need to do anything\n";
            continue;
        }
        if (temp.price < average)
        {
            customers.push_back(temp);
            continue;
        }

        if (temp.price > average)
        {
            if (customers.empty())
            {
                cout << "Something is wrong with inserts in the customer vector.";
                exit(1);
            }

            double amount_owed = temp.price - average;

            while (static_cast<int>(amount_owed) > 0)
            {
                double amount_payed = 0;
                double amount_can_be_payed = average - customers.back().price;
                if (amount_can_be_payed > amount_owed)
                {
                    amount_payed = amount_owed;
                    customers.back().price += amount_payed;
                    cout << customers.back().name << ", you gave " << temp.name << " $" << amount_payed << '\n';
                }
                else
                {
                    amount_payed = amount_can_be_payed;
                    cout << customers.back().name << ", you gave " << temp.name << " $" << amount_payed << '\n';
                    customers.pop_back();
                }
                amount_owed -= amount_payed;
            }
        }
    }
    cout << "In the end, you should all have spent around $" << average;
}

LinkedList<Customer> process_data_file(ifstream& data_file, double& average)
{
    LinkedList<Customer> processed_data;

    double sum = 0;
    double price = 0;
    string name = "";
    Customer new_customer;
    while (!data_file.eof())
    {
        data_file >> price;
        sum += price;
        getline(data_file, name);
        remove_white_space(name);
        new_customer.price = price;
        new_customer.name = name;
        processed_data.insert_asc_order(new_customer);
    }

    average = sum / processed_data.get_size();

    return processed_data;
}
void remove_white_space(string& line)
{
    if (line.empty())
        return;
    
    while (line.at(0) == ' ' || line.at(0) == '\t')
        line.erase(line.begin());
}