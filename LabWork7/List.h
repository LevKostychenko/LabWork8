#pragma once
#include <exception>

template<typename T>
class List
{
public:
	List();
	~List();

public:
	void PushBack(T data);
	void PushFront(T data);
	void InsertAt(int index, T data);
	void RemoveAt(int index);
	T& Find(T data);
	int GetSize() { return _size; }
	void PopFront();
	void Clear();

public:
	T& operator[] (int index);

private:

	template<typename T>
	class ListNode
	{
	public:
		ListNode *next;
		T data;
		ListNode(T data = T(), ListNode* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};

	int _size;
	ListNode<T> *_head;
};

