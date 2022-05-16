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
	void SetName(std::string _name) { name = _name; };
	void SetKey(int _key)
	{
		if (_key >= 0) key = _key;
		else _key = 0;
	};
	
	void SetRating(int _rating)
	{
		if (_rating >= 0) rating = _rating;
		else rating = 0;
	};
	
	void SwapData(MovieNode* _node)
	{
		MovieNode holder = _node;

		_node->SetName(name);
		_node->SetKey(key);
		_node->SetRating(rating);

		name = holder.GetName();
		key = holder.GetKey();
		rating = holder.GetRating();



		/*_node->SetPrevious(previous);
		_node->SetNext(next);
		next->SetPrevious(_node);
		previous->SetNext(_node);

		previous = holder.GetPrevious();
		holder.GetPrevious()->SetNext(this);
		next = holder.GetNext();
		holder.GetNext()->SetPrevious(this);*/

	};


}; //CLASS

