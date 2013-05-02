/*******************************************

	Author: Matthew Pfister
	Project: C++ Painting Manager
	Course: CS474

********************************************/

#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include "../header/ArtistList.h"

using namespace std;

int main(void)
{
	int width, height, id, numppl;
	string fName, lName, title, cmd, tHeight, tWidth, tid, medium, loc, tnumppl, type;

	ArtistList * artists = new ArtistList();

	cout << endl << "************************" << endl << "Welcome to Painting Manager 1.0" << endl << "Created by: Matthew Pfister" << endl << "************************" << endl;

	while(true)
	{
		cout << endl << "--------------------------\n>Please input a command: ";
		getline(cin, cmd);

		if(cmd.length() < 2 && cmd.compare("\0") != 0)
		{
			switch(cmd.at(0))
			{
				case 'a':
				{ 
					cout << "Artist's first name: ";
					getline(cin, fName);

					cout << "Artist's last name: ";
					getline(cin, lName);

					artists->add(fName, lName);
					break;
				}
				case 'p':
				{
					cout << "Artist's first name: ";
					getline(cin, fName);

					cout << "Artist's last name: ";
					getline(cin, lName);

					cout << "Painting title: ";
					getline(cin, title);

					cout << "Painting width: ";
					getline(cin, tWidth);
					istringstream(tWidth) >> width;

					while(width <= 0)
					{	
						cout << "ERROR: invalid width, please try again: ";
						getline(cin, tWidth);
						istringstream(tWidth) >> width;
					}

					cout << "Painting height: ";
					getline(cin, tHeight);
					istringstream(tHeight) >> height;

					while(height <= 0)
					{	
						cout << "ERROR: invalid height, please try again: ";
						getline(cin, tHeight);
						istringstream(tHeight) >> height;
					}

					cout << "Painting Type: ";
					getline(cin, type);

					while(type.at(0) != 's' && type.at(0) != 'p' && type.at(0) != 'l')
					{
						cout << "ERROR: invalid type, valid types are: l (landscape), p (portrait), s (stilllife)" << endl << "Please try again: ";
						getline(cin, type);						
					}

					switch(type.at(0))
					{
						case 's':
							cout << "Painting medium: ";
							getline(cin, medium);
							artists->addStill(fName, lName, title, medium, width, height);
							break;
						case 'l':
							cout << "Painting location: ";
							getline(cin, loc);							
							artists->addLandscape(fName, lName, title, loc, width, height);
							break;
						case 'p':
							cout << "Number of people in painting: ";
							getline(cin, tnumppl);
							istringstream(tnumppl) >> numppl;

							while(numppl <= 0)
							{	
								cout << "ERROR: invalid number of people, please try again: ";
								getline(cin, tnumppl);
								istringstream(tnumppl) >> numppl;
							}	

							int i;
							string * nms = new string[numppl];
							for(i = 0; i < numppl; i++)
							{
								cout << "Please enter the name of someone in the painting: ";
								getline(cin, nms[i]);
							}
					
							artists->addPortrait(fName, lName, title, nms, numppl, width, height);
							break;
					}
				}
				break;

				case 'r':
				{
					if(!artists->isEmpty())
					{
						cout << "Artist's first name: ";
						getline(cin, fName);

						cout << "Artist's last name: ";
						getline(cin, lName);

						cout << "Painting id: ";
						getline(cin, tid);
						istringstream(tid) >> id;

						while(id < 0)
						{	
							cout << "ERROR: invalid id, please try again: ";
							getline(cin, tid);
							istringstream(tid) >> id;
						}

						artists->remove(fName, lName, id);
						break;
					}
					else
						cout << endl << "ERROR: List is empty" << endl;
				}

				case 'd':
				{
					if(!artists->isEmpty())
					{
						cout << "Artist's first name to delete: ";
						getline(cin, fName);

						cout << "Artist's last name to delete: ";
						getline(cin, lName);
				
						artists->deleteArtist(fName, lName);
					}
					else
						cout << endl << "ERROR: List is empty" << endl;
					break;
				}
			
				case 'l':
					artists->printAll();
					break;

				case 'k':
					if(!artists->isEmpty())
					{
						cout << "Artist's first name: ";
						getline(cin, fName);

						cout << "Artist's last name: ";
						getline(cin, lName);

						cout << "id of painting to copy: ";
						getline(cin, tid);
						istringstream(tid) >> id;

						while(id < 0)
						{	
							cout << "ERROR: invalid id, please try again: ";
							getline(cin, tid);
							istringstream(tid) >> id;
						}
		
						artists->copyPainting(fName, lName, id);
						break;
					}
					else
						cout << endl << "ERROR: List is empty" << endl;
					break;
				case 'c':
					if(!artists->isEmpty())
					{
						cout << "Artist's first name: ";
						getline(cin, fName);

						cout << "Artist's last name: ";
						getline(cin, lName);

						artists->copyArtist(fName, lName);
						break;
					}
					else
						cout << endl << "ERROR: List is empty" << endl;
					break;

				case 'q':
				{
					cout << "Are you sure you want to quit? y/n: ";
					getline(cin, cmd);
					if(cmd.compare("\0") != 0 && cmd.at(0) == 'y')
					{
						delete(artists);
						return 0;
					}
					break;
				}

				default:
					cout << endl << "ERROR: INVALID COMMAND" << endl << "Valid commands:" << endl << "a - add artist" << endl << "p - add painting" << endl << "r - remove painting" << endl << "d - delete artist" << endl << "l - list all paintings" << endl << "c - copy artist" << endl << "k - copy painting" << endl <<  "q - quit" << endl; 								
					break;
			}
		}
		else
			cout << endl << "ERROR: INVALID COMMAND" << endl << "Valid commands:" << endl << "a - add artist" << endl << "p - add painting" << endl << "r - remove painting" << endl << "d - delete artist" << endl << "l - list all paintings" << endl << "c - copy artist" << endl << "k - copy painting" << endl <<  "q - quit" << endl; 										
	}
	return 1;
}

