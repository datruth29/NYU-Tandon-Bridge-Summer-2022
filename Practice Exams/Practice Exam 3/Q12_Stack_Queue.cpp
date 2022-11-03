#include <iostream>
#include <queue>

template <class T>
class QueueStack 
{
public:
	
	QueueStack()
	{}

	T peek() const
	{
		return _queue.front();
	}
	void push(T item)
	{
		if (isEmpty())
		{
			_queue.push(item);
			return;
		}
		_queue.push(item);

		for (size_t i = size(); i > 1; --i)
		{
			T temp = _queue.front();
			_queue.pop();
			_queue.push(temp);
		}
		
	}

	T pop()
	{
		T result = _queue.front();
		_queue.pop();

		return result;
	}

	bool isEmpty() const
	{
		return _queue.empty();
	}

	size_t size() const
	{
		return _queue.size();
	}
private:
	std::queue<T> _queue;
};

int main()
{
	QueueStack<int> test;
	std::queue<int> test_2;




	std::cout << "Pushing 1\n";
	test.push(1);
	std::cout << "Pushing 2\n";
	test.push(2);
	std::cout << "Pushing 3\n";
	test.push(3);
	std::cout << "Pushing 8\n";
	test.push(8);
	std::cout << "Pushing 7\n";
	test.push(7);
	std::cout << "Pushing 10\n";
	test.push(10);
	std::cout << test.peek()  << '\n';
	test.pop();
	std::cout << test.peek()  << '\n';
	test.pop();
	std::cout << test.peek()  << '\n';
	test.pop();
	std::cout << test.peek()  << '\n';
	test.pop();
	std::cout << test.peek()  << '\n';
	test.pop();
	std::cout << test.peek()  << '\n';

}
