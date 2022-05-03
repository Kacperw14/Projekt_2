#include<iostream>
#include<fstream>
#include"../Headers/List.h"
#include<string>

using namespace std;
int main()
{
	List<MovieNode> L;
	MovieNode* N;
	string name;
	int number = 1;
	float rating = 0.1;
	ifstream file;
	file.open("projekt2_dane.csv");
	//file.open("1.txt");
	//streambuf* sbuff = cin.rdbuf();

	if (file.is_open())
	{
		file.ignore(1);
		for (int i = 0; i < 1; i++)
			//while (file << "m")

		{
			//	file.unget();
			//getline(file, number, ',');
			file >> number;
			getline(file, name, ',');
			file >> rating;
			//getline(file, rating, ',');
			N = new MovieNode(name, number, rating);
			L.AddAtEnd(N);
			//info += s;
		}
		cout << name << endl;
		L.PrintList();
	}



	//system("pause");
	file.close();
	return 0;
} //main









