#include <iostream>
#include <fstream>
#include <string>
#define max 20
using namespace std;

class Stud_Info
{
	string name;
	int roll;
	char div;
	int marks;

public:
	Stud_Info()
	{
		name = "";
		roll = 0;
		div = ' ';
		marks = -1;
	}

	void get_Info()
	{
		cout << "\nROLL No. ";
		cin >> roll;
		cout << "\nNAME : ";
		cin >> name;
		cout << "\ndivision : ";
		cin >> div;
		cout << "\nScore : ";
		cin >> marks;
	}

	void display()
	{
		cout << "Roll No. -> " << roll << endl;
		cout << "Name     -> " << name << endl;
		cout << "Marks    -> " << marks << endl;
	}

	void get_Marks(int Marks)
	{
		marks = Marks;
	}

	string get_Name()
	{
		return name;
	}
};

class FileOpt
{
	fstream fio;
	int n;

public:
	FileOpt()
	{
		n = 0;
	}

	void open()
	{
		fio.open("assign10.txt", ios::in | ios::out);
	}

	void write()
	{
		Stud_Info s;
		fio.open("assign10.txt", ios::out);

		cout << "No. of students ? ";
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			s.get_Info();
			fio.write((char*)&s, sizeof(s));
		}

		fio.close();
	}

	void New()
	{
		Stud_Info s;
		fio.open("assign10.txt", ios::app);

		s.get_Info();
		fio.write((char*)&s, sizeof(s));

		fio.close();
	}


	void read()
	{
		fio.open("assign10.txt", ios::in);
		Stud_Info s;

		while(!fio.eof())
		{
			fio.read((char*)&s, sizeof(s));
			if(!fio.eof())
				s.display();
		}

		fio.close();
	}
	
	bool search(string name)
	{
		fio.open("assign10.txt", ios::in);
		Stud_Info s;
		int flag = 0;

		while(!fio.eof())
		{
			fio.read((char*)&s, sizeof(s));

			if (s.get_Name() == name)
			{
				s.display();
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			return 0;
		else
			return 1;
	}

	void update(string name)
	{
		fio.open("assign10.txt", ios::in | ios::out);
		Stud_Info s;
		int m, flag = 0;

		while(!fio.eof())
		{
			fio.read((char*)&s, sizeof(s));

			if (s.get_Name() == name)
			{
				cout << "Updated marks : ";
				cin >> m;
				s.get_Marks(m);
				fio.write((char*)&s, sizeof(s));
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			cout << "Record does not exist " << endl;
	}

	void remove(string name)
	{
		Stud_Info s;
		fstream temp;
		int m;
	
		temp.open("temp.txt", ios::out);
		fio.open("assign10.txt", ios::in);

		while(fio.read((char*)&s, sizeof(s)))
		{
			if (s.get_Name() != name)
				temp.write((char*)&s, sizeof(s));			
		}
		//cout << "Record does not exist " << endl;
		fio.close();
		temp.close();
		remove("assign10txt");
		rename("temp.txt", "assign10.txt");
	}

	void close()
	{
		fio.close();
	}
};

int main()
{
	int opt;
	FileOpt Fil;

	//Fil.open();

	do
	{
		cout << "=============================" << endl;
		cout << "Select an option             " << endl;
		cout << "1. Get Student Data          " << endl;
		cout << "2. Enter New Record          " << endl;
		cout << "3. Display Student Data      " << endl;
		cout << "4. Search for a given Record " << endl;
		cout << "5. Update a Record           " << endl;
		cout << "6. Delete a Record           " << endl;
		cout << "7. Exit                      " << endl;
		cout << "=============================" << endl;
		cin >> opt;

		switch (opt)
		{
		case 1:
			//Fil.open();
			Fil.write();
			//Fil.close();
			break;

		case 2:
			Fil.New();
			break;

		case 3:
			//Fil.open();
			Fil.read();
			//Fil.close();
			break;

		case 4:
		{
			//Fil.open();

			string name;
			cout << "Which Student record do you want to search ? " << endl;
			cin >> name;

			if (Fil.search(name))
				cout << "RECORD FOUND !! " << endl;
			else
				cout << "NO RECORD EXIST !! " << endl;

			Fil.close();
		}
		break;

		case 5:
		{
			//Fil.open();

			string name;
			cout << "Which Student record do you want to update ? " << endl;
			cin >> name;

			Fil.update(name);

			Fil.close();
		}
		break;

		case 6:
		{
			//Fil.open();

			string name;
			cout << "Which Student record do you want to delete ? " << endl;
			cin >> name;

			Fil.remove(name);

			//Fil.close();
		}
		break;

		case 7:
			cout << "Terminating !! " << endl;
			break;
		}

	} while (opt != 7);

	return 0;
}