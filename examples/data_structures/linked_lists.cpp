#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    Node()
        :data(), next(nullptr)
    {}
    Node(T new_data)
        :data(new_data), next(nullptr)
    {}
    ~Node()
    {
        next = nullptr;
    }
    void set_next(Node<T>* node)
    {
        next = node;
    }
    void set_data(T new_data)
    {
        data = new_data;
    }
    Node<T>* const get_next()
    {
        return next;
    }
    T const get_data()
    {
        return data;
    }

private:
    T data;
    Node<T>* next;
};

template <class T>
class LinkedList
{
public:
    LinkedList()
        :head(nullptr)
    {}
    void push_back(T data)
    {
        Node<T>* new_node = new Node<T>(data);
        push_back(new_node);
    }
    void push_back(Node<T>* new_node)
    {
        Node<int>* temp = head;
        if (temp == nullptr)
        {
            head = new_node;
            return;
        }
        while (temp->get_next() != nullptr)
        {
            temp = temp->get_next();
        }

        temp->set_next(new_node);
    }
    T pop_back()
    {
        T returning_data;
        if (head == nullptr)
        {
            cout << "ERROR: List is empty. Exiting Program Now" << '\n';
            exit(1);
        }
        if (head->get_next() == nullptr)
        {
            returning_data = head->get_data();
            head = nullptr;
            return returning_data;
        }

        Node<T>* temp_curr = head->get_next();
        Node<T>* temp_prev = head;

        while (temp_curr->get_next() != nullptr)
        {
            temp_prev = temp_curr;
            temp_curr = temp_curr->get_next();
        }
        
        returning_data = temp_curr->get_data();
        temp_prev->set_next(nullptr);
        delete temp_curr;
        return returning_data;
    }
    void print_list()
    {
        if (head == nullptr)
            cout << "List is empty" << '\n';

        Node<T>* temp = head;
        while (temp != nullptr)
        {
            cout << temp->get_data() << '\n';
            temp = temp->get_next();
        }
    }
private:
    Node<T>* head;
};

int main()
{
    Node<int> node = Node<int>(10);
    node.set_data(10);
    Node<int> new_node = Node<int>(20);
    node.set_next(&new_node);
    Node<int> another_node = Node<int>();
    //Node<int> new_node = node;

    LinkedList<int> linky = LinkedList<int>();
    linky.push_back(10);
    cout << linky.pop_back() << " POP!" << '\n';
    linky.push_back(20);
    linky.push_back(30);
    linky.push_back(40);
    cout << linky.pop_back() << " POP!" << '\n';
    linky.push_back(&node);
    cout << linky.pop_back() << " POP!" << '\n';
    linky.push_back(new Node<int>());
    linky.print_list();
    cin.get();

}
