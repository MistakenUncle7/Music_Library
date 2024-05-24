#include "List.h"

Playlist::~Playlist()
{
	while (head != nullptr) {
		newNode = head;
		head = newNode->next;
		delete[] newNode;
	}
}

void Playlist::addSong(const string song, const string artist)
{
	newNode = new Track;
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
			newNode->prev = nullptr;
			newNode->next = nullptr;
		}
		else {
			/*
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
			tail->next = nullptr;
			/* Elementos lista circular
			newNode->next = head;
			head->prev = newNode; // Revisar si es correcto para la lista circular
			*/

			newNode->prev = tail;
			tail->next = newNode;
			newNode->next = head;
			head->prev = newNode;
			tail = newNode;
		}
	}
}

int Playlist::search(string song)
{
	if (head == nullptr) {
		return -1; // No hay canciones en esta playlist
	}
	else {
		newNode = head;
		while (newNode != nullptr) {
			if (newNode->songName == song) {
				return 0; // Existe la cancion en la playlist
			}
			else if (newNode == tail) {
				return 1; // La cancion seleccionada no se encuentra en la playlist
			}
			else {
				newNode = newNode->next;
			}
		}
	}
}

void Playlist::remove(string song)
{
	int existSong = search(song);

	if (existSong == -1) {
		cout << "\nLa playlist esta vacía. No se puede eliminar niguna canción" << endl;
		cout << "\nRegresando al menú principal...";
	}
	else if(existSong == 1) {
		cout << "\nLa canción " << song << " no se encuentra en la playlist" << endl;
	}
	else {
		Track* temp = new Track;
		Track removed;
		newNode = head;
		while (newNode != tail) {
			if (newNode->songName == song) {
				removed.songName = newNode->songName;
				removed.artist = newNode->artist;

				temp = newNode;
				newNode = newNode->prev;
				newNode->next = temp->prev;
				newNode = temp->next;
				newNode->prev = temp->prev;
				delete temp;

				cout << "\nCanción eliminada: " << endl;
				cout << "Nombre: " << removed.songName << endl;
				cout << "Artista: " << removed.artist << endl;
			}
			newNode = newNode->next;
		}
	}
}

void Playlist::show()
{
	if (head == nullptr) {
		cout << "\nLa playlist esta vacía." << endl;
	}
	else {
		newNode = head;
		cout << "\nCanciones dentro de esta playlist: " << endl;
		do
		{
			cout << "\nCanción: " << newNode->songName << endl;
			cout << "Artista: " << newNode->artist << endl;
			newNode = newNode->next;
		} while (newNode != head);
	}
}

string Playlist::getPlaylistTitle()
{
	return playlistTitle;
}
