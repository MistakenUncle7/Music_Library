#include "Array.h"

Library::Library()
{
	size = 0;
	library = new Playlist[size];
}

Library::Library(int num) : size(num)
{
	library = new Playlist[size];
}

Library::~Library()
{}

void Library::increaseSize()
{
	Playlist* temp = new Playlist[getSize() + 1];
	for (int i = 0; i < getSize(); i++) {
	    temp[i] = library[i];
	}
	delete[] library;
	library = temp;
	size++;
}

void Library::decreaseSize()
{
	Playlist* temp = new Playlist[getSize() - 1];
	for (int i = 0; i < getSize(); i++) {
	    temp[i] = library[i];
	}
	delete[] library;
	library = temp;
	size--;
}

int Library::searchPlaylist(string playlist)
{
	for (int i = 0; i < getSize(); i++) {
		if (library[i].getPlaylistTitle() == playlist) {
			return i;
		}
	}
	return -1;
}

void Library::insert(Playlist newPlaylist)
{
	increaseSize();
	library[getSize() - 1] = newPlaylist;
}

void Library::printPlaylists()
{
	if (getSize() == 0) {
		cout << "\nNo se ha creado ninguna playlist." << endl;
	}
	else {
		cout << "\nPlaylists disponibles: " << endl;
		for (int i = 0; i < getSize(); i++) {
			cout << i + 1 << ". " << library[i].getPlaylistTitle() << endl;
		}
	}
}

int Library::getSize()
{
	return size;
}

Playlist& Library::getPlaylist(int index)
{
	if (index >= 0 && index <= getSize())
	{
		return library[index];
	}
}
