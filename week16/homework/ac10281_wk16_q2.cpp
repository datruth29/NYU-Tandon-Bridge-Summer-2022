#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class Queue
{
public:
    Queue()
        :m_queue(), m_size(0), m_index_start(0)
    {}
    ~Queue() = default;
    
    void enqueue(T data)
    {
        m_queue.push_back(data);
        ++m_size;
    }

    T dequeue()
    {
        if (m_size == 0)
        {
            cout << "ERROR: Can't get data off queue because queue is empty.";
            exit(1);
        }
        T return_result = m_queue.at(m_index_start);
        --m_size;
        ++m_index_start;
        if(isEmpty())
        {
            reset();
        }
        return return_result;
    }

    void peek() const
    {
        if (m_size == 0)
        {
            string err = "Error: Can't peek into an empty queue. Quitting program.";
            error(err);
        }

        cout << m_queue.front() << '\n';
    }

    int size() const
    {
        return (m_queue.size() - m_index_start);
    }

    bool isEmpty() const
    {
        return (m_size == 0);
    }

private:
    vector<T> m_queue;
    size_t m_size;
    size_t m_index_start;

    void error(string& err_message) const
    {
        cout << err_message << '\n';
        exit(1);
    }

    void reset()
    {
        cout << "Resetting inner vector" << '\n';
        m_queue.clear();
        m_index_start = 0;
        m_size = 0;
    }
};

int main()
{

    Queue<int> test_queue;

    test_queue.size();
    test_queue.enqueue(1);
    cout << (test_queue.size() == 1) << '\n';
    int num = test_queue.dequeue();
    cout << num << '\n';
    test_queue.enqueue(2);
    test_queue.enqueue(5);
    test_queue.enqueue(6);
    num = test_queue.dequeue();
    cout << num << '\n';
    cout << test_queue.size() << '\n';
    num = test_queue.dequeue();
    cout << num << '\n';
    test_queue.enqueue(2);
    num = test_queue.dequeue();
    cout << num << '\n';
    test_queue.peek();
    cout << test_queue.size() << '\n';
    

    num = test_queue.dequeue();
}