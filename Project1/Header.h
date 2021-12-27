struct Node
{
	int data;
	Node* prev, * next;
};

class Deque
{
public:
	Deque();
	Deque(int count);
	Deque& operator=(Deque&& other);
	int GetSize();
	bool pushFront(const int a);
	bool pushBack(const int a);
	bool popFront(int& a);
	bool popBack(int& a);
	bool peekFront(int& a);
	bool peekBack(int& a);
private:
	Node* head;
	Node* tail;
	int count;
};

