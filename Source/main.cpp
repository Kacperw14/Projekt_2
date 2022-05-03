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
	//file.open("1.txt");
	//streambuf* sbuff = cin.rdbuf();

	if (file.is_open())
	{
		file.ignore(1000, '\n');
		//file.ignore(100, '\n');


		for (int i = 0; i < 10; i++)
			//while (file << "m")
		{
			if (file.good())
			{
				//	file.unget();
				//getline(file, number, ',');
				file >> number;
				file.ignore(10, ',');

				/*else
				{
					cout << "Dupa" << endl;

					file.clear();
					file.ignore(10, -1);
				}*/

				getline(file, name, ',');
				//else
				//{
				//	cout << "zle" << endl;
				//	//file.unget();
				//	file.clear();
				//	file.ignore(EOF);
				//}

				file >> rating;
				file.ignore(10, '\n');
				//else
				//{
				//	cout << "nie" << endl;
				//	//file.unget();
				//	file.clear();
				//	file.ignore(EOF);
				//}

				sum += name;
				//cout << number << name << rating << endl;
				//cout << name << endl;
				//cout << rating << endl;
				//number = file.get();
				//file.ignore(1, '\n');
				//file >> rating;
				//getline(file, rating, ',');
				L.AddAtEnd(new MovieNode(name, number, rating));
			}
		}
		L.PrintList();
	}



	//system("pause");
	file.close();
	return 0;
} //main









