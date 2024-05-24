#pragma once
#include "Track.h"
#include <iostream>
#include <string>

using namespace std;

// Lista doblemente enlazada circular
class Playlist
{
public:
	Playlist() : head(nullptr), tail(nullptr), node(nullptr) {}
	Playlist(string playlistTitle) : playlistTitle(playlistTitle), head(nullptr), tail(nullptr), node(nullptr) {}
	~Playlist();
	void addSong(const string, const string);
	int search(const string);
	void remove(const string);
	void show();

	/* Setters and getters */
	string getPlaylistTitle();
private:
	string playlistTitle;
	Track* head;
	Track* tail;
	Track* node;
};
