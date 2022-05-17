#include<iostream>
#include"../Headers/List.h"

struct BucketSort
{

public:

	static void Sort(List<MovieNode>* _list)
	{
		List<MovieNode>* buckets[10]; //tworze 10 koszy kazdy przechowuje wartosci od 1 do 10

		for (int i = 0; i < 10; i++)
		{
			buckets[i] = new List<MovieNode>();	//inicjuje tablice
		}

		//MovieNode* help = _list->First();   //zmienna pomocnicza iterujaca po liscie
		for (MovieNode* help = _list->First(); help != _list->Last()->GetNext(); help = help->GetNext())
		{
			for (int j = 0; j < 10; j++)
			{
				if (help->GetRating() == j + 1) buckets[j]->AddAtEnd(help);//dodajemy do odpowiedniego kubelka
			}															
		}

		_list->ClearList();          //aby polaczc wszystkie tablice nalezy wczesniej ja wyczyscic
		for (int i = 0; i < 10; i++)
		{
			*_list + buckets[i];     //dodanie kazdej kolejnej tablicy do listy za pomoca przeciazonego operatora + dla klasy List
		}
	}

}; //Class
