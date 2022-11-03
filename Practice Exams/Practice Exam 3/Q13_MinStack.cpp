#include <iostream>
#include <stack>

struct StackNode
{
	int value;
	int min;
};
class MinStack
{
public:
	MinStack()
	{}

	void push(int value)
	{
		StackNode node;
		node.value = value;
		if (_stack.empty())
		{
			node.min = value;
			_stack.push(node);
			return;
		}
		

		int current_min = _stack.top().min;
		if (current_min > value)
		{
			node.min = value;
		}
		else
		{
			node.min = current_min;
		}
		_stack.push(node);
	}

	void pop()
	{
		_stack.pop();
	}

	int top() const
	{
		return _stack.top().value;

	}

	int getMin() const
	{
		return _stack.top().min;
	}
private:
	std::stack<StackNode> _stack;
};

int main()
{
	MinStack test = MinStack();

	test.push(10);
	test.push(5);
	test.push(15);

	std::cout << test.getMin() << '\n';
	test.push(1);
	std::cout << test.getMin() << '\n';
	test.pop();
	std::cout << test.getMin() << '\n';

}