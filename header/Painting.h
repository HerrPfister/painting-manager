/*******************************************

	Author: Matthew Pfister
	Project: C++ Painting Manager
	Course: CS474

********************************************/

#ifndef PAINTING_H
#define PAINTING_H

#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

/* ---- All Comments are in the source (.cpp) file ---- */

class Painting
{
	public:
		Painting(Painting& p);
		Painting(string pTitle, int pHeight, int pWidth);
		virtual ~Painting();

		bool idMatch(int temp_id);
		void setNext(Painting * pNode);
		virtual void print();
		virtual Painting * copy();

		Painting * getNext();
		string getTitle();
		int getWidth();
		int getHeight();
		int getID();

	protected:
		Painting * next;
		string title;
		int width;
		int height;
		int id;
		static int creationCounter;
};

#endif
