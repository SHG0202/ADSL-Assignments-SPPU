//============================================================================
// Name        : assign9.cpp
// Author      : SHG
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node
{
	int data;
	Node* next;

public:
	Node(int a)
	{
		data = a;
		next = NULL;
	}

	friend class SET;
	friend class Iterator;
};

class Iterator
{
	Node* it;

public:
	Iterator()
	{
		it = NULL;
	}

	void set(Node* node)
	{
		it = node;
	}

	bool end()
	{
		if (it == NULL)
			return 1;
		else
			return 0;
	}

	void next()
	{
		it = it->next;
	}

	void display()
	{
		cout << it->data;
	}
};

class SET
{
	Node* start;
	int len;

public:
	SET()
	{
		start = NULL;
		len = 0;
	}

	void Add(int a);

	void Remove(int a);

	bool Contains(int a);

	int Size();

	Node* begin();

	SET Inter(SET s1);

	SET Uni(SET s1);

	SET Diff(SET s1);

	bool Subs(SET s1);

	void Dislay();
};

Node* SET::begin()
{
	return start;
}

void SET::Add(int a)
{
	Node* new1 = new Node(a);

	if (start == NULL)
	{
		start = new1;
		start->next = NULL;
		len++;
	}
	else
	{
		Node* temp = start;

		if (temp->data > new1->data)
		{
			new1->next = start;
			start = new1;
			len++;
		}
		else
		{
			Node* temp2 = NULL;
			while (temp != NULL && (temp->data < new1->data))
			{
				temp2 = temp;
				temp = temp->next;
			}

			if (temp == NULL)
			{
				temp2->next = new1;
				new1->next = NULL;
				len++;
				return;
			}

			if (temp->data == new1->data)
				return;

			new1->next = temp2->next;
			temp2->next = new1;
			len++;
		}
	}
}

void SET::Remove(int a)
{
	Node* temp = start;
	Node* temp2 = NULL;

	while (temp->data != a && temp->next != NULL)
	{
		temp2 = temp;
		temp = temp->next;
	}

	if (temp->next == NULL)
	{
		if (temp->data == a)
		{
			if (len == 1)
				start = NULL;
			else
				temp2->next = NULL;
			len--;
			delete temp;
		}
		else
			cout << "Element does not exist " << endl;
	}
	else
	{
		if (temp == start)
		{
			start = temp->next;
			temp->next = NULL;
			len--;
			delete temp;
		}
		else
		{
			temp2->next = temp->next;
			temp->next = NULL;
			len--;
			delete temp;
		}
	}
}

bool SET::Contains(int a)
{
	Node* temp = start;

	while (temp->data != a && temp->next != NULL)
		temp = temp->next;

	if (temp->next == NULL)
	{
		if (temp->data == a)
			return 1;
		else
			return 0;
	}
	else
		return 1;
}

int SET::Size()
{
	return len;
}

SET SET::Inter(SET s1)
{
	SET inter;
	int len = 0;
	Node* temp1 = start;
	Node* temp2 = s1.start;
	Node* temp3 = NULL;

	while (temp1 != NULL && temp2 != NULL)
	{
		if (temp1->data == temp2->data)
		{
			Node* new1 = new Node(temp1->data);
			inter.start = new1;
			new1->next = NULL;
			temp3 = inter.start;
			temp1 = temp1->next;
			temp2 = temp2->next;
			len++;
			break;
		}
		else
		{
			if (temp1->data > temp2->data)
				temp2 = temp2->next;
			else
				temp1 = temp1->next;
		}
	}

	while (temp1 != NULL && temp2 != NULL)
	{
		if (temp1->data == temp2->data)
		{
			Node* new1 = new Node(temp1->data);
			temp3->next = new1;
			temp3 = temp3->next;
			temp1 = temp1->next;
			temp2 = temp2->next;
			new1->next = NULL;
			len++;
		}
		else
		{
			if (temp1->data > temp2->data)
				temp2 = temp2->next;
			else
				temp1 = temp1->next;
		}
	}

	inter.len = len;
	return inter;
}

SET SET::Uni(SET s1)
{
	SET uni;
	int len = 0;
	Node* temp1 = start;
	Node* temp2 = s1.start;
	Node* temp3 = NULL;

	if (temp1->data < temp2->data)
	{
		Node* new1 = new Node(temp1->data);
		temp3 = new1;
		new1->next = NULL;
		temp1 = temp1->next;
	}
	else if (temp1->data > temp2->data)
	{
		Node* new1 = new Node(temp2->data);
		temp3 = new1;
		new1->next = NULL;
		temp2 = temp2->next;
	}
	else
	{
		Node* new1 = new Node(temp1->data);
		temp3 = new1;
		new1->next = NULL;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	uni.start = temp3;
	len++;

	while (temp1 != NULL && temp2 != NULL)
	{
		if (temp1->data < temp2->data)
		{
			Node* new1 = new Node(temp1->data);
			temp3->next = new1;
			new1->next = NULL;
			temp3 = temp3->next;
			temp1 = temp1->next;
		}
		else if (temp1->data > temp2->data)
		{
			Node* new1 = new Node(temp2->data);
			temp3->next = new1;
			new1->next = NULL;
			temp3 = temp3->next;
			temp2 = temp2->next;
		}
		else
		{
			Node* new1 = new Node(temp1->data);
			temp3->next = new1;
			new1->next = NULL;
			temp3 = temp3->next;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		len++;
	}

	while (temp1 != NULL)
	{
		Node* new1 = new Node(temp1->data);
		temp3->next = new1;
		new1->next = NULL;
		temp3 = temp3->next;
		temp1 = temp1->next;
		len++;
	}

	while (temp2 != NULL)
	{
		Node* new1 = new Node(temp2->data);
		temp3->next = new1;
		new1->next = NULL;
		temp3 = temp3->next;
		temp2 = temp2->next;
		len++;
	}

	uni.len = len;
	return uni;
}

SET SET::Diff(SET s1)
{
	int len = 0;

	SET inter;
	inter = Inter(s1);

	SET diff;

	Node* temp1 = start;
	Node* temp2 = inter.start;
	Node* temp3 = NULL;

	if (temp2 == NULL)
	{
		Node* new1 = new Node(temp1->data);
		diff.start = new1;
		temp3 = new1;
		temp1 = temp1->next;
		len++;

		while (temp1 != NULL)
		{
			Node* new1 = new Node(temp1->data);
			temp3->next = new1;
			temp3 = temp3->next;
			temp1 = temp1->next;
			len++;
		}
	}

	while (temp2 != NULL)
	{
		if (temp1->data != temp2->data)
		{
			Node* new1 = new Node(temp1->data);
			diff.start = new1;
			temp3 = new1;
			temp1 = temp1->next;
			len++;
			break;
		}
		else
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}

	while (temp2 != NULL)
	{
		if (temp1->data != temp2->data)
		{
			Node* new1 = new Node(temp1->data);
			temp3->next = new1;
			temp3 = temp3->next;
			temp1 = temp1->next;
			len++;
		}
		else
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}

	diff.len = len;
	return diff;
}

bool SET::Subs(SET s1)
{
	Node* temp1 = start;
	Node* temp2 = s1.start;

	while (temp1 != NULL && temp2 != NULL)
	{
		if (temp1->data == temp2->data)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else
		{
			if (temp1->data < temp2->data)
				temp1 = temp1->next;
			else
				return 0;
		}
	}

	if (temp2 == NULL)
		return 1;
	else
		return 0;
}

void SET::Dislay()
{
	Node* temp = start;

	if (len != 0)
	{

		cout << "{ ";
		for (int i = 1; i < len; i++)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << temp->data << " }" << endl;
	}
	else
		cout << "{ } " << endl;
}

int main()
{
	SET s;
	int cho1;

	do
	{
		cout << "=============================" << endl;
		cout << "Select an operation " << endl;
		cout << "1.  Create a SET " << endl;
		cout << "2.  Add Element " << endl;
		cout << "3.  Remove Element " << endl;
		cout << "4.  Check for a Entry " << endl;
		cout << "5.  Size of SET " << endl;
		cout << "6.  Display using Iterator " << endl;
		cout << "7.  Intersection of two SETs " << endl;
		cout << "8.  Union of two SETs " << endl;
		cout << "9.  Difference of two SETs " << endl;
		cout << "10. Subset or Not " << endl;
		cout << "11. Display" << endl;
		cout << "12. Exit " << endl;
		cout << "=============================" << endl;
		cin >> cho1;

		switch (cho1)
		{
		case 1:
		{
			int n, ele;
			cout << "Enter number of elements to add " << endl;
			cin >> n;

			for (int i = 0; i < n; i++)
			{
				cout << "Element : ";
				cin >> ele;
				cout << endl;
				s.Add(ele);
			}
		}
		break;

		case 2:
		{
			int ele;
			cout << "Element : ";
			cin >> ele;
			cout << endl;
			s.Add(ele);
		}
		break;

		case 3:
		{
			int ele;
			cout << "Element : ";
			cin >> ele;
			cout << endl;
			s.Remove(ele);
		}
		break;

		case 4:
		{
			int ele;
			cout << "Element : ";
			cin >> ele;
			cout << endl;
			if (s.Contains(ele))
				cout << "Present !! " << endl;
			else
				cout << "Not Present !! " << endl;
		}
		break;

		case 5:
			cout << "Number Of elements = " << s.Size() << endl;
			break;

		case 6:
		{
			Iterator it;
			it.set(s.begin());
			cout << "{ ";
			while (!it.end())
			{
				it.display();
				cout << ", ";
				it.next();
			}
			cout << "} " << endl;
		}
		break;

		case 7:
		{
			SET s2, inter;
			cout << "Enter second SET" << endl;

			int n, ele;
			cout << "Enter number of elements to add " << endl;
			cin >> n;

			for (int i = 0; i < n; i++)
			{
				cout << "Element : ";
				cin >> ele;
				cout << endl;
				s2.Add(ele);
			}
			cout << "\nSET 1 : " << endl;
			s.Dislay();
			cout << "\nSET 2 : " << endl;
			s2.Dislay();

			inter = s.Inter(s2);

			cout << "\nSET 1 ^ SET 2 : " << endl;
			inter.Dislay();
		}
		break;

		case 8:
		{
			SET uni, s2;
			cout << "Enter second SET" << endl;

			int n, ele;
			cout << "Enter number of elements in SET 2 " << endl;
			cin >> n;

			for (int i = 0; i < n; i++)
			{
				cout << "Element : ";
				cin >> ele;
				cout << endl;
				s2.Add(ele);
			}
			cout << "\nSET 1 : " << endl;
			s.Dislay();
			cout << "\nSET 2 : " << endl;
			s2.Dislay();

			uni = s.Uni(s2);

			cout << "\nSET 1 + SET 2 : " << endl;
			uni.Dislay();
		}
		break;

		case 9:
		{
			SET s2, diff;
			cout << "Enter second SET" << endl;

			int n, ele;
			cout << "Enter number of elements in SET 2 " << endl;
			cin >> n;

			for (int i = 0; i < n; i++)
			{
				cout << "Element : ";
				cin >> ele;
				cout << endl;
				s2.Add(ele);
			}
			cout << "\nSET 1 : " << endl;
			s.Dislay();
			cout << "\nSET 2 : " << endl;
			s2.Dislay();

			diff = s.Diff(s2);

			cout << "\nSET 1 - SET 2 : " << endl;
			diff.Dislay();
		}
		break;

		case 10:
		{
			SET sub, s2;
			cout << "Enter second SET" << endl;

			int n, ele;
			cout << "Enter number of elements in SET 2 " << endl;
			cin >> n;

			for (int i = 0; i < n; i++)
			{
				cout << "Element : ";
				cin >> ele;
				cout << endl;
				s2.Add(ele);
			}
			cout << "\nSET 1 : " << endl;
			s.Dislay();
			cout << "\nSET 2 : " << endl;
			s2.Dislay();

			if (s.Subs(s2))
				cout << "SET 2 is SUBSET of SET 1 " << endl;
			else
				cout << "SET 2 is not a SUBSET of SET 1 " << endl;
		}
		break;

		case 11:
			s.Dislay();
			break;

		case 12:
			cout << "TERMINATING !!" << endl;
			break;

		default:
			cout << "Enter a valid option " << endl;
			break;
		}
	} while (cho1 != 12);

	return 0;
}
