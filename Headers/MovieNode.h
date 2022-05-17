#pragma once
#include <iostream>
#include <string>

class MovieNode
{
private:

	std::string name;
	int key;
	int rating;
	MovieNode* previous;
	MovieNode* next;

public:

	//Konstruktory
	MovieNode();
	MovieNode(std::string _name, int _key, int _rating);  //key
	MovieNode(std::string _name, int _key, int _rating, MovieNode* _previous, MovieNode* _next);
	MovieNode(const MovieNode& newNode); 	//Konstruktor kopiuj¹cy
	MovieNode(MovieNode* newNode); 	//Konstruktor kopiuj¹cy
	//~MovieNode();

	//Funkcje umozliwiajace dostep do atrybutow. Dostep tylko do odczytu!
	const std::string GetName() const;
	const int GetKey() const;
	const int GetRating() const;
	MovieNode* GetNext() const;
	MovieNode* GetPrevious() const;

	//Funkcje umozliwiajace zmiane atrybutow.
	void SetNext(MovieNode* newNode);
	void SetPrevious(MovieNode* newNode);
	void SetName(std::string _name) {name = _name;};
	void SetKey(int _key);
	void SetRating(int _rating);
	void SwapData(MovieNode* _node);



}; //CLASS

