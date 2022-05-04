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

	//c = file.get();
	//cout << isdigit(file.peek()) << endl;
	//for (int i = 0; i < 2; i++)
	//{
	//	while (!(file >> number))
	//	{
	//		file.clear();
	//		file.ignore();
	//	}
	//	file.ignore(1000, ',');
	//	while (!(getline(file, name, ',')))
	//	{
	//		file.clear();
	//		file.ignore();
	//	}
	//	//file.ignore(1000, ',');

	//	
	//	//rating = file.get();
	//	file >> rating;
	//	cout << file.good() << endl;

	//	/*while (!(file >> rating))
	//	{
	//		file.clear();
	//		file.ignore();
	//	}*/
	//	file.ignore(1000, '\n');

	//	//file.ignore(1000, '\n');
	//	cout <<number << name << " " << rating << endl;
	//}

	//file.clear();
	//cout << quoted(c, ',') << endl;

	if (file.is_open())
	{
		//file.ignore(1000, '\n');
		for (int i = 0; i < 50000; i++)
		//while (file.peek() != file.eof())
		{
			//if (file.good())
			//{

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
			//cout << isdigit(file.peek()) << endl;
			//cout << (!isdigit(file.peek())) << endl;
			//file.ignore(1000, ',');

			while (!(file >> rating))
			{
				file.clear();
				file.ignore();
			}
			file.ignore(1000, '\n');

			//cout << file.good() << endl;

			//do
			//{
			//	if (!file.good())
			//	{
			//		file.ignore(1000, ',');
			//		file.clear();
			//	}
			//	//if (!file.good()) file.ignore(1000, ',');
			//} while (!file.good());
			//cout << number << name << " " << rating << endl;
			L.AddAtEnd(new MovieNode(name, number, rating));
			//}
			//else cout << "Problem z plikiem" << endl;
		}
		//cout << (file.peek() == EOF) << endl;
		//cout << (file.peek() == file.eof()) << endl << L.Size() << endl;
		L.PrintList();

	}
	else cout << "Plik nie jest otwarty.";


	file.close();
	return 0;
} //main









