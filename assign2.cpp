//============================================================================
// Name        : assign2.cpp
// Author      : SHG
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

class Entry
{
	char word[20];
	char meaning[20];
	Entry* lchild;
	Entry* rchild;
	friend class Dictonary;

public:
	Entry()
	{
		lchild = NULL;
		rchild = NULL;

		for (int i = 0; i < 20; i++)
		{
			word[i] = meaning[i] = '\0';
		}
	}

	Entry(char* word, char* meaning)
	{
		lchild = rchild = NULL;
		strcpy(this->word, word);
		strcpy(this->meaning, meaning);
	}

	void get_data()
	{
		cout << "Enter Key " << endl;
		cin >> word;

		cout << "Enter meaning " << endl;
		cin >> meaning;
	}

	char* get_word()
	{
		return word;
	}

	char* get_meaning()
	{
		return meaning;
	}

	void set_meaning(char meaning[])
	{
		strcpy(this->meaning, meaning);
	}

};

class Dictonary
{
	Entry* root;
	int comp;

public:
	Dictonary()
	{
		root = NULL;
		comp = 0;
	}

	Entry* insert_word(char word[], char meaning[], Entry* current)
	{
		if (current == NULL)
		{
			Entry* p = new Entry(word, meaning);
			return p;
		}
		else
		{
			if (strcmp(current->word, word) < 0)
				current->rchild = insert_word(word, meaning, current->rchild);
			else
				current->lchild = insert_word(word, meaning, current->lchild);
			return current;
		}

	}

	void set_root(Entry* r)
	{
		root = r;
	}

	Entry* get_root()
	{
		return root;
	}


	void assending(Entry* t)
	{
		if (t != NULL)
		{
			assending(t->lchild);
			cout << t->word << " : " << t->meaning << endl;
			assending(t->rchild);
		}
	}

	void decending(Entry* t)
	{
		if (t != NULL)
		{
			decending(t->rchild);
			cout << t->word << " : " << t->meaning << endl;
			decending(t->lchild);
		}
	}

	void operator=(Dictonary& D)
	{
		root = D.copy_dict(D.get_root());
	}

	Entry* copy_dict(Entry* temp)
	{
		Entry* cpykey = NULL;

		if (temp)
		{
			cpykey = new Entry();
			int i = 0;
			while (temp->word[i] != '\0')
			{
				cpykey->word[i] = temp->word[i];
				i++;
			}
			i = 0;
			while (temp->meaning[i] != '\0')
			{
				cpykey->meaning[i] = temp->meaning[i];
				i++;
			}
			cpykey->lchild = copy_dict(temp->lchild);
			cpykey->rchild = copy_dict(temp->rchild);
		}
		return cpykey;
	}

	Entry* search(char word[])
	{
		Entry* temp = root;

		while (temp != NULL)
		{
			comp++;

			if (strcmp(temp->word, word) == 0)
				return temp;

			if (strcmp(temp->word, word) > 0)
				temp = temp->lchild;

			if (strcmp(temp->word, word) < 0)
				temp = temp->rchild;
		}
		return NULL;
	}

	int get_comparisions()
	{
		return comp;
	}

	void remove(char word[])
	{
		Entry* temp1 = root;
		Entry* temp2 = NULL;

		while (strcmp(temp1->word, word) != 0)
		{
			temp2 = temp1;
			if (strcmp(temp1->word, word) < 0)
				temp1 = temp1->rchild;
			else
				temp1 = temp1->lchild;
		}	

		if (temp1->lchild == NULL && temp1->rchild == NULL)
		{
			if (temp1 == root)
			{
				delete temp1;
				root = NULL;
				return;
			}
			else
			{
				if (temp2->lchild == temp1)
					temp2->lchild = NULL;
				else
					temp2->rchild = NULL;
			}

			delete temp1;
		}
		else if (temp1->lchild == NULL && temp1->rchild != NULL)
		{
			if (temp1 == root)
				root = temp1->rchild;
			else
			{
				if (temp2->lchild == temp1)
					temp2->lchild = temp1->rchild;
				else
					temp2->rchild = temp1->rchild;
			}

			temp1->rchild = NULL;

			delete temp1;
		}
		else if (temp1->lchild != NULL && temp1->rchild == NULL)
		{
			if (temp1 == root)
				root = temp1->lchild;
			else
			{
				if (temp2->lchild == temp1)
					temp2->lchild = temp1->lchild;
				else
					temp2->rchild = temp1->lchild;
			}

			temp1->lchild = NULL;

			delete temp1;
		}
		else
		{
			Entry* temp = temp1->rchild;

			while (temp->lchild != NULL)
			{
				temp2 = temp;
				temp = temp->lchild;
			}

			strcpy(temp1->word, temp->word);
			strcpy(temp1->meaning, temp->meaning);

			/*if (temp1 == root)
				temp2 = root;*/

			if (temp->rchild == NULL)
			{
				if (temp2->lchild == temp)
					temp2->lchild = NULL;
				else
					temp2->rchild = NULL;
			}
			else
			{
				if (temp2->lchild == temp)
					temp2->lchild = temp1->rchild;
				else
					temp2->rchild = temp1->rchild;
			}
		}
	}
};

int main()
{
	Dictonary d, copy;
	Entry* r;
	int n, choice1;
	char w[20], m[20];
	do
	{
		cout << "===================================================" << endl;
		cout << "Which operation do you want to perform ? " << endl;
		cout << "1. Create dictonary " << endl;
		cout << "2. Insert new elements " << endl;
		cout << "3. display all KEYS in ascending order " << endl;
		cout << "4. display all KEYS in descending order " << endl;
		cout << "5. copy this Dictonary " << endl;
		cout << "6. Search for a KEY " << endl;
		cout << "7. get number of comparisons for finding any KEY " << endl;
		cout << "8. Modify a particular KEY " << endl;
		cout << "9. Delete a particular KEY " << endl;
		cout << "10. EXIT " << endl;
		cout << "===================================================" << endl;
		cin >> choice1;

		switch (choice1)
		{
		case 1:case 2:
				cout << "How many KEYS do you wish to insert " << endl;
				cin >> n;

				for (int i = 0; i < n; i++)
				{
					cin >> w;
					cin >> m;

					r = d.insert_word(w, m, d.get_root());
					d.set_root(r);
				}

				break;

		case 3:
			if (d.get_root() == NULL)
				cout << "\nDICTONARY IS EMPTY " << endl;
			else
			{
				cout << "\n\nList in ascending order : " << endl;
				d.assending(d.get_root());
			}
			
			cout << endl << endl;
			break;

		case 4:
			if (d.get_root() == NULL)
				cout << "DICTONARY IS EMPTY " << endl;
			else
			{
				cout << "\n\nList in descending order : " << endl;
				d.decending(d.get_root());
			}
			
			cout << endl << endl;
			break;

		case 5:
			if (d.get_root() == NULL)
				cout << "DICTONARY IS EMPTY " << endl;
			else
			{
				copy = d;
				cout << "\n\ncopy of this dictonary is : " << endl;
				copy.assending(copy.get_root());
			}
			
			cout << endl << endl;
			break;

		case 6:
			if (d.get_root() == NULL)
				cout << "DICTONARY IS EMPTY " << endl;
			else
			{
				cout << "\n\nEnter word to be searched " << endl;
				cin >> w;

				r = d.search(w);
				if (r == NULL)
					cout << "NOT FOUND " << endl;
				else
					cout << "\n" << r->get_word() << " : " << r->get_meaning() << endl;
			}

			break;

		case 7:
			if (d.get_root() == NULL)
				cout << "DICTONARY IS EMPTY " << endl;
			else
			{
				cout << "\n\nEnter word to be searched " << endl;
				cin >> w;

				r = d.search(w);
				if (r == NULL)
					cout << "NOT FOUND " << endl;
				else
					cout << "\n" << r->get_word() << " : " << r->get_meaning() << endl;
			
				cout << "\nTotal number of comparisions is : " << d.get_comparisions() << endl;
			}
			
			break;

		case 8:
			if (d.get_root() == NULL)
				cout << "DICTONARY IS EMPTY " << endl;
			else
			{
				cout << "\n\nWhich word meaning to be modified ? " << endl;
				cin >> w;

				r = d.search(w);

				cout << "\nEnter new meaning " << endl;
				cin >> m;

				r->set_meaning(m);
				cout << endl;
				d.assending(d.get_root());
			}
			
			cout << endl;
			break;

		case 9:
			if (d.get_root() == NULL)
				cout << "DICTONARY IS EMPTY " << endl;
			else
			{
				cout << "Which word is to be deleted ? " << endl;
				cin >> w;

				d.remove(w);
				cout << "\nDELETED SUCCESSFULLY " << endl;
			}
			
			break;

		case 10:
			cout << "\nTERMINATING PROGRAM !! " << endl;
			break;

		default:
			cout << "Enter a valid option " << endl;
			break;
		}
	} while (choice1 != 10);

	return 0;
}
