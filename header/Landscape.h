#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include <stdio.h>
#include <string>
#include "Painting.h"

/* ---- All Comments are in the source (.cpp) file ---- */

class Landscape : public Painting
{

	public:
		Landscape(Landscape& p);
		Landscape(string aTitle, string aLocation, int width, int height);
		~Landscape();
		void print();

		string getLocation();
		Painting * copy();
	private:
		string location;


};

#endif
