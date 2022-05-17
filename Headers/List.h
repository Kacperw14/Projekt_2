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

	void operator= (List<T>* _lista);
	void operator+ (List<T>* _lista);
	
	// Podstaowe funkcje dla priorytetowej listy dwukierunkowej:
	const bool IsEmpty() const;
	int Size() const;
	T* AtIndex(const int _index) const;
	T* AtRating(const int _rating) const;
	const int& IndexOf(const std::string mess) const;
	T* Last() const { return trailer->GetPrevious(); };
	T* First() const { return header->GetNext(); };
	
	//Metody dodajace
	void AddAfter(T* afterMe, T* newNode);
	void AddAtEnd(const T* _node);
	void Insert(T* _node);
	//

	//Metody usuwajace
	void Remove(T* _node);
	void ClearList();
	//

	//Dodatkowe przydatne metody
	void PrintList() const;
	const int Min() const;
	const int Max() const;
	//

	//Metody umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	const T* GetHeader() const { return header; };
	const T* GetTrailer() const { return trailer; };
	//
}; //CLASS

