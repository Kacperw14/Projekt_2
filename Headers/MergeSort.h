#include<iostream>
#include"../Headers/List.h"

struct MergeSort
{

public:

	static List<MovieNode>* Split(List<MovieNode>* L)
	{
		MovieNode* head = L->First();
		List<MovieNode>* FirstL = new List<MovieNode>();
		List<MovieNode>* SecondL = new List<MovieNode>();

		for (int i = 0; i < L->Size(); i++)
		{
			std::cout << L->Size()/2 << std::endl;
			if(i >= (L->Size() / 2)) SecondL->AddAtEnd(head);
			else FirstL->AddAtEnd(head);
			head = head->GetNext();
		}

		L->ClearList();
		
		head = FirstL->First();

		for (int i = 0; i < FirstL->Size(); i++)
		{
			L->AddAtEnd(head);
			head = head->GetNext();
		}
		delete FirstL;
		return SecondL;
	}



}; //Class
