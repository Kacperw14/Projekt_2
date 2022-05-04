#include<iostream>
#include<iomanip> /////////////
#include<fstream>
#include"../Headers/List.h"
#include<string>

using namespace std;
int main()
{
	List<MovieNode> L;
	MovieNode* N;
	string name;
	int number = -1;
	float rating;
	ifstream file;
	file.open("projekt2_dane.csv");
	//file.open("1.txt");
	string help;

	if (file.is_open())
	{
	for (int i = 0; i < 50000; i++)
		{

			while (!(file >> number))
			{
				file.clear();
				file.ignore();
			}
			file.ignore(1000, ',');


			while (!getline(file, name, ','))
			{
				file.clear();
				file.ignore();
			}
			if (!isdigit(file.peek()))
			{
				getline(file, help, ',');
				name += help;
			}

			while (!(file >> rating))
			{
				file.clear();
				file.ignore();
			}
			file.ignore(1000, '\n');
			L.AddAtEnd(new MovieNode(name, number, rating));
		}
		//cout << (file.peek() == EOF) << endl;
		//cout << (file.peek() == file.eof()) << endl << L.Size() << endl;
		L.PrintList();

	}
	else cout << "Plik nie jest otwarty.";

	file.close();
	return 0;
} //main









