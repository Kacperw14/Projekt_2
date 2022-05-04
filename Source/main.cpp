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
	float rating = -1.0;
	ifstream file;
	//file.open("projekt2.csv");
	file.open("1.txt");
	int c;
	
	//c = file.get();
	//cout << isdigit(file.peek()) << endl;
	for (int i = 0; i < 3; i++)
	{
		//file.ignore(1000, '\n');
		
	}

	//file.clear();
	//cout << quoted(c, ',') << endl;

	if (file.is_open())
	{
		file.ignore(1000, '\n');
		for (int i = 0; i < 3; i++)
			//while (file.peek() != file.eof())
		{
			if (file.good())
			{
				
				while (!(file >> c))
				{
					file.clear();
					file.ignore();
				}
				file.ignore(1000, ',');

				//if (file >> number) cout << "tak" << file.fail() << endl;
				//else
				//{
				//	cout << "nie" << file.fail() << endl;
				//	//do
				//	//{

				//		//cout << name << endl;
				//		//file.unget();
				//		//while (file.fail())
				//		//{
				//		//	file.putback('\"');
				//		//	//file.ignore();
				//		//	//file >> number;
				//		//	file.get();
				//		//	cout << number << " " << file.fail() << endl;
				//		//}

				//		//file >> number;
				//	if (file.good()) cout << "dobry numer" << endl;
				//	cout << number << endl;
				//	//} while (!(file >> number));
				//}

				//if (file.peek() != '\"') file >> number;
				//else file.clear();


				
				//file.ignore(1000, '\n');

				//if (file.peek() == '\"') file.ignore();
				if (file.peek() != '\"')
				{
					getline(file, name, ',');
				}
				else getline(file, name, '\"');

				/*	if (file.peek() == '\"')
					{
						file.ignore();
						getline(file, name, ',');
						file.clear();
					}*/

				file >> rating;
				file.ignore(1000, '\n');

				//do
				//{
				//	if (!file.good())
				//	{
				//		file.ignore(1000, ',');
				//		file.clear();
				//	}
				//	//if (!file.good()) file.ignore(1000, ',');
				//} while (!file.good());

				L.AddAtEnd(new MovieNode(name, number, rating));
			}
			else cout << "Problem z plikiem" << endl;
		}
		//cout << (file.peek() == EOF) << endl;
		//cout << (file.peek() == file.eof()) << endl << L.Size() << endl;
		L.PrintList();

	}
	else cout << "Plik nie jest otwarty.";

	file.close();
	return 0;
} //main









