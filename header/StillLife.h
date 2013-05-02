#ifndef STILLLIFE_H
#define STILLLIFE_H

#include <stdio.h>
#include "Painting.h"

/* ---- All Comments are in the source (.cpp) file ---- */

class StillLife : public Painting
{

	public:
		StillLife(StillLife& p);
		StillLife(string aTitle, string aMedium, int width, int height);
		~StillLife();
		void print();

		string getMedium();
		Painting * copy();

	private:
		string medium;

};

#endif
