#pragma once
#include "../Headers/MovieNode.h"


//Mozliwosc rozszerzenia struktury o nowe wezly dwukietrunkowe (template)
template <typename T>
class List : MovieNode
{
private:
	T* header;
	T* trailer;

public:
	//Konstruktory
	List();
	//Konstruktor kopiujacy
	List(const List<T>& _lista) : header(_lista.header), trailer(_lista.trailer) {};
	//List(List<T>* _lista) //: header(_lista->header), trailer(_lista->trailer){};  
	//{
	//	header = _lista->header;
	//};
	//Destruktor
	void operator= (List<T>* _lista)
	{
		//std::cout <<"Jestem" << std::endl;
		ClearList();
		T* head = _lista->First();
		for (int i = 0; i < _lista->Size(); i++)
		{
			AddAtEnd(head); // << head->GetName() 
			head = head->GetNext();
		}
	};

	void operator+ (List<T>* _lista)
	{
		//std::cout << "Jestem" << std::endl;
		//ClearList();
		T* head = _lista->First();
		for (int i = 0; i < _lista->Size(); i++)
		{
			AddAtEnd(head); // << head->GetName() 
			head = head->GetNext();
		}
	};

	~List() { delete header; delete trailer; };
	//
	// Podstaowe funkcje dla priorytetowej listy dwukierunkowej:
	const bool& IsEmpty() const;
	int Size() const;
	T* AtIndex(const int& _key) const;
	const int& IndexOf(const std::string& mess) const;
	T* Last() const { return trailer->GetPrevious(); };
	T* First() const { return header->GetNext(); };
	//
	/*
	void Bind(List<T>* _lista) 
	{
		if(!IsEmpty())
		{ 
			//T* newNode = new T(_node->GetName(), _node->GetKey(), _node->GetRating(), afterMe, afterMe->GetNext());
			//_lista->Remove
			//delete (_lista->First()->GetPrevious());
			_lista->First()->SetPrevious(Last());
			std::cout << _lista->First()->GetName() << std::endl;
			//_lista->First()->SetPrevious(_lista->First());
			std::cout << Last()->GetName() << std::endl;
			//Last()->GetNext()->SetPrevious(nullptr);
			Last()->SetNext(_lista->First());
		}
		//AddAfter(Last(), _lista.First()); 
	
	};
	*/
	//Metody dodajace
	void AddAfter(T* afterMe, T* newNode);
	void AddAtEnd(std::string mess);
	void AddAtEnd(const T* _node);
	void Insert(T* _node);
	//

	//Metody usuwajace
	void Remove(T* _node);
	void ClearList();
	//

	//Dodatkowe przydatne metody
	void ReceiveMessage(List _lista);
	void PrintList() const;
	void PrintMessage() const;
	const int Min() const;
	const int Max() const;
	//

	//Metody umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	const T* GetHeader() const { return header; };
	const T* GetTrailer() const { return trailer; };
	//
}; //CLASS

