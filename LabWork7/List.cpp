#include "pch.h"
#include "List.h"

template<typename T>
List<T>::List()
{
	this->_size = 0;
	this->_head = nullptr;
}

template<typename T>
List<T>::~List()
{
	this->Clear();
}

template<typename T>
void List<T>::PushBack(T data)
{
	if (this->_head == nullptr)
	{
		this->_head = new ListNode<T>(data);
	}
	else
	{
		ListNode<T> *cur = this->_head;

		while (cur->next != nullptr)
		{
			cur = cur->next;
		}

		cur->next = new ListNode<T>(data);
	}

	this->_size++;
}

template<typename T>
void List<T>::PushFront(T data)
{
	this->_head = new ListNode<T>(data, this->_head);

	this->_size++;
}

template<typename T>
void List<T>::InsertAt(int index, T data)
{
	if (index == 0)
	{
		this->PushFront(data);
		
		this->_size++;
	}
	else if (index < 0 || index >= this->_size)
	{
		throw new std::exception("Out of array border");
	}
	else
	{
		ListNode<T> *prev = this->_head;

		for (int i = 0; i < index - 1; i++)
		{
			prev = prev->next;
		}

		ListNode<T> insertingNode = new ListNode<T>(data, prev->next);
		prev->next = insertingNode;

		this->_size++;
	}
}

template<typename T>
void List<T>::RemoveAt(int index)
{
	if (index == 0)
	{
		this->PopFront();

		this->_size--;
	}
	else if (index < 0 || index >= this->_size)
	{
		throw new std::exception("Out of array border");
	}
	else
	{
		ListNode<T> *prev = this->_head;

		for (int i = 0; i < index - 1; i++)
		{
			prev = prev->next;
		}

		ListNode<T> *deleting = prev->next;

		prev->next = deleting->next;

		delete deleting;

		this->_size--;
	}
}

template<typename T>
T & List<T>::Find(T data)
{
	ListNode<T> *cur = this->_head;

	while (cur != nullptr)
	{
		if (cur->data == data)
		{
			return cur->data;
		}

		cur = cur->next;
	}

	throw new std::exception("Searching element is not find.");
	return NULL;
}

template<typename T>
void List<T>::PopFront()
{
	ListNode<T> *temp = this->_head;

	this->_head = this->_head->next;
	
	delete temp;

	this->_size--;
}

template<typename T>
void List<T>::Clear()
{
	while (this->_size)
	{
		this->PopFront();
	}
}

template<typename T>
T & List<T>::operator[](int index)
{
	if (index < this->_size || index >= this->_size)
	{
		throw new std::exception("Out of array border");
	}

	ListNode<T> *cur = this->_head;
	int counter = 0;

	while (cur != nullptr)
	{
		if (counter == index)
		{
			return cur->data;
		}

		cur = cur->next;
		counter++;
	}

	return NULL;
}
