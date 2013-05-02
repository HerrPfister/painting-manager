#ifndef PORTRAIT_H
#define PORTRAIT_H

#include <stdio.h>
#include "Painting.h"

/* ---- All Comments are in the source (.cpp) file ---- */

class Portrait : public Painting
{
	public: 
		Portrait(Portrait& p);
		Portrait(string aTitle, string nms[], int numppl, int width, int height);
		~Portrait();
		void print();

		int getNumberOfPeople();
		string * getNames();
		Painting * copy();
	private:
		int numberOfPeople;
		string * names;

};

#endif
