#include "Header.h"

Deque::Deque()
{
	head = tail = nullptr;
	count = 0;
}


Deque::Deque(int a)
{
	head = tail = new Node();
	head->prev = nullptr;
	head->next = nullptr;
	head->data = a;
}

Deque& Deque::operator=(Deque &&other)
{
	if (this == &other)
	{
		return *this;
	}
	delete head;
	head = other.head;
	other.head = nullptr;
}


int Deque::GetSize()
{
	return count;
}

bool Deque::pushFront(const int a)
{
	Node* newNode = new Node();
	newNode->data = a;
	if (head == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	count++;
	return true;
};


bool Deque::pushBack(const int a)
{
	Node* newNode = new Node();
	newNode->data = a;
	if (tail == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;

	}
	count++;
	return true;
};

bool Deque::popFront(int& a)
{
	if (head == nullptr)
	{
		return false;
	}
	else
	{
		a = head->data;
		Node* temp = head;
		head = head->next;
		if (head == nullptr) {
			tail = nullptr;
		}
		else
		{
			head->prev = nullptr;
		}
		count--;
		return true;
	}
};

bool Deque::popBack(int& a)
{
	if (head == nullptr)
	{
		return false;
	}
	else
	{
	a = tail->data;
	Node* temp = tail;
	tail = tail->prev;
	if (tail == nullptr) {
		head = nullptr;
	}
	else
	{
		tail->next = nullptr;
	}
	count--;
	return true;
	}
};

bool Deque::peekFront(int& a)
{
	if (head == nullptr)
	{
		return false;
	}
	else
	{
		a = head->data;
		return true;
	}
}

bool Deque::peekBack(int& a)
{
	if (head == nullptr)
	{
		return false;
	}
	else
	{
		a = tail->data;
		return true;
	}
}