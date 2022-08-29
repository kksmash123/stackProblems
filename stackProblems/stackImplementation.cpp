#include <iostream>
using namespace std;


//stack using array

struct stack
{
	int size;
	int top;
	int* s;
};


//stack using linked list

struct Node
{
	int data;
	Node* next;
}*top =NULL;

//stack functions using linked list

struct Node* pushLL(struct Node* top,int val)
{
	//check for stack full condition

	struct Node* newNode = new Node;
	if (!newNode)
	{
		cout << "stack is full " << endl;
		delete newNode;
		return top;
	}

	newNode->data = val;
	newNode->next = top;
	top = newNode;
	return top;

}

void DisplaySLL(struct Node* top)
{
	if (!top)
	{
		cout << "stack is empty " << endl;
		return;
	}
	while (top)
	{
		cout << top->data << " ";
		top = top->next;
	}
}

int popSLL(struct Node* p)
{
	top = p->next;
	int x = p->data;
	delete p;
	return x;
}

int peekSLL(struct Node *p,int pos)
{
	for (int i = 0;i < pos - 1;i++)
		p = p->next;
	int x = p->data;
	return x;
}

bool IsEmpty(struct Node* top)
{
	return top ? 0 : 1;
}

bool IsFull()
{
	struct Node* newNode = new Node;
	if (!newNode)
	{
		delete newNode;
		return 1;
	}
	delete newNode;
	return 0;
}



//stack functions using array

void create(struct stack *pst)
{
	pst->size = 5;
	pst->top = -1;
	pst->s = new int[pst->size];

}

void DisplayStack(struct stack st)
{
	if (st.top == -1)
	{
		cout << "stack is empty " << endl;
		return;
	}

	for (int i = st.top;i >= 0;i--)
		cout << st.s[i] << " ";
	cout << endl;
}

void Push(struct stack* pst, int x)
{
	if (pst->top == pst->size - 1)
	{
		cout << "stack is overflow " << endl;
		return;
	}
	pst->s[++pst->top]=x;
}

int pop(struct stack* pst)
{
	int x = -1;
	if (pst->top == -1)
	{
		cout << "stack is underflow " << endl;
		return x;
	}
	x = pst->s[pst->top--];
	return x;
}

int peek(struct stack st,int pos)
{
	int x = -1;

	if (st.top - pos + 1 < 0)
	{
		cout << "Invalid position " << endl;
		return x;
	}

	return x=st.s[st.top - pos + 1];
}

bool IsEmpty(struct stack st)
{
	return (st.top == -1) ? 1 : 0;
}

bool IsFull(struct stack st)
{
	return (st.top == st.size - 1) ? 1 : 0;
}



int main()
{
	struct stack st;
	create(&st);
	cout << "Is the stack empty ->1(true) otherwise 0(false) : " << IsEmpty(st)<<endl;
	Push(&st, 5);
	Push(&st, 15);
	Push(&st, 25);
	Push(&st, 35);
	Push(&st, 45);
	cout << "After Pushing the elements " << endl;
	DisplayStack(st);
	cout <<endl<< "Is the stack full ->1(true) otherwise 0(false) : " << IsFull(st) << endl;
	cout << "Element deleted using pop : " << pop(&st);
	cout << "After Deletion " << endl;
	DisplayStack(st);
	cout << endl << "Is the stack full ->1(true) otherwise 0(false) : " << IsFull(st) << endl;
	cout << "using peek pos 1 : " << peek(st, 1) << endl;
	cout << "using peek pos 2 : " << peek(st, 2) << endl;
	cout << "using peek pos 3 : " << peek(st, 3) << endl;
	cout << "using peek pos 4 : " << peek(st, 4) << endl;


	//Stack implementation using linked list
	cout << endl << "stack using linked list " << endl;

	top = pushLL(top, 1);
	top = pushLL(top, 2);
	top = pushLL(top, 5);
	top = pushLL(top, 4);

	cout << "After pushing into the stack using linked list :" << endl;
	DisplaySLL(top);
	cout<<endl << "After poping 2 times: " << endl;
	popSLL(top);
	popSLL(top);
	DisplaySLL(top);
	cout << endl << "After peeking 2nd index: " <<peekSLL(top,2) << endl;
	cout << "IsFull() -> true(1)/false(0) " << IsFull()<<endl;
	cout << "IsEmpty() -> true(1)/false(0) " << IsEmpty(top)<<endl;

	
}

