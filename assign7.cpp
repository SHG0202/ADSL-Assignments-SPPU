//============================================================================
// Name        : assign7.cpp
// Author      : SHG
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#define max 10
using namespace std;

class Symbol
{
	string name;
	string type;
	float value;

public:
	Symbol()
	{
		name = "";
		type = "";
		value = -1;
	}

	friend class ST;
};

class ST
{
	Symbol st[max];
	int chain[max];

public:
	ST()
	{
		for (int i = 0; i < max; i++)
			chain[i] = -1;
	}

	int Hash_fun(string name)
	{
		int temp = ((name[0] + name[1]) / 2) % 10;
		return temp;
	}

	void insert_wr(string name, string type, float value)
	{
		int temp = Hash_fun(name);

		if (st[temp].name == "")
		{
			st[temp].name = name;
			st[temp].type = type;
			st[temp].value = value;
		}
		else
		{
			string key = st[temp].name;
			int temp2 = Hash_fun(key);

			if (temp2 == temp)
			{
				int t = temp;
				
				if (t != -1)
					while (chain[t] != -1)
						t = chain[t];

				int i = temp;

				while (st[i].name != "")
				{
					if (i == max - 1)
						i = 0;
					else
						i++;
				}

				st[i].name = name;
				st[i].type = type;
				st[i].value = value;
				chain[i] = -1;
				chain[t] = i;
			}
			else
			{
				int i = temp;

				while (st[i].name != "")
				{
					if(Hash_fun(st[i].name) == temp)
						break;

					if (i == max - 1)
						i = 0;
					else
						i++;
				}

				int t = i;

				if(st[t].name == "")
				{
					st[i].name = name;
					st[i].type = type;
					st[i].value = value;
				}
				else
				{
					if(chain[t] != -1)
					{
						 while(chain[t] != -1)
							 t = chain[t];
					}

					while (st[i].name != "")
					{
						if (i == max - 1)
							i = 0;
						else
							i++;
					}

					st[i].name = name;
					st[i].type = type;
					st[i].value = value;

					chain[t] = i;
				}
			}
		}
	}

	void insert_r(string name, string type, float value)
	{
		int temp = Hash_fun(name);

		if (st[temp].name == "")
		{
			st[temp].name = name;
			st[temp].type = type;
			st[temp].value = value;
		}
		else
		{
			if(Hash_fun(st[temp].name) == temp)
			{
				int t = temp;

				while(chain[t] != -1)
					t = chain[t];

				int i = temp;

				while(st[i].name != "")
				{
					if(i == max - 1)
						i = 0;
					else
						i++;
				}

				chain[t] = i;
				st[i].name = name;
				st[i].type = type;
				st[i].value = value;
			}
			else
			{
				string key = st[temp].name;

				int temp2 = Hash_fun(key);

				while(chain[temp2] != temp)
					temp2 = chain[temp2];

				int i = temp;

				while(st[i].name != "")
				{
					if(i == max - 1)
						i = 0;
					else
						i++;
				}

				st[i].name = st[temp].name;
				st[i].type = st[temp].type;
				st[i].value = st[temp].value;
				chain[temp2] = i;
				chain[i] = chain[temp];

				st[temp].name = name;
				st[temp].type = type;
				st[temp].value = value;
				chain[temp] = -1;
			}
		}
	}

	int search_wr(string name)
	{
		int temp = Hash_fun(name);
		int i, count = 1;

		if (st[temp].name == name)
		{
			i = temp;

			cout << "No. of Commparision = " << count << endl;
			return i;
		}
		else
		{
			if (Hash_fun(st[temp].name) == temp)
			{
				int t = temp;

				while (st[t].name != name && chain[t] != -1)
				{
					t = chain[t];
					count++;
				}

				if (st[t].name == name)
				{
					cout << "No. of Commparision = " << count << endl;
					return t;
				}
				else
					return -1;
			}
			else
			{
				i = temp;
				while (Hash_fun(st[i].name) != temp)
				{
					if (i == max - 1)
						i = 0;
					else
						i++;

					count++;
				}

				while (st[i].name != name && chain[i] != -1)
				{
					i = chain[i];
					count++;
				}

				if (st[i].name == name)
				{
					cout << "No. of Commparision = " << count << endl;
					return i;
				}
				else
					return -1;
			}
		}
	}

	int search_r(string name)
	{
		int temp = Hash_fun(name);
		int i = temp, count = 1;

		if (st[temp].name == name)
		{
			cout << "No. of Comparision = " << count << endl;
			return i;
		}
		else
		{
			while (st[i].name != name && chain[i] != -1)
			{
				i = chain[i];
				count++;
			}

			if (st[i].name == name)
			{
				cout << "No. of Commparision = " << count << endl;
				return i;
			}
			else
				return -1;
		}
	}

	void modify(int Index, int value)
	{
		st[Index].value = value;
	}

	void Remove_wr(string name)
	{
		int temp1 = Hash_fun(name);
		int temp2 = search_wr(name);
		int t = temp1;

		if(Hash_fun(st[temp1].name) != temp1)
		{
			int i = temp1;
			while(Hash_fun(st[i].name) != temp1)
			{
				if(i == max - 1)
					i = 0;
				else
					i++;
			}

			temp1 = i;
		}

		if (temp1 != temp2)
		{
			while (chain[t] != temp2)
				t = chain[t];
		}
		else
		{
			if(chain[temp1] != -1)
			{
				int temp3 = chain[temp1];

				st[temp1].name = st[temp3].name;
				st[temp1].type = st[temp3].type;
				st[temp1].value = st[temp3].value;
				chain[temp1] = chain[temp3];

				st[temp3].name = "";
				st[temp3].type = "";
				st[temp3].value = -1;
				chain[temp3] = -1;

				return;
			}
		}

		if (chain[temp2] == -1)
			chain[t] = -1;
		else
			chain[t] = chain[temp2];

		st[temp2].name = "";
		st[temp2].type = "";
		st[temp2].value = -1;
	}

	void remove_r(string name)
	{
		int temp1 = Hash_fun(name);
		int temp2 = search_r(name);
		int t = temp1;

		if (temp1 == temp2)
		{
			if (chain[t] == -1)
			{
				st[t].name = "";
				st[t].type = "";
				st[t].value = -1;
			}
			else
			{
				t = chain[t];
				chain[temp1] = chain[t];
				st[temp1].name = st[t].name;
				st[temp1].type = st[t].type;
				st[temp1].value = st[t].value;
				st[t].name = "";
				st[t].type = "";
				st[t].value = -1;
				chain[t] = -1;
			}
		}
		else
		{
			while (chain[t] != temp2)
				t = chain[t];

			if (chain[temp2] != -1)
			{
				chain[t] = chain[temp2];
				st[temp2].name = "";
				st[temp2].type = "";
				st[temp2].value = -1;
				chain[temp2] = -1;

			}
			else
			{
				chain[t] = -1;
				st[temp2].name = "";
				st[temp2].type = "";
				st[temp2].value = -1;
				chain[temp2] = -1;

			}
		}
	}

	void display()
	{
		cout << "   " << "NAME " << "  " << "TYPE " << "  " << "VALUE " << "  " << "CHAIN " << endl;
		for (int i = 0; i < max; i++)
		{
			if (st[i].name != "")
				cout << i << " :" << st[i].name << "    " << st[i].type << "     " << st[i].value << "      " << chain[i] << endl;
			else
				cout << i << " :" << endl;
		}
	}

};

int main()
{
	int cho1;
	string name, type;
	int value;

	do
	{
		cout << "=======================" << endl;
		cout << "       MAIN MENU       " << endl;
		cout << "1. Without replacement " << endl;
		cout << "2. With replacement    " << endl;
		cout << "3. Exit                " << endl;
		cout << "=======================" << endl;
		cin >> cho1;

		switch (cho1)
		{
		case 1:
		{
			ST s1;
			int cho2, n;

			do
			{
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Select operation to perform   " << endl;
				cout << "1. Add a new variable         " << endl;
				cout << "2. Search for a Variable      " << endl;
				cout << "3. Modify a Variable          " << endl;
				cout << "4. Delete a Variable          " << endl;
				cout << "5. Display Variable from List " << endl;
				cout << "6. Exit                       " << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cin >> cho2;

				switch (cho2)
				{
				case 1:
				{
					cout << "No. of elements " << endl;
					cin >> n;

					for (int i = 0; i < n; i++)
					{
						cout << "Name, Type and Value " << endl;
						cin >> name >> type >> value;

						s1.insert_wr(name, type, value);
					}
				}
					break;

				case 2:
				{
					string nam;
					cout << "Variable to be searched " << endl;
					cin >> nam;

					int res = s1.search_wr(nam);

					if (res == -1)
						cout << "Item not found " << endl;
					else
					{
						int temp = s1.Hash_fun(nam);

						cout << "Found at position  : " << res << endl;
						cout << "Expected position  : " << temp << endl;
					}
				}
					break;

				case 3:
				{
					string nam;
					int val;
					cout << "Variable to be modified " << endl;
					cin >> nam;

					int res = s1.search_wr(nam);

					cout << "New VALUE = ";
					cin >> val;

					s1.modify(res, val);
				}
					break;

				case 4:
				{
					string nam;

					cout << "Which variable to remove " << endl;
					cin >> nam;

					s1.Remove_wr(nam);
				}
					break;

				case 5:
					s1.display();
					break;

				case 6:
					cout << "Back to MAIN MENU " << endl;
					break;

				default:
					cout << "Enter a Valid option " << endl;
					break;
				}
			} while (cho2 != 6);
		}
			break;

		case 2:
		{
			ST s2;
			int cho3, n;

			do
			{
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Select operation to perform   " << endl;
				cout << "1. Add a new variable         " << endl;
				cout << "2. Search for a Variable      " << endl;
				cout << "3. Modify a Variable          " << endl;
				cout << "4. Delete a Variable          " << endl;
				cout << "5. Display Variable from List " << endl;
				cout << "6. Exit                       " << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cin >> cho3;

				switch(cho3)
				{
				case 1:
				{
					cout << "No. of elements " << endl;
					cin >> n;

					for (int i = 0; i < n; i++)
					{
						cout << "Name, Type and Value " << endl;
						cin >> name >> type >> value;

						s2.insert_r(name, type, value);
					}
				}
					break;

				case 2:
				{
					string nam;
					cout << "Variable to be searched " << endl;
					cin >> nam;

					int res = s2.search_r(nam);

					if (res == -1)
						cout << "Item not found " << endl;
					else
					{
						int temp = s2.Hash_fun(nam);

						cout << "Found at position  : " << res << endl;
						cout << "Expected position  : " << temp << endl;
					}
				}
					break;

				case 3:
				{
					string nam;
					int val;
					cout << "Variable to be modified " << endl;
					cin >> nam;

					int res = s2.search_r(nam);

					cout << "New VALUE = ";
					cin >> val;

					s2.modify(res, val);
				}
					break;

				case 4:
				{
					string nam;

					cout << "Which variable to remove " << endl;
					cin >> nam;

					s2.Remove_r(nam);
				}
					break;

				case 5:
					s2.display();
					break;

				case 6:
					cout<<"BACK TO MAIN MENU "<<endl;
					break;
				}
			}while(cho3 != 6);
		}
			break;

		case 3:
			cout << "TERMNATING !! " << endl;
			break;

		default:
			cout << "Enter a valid option " << endl;
			break;
		}
	} while (cho1 != 3);

	return 0;
}
