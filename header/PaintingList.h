/*******************************************

	Author: Matthew Pfister
	Project: C++ Painting Manager
	Course: CS474

********************************************/

#ifndef PLIST_H
#define PLIST_H

#include <stdio.h>
#include <string>
#include <iostream>
#include "StillLife.h"
#include "Portrait.h"
#include "Landscape.h"

using namespace std;

/* ---- All Comments are in the source (.cpp) file ---- */

class PaintingList
{
	public:
		PaintingList();
		PaintingList(string pTitle, int pHeight, int pWidth);
		~PaintingList();

		void printAll();
		void copyPainting(int temp_id);
		void deleteAllPaintings(Painting * curr);
		void appendToTail(Painting * pNode);

		bool removePainting(int temp_id);
		bool isEmpty();

		Painting * findPaintingParent(int temp_id);
		Painting * findPainting(int temp_id);

		Painting * getHead();

	private:
		Painting * head;
		Painting * tail;




};
#endif
