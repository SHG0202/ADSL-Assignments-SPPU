//============================================================================
// Name        : assign5.cpp
// Author      : SHG
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define max 20
using namespace std;

class P_lines
{
	int N_cities;
	int N_lines;
	int G[max][max];
	int Z[max][max];
	int Z2[max][max];

public:
	P_lines()
	{
		N_cities = 0;
		N_lines = 0;

		for (int i = 0; i < max; i++)
			for (int j = 0; j < max; j++)
				G[i][j] = Z[i][j] = Z2[i][j] = 0;
	}

	P_lines(int nc, int nl)
	{
		N_cities = nc;
		N_lines = nl;

		for (int i = 0; i < max; i++)
			for (int j = 0; j < max; j++)
				G[i][j] = Z[i][j] = Z2[i][j] = 0;
	}

	void get_lines()
	{
		int s, d, c;

		for (int t = 0; t < N_lines; t++)
		{
			cout << "Source <--> Destination and Cost ? " << endl;
			cin >> s >> d >> c;

			G[s - 1][d - 1] = G[d - 1][s - 1] = c;
		}
	}

	void display()
	{
		cout << "City -->";
		for (int i = 0; i < N_cities; i++)
			cout << i + 1 << "  ";
		cout << endl;
		for (int i = 0; i < N_cities; i++)
		{
			cout << "City " << i + 1 << ": ";
			for (int j = 0; j < N_cities; j++)
				cout << G[i][j] << "  ";
			cout << endl;
		}
	}

	void prims()
	{
		int reached[max], unreached[max];

		for (int i = 0; i < N_cities; i++)
		{
			reached[i] = 0;
			unreached[i] = 1;
		}

		int min = 10000;
		int yc, xc;
		int count = N_cities - 1;
		int weight = 0;

		reached[0] = 1;
		unreached[0] = 0;

		while (count != 0)
		{
			for (int i = 0; i < N_cities; i++)
			{
				for (int j = 0; j < N_cities; j++)
				{
					if ((reached[i] == 1 && unreached[j] == 1) && (G[i][j] < min && G[i][j] >0))
					{
						yc = j;
						xc = i;
						min = G[i][j];
					}
				}
			}
			Z[xc][yc] = Z[yc][xc] = min;
			weight += min;
			reached[xc] = reached[yc] = 1;
			unreached[yc] = unreached[xc] = 0;
			count--;

			min = 10000;
		}


		cout << "City -->";
		for (int i = 0; i < N_cities; i++)
			cout << i + 1 << "  ";
		cout << endl;
		for (int i = 0; i < N_cities; i++)
		{
			cout << "City " << i + 1 << ": ";
			for (int j = 0; j < N_cities; j++)
				cout << Z[i][j] << "  ";
			cout << endl;
		}

		cout << "\nCost = " << weight << endl;
	}

	void kruskals()
	{
		int ANC[max];
		int C = 0;

		int p = -1;
		int q = -1;

		for (int i = 0; i < N_cities; i++)
			ANC[i] = i;

		int New[max][3];

		for (int i = 0; i < N_cities; i++)
		{
			for (int j = i + 1; j < N_cities; j++)
			{
				if (G[i][j] != 0)
				{
					New[++p][++q] = i;
					New[p][++q] = j;
					New[p][++q] = G[i][j];
					q = -1;
					C++;
				}
			}
		}
		
		for (int i = 0; i < N_lines; i++)
			for (int j = i + 1; j < N_lines; j++)
			{
				if (New[j][2] < New[i][2])
				{
					swap(New[j][0], New[i][0]);
					swap(New[j][1], New[i][1]);
					swap(New[j][2], New[i][2]);
				}
			}

		int count = 0;
		int weight = 0;

		while(count != C)
		{
			if (ANC[New[count][0]] != ANC[New[p][1]])
			{
				Z2[New[count][0]][New[count][1]] = New[count][2];
				weight += New[count][2];
				ANC[New[count][0]] = ANC[New[count][1]];
			}
			count++;
		}

		cout << "City -->";
		for (int i = 0; i < N_cities; i++)
			cout << i + 1 << "  ";
		cout << endl;
		for (int i = 0; i < N_cities; i++)
		{
			cout << "City " << i + 1 << ": ";
			for (int j = 0; j < N_cities; j++)
				cout << Z[i][j] << "  ";
			cout << endl;
		}

		cout << "\nCost = " << weight << endl;
	}
};

int main()
{
	int nc, nl;
	int cho1;

	cout << "No. of cities ?" << endl;
	cin >> nc;
	cout << "No. of lines ? " << endl;
	cin >> nl;

	P_lines p(nc, nl);

	do
	{
		cout << "================================" << endl;
		cout << "Select a option " << endl;
		cout << "1. Get Connections " << endl;
		cout << "2. Min. spanning using Prims " << endl;
		cout << "3. Min. spanning using Kruskals " << endl;
		cout << "4. Display Connections " << endl;
		cout << "5. Exit " << endl;
		cout << "================================" << endl;
		cin >> cho1;

		switch (cho1)
		{
		case 1:
			p.get_lines();
			break;

		case 2:
			p.prims();
			break;

		case 3:
			p.kruskals();
			break;

		case 4:
			p.display();
			break;

		case 5:
			cout << "Terminating !! " << endl;
			break;

		default:
			cout << "Enter a valid option" << endl;
			break;
		}
	} while (cho1 != 5);

	return 0;
}
