#include<iostream>
#include"../Headers/List.h"

struct MergeSort
{

public:
	static MovieNode* Split(MovieNode* head)
	{
		//zabezpiecz
		MovieNode* first = head;
		MovieNode* last = head;
		bool odd = true;
		while (last->GetNext() != nullptr) last = last->GetNext(); //last przypisany jako trailer
		last = last->GetPrevious();   //przed trailerem
		while (first != last)
		{
			if (odd)
			{
				first = first->GetNext();
				odd = false;
			}
			else
			{
				last = last->GetPrevious();
				odd = true;
			}
			std::cout << first->GetName()<< last->GetName() << std::endl;
		}
		return first;
	}
}; //Class
