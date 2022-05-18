#include "../Headers/List.h"

//Konstruktor glowny inicjuje poczatek i koniec tablicy oraz polaczenie miedzy nimi.
template <typename T>
List<T>::List()
{
	header = new T("header", 0, 0,nullptr, nullptr);
	trailer = new T("trailer", 0, 0,header, nullptr);
	header->SetNext(trailer);
}

template<typename T>
void List<T>::operator+(List<T>* _lista)
{
	for (T* head = _lista->First(); head != _lista->Last()->GetNext(); head = head->GetNext())
	{
		AddAtEnd(head); 
	}
}

template <typename T>
const bool List<T>::IsEmpty() const
{
	if (header->GetNext() == trailer)
	{
		return true;
	}
	else return false;
}

template <typename T>
int List<T>::Size() const
{
	if (IsEmpty()) return 0;
	else
	{
		int size = 0;
		T* head = header->GetNext();			//Nie liczymy header'a, jesli IsEmpty != true to header->GetNext() istnieje.
		while (head != trailer)
		{
			size++;
			head = head->GetNext();
		}
		return size;
	}
}

template <typename T>
void List<T>::AddAtEnd(const T* _node)
{
	T* newNode = new T(_node->GetName(), _node->GetKey(), _node->GetRating(), trailer->GetPrevious(), trailer);
	trailer->GetPrevious()->SetNext(newNode);
	trailer->SetPrevious(newNode);
}

template<typename T>
void List<T>::Remove(T* _node)
{
	if (_node != nullptr && _node != header && _node != trailer)
	{
		_node->GetNext()->SetPrevious(_node->GetPrevious());	 //Aby nie doszlo do wyciekow pamieci ustalane sa nowe wezly.
		_node->GetPrevious()->SetNext(_node->GetNext());
		delete _node;                                            //Zwolnienie pamieci komputera.
	}
	else std::cout << "Funkcja \"Remove\": Nie mozna usunac nullptr, header ani trailer" << std::endl; //Informacja o nieprawidlowych dzialaniach
}

template<typename T>
void List<T>::ClearList()
{
	while (!IsEmpty())
	{
		Remove(Last());
	}
}
//Metoda pomocnicza ulatwiajaca sledzenie atrybutow kazdego z wezlow, zarowno klucza jak i wiadomosci.
template <typename T>
void List<T>::PrintList() const
{
	if (IsEmpty()) std::cout << "Funkcja \"PrintList\": Lista jest pusta" << std::endl;
	else
	{
		
		for (T* head = header->GetNext(); head != trailer; head = head->GetNext())
		{
			std::cout << head->GetName() << " (nr wiadomosci: " << head->GetKey() << ")" 
				<< " (rating: " << head->GetRating() << ")"<< std::endl;
		}
	}
}

//Przykladowy szablon wezla dwukierunkowego uzyty w projektcie
template
class List<MovieNode>;
