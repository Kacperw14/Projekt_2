#include<iostream>
#include<iomanip> /////////////
#include<fstream>
#include<string>
#include<chrono>
#include"../Headers/List.h"

using namespace std;
int main()
{
	chrono::steady_clock::time_point TimerStart = chrono::high_resolution_clock::now();
	List<MovieNode> L;
	//MovieNode* N;
	string name;
	int number = -1;
	string  rating;
	ifstream file;
	file.open("projekt2.csv");
	//file.open("1.txt");
	string help;

	if (file.is_open())
	{
		//file.ignore(1000, '\n');      
		//while (file.peek() != file.eof())
		for (int i = 0; i < 3; i++)
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
				getline(file, help, ',');
				name += help;
				//cout << help << endl;
			}
			//cout << (file.peek() == '\n') << endl;
			if ((file.peek() == '\n') || !(file >> rating))
			{
				//cout <<rating<< file.good()<<"kwadrat" << endl;
				
				rating = "zero";
				file.clear();
			}
			cout << rating << endl;
				/*while (!(file >> rating))
			{
				file.clear();
				file.ignore();
			}*/
			//file.ignore(1000, '\n');
			//L.AddAtEnd(new MovieNode(name, number, rating));
		}
		//cout << (file.peek() == EOF) << endl;
		//cout << (file.peek() == file.eof()) << endl << L.Size() << endl;

	}
	else cout << "Plik nie jest otwarty.";
	file.close();

	
	chrono::steady_clock::time_point TimerEnd = chrono::high_resolution_clock::now();
	chrono::duration<float> ExTime = TimerEnd - TimerStart;
	cout << "Execution time: " << ExTime.count() << endl;
	
	//L.PrintList();
	//cout << L.Last()->GetKey() << L.Last()->GetName() << L.Last()->GetRating() << endl;
	//chrono::high_resolution_clock::now();

	return 0;
} //main









