#pragma once
#include <iostream>
#include <string>

class MovieNode
{
private:

	std::string name;
	int key;
	int rating;    //float
	MovieNode* previous;
	MovieNode* next;

public:

	//Konstruktory
	MovieNode();
	MovieNode(std::string _name, int _key, int _rating);  //key
	MovieNode(std::string _name, int _key, int _rating, MovieNode* _previous, MovieNode* _next);
	MovieNode(const MovieNode& newNode); 	//Konstruktor kopiuj¹cy
	MovieNode(MovieNode* newNode); 	//Konstruktor kopiuj¹cy
	~MovieNode();

	//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	const std::string GetName() const;   //const &
	const int GetKey() const;
	const int GetRating() const;
	MovieNode* GetNext() const;
	MovieNode* GetPrevious() const;

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetNext(MovieNode* newNode);
	void SetPrevious(MovieNode* newNode);

	void SetRaiting(int _rating)
	{
		if (_rating > 0) rating = _rating;
		else rating = 0;
	};
	void SwapData(MovieNode* _node)
	{
		MovieNode holder = _node;

		//	_node = new MovieNode(name, key, rating, previous, next);
		_node->SetPrevious(previous);
		_node->SetNext(next);
		next->SetPrevious(_node);
		previous->SetNext(_node);


		//name = holder->GetName();
		//key = holder->GetKey();
		//rating = holder->GetRating();
		previous = holder.GetPrevious();
		holder.GetPrevious()->SetNext(this);
		next = holder.GetNext();
		holder.GetNext()->SetPrevious(this);

		//_node->SetNext(next);
		//_node->SetPrevious(previous);
		//// _node->GetPrevious()->SetNext();
		//next->SetPrevious(_node);
		//previous->SetNext(_node);

		//this->SetNext(holder->next);
		//this->SetPrevious(holder->previous);

		//delete holder;
	};


}; //CLASS

