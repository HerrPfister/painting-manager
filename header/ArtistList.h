/*******************************************

	Author: Matthew Pfister
	Project: C++ Painting Manager
	Course: CS474

********************************************/

#ifndef ALIST_H
#define ALIST_H

#include <stdio.h>
#include <string>
#include <iostream>
#include "Artist.h"

using namespace std;

/* ---- All Comments are in the source (.cpp) file ---- */

class ArtistList
{
	public:
		ArtistList();
		~ArtistList();

		void add(string aFirstName, string aLastName);
		void addStill(string aFirstName, string aLastName, string pTitle, string medium, int pHeight, int pWidth);
		void addLandscape(string aFirstName, string aLastName, string pTitle, string location, int pHeight, int pWidth);
		void addPortrait(string aFirstName, string aLastName, string pTitle, string nms[], int numppl, int pHeight, int pWidth);
		void copyPainting(string aFirstName, string aLastName, int temp_id);
		void copyArtist(string aFirstName, string aLastName);

		void removeAllArtists(Artist * curr);
		void remove(string aFirstName, string aLastName, int temp_id);
		void deleteArtist(string aFirstName, string aLastName);

		void printAll();
		int numberOfArtists();
		bool isEmpty();

		Artist * findArtist(string aFirstName, string aLastName);
		Artist * findArtistParent(string aFirstName, string aLastName);

	private:
		Artist * head;
		Artist * tail;	
};

#endif
