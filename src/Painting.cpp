/*******************************************

	Author: Matthew Pfister
	Project: C++ Painting Manager
	Course: CS474

********************************************/

#include "../header/Painting.h"

int Painting::creationCounter = 0;
/**************************************************************************
	parameters: string int int
	return value: -

	Constructor for Painting class. Sets all member variables to the
	appropriate values passed in. Increments id counter.
	
**************************************************************************/
Painting::Painting(string pTitle, int pWidth, int pHeight)
{
	title = pTitle;
	height = pHeight;
	width = pWidth;
	id = Painting::creationCounter;
	Painting::creationCounter = Painting::creationCounter + 1;
    	next = NULL;
}

/**************************************************************************
	parameters: Painting *
	return value: -

	Copy constructor. Preforms a deep copy on a Painting. Appends "_COPY"
	to the title to denote that it is a copy.
	
**************************************************************************/
Painting::Painting(Painting& p)
{
	ostringstream convert;
	Painting::creationCounter = Painting::creationCounter + 1;
	height = p.getHeight();
	width = p.getWidth();
	id = Painting::creationCounter;
	convert << Painting::creationCounter;
	title = p.getTitle() + "_COPY" + convert.str();
    	next = NULL;
}

Painting::~Painting()
{}

/**************************************************************************
	parameters: -
	return value: Painting *

	virtual function that calls the copy constructor for the given instance
	of the class (be it derived or the base). Returns the new copy.
	
**************************************************************************/
Painting * Painting::copy()
{
	return new Painting(*(this));
}

void Painting::print()
{
	cout << "  ID: " << id << " | Painting: " << title << " (" << width << "\", " << height << "\")" << endl;
}

/**************************************************************************
	parameters: int
	return value: bool

	checks to see if the passed-in value matches the current paintings
	id. If so, return true. Else, false.
	
**************************************************************************/
bool Painting::idMatch(int temp_id)
{
	if(id == temp_id)
		return true;

	return false;
}

/**************************************************************************
	Getters and Setters of Painting Class
**************************************************************************/
void Painting::setNext(Painting * p){ next = p;}

Painting * Painting::getNext() {return next;}
string Painting::getTitle() {return title;}
int Painting::getWidth() {return width;}
int Painting::getHeight() {return height;}
int Painting::getID() {return id;}

