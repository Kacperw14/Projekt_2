#include<iostream>
#include"../Headers/List.h"

static struct Quicksort
{

public:
	static void QuickSort(MovieNode* _header, MovieNode* _trailer)
	{
		MovieNode* p = _header;
		MovieNode* q = _trailer;

		/*while (_header != _trailer)
		{
			 _header = _header->GetNext();
			if (_header != _trailer) _trailer = _trailer->GetPrevious();
		}*/
		int	pivot = _header->GetKey();
		std::cout << "pivot: " << pivot << std::endl;
		//if (p->GetNext()) pivot = p->GetNext()->GetKey();         //Zabezpiecz
		//if (p != nullptr && q != nullptr)    //nie wiem header i trailer= nullptr
		//{
		do
		{
			while (p->GetKey() < pivot) p = p->GetNext();  //nigdy dla pivot = p
			while (q->GetKey() > pivot) q = q->GetPrevious();
			if (_header <= _trailer)
			{
				std::cout << "q: " << q->GetKey() << std::endl;
				std::cout << "p: " << p->GetKey() << std::endl;

				p->SwapKeys(q);
				_header = _header->GetNext();
				_trailer = _trailer->GetPrevious();
				//if (p != nullptr && p->GetNext() != nullptr) p = p->GetNext();
				//if (q != nullptr && q->GetPrevious() != nullptr) q = q->GetPrevious();

			}
			//while (q->GetKey() > pivot) q = q->GetPrevious();
		} while (_header <= _trailer);

		//if (q > _header) QuickSort(_header, q);
		//if (p < _trailer) QuickSort(p, _trailer);

	//std::cout << "j: " << j->GetKey() << std::endl;


				//std::cout << "i: " << i->GetKey()<< std::endl;
				//std::cout << "j: " << j->GetKey() << std::endl;
				//std::cout << "i: " << i->GetKey() << std::endl;
	}




}; //Class
