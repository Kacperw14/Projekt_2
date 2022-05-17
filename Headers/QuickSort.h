#include<iostream>
#include"../Headers/List.h"

struct QuickSort
{

public:

	static MovieNode* Partition(MovieNode* first, MovieNode* last)  //funkcja dzielaca liste na mniejsze czesci
	{
		int pivot = last->GetRating();   //przedzialka ustawiona jako ostatnim elementem

		MovieNode* help = first->GetPrevious();

		for (MovieNode* i = first; i != last; i = i->GetNext()) //petla laczaca 
		{
			if (i->GetRating() <= pivot)  //jesli wartosc mniejsza rowna przedzialce zamieniamy go z pierwszy elementem 
			{
				help = help->GetNext();
				help->SwapData(i);            //zamiana za pomoca funkcji napisanej w List.h
			}
		}
		help = help->GetNext();
		help->SwapData(last);               //zamiana z ostatnim elementem, nasza przedzialka
		return help;
	}

	static void Sort(MovieNode* first, MovieNode* last)
	{
		if (last != nullptr && first != last && first != last->GetNext())//funckja konczy dzialanie gdy ostatni element jest null, 
		{												//lewy i prawy wskaŸnik spotkaj¹ siê, lub lewy wyprzedzi prawy wskaznik
			MovieNode* p = Partition(first, last); //ustalenie przedzialki
			Sort(first, p->GetPrevious());			//rekurencyjne wywolanie funkcji dla argumentow przed
			Sort(p->GetNext(), last);				// i za przedzialka
		}
	}



}; //Class
