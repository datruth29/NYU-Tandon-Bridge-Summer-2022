#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Queue
{
public:
    Queue()
        :m_queue(), m_index_start(0), m_size(0)
    {}
    ~Queue() = default;
    
    void enqueue(T data)
    {
        m_queue.append(data);
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
        ++m_index_start
    }

    T peek() const
    {
        if (m_size == 0)
    }

private:
    vector<T> m_queue;
    size_t m_size;
    size_t m_index_start;

    void access_error()
    {
        
    }
} int main()
{

}