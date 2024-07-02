/*
Name:			Syed Aalyan Raza Kazmi
Roll Number:	22i-0833
Section:		A
*/
#pragma once
#include<iostream>
#include<string>
using namespace std;

template <class t>
class Node
{
public:
	t data;
	Node* next;

	Node(t num = 0)
	{
		data = num;
	}
};


template <class t>
class Stack
{
public:
	Node<t>* top;
	int numelements;

	Stack(int ignored = 0)
	{
		top = NULL;
	}
	bool isEmpty()
	{
		return top == NULL;
	}

	void push(const t DataItem)
	{
		Node<t>* temp = new Node<t>(DataItem);
		temp->next = top;
		top = temp;
		numelements++;
	}
	t pop()
	{
		if (top)
		{
			t temp = top->data;
			Node<t>* temp1 = top;
			top = top->next;
			delete temp1;
			return temp;
			numelements--;
		}
		return -1;
	}
	t peek()
	{
		if (top)
			return top->data;
	}

	void clear()
	{
		while (top)
		{
			pop();
		}
	}

};
//Question 1
/*
The for loop run for the length of the string and while loop runs for a max ' k ' times. Hence the complexity is O(length of string +k)
*/
string largestString(string str, int k)
{
	Stack<char> stack;

	for (char s : str)
	{
		while (!stack.isEmpty() && stack.peek() < s && k > 0)
		{
				stack.pop();
				k--;
		}
		stack.push(s);
		if (stack.numelements == 1 && s == '0')
		{
			stack.pop();
			k--;
		}
	}
	if (k > 0)
	{
		while (k > 0 && !stack.isEmpty())
		{
			stack.pop();
			k--;
		}
	}


	string result = "";
	while (!stack.isEmpty())
	{
		result += stack.pop();
	}
	reverse(result.begin(), result.end());
	return result;
}

//Question 2
/*
The for loop run for the length of the string and while loop runs for a max ' k ' times. Hence the complexity is O(length of string +k)
*/

string solve(string number, int k)
{
	if (k == 0)
		return number;
	
	Stack<char> stack;
	stack.push(number[0]);
	bool clear = 0;

	for (char s : number)
	{
		if (!clear)
		{
			clear = 1;
			continue;
		}
		if (s < stack.peek() || stack.peek() == '0')
		{
			if (s != '0')
			{
				while ((k > 0 && !stack.isEmpty() && s < stack.peek()) || stack.peek() == '0')
				{
					if (stack.peek() == '0')
					{
						Node<char>* temp= stack.top;
					
						int zeronum = 0;
						while (temp->data == '0')
						{
							temp = temp->next;
							zeronum+=1;
						}
						if (zeronum < k && temp->data > s)
						{
							int i = 0;
							while (i < zeronum+1)
							{
								k -= 1;
								stack.pop();
								i++;
							}
						}
						break;
					}
					else
					{
						k -= 1;
						stack.pop();
					}
				}
				
			}
			else
			{
				while (k > 0 && stack.top->next && s < stack.peek())
				{
					k = k - 1;
					stack.pop();
				}
			}
			stack.push(s);
		}
		else
		{
			stack.push(s);
		}
	}
	
	if (k > 0)
	{
		while (k > 0 && !stack.isEmpty())
		{
			stack.pop();
			k--;
		}
	}


	string result = "";
	while (!stack.isEmpty())
	{
		result += stack.pop();
	}
	reverse(result.begin(), result.end());
	return result;
}

template <class t>
class QNode
{
public:
	t data;
	QNode* next;

	QNode(t num) { data = num; next = NULL; }
};

template <class t>
class Queue
{
public:
	QNode<t>* head;
	QNode<t>* tail;

	int size()
	{
		if (head == NULL)
			return 0;
		else
		{
			QNode<t>* current = head;
			int num = 0;
			while (current)
			{
				current = current->next;
				num++;
			}
			return num;
		}
	}

	Queue() { head = tail = NULL; }
	Queue(Queue* copy)
	{
		head = copy->head;
		tail = copy->tail;
	}

	void enqueue(t num)
	{
		QNode<t>* ptr = new QNode<t>(num);
		if (head == NULL)
			head = tail = ptr;
		else
		{
			tail->next = ptr;
			tail = ptr;
		}
	}
	t dequeue()
	{
		if (head == NULL)
			return -1;
		else if (head == tail)
		{
			t num = head->data;
			delete head;
			head = tail = NULL;
			return num;
		}
		else if (head)
		{
			t num = head->data;
			QNode<t>* ptr = head;
			head = head->next;
			delete ptr;
			return num;
		}
	}
	t peek()
	{
		if (head)
			return head->data;
		else
			return -1;
	}

	bool is_empty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}
	void clear()
	{
		while (head)
			dequeue();
		tail == NULL;
	}
};


//Question 3
/*
The for loop run for the length of array so its complexity is O(n)
*/
int* maxSubsequence(int nums[], int size, int k)
{
	Queue<int> queue;
	int maxsum = 0;
	int maxindex = 0;

	for (int i = 0; i < k; i++)
	{
		maxsum += nums[i];
		queue.enqueue(nums[i]);
	}

	int currentsum = maxsum;

	for (int i = k; i < size; i++)
	{
		currentsum += nums[i];
		currentsum -= queue.dequeue();
		queue.enqueue(nums[i]);

		if (currentsum > maxsum)
		{
			maxsum = currentsum;
			maxindex = i - k + 1;
		}
	}

	int* arr = new int[k];
	for (int i = 0; i < k; i++)
	{
		arr[i] = nums[maxindex + i];
	}

	return arr;
}
