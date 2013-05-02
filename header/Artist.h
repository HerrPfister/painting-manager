/*******************************************

	Author: Matthew Pfister
	Project: C++ Painting Manager
	Course: CS474

********************************************/

#ifndef ANODE_H
#define ANODE_H

#include <stdio.h>
#include <string>
#include "PaintingList.h"

/* ---- All Comments are in the source (.cpp) file ---- */

class Artist
{
	public:
		Artist(Artist& a);
		Artist(string aFirstName, string aLastName);
		Artist(string aFirstName, string aLastName, string pTitle, int pHeight, int pWidth);
		~Artist();

		Artist * getNext();
		PaintingList * getPaintingList();
		string getFirstName();
		string getLastName();
		int getNumberOfPaintings();
		void setNext(Artist * nextList);

		bool artistMatch(string aFirstName, string aLastName);
		void addToPaintingList(Painting * pNode);
		bool removePainting(int temp_id);
		void print();
		void copyPainting(int temp_id);

	private:
		PaintingList * pList;
		Artist * next;
		string firstName;
		string lastName;
		int numberOfPaintings;
};

#endif
