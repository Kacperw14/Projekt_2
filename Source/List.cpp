#include "../Headers/List.h"

//Konstruktor glowny inicjuje poczatek i koniec tablicy oraz polaczenie miedzy nimi.
template <typename T>
List<T>::List()
{
	header = new T("header", 0, 0,nullptr, nullptr);
	trailer = new T("trailer", 0, 0,header, nullptr);
	header->SetNext(trailer);
}

template <typename T>
const bool& List<T>::IsEmpty() const
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
T* List<T>::AtIndex(const int& _key) const
{
	if (IsEmpty() || _key <= 0)	throw "Index musi istniec";   //Aby zapobiec probie dostepu do nieobslugiwanej pamieci uzyto wyjatku
	else
	{
		T* head = header->GetNext();						  //Nie liczymy header'a, jesli IsEmpty != true to header->GetNext() istnieje.
		for (int i = 0; i < Size(); i++)
		{
			if (head->GetKey() == _key) return head;
			else head = head->GetNext();
		}
		std::cout << "Funkcja \"AtIndex\":Nie ma takiego indexu: " << std::endl;  //W przypadku braku wybranego indeksu odsylany jest nullptr.
		return nullptr;
	}
}

template <typename T>
const int& List<T> ::IndexOf(const std::string& mess) const
{
	if (IsEmpty()) return 0;
	else
	{
		T* head = header->GetNext();		 //Nie liczymy header'a, jesli IsEmpty != true to header->GetNext() istnieje.
		for (int i = 0; i < Size(); i++)
		{
			if (mess == head->GetName()) return head->GetKey();
			else head = head->GetNext();
		}
		return 0;							//Jesli nie ma wybranej frazy lub lista jest pusta program odsyla indeks zerowy.
	}
}

//Metoda pozwala na symulacje odbioru wiadomosci.
template<typename T>
void List<T>::ReceiveMessage(List _lista)
{
	if (_lista.IsEmpty()) std::cout << "Funkcja \"ReceiveMessage\": Lista jest pusta" << std::endl;
	else
	{
		for (T* i = _lista.First(); i != _lista.Last(); i = i->GetNext())   //Petla z iteratorem przyjmujacym postac wezla.
		{
			Insert(i);								//Metoda zarowno dodaje jak i segreguje elementy, wiec przedstawiona metoda przesyla posegregowana wiadomosc
		}
		Insert(_lista.Last());      //Petla nie dodaje ostatniego elementu.

	}
}

template <typename T>
void List<T>::AddAtEnd(std::string mess)
{
	T* newNode = new T(mess, trailer->GetPrevious()->GetKey(), trailer->GetPrevious()->GetRating(), trailer->GetPrevious(), trailer); //Uzycie konstruktora optymalizuje kod.
	trailer->GetPrevious()->SetNext(newNode);             //Ustawienie wszystkich polaczen niezbednych do wzajemnego funkcjonowania elementow.
	trailer->SetPrevious(newNode);
}

template <typename T>
void List<T>::AddAtEnd(const T* _node)
{
	T* newNode = new T(_node->GetName(), _node->GetKey(), _node->GetRating(), trailer->GetPrevious(), trailer);
	trailer->GetPrevious()->SetNext(newNode);
	trailer->SetPrevious(newNode);
}

//template <typename T>
//void List<T>::AddAtEnd(const T* _node)
//{
//	T* newNode = new T(_node->GetName(), _node->GetKey(), _node->GetRating(), trailer->GetPrevious(), trailer);
//	trailer->GetPrevious()->SetNext(newNode);
//	trailer->SetPrevious(newNode);
//}

template <typename T>
void List<T>::AddAfter(T* afterMe, T* _node)
{

	if (afterMe != nullptr)
	{
		T* newNode = new T(_node->GetName(), _node->GetKey(), _node->GetRating(), afterMe, afterMe->GetNext());
		afterMe->GetNext()->SetPrevious(newNode);
		afterMe->SetNext(newNode);
	}
	else std::cout<< "Funkcja \"AddAfter\": Nale¿y podaæ element inny ni¿ nulltr";
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

//Metoda dodaje element na pozycji uzaleznionej od posiadanego klucza. Klucze w liscie ustawione sa od najmniejszego na pocz¹tku do najwiekszego na koncu.
template<typename T>
void List<T>::Insert(T* _node)
{
	if (IsEmpty()) AddAfter(header, _node);
	else
	{
		T* head = header;
		T* index = head;             //Zmienna pomocnicza przyjmujaca posatac najwiekszego indeksu
		for (int i = 0; i < Size(); i++)
		{
			head = head->GetNext();                              //Nie liczymy header'a, jesli IsEmpty != true to header->GetNext() istnieje.
			if (_node->GetKey() >= head->GetKey()) index = head;  //W ten sposob _node jest zawsze wiekszy rowny index.
		}
		AddAfter(index, _node);        //Dodajemy przeslany element zaraz za ustalonym wczesniej elementem index.
	}
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
		T* head = header;
		for (int i = 0; i < Size(); i++)
		{
			head = head->GetNext();
			std::cout << head->GetName() << " (nr wiadomosci: " << head->GetKey() << ")" 
				<< std::endl << " (rating: " << head->GetRating() << ")"<< std::endl;
		}
	}
}

//Metoda pomocnicza drukujaca zawartosc listy jako spojna wiadomosc.
template <typename T>
void List<T>::PrintMessage() const
{
	if (IsEmpty()) std::cout << "Funkcja \"PrintMessage\": Lista jest pusta" << std::endl;
	else
	{
		T* head = header;
		for (int i = 0; i < Size(); i++)
		{
			head = head->GetNext();
			std::cout << head->GetName();
		}
		std::cout << std::endl;
	}
}
//Metoda pomocnicza wyswietlajaca minimalny indeks znajdujacy sie w liscie.
template<typename T>
const int List<T>::Min() const
{
	if (IsEmpty()) return 0;
	else
	{
		T* help = header;
		int min = 1;
		for (int i = 0; i < Size(); i++)
		{
			help = help->GetNext();
			if (min > help->GetKey()) min = help->GetKey();
		}

		return min;
	}
}

//Metoda pomocnicza wyswietlajaca maksymalny indeks znajdujacy sie w liscie.
template<typename T>
const int List<T>::Max() const
{
	if (IsEmpty()) return 0;
	else
	{
		T* help = header;
		int max = 1;
		for (int i = 0; i < Size(); i++)
		{
			help = help->GetNext();
			if (max < help->GetKey()) max = help->GetKey();
		}
		return max;
	}
}

//Przykladowy szablon wezla dwukierunkowego uzyty w projektcie
template
class List<MovieNode>;
