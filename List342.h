#ifndef LIST342_H_ 
#define LIST342_H_ 

#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template<class ItemType>
class List342
{
	friend ostream& operator<<(ostream& os, const List342<ItemType>& rhs)
	{
		{
			if (rhs.head == NULL)
			{
				os << "Empty";
				return os;
			}

			Node* current = rhs.head;
			while (current != NULL)
			{
				os << *current->data;
				current = current->next;
			}

			return os;
		}
	}

public:
	List342();
	List342(string FileName);
	List342(List342<ItemType>& rhs);
	~List342();

	bool BuildList(string FileName);
	bool Insert(ItemType* obj);
	bool Remove(ItemType target, ItemType& result);
	bool Peek(ItemType target, ItemType& result);
	bool isEmpty();
	void DeleteList();
	bool Merge(List342& list1);

	List342 operator+(const List342& rhs) const;
	List342& operator+=(const List342& rhs);

	bool operator==(const List342& rhs)const;
	bool operator!=(const List342& rhs)const;
	const List342& operator=(const List342& rhs);


private:
	struct Node
	{
		ItemType* data = NULL;
		Node* next = NULL;
	};

	Node* head = NULL;
	int size;

};


	template<class ItemType>
	List342<ItemType>::List342()
	{
		head = NULL;
	}

	template<class ItemType>
	List342<ItemType>::List342(string FileName)
	{
		BuildList(FileName);
	}

	//copy constructor 
	template<class ItemType>
	List342<ItemType>::List342(List342<ItemType>& rhs)
	{
		head = NULL;
		*this = rhs;

	}
	//destructor that deletes the necessary nodes
	template<class ItemType>
	List342<ItemType>::~List342()
	{
		DeleteList();
	}

	template<class ItemType>
	bool List342<ItemType>::BuildList(string FileName)
	{
		ifstream in(FileName);
		DeleteList();

		if (!in)	// unable to find the file
		{
			return false; 
		}

		ItemType* itemObject = new ItemType;
		while (!in.eof()) 
		{
			in >> *itemObject;
			Insert(itemObject);

		}

		delete itemObject;

		in.close();
		return true;
	}

	template<class ItemType>
	bool List342<ItemType>::Insert(ItemType* obj)
	{

		if (obj == NULL) // check for null pointer exceptions 
		{
			return false;
		}

		Node* pTemp = new Node();
		pTemp->data = new ItemType(*obj);

		if (head == NULL || *pTemp->data < *head->data) // orders items accordingly 
		{
			pTemp->next = head;
			head = pTemp;
			//pTemp = NULL;
			return true;
		}

		Node* previous = head;
		Node* current = previous->next;

		// traverse through the list with two pointers 
		while (current != NULL && *current->data <= *pTemp->data)
		{
			previous = current;
			current = current->next;
		}

		if (*previous->data == *pTemp->data)
		{
			delete pTemp;
			pTemp = NULL;
			return false;
		}

		pTemp->next = current;
		previous->next = pTemp;

		pTemp = NULL;
		previous = NULL;
		current = NULL;

		return true;
	
	}

	template<class ItemType>
	bool List342<ItemType>::Remove(ItemType target, ItemType& result)
	{
		if (head == NULL)
		{
			return false;
		}

		Node* pTemp;

		if (*head->data == target)
		{
			pTemp = head;
			result = target;
			head = head->next;
			delete pTemp;
			return true;
		}

		Node* pCurrent = head;

		while( (pCurrent->next != NULL) && (*pCurrent->next->data == target))
		{

			pCurrent = pCurrent->next;
		}

		if (pCurrent == NULL)
		{
			return false;
		}
		else
		{
			pTemp = pCurrent->next;
			pCurrent->next = pCurrent->next->next;
			result = target;
			delete pTemp;
			return true;
		}
		
	}

	template<class ItemType>
	bool List342<ItemType>::Peek(ItemType target, ItemType& result)
	{
		if (head == NULL)
		{
			return false;
		}

		if (*head->data == target)
		{
			result = target;
			return true;
		}

		Node *current = head;

		while (current->next != NULL && *current->data == target)
		{
			current = current->next;
		}

		if (*current->data == target)
		{
			result = target;
			return true;
		}

		return false;
	}

	template<class ItemType>
	bool List342<ItemType>::isEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


//Operator overloads
	template<class ItemType>
	List342<ItemType> List342<ItemType>::operator+(const List342& rhs) const
	{
		List342<ItemType> temp;
		Node* pCurrent;

		while (pCurrent != NULL)
		{
			temp.Insert(pCurrent->data);
			pCurrent = pCurrent->next;
		}

		pCurrent = rhs.head;

		while (pCurrent != NULL)
		{
			temp.Insert(pCurrent->data);
			pCurrent = pCurrent->next;
		}

		return temp;
	}

	template<class ItemType>
	List342<ItemType> &List342<ItemType>::operator+=(const List342& rhs)
	{

		if (rhs.head == NULL)
		{
			return *this;
		}
		else
		{
			Node* pCurrent = rhs.head;
			while (pCurrent != NULL)
			{
				this->Insert(pCurrent->data); 
				pCurrent = pCurrent->next;
			}
		}

		return *this;
	}


	template<class ItemType>
	bool List342<ItemType>::operator==(const List342& rhs)const
	{
		Node* leftHandSide = this->head;
		Node* rightHandSide = rhs.head;

		while (leftHandSide != NULL)
		{
			if (leftHandSide != rightHandSide)
			{
				return false;
			}

			leftHandSide = leftHandSide->next;
			rightHandSide = rightHandSide->next;
		}

		return false;
	}

	template<class ItemType>
	bool List342<ItemType>::operator!=(const List342& rhs)const
	{
		Node* leftHandSide = this->head;
		Node* rightHandSide = rhs.head;

		while (leftHandSide != NULL)
		{
			if (leftHandSide->data != rightHandSide->data)
			{
				return false;
			}

			leftHandSide = leftHandSide->next;
			rightHandSide = rightHandSide->next;
		}

		return false;
	}

	template<class ItemType>
    const List342<ItemType>& List342<ItemType>::operator=(const List342& rhs)
	{


		if (this == &rhs)
		{
			return *this;
		}

		DeleteList();

		head = new Node();
		Node* pCurrentRhs = rhs.head;
		Node *pCurrent = head;

		pCurrent->data = new ItemType(*pCurrentRhs->data);
		pCurrentRhs = pCurrentRhs->next;

		while (pCurrentRhs != NULL)
		{
			pCurrent->next = new Node();
			pCurrent = pCurrent->next;
			pCurrent->data = new ItemType(*pCurrentRhs->data);
			pCurrentRhs = pCurrentRhs->next;
		}

		return *this;

	}

	template<class ItemType>
	void List342<ItemType>::DeleteList()
	{
		if (head == NULL)
		{
			return;
		}
		else
		{


			while (head != NULL)
			{
				Node* pTemp = head;
				head = head->next;
				delete pTemp->data;
				delete pTemp;
			}

			head = NULL;
			return;
		}
	}

	template<class ItemType>
	bool List342<ItemType>::Merge(List342& list1)
	{
		if ((this == &list1) || (list1.head == NULL))
		{
			return false;
		}

		if ((head == NULL) && !(list1.head == NULL))
		{
			head = list1.head;
			list1.head = NULL;
			return true;
		}

		Node* currentLhs = head;
		Node* curRight = list1.head;
		head = NULL;
		list1.head = NULL;

		Node temp;
		Node *cur = &temp;

		while (currentLhs != NULL && curRight != NULL)
		{
			if ((*currentLhs->data) == (*curRight->data))
			{
				cur->next = currentLhs;
				currentLhs = currentLhs->next;

				Node *dupeToDelete = curRight;
				curRight = curRight->next;
				delete dupeToDelete->data;
				delete dupeToDelete;
			}
			else if ((*currentLhs->data) < (*curRight->data))
			{
				cur->next = currentLhs;
				currentLhs = currentLhs->next;
			}
			else
			{
				cur->next = curRight;
				curRight = curRight->next;
			}

			cur = cur->next;
		}

		if (currentLhs != NULL)
		{
			cur->next = currentLhs;
		}

		if (curRight != NULL)
		{
			cur->next = curRight;
		}

		head = temp.next;

		return true;
	}

#endif 
