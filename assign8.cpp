#include <iostream>
#include <string>
using namespace std;

class NODE
{
	string key;
	NODE* lchild;
	NODE* rchild;
	int BF;

public:

	NODE()
	{
		key = "";
		lchild = rchild = NULL;
		BF = 0;
	}

	NODE(string ele)
	{
		key = ele;
		lchild = rchild = NULL;
		BF = 0;
	}

	friend class AVL;
};

class AVL
{
	NODE* head;
	NODE* Stack[30];
	int top;

public:

	AVL()
	{
		for (int i = 0; i < 30; i++)
			Stack[i] = NULL;

		top = -1;

		head = NULL;
	}

	//STACK

	void Push(NODE*);
	NODE* pop();

	//AVL

	void create(string);

	int height(NODE*);
	int Max(int, int);

	void call_Inorder();
	void Inorder(NODE*);

	void Update_BF();
	void Update(NODE*);

	void Search(string);

	void Balance(string);

	void LL(NODE*, NODE*, NODE*);
	void LR(NODE*, NODE*, NODE*);
	void RR(NODE*, NODE*, NODE*);
	void RL(NODE*, NODE*, NODE*);

};

void AVL::Push(NODE* ele)
{
	Stack[++top] = ele;
}

NODE* AVL::pop()
{
	NODE* ele = Stack[top];
	top--;
	return ele;
}

void AVL::create(string ele)
{
	NODE* temp = new NODE(ele);

	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		NODE* p = head;
		NODE* q = head;

		while (p != NULL)
		{
			q = p;
			if (p->key < ele)
			{
				p = p->rchild;
			}
			else
			{
				p = p->lchild;
			}
		}

		if (q->key < ele)
		{
			q->rchild = temp;
		}
		else
		{
			q->lchild = temp;
		}
	}
}

void AVL::call_Inorder()
{
	Inorder(head);
}

void AVL::Inorder(NODE* root)
{
	if (root != NULL)
	{
		Inorder(root->lchild);
		cout << "KETWORD : " << root->key << endl;
		Inorder(root->rchild);
	}
}

int AVL::height(NODE* ele)
{
	if (ele != NULL)
	{
		if (ele->lchild != NULL && ele->rchild != NULL)
		{
			return(1 + Max(height(ele->lchild), height(ele->rchild)));
		}
		else if (ele->lchild != NULL && ele->rchild == NULL)
		{
			return(1 + height(ele->lchild));
		}
		else if (ele->lchild == NULL && ele->rchild != NULL)
		{
			return(1 + height(ele->rchild));
		}
		else
			return 0;
	}
	else
	{
		return -1;
	}
}

void AVL::Update_BF()
{
	Update(head);
}

void AVL::Update(NODE* root)
{
	if (root != NULL)
	{
		Update(root->lchild);
		root->BF = height(root->lchild) - height(root->rchild);
		Update(root->rchild);
	}
}

void AVL::Balance(string ele)
{
	int flag = 0;
	int balance = 0;

	//Pushing nodes in stack

	NODE* temp1 = head;

	while (1)
	{
		if (temp1->key < ele)
		{
			Push(temp1);
			temp1 = temp1->rchild;
		}
		else if (temp1->key > ele)
		{
			Push(temp1);
			temp1 = temp1->lchild;
		}
		else
		{
			Push(temp1);
			flag = 1;

			if (temp1->lchild == NULL && temp1->rchild == NULL)
				break;
		}
	}

	//Poping Nodes from Stack

	NODE* child = NULL, * parent = NULL, * grand = NULL;
	NODE* p = NULL, * q = NULL, * r = NULL;
	flag = -100;

	while (top != -1)
	{
		p = pop();

		if (top == -1)
		{
			flag = -1;
			goto out;
		}
		else
		{
			q = pop();
		}

		if (top == -1)
		{
			flag = -2;
			goto out;
		}
		else
		{
			r = pop();
		}

	out:	if (p->BF == 2 || p->BF == -2)
	{
		flag = 0;
		break;
	}

	if ((q != NULL) && (q->BF == 2 || q->BF == -2))
	{
		flag = 1;
		break;
	}

	if ((r != NULL) && (r->BF == 2 || r->BF == -2))
	{
		flag = 2;
		break;
	}
	}

	//Finding Unbalanced nodes

	if (flag == -1 || flag == -2 || flag == -3)
	{
		cout << "TREE IS BALANCED !! " << endl;
		balance = 1;
	}
	else if (flag == 0)
	{
		grand = p;
		parent = r;
		child = q;
	}
	else if (flag == 1)
	{
		grand = q;
		parent = p;
		child = r;
	}
	else if (flag == 2)
	{
		grand = r;
		parent = q;
		child = p;
	}

	if (balance == 0)
	{
		flag = 0;

		//Finding rotations

		if (grand->lchild->key == parent->key)
		{
			if (parent->lchild == child)
				LL(grand, parent, child);
			else if (parent->rchild == child)
				LR(grand, parent, child);

		}
		else if (grand->rchild == parent)
		{
			if (parent->rchild->key == child->key)
				RR(grand, parent, child);
			else if (parent->lchild == child)
				RL(grand, parent, child);
		}
	}
}

int AVL::Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

void AVL::LL(NODE* a, NODE* b, NODE* c)
{
	a->lchild = b->rchild;
	b->rchild = a;
	a->BF = b->BF = 0;
}

void AVL::RR(NODE* a, NODE* b, NODE* c)
{
	a->rchild = b->lchild;
	b->lchild = a;
	a->BF = b->BF = 0;
}

void AVL::LR(NODE* a, NODE* b, NODE* c)
{
	b->rchild = c->lchild;
	a->lchild = c->rchild;
	c->lchild = b;
	c->rchild = a;

	switch (c->BF)
	{
	case 0:
		a->BF = b->BF;
		break;

	case 1:
		a->BF = -1;
		b->BF = 0;
		break;

	case -1:
		a->BF = 0;
		b->BF = 1;
		break;
	}
	c->BF = 0;
}

void AVL::RL(NODE* a, NODE* b, NODE* c)
{
	b->lchild = c->rchild;
	a->rchild = c->lchild;
	c->rchild = b;
	c->lchild = a;

	switch (c->BF)
	{
	case 0:
		a->BF = b->BF = 0;
		break;

	case 1:
		a->BF = 0;
		b->BF = -1;
		break;

	case -1:
		a->BF = 1;
		b->BF = 0;
		break;
	}
	c->BF = 0;
}

void AVL::Search(string ele)
{
	int flag = 0;
	int cnt = 0;

	NODE* p = head;

	while (p != NULL)
	{
		if (p->key < ele)
		{
			cnt++;
			p = p->rchild;
		}
		else if (p->key > ele)
		{
			cnt++;
			p = p->lchild;
		}
		else
		{
			flag = 1;
			break;
		}
	}

	if (flag == 1)
	{
		cout << "FOUND !! " << endl;
		cout << "No. of steps = " << cnt << endl;
	}
	else
	{
		cout << "NOT FOUND !! " << endl;
	}

}

int main()
{
	AVL a;
	string name;
	int cho;

	do
	{
		cout << "====================" << endl;
		cout << "Selet an option " << endl;
		cout << "1. Insert a Keyword " << endl;
		cout << "2. Display List " << endl;
		cout << "3. Search a Keyword " << endl;
		cout << "4. EXIT " << endl;
		cout << "====================" << endl;
		cin >> cho;

		switch (cho)
		{
		case 1:
			cout << "WORD : ";
			cin >> name;
			cout << endl;

			a.create(name);
			a.Update_BF();
			a.Balance(name);
			a.Update_BF();

			break;

		case 2:
			a.call_Inorder();
			break;

		case 3:
			cout << "Word to be Searched ? " << endl;
			cin >> name;

			a.Search(name);
			break;

		case 4:
			cout << "TERMINATING !! " << endl;
			break;

		default:
			cout << "Enter a vald choice " << endl;
			break;
		}
	} while (cho != 4);
}
