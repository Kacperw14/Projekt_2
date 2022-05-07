#pragma once
#include <iostream>
#include <string>

class MovieNode
{
private:

	std::string name;
	int key;
	float rating;
	MovieNode* previous;
	MovieNode* next;

public:

	//Konstruktory
	MovieNode();
	MovieNode(std::string _name, int _key, float _rating);  //key
	MovieNode(std::string _name, int _key, float _rating, MovieNode* _previous, MovieNode* _next);
	MovieNode(const MovieNode& newNode); 	//Konstruktor kopiuj¹cy
	~MovieNode();

	//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	const std::string GetName() const;   //const &
	const int GetKey() const;
	const float GetRating() const;
	MovieNode* GetNext() const;
	MovieNode* GetPrevious() const;

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetNext(MovieNode* newNode);
	void SetPrevious(MovieNode* newNode);

	void SetKey(int _key) 
	{
		if (_key > 0) key = _key;
		else key = 0;
	};
	void SwapKeys(MovieNode* _node)
	{
		int holder = _node->GetKey();
		_node->SetKey(key);
		SetKey(holder);
	};


}; //CLASS

