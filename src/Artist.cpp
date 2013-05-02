/*******************************************

	Author: Matthew Pfister
	Project: C++ Painting Manager
	Course: CS474

********************************************/

#include "../header/Artist.h" 

/**************************************************************************
	parameters: string string
	return value: -

	Constructor, creates a new instance of Artist class, with an empty painting list.
**************************************************************************/
Artist::Artist(string aFirstName, string aLastName)
: firstName(aFirstName), lastName(aLastName), numberOfPaintings(0)
{
	pList = new PaintingList();
	next = NULL;
}

/**************************************************************************
	parameters: string string string int int
	return value: -

	Constructor, creates a new instance of Artist class, and initializes
	its painting list with the passed in values.
**************************************************************************/
Artist::Artist(string aFirstName, string aLastName, string pTitle, int pHeight, int pWidth)
: firstName(aFirstName), lastName(aLastName), numberOfPaintings(1)
{
	pList = new PaintingList(pTitle, pHeight, pWidth);
	next = NULL;
}

/**************************************************************************
	parameters: -
	return value: -

	Destructor, deletes all dynamically allocated parts of an instance 
	of the class. As well as, the instance.
**************************************************************************/
Artist::Artist(Artist& a)
{
	cout << "Please enter a new first name: ";
	getline(cin, firstName);

	lastName = a.getLastName();
	numberOfPaintings = a.getNumberOfPaintings();

	pList = new PaintingList();
	next = NULL;
	
	int i;
	PaintingList * pl = a.getPaintingList();
	Painting * p = pl->getHead();
	for(i = 0; i < numberOfPaintings; i++, p = p->getNext())
	{	
		pList->appendToTail(p->copy());
	}
}

Artist::~Artist()
{
	delete(pList);
}

/**************************************************************************
	parameters: Painting
	return value: -

	Appends painting to the tail of artist's painting list.
**************************************************************************/
void Artist::addToPaintingList(Painting * pNode)
{
	pList->appendToTail(pNode);
	numberOfPaintings++;
}

/**************************************************************************
	parameters: int
	return value: bool

	Calls removePainting(int) in PaintingList class. Returns the
	return value of removePainting(int) function.
**************************************************************************/
bool Artist::removePainting(int temp_id)
{
	numberOfPaintings--;
	return pList->removePainting(temp_id);
}

/**************************************************************************
	parameters: int
	return value: -

	Calls copyPainting(int) in PaintingList Class.
**************************************************************************/
void Artist::copyPainting(int temp_id)
{
	pList->copyPainting(temp_id);
	numberOfPaintings++;
}

/**************************************************************************
	parameters: -
	return value: -

	Prints contents of Artist, and then calls print() in PaintingList 
	Class.
**************************************************************************/
void Artist::print()
{
	cout << endl << "Artist: " << firstName << " " << lastName << endl;
	pList->printAll();
}

/**************************************************************************
	parameters: string, string
	return value: bool

	Compares the firstname and lastname passed in, to this artist's
	firstname and lastname. If they match, return true. Otherwise,
	return false.
**************************************************************************/
bool Artist::artistMatch(string aFirstName, string aLastName)
{
	if(firstName.compare(aFirstName) == 0 && lastName.compare(aLastName) == 0)
		return true;

	return false;
}

/**************************************************************************
	Getter and Setter Functions for Artist Class
**************************************************************************/
PaintingList * Artist::getPaintingList(){return pList;}
Artist * Artist::getNext(){return next;}
string Artist::getFirstName() {return firstName;}
string Artist::getLastName() {return lastName;}
int Artist::getNumberOfPaintings(){return numberOfPaintings;}
void Artist::setNext(Artist * nextList){next = nextList;}
