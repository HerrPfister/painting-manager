/*******************************************

	Author: Matthew Pfister
	Project: C++ Painting Manager
	Course: CS474

********************************************/

#include "../header/Portrait.h"

/**************************************************************************
	parameters: string, string *, int, int, int
	return value: -

	Default Constructor, creates a new instance of Portrait class.
**************************************************************************/
Portrait::Portrait(string aTitle, string nms[], int numppl, int width, int height)
: Painting(aTitle, width, height), numberOfPeople(numppl)
{
	names = new string[numppl];

	int i;
	for(i = 0; i < numppl; i++)
	{
		names[i] = nms[i];
	}

}

/**************************************************************************
	parameters: Portrait& p
	return value: -

	copy Constructor, creates a new instance of portrait class that
	is a copy of p.
**************************************************************************/
Portrait::Portrait(Portrait& p)
: Painting("", p.getWidth(), p.getHeight())
{
	ostringstream convert;
	Painting::creationCounter = Painting::creationCounter + 1;
	height = p.getHeight();
	width = p.getWidth();
	id = Painting::creationCounter;
	convert << Painting::creationCounter;
	title = p.getTitle() + "_COPY" + convert.str();
    	next = NULL;

	numberOfPeople = p.getNumberOfPeople();

	names = new string[numberOfPeople];

	string * nms = p.getNames();
	int i;
	for(i = 0; i < numberOfPeople; i++)
	{
		names[i] = nms[i];
	}
}


Portrait::~Portrait()
{
	delete[] names;
}

/**************************************************************************
	parameters: -
	return value: Painting *

	calls copy constructor.
**************************************************************************/
Painting* Portrait::copy()
{
	return new Portrait(*(this));
}

/**************************************************************************
	parameters: -
	return value: -

	Prints member variables.
**************************************************************************/
void Portrait::print()
{
	cout << "  ID: " << id << " | Painting: " << title << " (" << width << "\", " << height << "\")" << endl;
	cout << "   Total number of people in painting: " << numberOfPeople << endl;
	cout << "   People in painting: ";	

	int i;
	for(i = 0; i < numberOfPeople - 1; i++)
	{
		cout << names[i] << ", ";
	}
	cout << names[i];
}

/**************************************************************************
	Getter and setter functions of Portrait class
**************************************************************************/
int Portrait::getNumberOfPeople(){return numberOfPeople;}
string * Portrait::getNames(){return names;}
