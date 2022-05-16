#include<iostream>
#include"../Headers/List.h"

struct QuickSort
{

public:

	static MovieNode* Partition(MovieNode* first, MovieNode* last)
	{
		int pivot = last->GetRating();  

		MovieNode* i = first->GetPrevious();

		for (MovieNode* j = first; j != last; j = j->GetNext())
		{
			if (j->GetRating() <= pivot)
			{
				i = (i == nullptr) ? first : i->GetNext();
				i->SwapData(j);
			}
		}
		i = (i == nullptr) ? first : i->GetNext();
		i->SwapData(last);
		return i;
	}

	static void Sort(MovieNode* first, MovieNode* last)
	{
		if (last != NULL && first != last && first != last->GetNext())
		{
			MovieNode* p = Partition(first, last);
			Sort(first, p->GetPrevious());
			Sort(p->GetNext(), last);
		}
	}



}; //Class
