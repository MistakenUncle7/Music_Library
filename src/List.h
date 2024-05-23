#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Track
{
	string songName;
	string artist;
	Track* prev;
	Track* next;
};
// Lista doblemente enlazada circular
class Playlist
{
public:
	Playlist();
	Playlist(string);
	~Playlist();
	void addSong(string, string);
	int search(string);
	void remove(string);
	void show();

	/* Setters and getters */
	string getPlaylistTitle();
private:
	string playlistTitle;
	Track* head;
	Track* tail;
	Track* newNode;
};
