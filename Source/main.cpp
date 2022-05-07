#include<iostream>
#include<fstream>
#include<string>
#include<chrono>
#include"../Headers/List.h"

using namespace std;
int main()
{
	chrono::steady_clock::time_point TimerStart = chrono::high_resolution_clock::now();
	List<MovieNode> L;
	string name;
	int number = 0;
	float  rating = 0;
	ifstream file;
	file.open("projekt2_dane.csv");
	//file.open("1.txt");
	string help;

	if (file.is_open())
	{
		// 1010294                             Wszystkie dane
			//for (int i = 0; i < 1010293; i++)
		while (file.peek() != EOF)
		{
			while (!(file >> number))          // Ulepsz(sprawdza tylko kilka znaków jak nie to idzie dalej)
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
			if (!isdigit(file.peek()) && (file.peek() != '\n'))
			{
				int length = file.tellg();
				getline(file, help, ',');
				if ((help.find("\n") != std::string::npos))
				{
					file.seekg(length, std::ios_base::beg);
					//	file.unget();
				}
				else name += help;

				//cout << help << " " << (help.find("\n") == std::string::npos) << endl;
			}

			if ((file.peek() == '\n') || !(file >> rating))
			{
				rating = 0;
				file.clear();
			}

			file.ignore(1000, '\n');

			L.AddAtEnd(new MovieNode(name, number, rating));
		}
	}
	else cout << "Plik nie jest otwarty.";
	file.close();


	chrono::steady_clock::time_point TimerEnd = chrono::high_resolution_clock::now();
	chrono::duration<float> ExTime = TimerEnd - TimerStart;
	cout << "Execution time: " << ExTime.count() << endl;

	//L.PrintList();
	cout << L.Last()->GetKey() << L.Last()->GetName() << L.Last()->GetRating() << endl;
	return 0;
} //main









