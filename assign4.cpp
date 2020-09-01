//============================================================================
// Name        : assign4.cpp
// Author      : SHG
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define max 20
#include <string>
using namespace std;

class City
{
	string name;
	int cost;
	City* next;

public:
	City(string name)
	{
		this->name = name;
		cost = -1;
		next = NULL;
	}

	friend class Airways;
};

class Stack
{
	string S[max];
	int top;

public:
	Stack()
	{
		for (int i = 0; i < max; i++)
			S[i] = " ";

		top = -1;
	}

	void push(string ele);

	void pop();

	bool empty();

	bool full();

	string get_top();
};

void Stack::push(string ele)
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

string Stack::get_top()
{
	string temp = S[top];
	if (empty())
		return " ";
	else
		return temp;
}

class Queue
{
	string Q[max];
	int front;
	int rear;

public:
	Queue()
	{
		for (int i = 0; i < max; i++)
			Q[i] = " ";

		front = rear = -1;
	}

	void enque(string ele);

	void dequeue();

	bool empty();

	bool full();

	string get_front();
};

void Queue::enque(string ele)
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

string Queue::get_front()
{
	string temp = Q[front];

	if (!empty())
		return temp;
	else
		return " ";
}


class Airways
{
	City* head[max];
	int N;

public:
	Airways()
	{
		for (int i = 0; i < 20; i++)
			head[i] = NULL;

		N = -1;
	}

	void create_port(string name)
	{
		head[++N] = new City(name);
	}

	void destinations()
	{
		int n, cost;
		string des;

		for (int i = 0; i <= N; i++)
		{
			cout << "How many cities is " << head[i]->name << " connected ? " << endl;
			cin >> n;

			for (int j = 0; j < n; j++)
			{
				cout << "destination and cost ? " << endl;
				cin >> des >> cost;
				City* new1 = new City(des);
				new1->cost = cost;

				if (head[i]->next == NULL)
				{
					head[i]->next = new1;
					new1->next = NULL;
				}
				else
				{
					City* temp = head[i];

					while (temp->next != NULL)
						temp = temp->next;

					temp->next = new1;
					new1->next = NULL;
				}
			}
		}
	}

	void remove_port(string port)
	{
		for (int i = 0; i <= N; i++)
		{
			if (head[i]->name == port)
			{
				if (i == N)
					head[N--] = NULL;
				else
				{
					int j = i;

					while (j != N)
					{
						head[j] = head[j + 1];
						j++;
					}
					head[j] = NULL;

					N--;
					i--;
				}
			}
			else
			{
				City* temp = head[i]->next;

				while (temp->name != port && temp != NULL)
				{
					temp = temp->next;
				}

				if (temp == NULL)
					break;
				else
				{
					remove_route(head[i]->name, port);
				}
			}
		}
	}

	void add_route(string sour, string dest, int cost)
	{
		for (int i = 0; i <= N; i++)
		{
			if (head[i]->name == sour)
			{
				City* temp = head[i]->next;

				while (temp->next != NULL)
					temp = temp->next;

				City* new1 = new City(dest);
				new1->cost = cost;

				temp->next = new1;
				new1->next = NULL;

				break;
			}
			else
				continue;
		}
	}

	void remove_route(string sour, string des)
	{
		for (int i = 0; i <= N; i++)
		{
			if (head[i]->name == sour)
			{
				City* temp = head[i]->next;
				City* temp2 = NULL;

				while (temp->name != des)
				{
					temp2 = temp;
					temp = temp->next;
				}

				if (temp == head[i]->next)
				{
					head[i]->next = temp->next;
					temp->next = NULL;
					delete temp;
				}
				else
				{
					if (temp->next == NULL)
					{
						temp2->next = NULL;
						delete temp;
					}
					else
					{
						temp2->next = temp->next;
						temp->next = NULL;
						delete temp;
					}
				}

				break;
			}
			else
				continue;
		}
	}

	void in_out(string name)
	{
		int in = 0, out = 0;

		for (int i = 0; i < N; i++)
		{
			if (head[i]->name == name)
			{
				City* temp = head[i]->next;

				while (temp != NULL)
				{
					out++;
					temp = temp->next;
				}
			}
			else
			{
				City* temp = head[i]->next;

				while (temp != NULL && temp->name != name)
					temp = temp->next;

				if (temp->name == name)
					in++;
			}

			cout << "In-degree = " << in << endl;
			cout << "Out-degree = " << out << endl;
		}
	}

	void chart()
	{
		for (int i = 0; i <= N; i++)
		{
			cout << head[i]->name << " : ";
			
			City* temp = head[i]->next;
			while (temp->next != NULL)
			{
				cout << temp->name << " ( "<<temp->cost<<"/- ) "<< "__";
				temp = temp->next;
			}
			cout << temp->name << " ( " << temp->cost << "/- ) "<< endl;
		}
	}

	void BFS(string start)
	{
		Queue Q;
		string visited[max], current, temp;
		City* temp1 = NULL;
		City* temp2 = NULL;
		int n = -1;

		for (int i = 0; i <= N; i++)
		{
			if (head[i]->name == start)
			{
				temp1 = head[i];
				Q.enque(temp1->name);
				visited[++n] = temp1->name;
				break;
			}
		}

		while (1)
		{
			current = Q.get_front();
			cout << current << " ---> ";
			Q.dequeue();

			temp2 = temp1->next;

			while (temp2 != NULL)
			{
				int flag = 0;
				for (int i = 0; i <= n; i++)
				{
					if (visited[i] == temp2->name)
					{
						//temp2 = temp2->next;
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					visited[++n] = temp2->name;
					Q.enque(temp2->name);
					//temp2 = temp2->next;
				}
				temp2 = temp2->next;
			}

			if (Q.empty())
				break;

			temp = Q.get_front();

			for (int i = 0; i <= N; i++)
			{
				if (head[i]->name == temp)
				{
					temp1 = head[i];
					break;
				}
			}
		}
	}

	void DFS(string start)
	{
		Stack S;
		string visited[max], current, temp;
		City* temp1 = NULL;
		City* temp2 = NULL;
		int n = -1;

		for (int i = 0; i <= N; i++)
		{
			if (head[i]->name == start)
			{
				temp1 = head[i];
				S.push(temp1->name);
				visited[++n] = temp1->name;
				break;
			}
		}

		while (1)
		{
			current = S.get_top();
			cout << current << " ---> ";
			S.pop();

			temp2 = temp1->next;

			while (temp2 != NULL)
			{
				int flag = 0;
				for (int i = 0; i <= n; i++)
				{
					if (visited[i] == temp2->name)
					{
						//temp2 = temp2->next;
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					visited[++n] = temp2->name;
					S.push(temp2->name);
					//temp2 = temp2->next;
				}
				temp2 = temp2->next;
			}

			if (S.empty())
				break;

			temp = S.get_top();

			for (int i = 0; i <= N; i++)
			{
				if (head[i]->name == temp)
				{
					temp1 = head[i];
					break;
				}
			}
		}
	}
};

int main()
{
	int cho1, cho2;
	Airways A;

	do
	{
		cout << "\n==================================" << endl;
		cout << "               AIRWAYS            " << endl;
		cout << "1. Add a Airport " << endl;
		cout << "2. Remove a Airport " << endl;
		cout << "3. Add a new route " << endl;
		cout << "4. Remove a route " << endl;
		cout << "5. In and Out degree of a Airport " << endl;
		cout << "6. Display transport chart " << endl;
		cout << "7. greph traversal " << endl;
		cout << "8. Exit " << endl;
		cout << "==================================" << endl;
		cin >> cho1;

		switch (cho1)
		{
		case 1:
		{
			int n;
			string name;

			cout << "No. of ports to be added " << endl;
			cin >> n;
			cout << "Enter names " << endl;

			for (int i = 0; i < n; i++)
			{
				cin >> name;
				A.create_port(name);
			}

			A.destinations();

			break;
		}
		case 2:
		{
			string port;

			cout << "Which port to remove ? " << endl;
			cin >> port;

			A.remove_port(port);

			break;
		}
		case 3:
		{
			string so, de;
			int cost;

			cout << "Enter a source and a destination and cost" << endl;
			cin >> so >> de >> cost;

			A.add_route(so, de, cost);

			break;
		}
		case 4:
		{
			string sour, des;

			cout << "Enter source and destination " << endl;
			cin >> sour >> des;

			A.remove_route(sour, des);

			break;
		}
		case 5:
		{
			string name;

			cout << "Enter port who info is to be found " << endl;
			cin >> name;
			
			A.in_out(name);
			
			break;
		}
		case 6:
			A.chart();
			break;

		case 7:
		{
			string name;

			cout << "Enter starting port " << endl;
			cin >> name;
			
			cout << "\nSelect a type " << endl;
			cout << "1. BFS Traversal " << endl;
			cout << "2. DFS Traversal " << endl;
			cin >> cho2;

			switch (cho2)
			{
			case 1:
				A.BFS(name);
				break;

			case 2:
				A.DFS(name);
				break;

			default:
				cout << "Select a valid option " << endl;
				break;
			}

			break;
		}
		case 8:
			cout << "Treminating !!" << endl;
			break;

		default:
			cout << "Enter a valid choice " << endl;
			break;
		}

	} while (cho1 != 8);
	
	return 0;
}

