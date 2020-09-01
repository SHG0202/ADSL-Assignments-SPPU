//============================================================================
// Name        : assign6.cpp
// Author      : SHG
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#define max 10
using namespace std;

class Word
{
	string Key;
	string meaning;

public:
	Word()
	{
		Key = "";
		meaning = "";
	}

	friend class Hash_Tbl;
};

class Hash_Tbl
{
	Word Hz[max];

public:

	int Hash_fun(string key)
	{
		int temp = ((key[0] + key[1]) / 2) % 10;
		return temp;
	}

	void insert(string Key, string meaning, int index)
	{
		if (Hz[index].Key == "")
		{
			Hz[index].Key = Key;
			Hz[index].meaning = meaning;
		}
		else
		{
			while (Hz[index].Key != "")
			{
				if (index == max)
					index = 0;
				else
					index++;
			}

			Hz[index].Key = Key;
			Hz[index].meaning = meaning;
		}
	}

	void insert_rep(string Key, string meaning, int index)
	{
		int j = -1;

		if (Hz[index].Key == "")
		{
			Hz[index].Key = Key;
			Hz[index].meaning = meaning;
		}
		else
		{
			string temp = Hz[index].Key;
			int i = Hash_fun(temp);

			if(i == index)
			{
				j = index;
				while (Hz[j].Key != "")
				{
					if (j == max)
						j = 0;
					else
						j++;
				}

				Hz[j].Key = Key;
				Hz[j].meaning = meaning;
			}
			else
			{
				j = i;
				while (Hz[j].Key != "")
				{
					if (j == max)
						j = 0;
					else
						j++;
				}

				Hz[j].Key = Hz[index].Key;
				Hz[j].meaning = Hz[index].meaning;
				Hz[index].Key = Key;
				Hz[index].meaning = meaning;
			}
		}
	}

	int search(string Entry, int Index)
	{
		int count = 1;
		int i = Index;
		while (Hz[i].Key != Entry && i != Index - 1)
		{
			if (i == max - 1)
				i = 0;
			else	
				i++;
			count ++;
		}

		cout<<"No. of comparision = "<<count++<<endl;

		if (Hz[i].Key == Entry)
			return i;
		else
			return -1;
	}

	void Edit_meaning(string mean, int index)
	{
		Hz[index].meaning = mean;
	}

	void remove(int Index)
	{
		Hz[Index].Key = "";
		Hz[Index].meaning = "";

		int i = -1;

		if(Index == max-1)
			i = 0;
		else
			i = Index + 1;

		while(i != Index)
		{
			if(Hash_fun(Hz[i].Key) == Index)
			{
				Hz[Index].Key = Hz[i].Key;
				Hz[Index].meaning = Hz[i].meaning;
				Hz[i].Key = "";
				Hz[i].meaning = "";

				Index = i;
			}

			if(i == max-1)
				i = 0;
			else
				i++;
		}
	}

	void display()
	{
		for (int i = 0; i < max; i++)
		{
			if (Hz[i].Key != "")
				cout << i << " :" << Hz[i].Key << "-->" << Hz[i].meaning << endl;
			else
				cout << i << " :" << endl;
		}
	}
};


class Dictonary
{
	Hash_Tbl HT;

public:

	void New_Entry(string Entry, string Meaning)
	{
		int Index = HT.Hash_fun(Entry);

		HT.insert(Entry, Meaning, Index);
	}

	void New_Entry_rep(string Entry, string Meaning)
	{
		int Index = HT.Hash_fun(Entry);

		HT.insert_rep(Entry, Meaning, Index);
	}

	void Search(string Entry)
	{
		int Index = HT.Hash_fun(Entry);
		int temp = HT.search(Entry, Index);

		if (temp != -1)
		{
			cout << "Found at Position : " << temp <<endl;
			cout << "expected position : " << Index << endl;
		}
		else
			cout << "Key does not exist " << endl;
	}

	void Edit(string Entry)
	{
		string mean;

		int Index = HT.Hash_fun(Entry);
		int temp = HT.search(Entry, Index);

		cout << "Enter New meaning " << endl;
		cin >> mean;

		HT.Edit_meaning(mean, temp);
	}

	void remove(string Entry)
	{
		int Index = HT.Hash_fun(Entry);
		int temp = HT.search(Entry, Index);

		if (temp == -1)
			cout << "Key does not exist" << endl;
		else
			HT.remove(temp);
	}

	void display()
	{
		HT.display();
	}
};


int main()
{
	Dictonary d1, d2;
	int n;
	int opt1, opt2;
	string w, k, key;

	do
	{
		cout << "==============================" << endl;
		cout << "Select an operation " << endl;
		cout << "1. Input element in dictionary " << endl;
		cout << "2. Search for a given word " << endl;
		cout << "3. Modify a given word " << endl;
		cout << "4. Delete a given word " << endl;
		cout << "5. Display dictionary " << endl;
		cout << "6. Exit " << endl;
		cout << "==============================" << endl;
		cin >> opt1;

		switch (opt1)
		{
		case 1:
		{
			cout<<"Select the Method "<<endl;
			cout<<"1. With replacement "<<endl;
			cout<<"2. Without replacement "<<endl;
			cin>>opt2;

			switch(opt2)
			{
			case 1:
			{
				cout << "No. of Entries ? " << endl;
				cin >> n;

				for (int i = 0; i < n; i++)
				{
					cout << "\n WORD AND KEY : " << endl;
					cin >> w >> k;
					d1.New_Entry_rep(w, k);
				}
			}
			break;

			case 2:
			{
				cout << "No. of Entries ? " << endl;
				cin >> n;

				for (int i = 0; i < n; i++)
				{
					cout << "\n WORD AND KEY : " << endl;
					cin >> w >> k;
					d1.New_Entry(w, k);
				}
			}
			break;

			default:
				cout<<"Enter a valid option "<<endl;
				break;
			}
		}
		break;

		case 2:
			cout << "Which Key to be searched ? " << endl;
			cin >> key;
			d1.Search(key);
			break;

		case 3:
			cout << "Which Key to be Modified ? " << endl;
			cin >> key;
			d1.Edit(key);
			break;

		case 4:
			cout << "Which Key to be Deleted ? " << endl;
			cin >> key;
			d1.remove(key);
			break;

		case 5:
			d1.display();
			break;

		case 6:
			cout << "Back to Main menu !! " << endl;
			break;

		default:
			cout << "Enter a valid option " << endl;
			break;
		}
	} while (opt1 != 6);

	return 0;
}
