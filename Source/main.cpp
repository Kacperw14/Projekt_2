#include<iostream>
#include <iomanip>    //quoted
#include<fstream>
#include<ostream>
#include<string>
#include<chrono>
#include"../Headers/List.h"
#include"../Headers/MergeSort.h"
#include"../Headers/QuickSort.h"
#include"../Headers/BucketSort.h"

int arr[10000000];  /////arr

using namespace std;
int main()
{
	bool flaga = false;
	int num = 0;
	List<MovieNode> L;
	string name;
	int number = 0;
	int  rating = 0;
	ifstream file;
	string help;
	char choice = 'm';

	while (choice != 'k')
	{
		switch (choice)
		{
		case 'm':
		{
			cout << "Menu wyboru: " << endl;
			cout << "Wybierz \'m\' aby zobaczyc menu" << endl;
			cout << "Wybierz \'w\' aby wczytac dane" << endl;
			cout << "Wybierz \'b\' aby uzyc algorytmu kubelkowego" << endl;
			cout << "Wybierz \'q\' aby uzyc algorytmu quicksort" << endl;
			cout << "Wybierz \'e\' aby uzyc algorytmu merge sort" << endl;
			cout << "Wybierz \'d\' aby wydrukowac liste" << endl;
			cout << "Wybierz \'k\' aby wyjsc" << endl;
		}
		break;
		case 's':
		{
			MovieNode* M = L.First();
			int size = L.Size();
			int iter = 0;
			float srednia = 0;
			for (MovieNode* N = L.First(); N != L.Last()->GetNext(); N = N->GetNext())
			{
				srednia += N->GetRating();
				if (++iter <= (size / 2)) M = N;
			}
			if (size % 2 == 0) cout << "Mediana: " << (float)(M->GetRating() + M->GetPrevious()->GetRating()) / 2 << endl;
			else cout << "Mediana: " << M->GetRating() << endl;

			cout << "Srednia: " << (srednia / L.Size()) << endl;
		}
		break;
		case 'w':
		{
			file.open("projekt2_dane.csv");

			if (file.is_open())
			{
				// 1010293                             Wszystkie dane
				cout << "Ile danych wczytac? ";
				cin >> num;
				cout << endl;

				for (int i = 0; i < num; i++)
					//while (file.peek() != EOF)
				{
					//wczytanie "numer"
					while (!(file >> number))
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
					arr[i] = rating;
				}
				cout << "Operacja wczytania zakonczyla sie pomyslnie" << endl;
			}
			else cout << "Plik nie jest otwarty.";
			file.close();
			flaga = true;
		}
		break;
		case'e':
		{
			if (flaga)
			{
				chrono::steady_clock::time_point TimerStart = chrono::high_resolution_clock::now(); //start Timera
				MergeSort(arr, 0, num / 2 - 1);
				chrono::steady_clock::time_point TimerEnd = chrono::high_resolution_clock::now(); //Koniec Timera
				chrono::duration<float> ExTime = TimerEnd - TimerStart;
				cout << "Czas wykonywania operacji: " << ExTime.count() << endl;
				flaga = false;
			}
			else cout << "Dane nalezy wczytac \'w\' przed kazdym uzyciem algorytmu sortowania" << endl;
		}break;
		case'b':
		{
			if (flaga)
			{
				chrono::steady_clock::time_point TimerStart = chrono::high_resolution_clock::now(); //start Timera
				BucketSort::Sort(&L);
				chrono::steady_clock::time_point TimerEnd = chrono::high_resolution_clock::now(); //Koniec Timera
				chrono::duration<float> ExTime = TimerEnd - TimerStart;
				cout << "Czas wykonywania operacji: " << ExTime.count() << endl;
				flaga = false;
			}
			else cout << "Dane nalezy wczytac \'w\' przed kazdym uzyciem algorytmu sortowania" << endl;
		}break;
		case'q':
		{
			if (flaga)
			{
				chrono::steady_clock::time_point TimerStart = chrono::high_resolution_clock::now(); //start Timera
				QuickSort::Sort(L.First(), L.Last());
				chrono::steady_clock::time_point TimerEnd = chrono::high_resolution_clock::now(); //Koniec Timera
				chrono::duration<float> ExTime = TimerEnd - TimerStart;
				cout << "Czas wykonywania operacji: " << ExTime.count() << endl;
				flaga = false;
			}
			else cout << "Dane nalezy wczytac \'w\' przed kazdym uzyciem algorytmu sortowania" << endl;
		}break;
		case'd':
		{
			int w; //wybor druku
			cout << "Wybierz czy wydrukowac liste: nr \'1\', czy tablice: nr \'2\' (tylko dla merge sort) ";
			cin >> w;
			if (w == 1) L.PrintList();
			else if (2)
			{
				PrintArray(arr, num / 2);
				cout << endl;
			}
		}break;
		default:
		{
			cout << "Niepoprawne polecenie" << endl;
			cin.ignore(10000, '\n');                 //Pozwala na ignorowanie losowo wpisanych liter.
		}
		break;
		}
		cin >> choice;      //Wybor opcji
	}
	return 0;
} //main









