#include<iostream>
#include <iomanip>    //quoted
#include<fstream>
#include<ostream>
#include<string>
#include<chrono>
#include"../Headers/List.h"
#include"../Headers/MergeSort.h"
#include"../Headers/QuickSort.h"

using namespace std;
int main()
{
	chrono::steady_clock::time_point TimerStart = chrono::high_resolution_clock::now();
	List<MovieNode> L, Q;
	string name;
	int number = 0;
	int  rating = 0;
	ifstream file;
	file.open("projekt2_dane.csv");
	//file.open("1.txt");
	string help;

	Q.AddAtEnd(new MovieNode("a", 1, 1));
	Q.AddAtEnd(new MovieNode("b", 2, 2));
	Q.AddAtEnd(new MovieNode("c", 3, 3));
	Q.AddAtEnd(new MovieNode("d", 4, 4));
	//Q.AddAtEnd(new MovieNode("f", 6, 6));
	/*Q.AddAtEnd(new MovieNode("e", 5, 5));
	Q.AddAtEnd(new MovieNode("g", 7, 7));*/
	
	Q.PrintList();
	//MergeSort::Sort(Q.First(), Q.Last());
	cout << endl  << endl;
	MergeSort::Split(&Q)->PrintList();//.PrintList();
	//->PrintList();
	//MergeSort::Sort(Q.First())->GetName();
	cout << endl << endl;
	Q.PrintList();
	cout << endl;

	if (file.is_open())
	{
		//3892
		// 1010293                             Wszystkie dane
		for (int i = 0; i < 10; i++)
			//while (file.peek() != EOF)
		{
			//wczytanie "numer"
			while (!(file >> number))          // Ulepsz(sprawdza tylko kilka znaków jak nie to idzie dalej)
			{
				file.clear();
				file.ignore();
			}
			file.ignore(1000, ',');

			//wczytanie "name"
			if (file.peek() != '\"')
			{
				while (!getline(file, name, ','))
				{
					file.clear();
					file.ignore();
				}
				//if (!isdigit(file.peek()) && (file.peek() != '\n'))
				//{
				//	int length = file.tellg();
				//	getline(file, help, ',');
				//	if ((help.find("\n") != std::string::npos))
				//	{
				//		file.seekg(length, std::ios_base::beg);
				//		//	file.unget();
				//	}
				//	else name += help;

				//	//cout << help << " " << (help.find("\n") == std::string::npos) << endl;
				//}
			}
			else
			{
				file.ignore(1000, '\"');
				file.ignore();

				while (!getline(file, name, '\"'))
				{
					file.clear();
					file.ignore();
				}

				/*ostringstream oss;
			oss << quoted(name);
				string name = oss.str();*/

				//name = quoted(name);
				file.ignore(1000, ',');

			}

			//wczytanie "rating"
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

	//QuickSort::Sort(L.First(), L.Last());

	chrono::steady_clock::time_point TimerEnd = chrono::high_resolution_clock::now();
	chrono::duration<float> ExTime = TimerEnd - TimerStart;
	cout << "Execution time: " << ExTime.count() << endl;


	//L.PrintList();
	
	cout << L.Last()->GetKey() << " " << L.Last()->GetName() << endl << L.Last()->GetRating() << endl;
	//cout << L.First()->GetKey() << " " << L.First()->GetName() << endl << L.First()->GetRating() << endl;

	return 0;
} //main









