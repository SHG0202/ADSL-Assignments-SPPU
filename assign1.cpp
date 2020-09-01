//============================================================================
// Name        : assign1.cpp
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
	NODE* lchile;
	NODE* rchile;

public:
	NODE(int x)
	{
		data = x;
		lchile = rchile = NULL;
	}

	friend class Tree;
	friend class Queue;
};

class Stack
{
	NODE* S[max];
	int top;

public:
	Stack()
	{
		for (int i = 0; i < max; i++)
			S[i] = NULL;

		top = -1;
	}

	void push(NODE* ele);

	void pop();

	bool empty();

	bool full();

	NODE* get_top();
};

void Stack::push(NODE* ele)
{
	if (!full())
	{
		top++;
		S[top] = ele;
	}
	else
		cout << "OVERFLOW ";
}

void Stack::pop()
{
	if (!empty())
		top--; 
	else
		cout << "UNDERFLOW " << endl;
}

bool Stack::empty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

bool Stack::full()
{
	if (top == max)
		return 1;
	else
		return 0;
}

NODE* Stack ::get_top()
{
	NODE* temp = S[top];
	if (empty())
		return NULL;
	else
		return temp;
}

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

class Tree
{
	NODE* root;
	int leaf_c;
	int inter_c;

public:
	int leaf[max],inter[max];

	Tree()
	{
		root = NULL;
		leaf_c = inter_c = 0;
	}

	void create()
	{
		int choice;

		cout << "How to create ? " << endl;
		cout << "1.Recursively " << endl;
		cout << "2.Non - Recursively " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			root = create_rec();
			break;

		case 2:
			create_nonrec();
			break;

		default:
			cout << "Enter a valid option " << endl;
			break;
		}
		
	}

	NODE* create_rec()
	{
		NODE* new1;
		int x;

		cout << "Enter data or -1 " << endl;
		cin >> x;
		if (x == -1)
		{
			return NULL;
		}
		else
		{
			new1 = new NODE(x);
			cout << "Enter left child of " << new1->data << endl;
			new1->lchile = create_rec();
			cout << "Enter right child of " << new1->data << endl;
			new1->rchile = create_rec();
		}
		return new1;
	}

	void create_nonrec()
	{
		Queue q;
		int x;
		char choice;

		cout << "Enter root node " << endl;
		cin >> x;

		root = new NODE(x);

		q.enque(root);

		while (!q.empty())
		{
			NODE* t = q.get_front();
			q.dequeue();

			cout << "Enter left node of " << t->data << " ? " << endl;
			cin >> choice;

			if (choice == 'y')
			{
				cout << "DATA ? " << endl;
				cin >> x;

				t->lchile = new NODE(x);
				q.enque(t->lchile);
			}

			cout << "Enter right node of " << t->data << " ? " << endl;
			cin >> choice;

			if (choice == 'y')
			{
				cout << "DATA ? " << endl;
				cin >> x;

				t->rchile = new NODE(x);
				q.enque(t->rchile);
			}
		}
	}

	void display()
	{
		int choice;

		cout << "In which format do you want to display ? " << endl;
		cout << "1. Recursive " << endl;
		cout << "2.Non - Recursive " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			display_rec();
			break;

		case 2:
			display_nonrec();
			break;

		default:
			cout << "select a valid option " << endl;
			break;
		}
	}

	void display_rec()
	{
		int choice1;
		char choice2;
		cout << "In which format do you want to display " << endl;
		do
		{
			cout << "1. INORDER " << endl;
			cout << "2. PREORDER " << endl;
			cout << "3. POSTORDER " << endl;
			cin >> choice1;

			switch (choice1)
			{
			case 1:
				inorder_rec(root);
				break;

			case 2:
				preorder_rec(root);
				break;

			case 3:
				postorder_rec(root);
				break;

			default:
				cout << "Enter a valid option " << endl;
			}

			cout << "CONTINUE ? " << endl;
			cin >> choice2;

		} while (choice2 == 'y');
	}

	void inorder_rec(NODE* t)
	{
		if (t != NULL)
		{
			inorder_rec(t->lchile);
			cout << t->data << " ";
			inorder_rec(t->rchile);
		}
	}

	void preorder_rec(NODE* t)
	{
		if (t != NULL)
		{
			cout << t->data << " ";
			preorder_rec(t->lchile);
			preorder_rec(t->rchile);
		}
	}

	void postorder_rec(NODE* t)
	{
		if (t != NULL)
		{
			postorder_rec(t->lchile);
			postorder_rec(t->rchile);
			cout << t->data << " ";
		}
	}

	void display_nonrec()
	{
		int choice1;
		char choice2;

		cout << "In which format do you want to display " << endl;
		do
		{
			cout << "1. INORDER " << endl;
			cout << "2. PREORDER " << endl;
			cout << "3. POSTORDER " << endl;
			cin >> choice1;

			switch (choice1)
			{
			case 1:
				inorder_nonrec();
				break;

			case 2:
				preorder_nonrec();
				break;

			case 3:
				postorder_nonrec();
				break;

			default:
				cout << "Enter a valid option " << endl;
			}

			cout << "CONTINUE ? " << endl;
			cin >> choice2;

		} while (choice2 == 'y');
	}

	void inorder_nonrec()
	{
		Stack s;
		NODE* T = root;
		while (1)
		{
			while (T != NULL)
			{
				s.push(T);
				T = T->lchile;
			}

			if (s.empty())
				return;

			T = s.get_top();
			s.pop();

			cout << T->data << " ";
			T = T->rchile;
		}
	}

	void preorder_nonrec()
	{
		Stack s;
		NODE* T = root;
		/*while (1)
		{
			while (T != NULL)
			{
				cout << T->data << " ";

				if (T->rchile != NULL)
					s.push(T->rchile);

				T = T->lchile;
			}

			if (s.empty())
				return;

			T = s.get_top();
			s.pop();
		}*/

		s.push(T);

		while(!s.empty())
		{
			T = s.get_top();
			s.pop();
			cout<<T->data<<" ";

			while(T->rchile != NULL)
				s.push(T->rchile);
			while(T->lchile != NULL)
				s.push(T->lchile);
		}
	}

	void postorder_nonrec()
	{
		Stack s1,s2;
		NODE* T = root;

		s1.push(T);

		while(!s1.empty())
		{
			T = s1.get_top();
			s1.pop();
			s2.push(T);

			if(T->lchile != NULL)
				s1.push(T->lchile);

			if(T->rchile != NULL)
				s1.push(T->rchile);
		}

		while(!s2.empty())
		{
			T = s2.get_top();
			s2.pop();

			cout<<T->data<<" ";
		}
	}

	NODE* get_root()
	{
		return root;
	}

	void delete_tree(NODE* temp)
	{
		if(temp != NULL)
		{
			delete_tree(temp->lchile);
			delete_tree(temp->rchile);
			cout<<"deleted "<<temp->data<<endl;
			delete temp;
		}
		root = NULL;
	}

	NODE* copy_tree(NODE* temp)
	{
		NODE* cpynode = NULL;

		if(temp)
		{
			cpynode = new NODE(temp -> data);
			cpynode->lchile = copy_tree(temp->lchile);
			cpynode->rchile = copy_tree(temp->rchile);
		}
		return cpynode;
	}

	NODE* mirror_tree(NODE* temp)
	{
		NODE* minode = NULL;

		if(temp)
		{
			minode = new NODE(temp -> data);
			minode->rchile = copy_tree(temp->lchile);
			minode->lchile = copy_tree(temp->rchile);
		}
		return minode;
	}

	void operator=(Tree &t)
	{
		root = t.copy_tree(t.get_root());
	}

	void set_root(NODE* t)
	{
		root = t;
	}

	bool compare(Tree &t)
	{
		Stack s1, s2;
		NODE* temp1 = root;
		NODE* temp2 = t.root;

		s1.push(temp1);
		s2.push(temp2);

		while(!s1.empty() && !s2.empty())
		{
			temp1 = s1.get_top();
			temp2 = s2.get_top();

			if(temp1->data != temp2->data)
				return 0;

			s1.pop();
			s2.pop();

			if(temp1->rchile != NULL || temp2->rchile != NULL)
			{
				s1.push(temp1->rchile);
				s2.push(temp2->rchile);
			}

			if(temp1->lchile != NULL || temp2->lchile != NULL)
			{
				s1.push(temp2->lchile);
				s2.push(temp2->lchile);
			}
		}

		if(!s1.empty() || !s2.empty())
			return 0;
		else
			return 1;
	}

	void FIL_node(NODE* p)
	{
		static int i = 0;
		static int j = 0;

		if(p == NULL)
			return;

		if(p != NULL)
		{
			FIL_node(p->lchile);
			FIL_node(p->rchile);
		}

		if(p->rchile == NULL && p->lchile == NULL)
		{
			leaf_c ++;
			leaf[i] = p->data;
			i++;
		}

		if(p->lchile != NULL || p->rchile != NULL)
		{
			inter_c++;
			inter[j] = p->data;
			j++;
		}
	}

	int get_inter_c()
	{
		return inter_c;
	}

	int get_leaf_c()
	{
		return leaf_c;
	}

	int get_height(NODE* t)
	{
		static int height;

		if(t->lchile == NULL && t->rchile == NULL)
			return 1;
		else
		{
			height = height + max(get_height(t->lchile),get_height(t->rchile));
		}

		return height;
	}
};

int main()
{
	Tree t, cpy, mirror, t1, t2;
	int choice, height;
	char choice2;
	NODE* temp;

	t.create();
	cout<<"TREE CREATED "<<endl;

	do
	{
		cout<<"Which operation do you want to perform with this tree ? "<<endl;
		cout<<"1. Display "<<endl;
		cout<<"2. Copy tree "<<endl;
		cout<<"3. Mirror image of tree "<<endl;
		cout<<"4. delete tree "<<endl;
		cout<<"5. comparing two trees "<<endl;
		cout<<"6. calculating intermediate and leaf nodes of a tree "<<endl;
		cout<<"7. height of tree "<<endl;
		cout<<"8. exit "<<endl;
		cin>>choice;

		switch(choice)
		{
		case 1:
			if(t.get_root() == NULL)
				cout<<"TREE IS EMPTY "<<endl;
			else
				t.display();

			break;

		case 2:
			cpy = t;
			cout<<"In-order copy of tree is : "<<endl;
			cpy.inorder_rec(cpy.get_root());
			break;

		case 3:
			temp = t.mirror_tree(t.get_root());
			mirror.set_root(temp);
			cout<<"In-order mirror of tree is : "<<endl;
			mirror.inorder_rec(mirror.get_root());
			break;

		case 4:
			t.delete_tree(t.get_root());
			break;

		case 5:
			cout<<"ENTER TREE 1 "<<endl;
			t1.create();
			cout<<"ENTER TREE 2 "<<endl;
			t2.create();

			cout<<"TREE 1 : "<<endl;
			t1.display();
			cout<<"TREE 2 : "<<endl;
			t2.display();

			if(t1.compare(t2))
				cout<<"Both trees are equal "<<endl;
			else
				cout<<"Trees are not equal "<<endl;

			break;

		case 6:
			t.FIL_node(t.get_root());

			cout<<"\nIntermediate nodes are : ";
			for(int i=0;i<t.get_inter_c()-1;i++)
				cout<<t.inter[i]<<" ";

			cout<<"\n\n leaf nodes are : ";
			for(int i=0;i<t.get_leaf_c();i++)
				cout<<t.leaf[i]<<" ";

			break;
		case 7:
			height = t.get_height(t.get_root());
			cout<<"Height of tree is : "<<height;
			break;

		case 8:
			cout<<"terminating program !! "<<endl;
			break;

		default:
			cout<<"Enter a valid option "<<endl;
			break;
		}

		cout<<"COUNINUE ? "<<endl;
		cin>>choice2;

	}while(choice2 == 'y');

	return 0;
}
