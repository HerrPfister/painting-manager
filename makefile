paintingmanager: src/main.cpp src/Painting.cpp src/PaintingList.cpp src/Artist.cpp src/ArtistList.cpp src/StillLife.cpp src/Landscape.cpp src/Portrait.cpp header/StillLife.h header/Landscape.h header/Portrait.h header/PaintingList.h header/Artist.h header/ArtistList.h header/Painting.h
		 g++ src/main.cpp src/Painting.cpp src/PaintingList.cpp src/StillLife.cpp src/Landscape.cpp src/Portrait.cpp src/Artist.cpp src/ArtistList.cpp -o paintingmanager

clean:	
	rm paintingmanager
