/*******************************************

	Author: Matthew Pfister
	Project: C++ Painting Manager
	Course: CS474

********************************************/

#include "../header/StillLife.h"

/**************************************************************************
	parameters: string, string, int, int
	return value: -

	Default Constructor, creates a new instance of StillLife class.
**************************************************************************/
StillLife::StillLife(string aTitle, string aMedium, int width, int height)
: Painting(aTitle, width, height), medium(aMedium)
{}

/**************************************************************************
	parameters: StillLife& p
	return value: -

	copy Constructor, creates a new instance of StillLife class that
	is a copy of p.
**************************************************************************/
StillLife::StillLife(StillLife& p)
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

	medium = p.getMedium();
}


StillLife::~StillLife()
{}

/**************************************************************************
	parameters: -
	return value: Painting *

	calls copy constructor.
**************************************************************************/
Painting * StillLife::copy()
{
	return new StillLife(*(this));
}

/**************************************************************************
	parameters: -
	return value: -

	prints member variables
**************************************************************************/
void StillLife::print()
{
	cout << "  ID: " << id << " | Painting: " << title << " (" << width << "\", " << height << "\")" << endl;
	cout << "   Medium used: " << medium << endl;
}

/**************************************************************************
	Getter and setter functions of still-life class
**************************************************************************/
string StillLife::getMedium(){return medium;}
