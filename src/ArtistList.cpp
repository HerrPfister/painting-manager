/*******************************************

	Author: Matthew Pfister
	Project: C++ Painting Manager
	Course: CS474

********************************************/

#include "../header/ArtistList.h"

/**************************************************************************
	parameters: -
	return value: -

	Default Constructor, creates a new instance of ArtistList class.
**************************************************************************/
ArtistList::ArtistList()
{
	head = NULL;
	tail = head;
}

/**************************************************************************
	parameters: -
	return value: -

	Destructor, calls removeAllArtists (which will remove all dynamically
	allocated parts of this instance).
**************************************************************************/
ArtistList::~ArtistList()
{
	removeAllArtists(head);
}

/**************************************************************************
	parameters: string, string, int
	return value: -

	First check to see if the artist exists. If it does, call 
	removePainting(int). If it returns true (indicating that it was
	the only one in the list) call deleteArtist(string, string) to delete 
	the artist.
	
**************************************************************************/
void ArtistList::remove(string aFirstName, string aLastName, int temp_id)
{
	Artist * artist = findArtist(aFirstName, aLastName);

	if(NULL != artist)
	{
		if(artist->removePainting(temp_id))
		{
			deleteArtist(aFirstName, aLastName);
		}
	}
	else
		cout << endl << "ERROR: Could not find Artist: " << aFirstName << " " << aLastName << endl;
}

/**************************************************************************
	parameters: string, string
	return value: -

	First check to see if the artist exists. If it does not, output an
	error. Otherwise, store find its' parent and itself. If the parent does
	not equal NULL and the artist does not equal NULL then get the
	artist's child. Then check to see if the the artist is the last node 
	in the list. If it is set the tail pointer to the artist's parent,
	then set the parent's next to the artist's child, and then delete 
	the artist. If it is not the last in the list, set the parent's next
	to the current node's next and then delete the current node.

	Note: if the parent is not NULL and the artist is NULL then that 
	      means it is the first in the list.
	
**************************************************************************/
void ArtistList::deleteArtist(string aFirstName, string aLastName)
{

	if(head->artistMatch(aFirstName, aLastName))
	{
		Artist * temp = head;
		head = head->getNext();
		
		if(NULL == head)
		{
			delete(temp);
			head = NULL;
			tail = NULL;
			temp->setNext(NULL);
		}
		else
		{
			delete(temp);
		    	temp->setNext(NULL);
		}
	}
	else
	{
		Artist * aNodeParent = findArtistParent(aFirstName, aLastName);

		if(NULL != aNodeParent)
		{
			Artist * aNode = aNodeParent->getNext();
			Artist * aNodeChild = aNode->getNext();

			delete(aNode);
            		aNode->setNext(NULL);

			if(NULL == aNodeChild)
			{
				tail = aNodeParent;
				aNodeParent->setNext(NULL);
			}
			else
				aNodeParent->setNext(aNodeChild);
		}
		else
			cout << endl << "ERROR: Could not find artist with name: " << aFirstName << ", " << aLastName << endl;
	}
}

/**************************************************************************
	parameters: Artist
	return value: -

	recursively traverse ArtistList and delete all nodes.
	
**************************************************************************/
void ArtistList::removeAllArtists(Artist * curr)
{
	if(isEmpty())
		return;

	if(NULL == curr->getNext())
	{
		delete(curr);
		return;
	}
	
	removeAllArtists(curr->getNext());
	delete(curr);
}

/**************************************************************************
	parameters: string, string, string, string int, int
	return value: -

	Appends new still-life painting object to the appropriate artist's painting list. 
	However, it first determines if the ArtistList is empty, if so create 
	a new artist and append the new still-life painting. If not, check to see if the 
	artist is already included in the ArtistList. If it is, select that
	artist, otherwise create a new one, and then append to that artist's
	list.
	
**************************************************************************/
void ArtistList::addStill(string aFirstName, string aLastName, string pTitle, string medium, int pHeight, int pWidth)
{
	Artist * artist;
	if(isEmpty())
	{
		Artist * node = new Artist(aFirstName, aLastName);
		tail = head = node;
		node->addToPaintingList(new StillLife(pTitle, medium, pHeight, pWidth));
	}
	else if(NULL == (artist = findArtist(aFirstName, aLastName)))
	{	
		Artist * node = new Artist(aFirstName, aLastName);
		tail->setNext(node);
		tail = node;
		node->addToPaintingList(new StillLife(pTitle, medium, pHeight, pWidth));
	}
	else
	{
		Painting *pNode = new StillLife(pTitle, medium, pHeight, pWidth);
		artist->addToPaintingList(pNode);
	}
}

/**************************************************************************
	parameters: string, string, string, string int, int
	return value: -

	Appends new landscape painting object to the appropriate artist's painting list. 
	However, it first determines if the ArtistList is empty, if so create 
	a new artist and append the new landscape painting. If not, check to see if the 
	artist is already included in the ArtistList. If it is, select that
	artist, otherwise create a new one, and then append to that artist's
	list.
	
**************************************************************************/
void ArtistList::addLandscape(string aFirstName, string aLastName, string pTitle, string location, int pHeight, int pWidth)
{
	Artist * artist;
	if(isEmpty())
	{
		Artist * node = new Artist(aFirstName, aLastName);
		tail = head = node;
		node->addToPaintingList(new Landscape(pTitle, location, pHeight, pWidth));
	}
	else if(NULL == (artist = findArtist(aFirstName, aLastName)))
	{	
		Artist * node = new Artist(aFirstName, aLastName);
		tail->setNext(node);
		tail = node;
		node->addToPaintingList(new Landscape(pTitle, location, pHeight, pWidth));
	}
	else
	{
		Painting *pNode = new Landscape(pTitle, location, pHeight, pWidth);
		artist->addToPaintingList(pNode);
	}
}

/**************************************************************************
	parameters: string, string, string, string *, int int, int
	return value: -

	Appends new portrait painting object to the appropriate artist's painting list. 
	However, it first determines if the ArtistList is empty, if so create 
	a new artist and append the new portrait painting. If not, check to see if the 
	artist is already included in the ArtistList. If it is, select that
	artist, otherwise create a new one, and then append to that artist's
	list.
	
**************************************************************************/
void ArtistList::addPortrait(string aFirstName, string aLastName, string pTitle, string nms[], int numppl, int pHeight, int pWidth)
{
	Artist * artist;
	if(isEmpty())
	{
		Artist * node = new Artist(aFirstName, aLastName);
		tail = head = node;
		node->addToPaintingList(new Portrait(pTitle, nms, numppl, pHeight, pWidth));
	}
	else if(NULL == (artist = findArtist(aFirstName, aLastName)))
	{	
		Artist * node = new Artist(aFirstName, aLastName);
		tail->setNext(node);
		tail = node;
		node->addToPaintingList(new Portrait(pTitle, nms, numppl, pHeight, pWidth));
	}
	else
	{
		Painting *pNode = new Portrait(pTitle, nms, numppl, pHeight, pWidth);
		artist->addToPaintingList(pNode);
	}
}

void ArtistList::add(string aFirstName, string aLastName)
{
	Artist * artist;
	if(isEmpty())
	{
		Artist * node = new Artist(aFirstName, aLastName);
		tail = head = node;
	}
	else if(NULL == (artist = findArtist(aFirstName, aLastName)))
	{	
		Artist * node = new Artist(aFirstName, aLastName);
		tail->setNext(node);
		tail = node;
	}
}

/**************************************************************************
	parameters: string, string, int
	return value: -

	First it checks to make sure the artist exists. If it does it calls
	copyPainting(int) in the Artist class. Otherwise, it ouputs an
	error.
	
**************************************************************************/
void ArtistList::copyPainting(string aFirstName, string aLastName, int temp_id)
{
	Artist * node = findArtist(aFirstName, aLastName);

	if(NULL != node)
		node->copyPainting(temp_id);
	else
		cout << endl << "ERROR: Could not find Artist: " << aFirstName << " " << aLastName << endl;
}

void ArtistList::copyArtist(string aFirstName, string aLastName)
{
	Artist * node = findArtist(aFirstName, aLastName);

	if(NULL != node)
	{
		tail->setNext(new Artist(*(node)));
		tail = tail->getNext();
	}
	else
		cout << endl << "ERROR: Could not find Artist: " << aFirstName << " " << aLastName << endl;
}

/**************************************************************************
	parameters: string, string
	return value: Artist *

	First it sets both the parent and current pointers to the head. 
	While curr does not equal NULL check to see if the current artist's 
	name matches the name passed in. If it does, return that artist's parent.
	Otherwise, continue by setting the parent to curr and curr to curr->next(). 
	If the loop terminates, no match was found and it returns NULL.
	
**************************************************************************/
Artist * ArtistList::findArtistParent(string aFirstName, string aLastName)
{
	Artist * curr = head;
	Artist * parent = curr;
	while(NULL != curr)
	{
		if(curr->artistMatch(aFirstName, aLastName))
			return parent;

		parent = curr;
		curr = curr->getNext();
	}
	return NULL;
}

/**************************************************************************
	parameters: string, string
	return value: Artist *

	First it grabs the head pointer, and sets curr to it. While curr does
	not equal NULL check to see if the current artist's name matches the 
	name passed in. If it does, return that artist. Otherwise, continue 
	by setting curr to curr->next(). If the loop terminates, no match was 
	found and it returns NULL.
	
**************************************************************************/
Artist * ArtistList::findArtist(string aFirstName, string aLastName)
{
	Artist * curr = head;
	while(NULL != curr)
	{
		if(curr->artistMatch(aFirstName, aLastName))
			return curr;
		curr = curr->getNext();
	}
	return NULL;
}

/**************************************************************************
	parameters: -
	return value: -

	First grab the head of the list and store it in curr. Then print out
	the total number of DIFFERENT artists in the list. Then loop while
	curr does not equal NULL, and in each iteration print out that painting
	and Artist's member variables.	
	
**************************************************************************/
void ArtistList::printAll()
{
	Artist * curr = (head);
	cout << endl << "Total Number of Artists: " << numberOfArtists() << endl;
	while(NULL != curr)
	{
		curr->print();
		curr = curr->getNext();
	}

}

/**************************************************************************
	parameters: -
	return value: int

	Iterate through the list of artists, incrementing a counter in each
	iteration. Then return the counter.
	
**************************************************************************/
int ArtistList::numberOfArtists()
{
	int num = 0;
	Artist * curr = (head);
	while(NULL != curr)
	{
		num++;
		curr = curr->getNext();
	}

	return num;
}

/**************************************************************************
	parameters: -
	return value: bool

	If head is equal to NULL return true (since the list is empty).
	Otherwise, return false.
	
**************************************************************************/
bool ArtistList::isEmpty()
{
	if(NULL == head)
		return true;
	
	return false;
}

