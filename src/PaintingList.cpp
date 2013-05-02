/*******************************************

	Author: Matthew Pfister
	Project: C++ Painting Manager
	Course: CS474

********************************************/

#include "../header/PaintingList.h"

/**************************************************************************
	parameters: -
	return value: -

	Default Constructor, creates a new instance of PaintingList class.
**************************************************************************/
PaintingList::PaintingList()
{
	head = tail = NULL;
}

/**************************************************************************
	parameters: string int int
	return value: -

	Constructor, creates a new instance of PaintingList class, setting
	the head to a new painting instance with the passed in values as
	member variables.
**************************************************************************/
PaintingList::PaintingList(string pTitle, int pHeight, int pWidth)
{
	head = new Painting(pTitle, pHeight, pWidth);
	tail = head;
}

/**************************************************************************
	parameters: -
	return value: -

	Default destructor. Deletes the class instance and calls deleteAllPaintings
	to remove each Painting from the list
**************************************************************************/
PaintingList::~PaintingList()
{
	if(NULL != head)
        deleteAllPaintings(head);
}

/**************************************************************************
	parameters: Painting *
	return value: -

	Recursivly delete all Paintings.
**************************************************************************/
void PaintingList::deleteAllPaintings(Painting * curr)
{
	if(NULL == curr->getNext())
	{
		delete(curr);
		return;
	}
	
	deleteAllPaintings(curr->getNext());
	delete(curr);
}

/**************************************************************************
	parameters: int
	return value: -

	First it finds the painting with the passed in id, and then it
	creates a new Painting, by preforming a deep copy. If it does not
	find a painting with the passed in id, it will ouput an error.
**************************************************************************/
void PaintingList::copyPainting(int temp_id)
{
	Painting * pNode = findPainting(temp_id);

	if(NULL != pNode)
		appendToTail(new Painting(*(pNode)));
	else
		cout << endl << "ERROR: Could not find painting with id: " << temp_id << endl;
}

/**************************************************************************
	parameters: Painting
	return value: -

	If painting is not already in list, then it is added to the tail.
**************************************************************************/
void PaintingList::appendToTail(Painting * pNode)
{
	int t = pNode->getID();
	if(NULL == findPainting(t))
	{
		if(NULL == tail)
		{
			head = tail = pNode;
		}
		else
		{
			tail->setNext(pNode);
			tail = pNode;
		}
	}
	else
		cout << endl << "ERROR: A painting already exists by the title: " <<  t << endl;
}

/**************************************************************************
	parameters: -
	return value: -

	Starting from the head, while the current node does not equal null,
	output the nodes contents.
**************************************************************************/
void PaintingList::printAll()
{
	Painting * curr = head;
	while(NULL != curr)
	{
		curr->print();
		curr = curr->getNext();
	}

}

/**************************************************************************
	parameters: string
	return value: Painting *

	Starting from the head, while the current node does not equal NULL,
	compare the passed in title to the current node's title. If it matches
	return current node. Otherwise continue. If current node is equal to NULL 
	return NULL (since no matching title was found).
**************************************************************************/
Painting * PaintingList::findPainting(int temp_id)
{
	Painting * curr = head;
	while(NULL != curr)
	{
		if(curr->idMatch(temp_id))
			return curr;

		curr = curr->getNext();
	}
	return NULL;

}

/**************************************************************************
	parameters: int
	return value: Painting *

	Starting from the head and setting parent pointer to NULL, while the 
	current node does not equal NULL, compare the passed in id to the
	current node's id. If it matches return parent node. Otherwise continue. 
	If current node is equal to NULL return NULL (since no matching id 
	was found).
**************************************************************************/
Painting * PaintingList::findPaintingParent(int temp_id)
{
	Painting * parent = NULL;
	Painting * curr = head;
	while(NULL != curr)
	{
		if(curr->idMatch(temp_id))
			return parent;

		parent = curr;
		curr = curr->getNext();
	}
	return NULL;

}

/**************************************************************************
	parameters: int
	return value: bool
	
	Since a paintinglist will never be empty, since it is only created
	when the user inputs a painting and an artist, we can always check
	the first item in the paintinglist.

	If the head of the list is the node to remove, then store the value at
	head in a temporary pointer and move the head to the next node in the 
	list. If the next node in the list is NULL remove the temporary pointer
	and return true (denoting that the artist should be deleted too, since
	he has no paintings). Otherwise, delete the temporary variable, and its'
	next is the new head of the list.

	If the node to delete is not the first in the list, search for it. If
	it does not equal to NULL grab its' parent and child. If the child is
	NULL then set the tail of the list to the parent (since the node to 
	delete is the last in the list), and then set the parent's next to NULL.
	Otherwise set the parents next to the child, and delete the node.
	
**************************************************************************/
bool PaintingList::removePainting(int temp_id)
{
	if(head->idMatch(temp_id))
	{
        	Painting * temp = head;
		head = head->getNext();
		
		if(NULL == head)
		{
			delete(temp);
			temp->setNext(NULL);
			head = NULL;
			tail = NULL;
			return true;
		}
		else
		{
			delete(temp);
            		temp->setNext(NULL);
			return false;
		}
	}
	
	Painting * pNodeParent = findPaintingParent(temp_id);

	if(NULL != pNodeParent)
	{
		Painting * pNode = pNodeParent->getNext();
		Painting * pNodeChild = pNode->getNext();

		delete(pNode);
        	pNode->setNext(NULL);

		if(NULL == pNodeChild)
		{
		    tail = pNodeParent;
		    pNodeParent->setNext(NULL);
		}
		else
		    pNodeParent->setNext(pNodeChild);
	}
	else
		cout << endl << "ERROR: Could not find painting with id: " << temp_id << endl;

	return false;
}

/**************************************************************************
	Getter and Setter Functions for PaintingList Class
**************************************************************************/
Painting * PaintingList::getHead(){return head;}

