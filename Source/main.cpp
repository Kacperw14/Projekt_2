#include<iostream>
#include<fstream>
#include"../Headers/List.h"
#include<string>

using namespace std;
int main()
{
	List<MovieNode> L;
	MovieNode* N;
	string name, sum;
	int number;
	float rating = 0.1;
	ifstream file;
	file.open("projekt2_dane.csv");

	if (file.is_open())
	{
		file.ignore(1000, '\n');

		for (int i = 0; i < 10; i++)
			//while (file << "m")
		{
			if (file.good())
			{
				file >> number;
				file.ignore(10, ',');
				getline(file, name, ',');
				file >> rating;
				file.ignore(10, '\n');
				sum += name;
				L.AddAtEnd(new MovieNode(name, number, rating));
			}
		}
		L.PrintList();
	}
	file.close();
	return 0;
} //main









