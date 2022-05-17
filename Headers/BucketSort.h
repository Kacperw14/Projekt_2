#include<iostream>
#include"../Headers/List.h"

struct BucketSort
{

public:

	static void Sort(List<MovieNode>* L)
	{
		List<MovieNode>* buckets[10]; //= new List<MovieNode>()[10];

		for (int i = 0; i < 10; i++)
		{
			buckets[i] = new List<MovieNode>();
		}

		MovieNode* head = L->First();
		for (int i = 0; i < L->Size(); i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (head->GetRating() == j+1) buckets[j]->Insert(head); //->AddAtEnd(head);
			}
			head = head->GetNext();
		}
		//buckets[1].PrintList();
		//buckets[2]->PrintList();
		//buckets[3].PrintList();
		//*L = buckets[2];
		L->ClearList();
		for (int i = 0; i < 10; i++)
		{
			//buckets[i] = new List<MovieNode>();
			*L + buckets[i];
		}
	}

}; //Class
