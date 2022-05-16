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
		//std::cout << head->GetName() << std::endl;
		for (int i = 0; i < L->Size(); i++)
		{
			std::cout << L->Size()/2 << std::endl;
			if(i >= (L->Size() / 2)) SecondL->AddAtEnd(head);
			else FirstL->AddAtEnd(head);
			//L->Remove(head);
			head = head->GetNext();
		}
		L->ClearList();
		// 
		//for (MovieNode* i = FirstL->First(); i != FirstL->GetTrailer(); i++)
		//{
		//	L->AddAtEnd(i);
		//	std::cout <<i->GetName() << std::endl;
		//	//i = i->GetNext();
		//}
		head = FirstL->First();
		for (int i = 0; i < FirstL->Size(); i++)
		{
			L->AddAtEnd(head);
			head = head->GetNext();
		}
		delete FirstL;

		//L = FirstL;
		//L->PrintList();
		//FirstL->PrintList();
		std::cout << std::endl;
		return SecondL;
	}



}; //Class
