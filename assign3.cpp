//============================================================================
// Name        : assign3.cpp
// Author      : SHG
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define max 20
using namespace std;

class NODE
{
	int data;
	NODE* lchild;
	NODE* rchild;
	bool lbit;
	bool rbit;

public:
	NODE(int X)
	{
		data = X;
		lchild = rchild = NULL;
		lbit = rbit = 0;
	}
	friend class TBT;
};

class Queue
{
	NODE* Q[max];
	int front;
	int rear;

public:
	Queue()
	{
		for (int i = 0; i < max; i++)
			Q[i] = NULL;

		front = rear = -1;
	}

	void enque(NODE* ele);

	void dequeue();

	bool empty();

	bool full();

	NODE* get_front();
};

void Queue::enque(NODE* ele)
{
	if (front == -1)
		front = 0;
	rear = rear + 1;

	Q[rear] = ele;
}

void Queue::dequeue()
{
	if (empty())
	{
		cout << "EMPTY !!";
	}
	else
	{
		front = front + 1;

		if (front > rear)
			front = rear = -1;
	}
}

bool Queue::empty()
{
	if (front == -1)
		return 1;
	else
		return 0;
}

bool Queue::full()
{
	if (rear == max - 1)
		return 1;
	else
		return 0;
}

NODE* Queue::get_front()
{
	NODE* temp = Q[front];

	if (temp == NULL)
		return NULL;
	else
		return temp;
}

class TBT
{
	NODE* header;
	NODE* root;

public:
	TBT()
	{
		header = new NODE(-99);
		header->lbit = header->rbit = 0;
		header->lchild = header->rchild = header;

		root = NULL;
	}

	NODE* head()
	{
		return header;
	}

	void insert(int x)
	{
		if (root == NULL)
		{
			header->lbit = 1;
			root = new NODE(x);
			header->lchild = root;
			root->lchild = root->rchild = header;
		}
		else
		{
			NODE* ptr = root;
			NODE* new1 = new NODE(x);

			while (1)
			{
				if (ptr->data > new1->data)
				{
					if (ptr->lbit == 0)
					{
						new1->lbit = 0;
						new1->lchild = ptr->lchild;
						ptr->lbit = 1;
						ptr->lchild = new1;
						new1->rbit = 0;
						new1->rchild = ptr;

						return;
					}
					else
					{
						ptr = ptr->lchild;
					}
				}
				else
				{
					if (ptr->rbit == 0)
					{
						new1->rbit = 0;
						new1->rchild = ptr->rchild;
						ptr->rbit = 1;
						ptr->rchild = new1;
						new1->lbit = 0;
						new1->lchild = ptr;

						return;
					}
					else
					{
						ptr = ptr->rchild;
					}
				}
			}
		}
	}

	void Inorder_disp(NODE* h)
	{
		NODE* temp = h->lchild;

		while (temp->lbit != 0)
		{
			temp = temp->lchild;
		}
		
		while (temp != h)
		{
			cout << temp->data << " ";

			if(temp->rbit == 1)
			{
				temp = temp->rchild;

				while(temp->lbit != 0)
					temp = temp->lchild;
			}
			else
				temp = temp->rchild;
		}
	}

	void Preorder_disp(NODE* h)
	{
		NODE* T = h->lchild;

		while(T != h)
		{
			cout<<T->data<<" ";
			if(T->lbit == 1)
				T = T->lchild;
			else
			{
				if(T->rbit == 1)
					T = T->rchild;
				else
				{
					while(T->rbit != 1 && T != h)
						T = T->rchild;
					T = T->rchild;
				}
			}
		}
	}
};

int main()
{
	TBT t;
	int n, data;
	int choice;

	do
	{
		cout<<"============================="<<endl;
		cout<<"Which operation to perform ? "<<endl;
		cout<<"1. Create a TBT "<<endl;
		cout<<"2. Insert new nodes in TBT "<<endl;
		cout<<"3. In-order display of TBT "<<endl;
		cout<<"4. Pre-order display of TBT "<<endl;
		cout<<"5. Exit "<<endl;
		cout<<"============================="<<endl;
		cin>>choice;

		switch(choice)
		{
		case 1:
			cout << "How many nodes ? " << endl;
			cin >> n;

			for (int i = 0; i < n; i++)
			{
				cout << " DATA : ";
				cin >> data;
				t.insert(data);
			}

			break;

		case 2:
			cout << "How many nodes ? " << endl;
			cin >> n;

			for (int i = 0; i < n; i++)
			{
				cout << " DATA : ";
				cin >> data;
				t.insert(data);
			}

			break;

		case 3:
			cout<<"In-order list : ";
			t.Inorder_disp(t.head());
			cout<<endl;

			break;

		case 4:
			cout<<"Pre-order list : ";
			t.Preorder_disp(t.head());
			cout<<endl;

			break;

		case 5:
			cout<<"Terminating program !! "<<endl;
			break;

		default:
			cout<<"Enter a valid option "<<endl;
			break;
		}
	}while(choice != 5);

	return 0;
}
