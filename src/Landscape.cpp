/*******************************************

	Author: Matthew Pfister
	Project: C++ Painting Manager
	Course: CS474

********************************************/

#include "../header/Landscape.h"

/**************************************************************************
	parameters: string, string, int, int
	return value: -

	Default Constructor, creates a new instance of Landscape class.
**************************************************************************/
Landscape::Landscape(string aTitle, string loc, int width, int height)
: Painting(aTitle, width, height), location(loc)
{}

/**************************************************************************
	parameters: Landscape& p
	return value: -

	copy Constructor, creates a new instance of landscape class that
	is a copy of p.
**************************************************************************/
Landscape::Landscape(Landscape& p)
: Painting("", p.getWidth(), p.getHeight())
{
	ostringstream convert;
	Painting::creationCounter = Painting::creationCounter + 1;
	id = Painting::creationCounter;
	convert << Painting::creationCounter;
	title = p.getTitle() + "_COPY" + convert.str();
    	next = NULL;

	location = p.getLocation();
}


Landscape::~Landscape()
{}

/**************************************************************************
	parameters: -
	return value: Painting *

	calls copy constructor.
**************************************************************************/
Painting * Landscape::copy()
{
	return new Landscape(*(this));
}

/**************************************************************************
	parameters: -
	return value: -

	Prints member variables.
**************************************************************************/
void Landscape::print()
{
	cout << "  ID: " << id << " | Painting: " << title << " (" << width << "\", " << height << "\")" << endl;
	cout << "   Painting location: " << location << endl;
}

/**************************************************************************
	Getter and setter functions of Landscape class
**************************************************************************/
string Landscape::getLocation(){return location;}
