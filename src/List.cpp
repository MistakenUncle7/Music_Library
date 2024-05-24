#include "List.h"

Playlist::~Playlist()
{
	while (head != nullptr) {
		node = head;
		head = node->next;
		delete[] node;
	}
}

void Playlist::addSong(const string song, const string artist)
{
	Track* newNode = new Track;
	newNode->songName = song;
	newNode->artist = artist;

	int existSong = search(song);
	if (existSong == 0) {
		cout << "\nLa canción " << song << " ya se encuentra en la playlist." << endl;
	}
	else {
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
			newNode->prev = newNode;
			newNode->next = newNode;
		}
		else {
			newNode->prev = tail;
			newNode->next = head;
			tail->next = newNode;
			head->prev = newNode;
			tail = newNode;
		}
	}
}

int Playlist::search(const string song)
{
	if (head == nullptr) {
		return -1; // No songs on the playlist
	}
	else {
		node = head;
		while (node != nullptr) {
			if (node->songName == song) {
				return 0; // Song found
			}
			else if (node == tail) {
				return 1; // Song not found
			}
			else {
				node = node->next;
			}
		}
	}
}

void Playlist::remove(const string song)
{
	int existSong = search(song);

	if (existSong == -1) {
		cout << "\nLa playlist esta vacía. No se puede eliminar niguna canción." << endl;
		cout << "\nRegresando al menú principal...";
	}
	else if(existSong == 1) {
		cout << "\nLa canción " << song << " no se encuentra en la playlist" << endl;
		cout << "\nRegresando al menú principal...";
	}
	else {
		Track* temp = new Track;
		Track removed;
		node = head;
		do
		{
			if (node->songName == song) {
				removed.songName = node->songName;
				removed.artist = node->artist;

				cout << "\nCanción eliminada: " << endl;
				cout << "Nombre: " << removed.songName << endl;
				cout << "Artista: " << removed.artist << endl;

				if (node == head && node == tail) {
					head = nullptr;
					tail = nullptr;
					delete node;
					return;
				}
				else if (node == head) {
					temp = node;
					node = temp->next;
					node->prev = temp->prev;
					head = node;
					tail->next = head;
					delete temp;
				}
				else if (node == tail) {
					tail = node->prev;
					tail->next = head;
					head->prev = tail;
					delete node;
					return;
				}
				else {
					temp = node;
					node = temp->prev;
					node->next = temp->next;
					node = temp->next;
					node->prev = temp->prev;
					delete temp;
				}
			}
			node = node->next;
		} while (node != head);
	}
}

void Playlist::show()
{
	if (head == nullptr) {
		cout << "\nLa playlist esta vacía." << endl;
	}
	else {
		node = head;
		cout << "\nCanciones dentro de esta playlist: " << endl;
		do
		{
			cout << "\nCanción: " << node->songName << endl;
			cout << "Artista: " << node->artist << endl;
			node = node->next;
		} while (node != head);
	}
}

string Playlist::getPlaylistTitle()
{
	return playlistTitle;
}
