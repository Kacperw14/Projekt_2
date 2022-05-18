#include"../Headers/MovieNode.h"

MovieNode::MovieNode()
{
	name = "0";
	key = 0;
	previous = nullptr;
	next = nullptr;
}

MovieNode::MovieNode(std::string _name, int _key, int _rating)
{
	name = _name;
	key = _key;
	rating = _rating;
	previous = nullptr;
	next = nullptr;
}

MovieNode::MovieNode(std::string _name, int _key, int _rating, MovieNode* _previous, MovieNode* _next)
{
	name = _name;
	key = _key;
	rating = _rating;
	previous = _previous;
	next = _next;
}

MovieNode::MovieNode(const MovieNode& newNode)
{
	name = newNode.GetName();
	key = newNode.GetKey();
	rating = newNode.GetRating();
	next = newNode.GetNext();
	previous = newNode.GetPrevious();
}

MovieNode::MovieNode(MovieNode* newNode)
{
	name = newNode->GetName();
	key = newNode->GetKey();
	rating = newNode->GetRating();
	next = newNode->GetNext();
	previous = newNode->GetPrevious();
}

const std::string MovieNode::GetName() const
{
	if (this == nullptr) return "0";
	else return name;
}

const int MovieNode::GetKey() const
{
	if (this == nullptr) return 0;
	else return key;
}

const int MovieNode::GetRating() const
{
	if (this == nullptr) return 0;
	else return rating;
}

MovieNode* MovieNode::GetNext() const
{
	if (this == nullptr) throw nullptr; //std::cout << "Funkcja \"GetNext:\": otrzymala nullptr" << std::endl;
	else return next;
}

MovieNode* MovieNode::GetPrevious() const
{
	if (this == nullptr) throw nullptr; //std::cout << "Funkcja \"GetPrevious:\": otrzymala nullptr" << std::endl;
	else return previous;
}

void MovieNode::SetNext(MovieNode* newNode)
{
	if (this == nullptr)  std::cout << "Funkcja \"SetNext:\": otrzymala nullptr" << std::endl;
	else next = newNode;
}
void MovieNode::SetPrevious(MovieNode* newNode)
{
	if (this == nullptr)  std::cout << "Funkcja \"SetPrevious:\": otrzymala nullptr" << std::endl;
	else previous = newNode;
}

void MovieNode::SetKey(int _key)
{
	if (_key >= 0) key = _key;
	else _key = 0;
}

void MovieNode::SetRating(int _rating)
{
	if (_rating >= 0) rating = _rating;
	else rating = 0;
}

void MovieNode::SwapData(MovieNode* _node)
{
	MovieNode* holder = new MovieNode(_node->GetName(),_node->GetKey(), _node->GetRating());// = _node;
	//*holder = _node;
	_node->SetName(name);
	_node->SetKey(key);
	_node->SetRating(rating);

	name = holder->GetName();
	key = holder->GetKey();
	rating = holder->GetRating();
	delete holder;
}




