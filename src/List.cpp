#include "List.h"

Playlist::Playlist()
{
	head = tail = newNode = NULL;
}

Playlist::Playlist(string playlistTitle) : playlistTitle(playlistTitle)
{
	head = tail = newNode = NULL;
}

Playlist::~Playlist()
{
	while (head != NULL) {
		newNode = head;
		head = newNode->next;
		delete[] newNode;
	}
}

void Playlist::addSong(string song, string artist)
{
	newNode = new Track;
	newNode->songName = song;
	newNode->artist = artist;

	if (head == NULL){
		head = newNode;
		tail = newNode;
		newNode->prev = NULL;
		newNode->next = NULL;
	}
	else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
		tail->next = NULL;
		/* Elementos lista circular */
		newNode->next = head;
		head->prev = newNode; // Revisar si es correcto para la lista circular
	}
}

int Playlist::search(string song)
{ // Revisar si es mejor manejar errores de codigo retornando -1 o 0
	if (head == NULL) {
		return -1; // No hay canciones en esta playlist
	}
	else {
		newNode = head;
		while (newNode != NULL) {
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
	Track* temp = new Track;
	Track removed;
	int existSong = search(song);

	if (head == NULL) {
		cout << "La playlist esta vacia. No se puede eliminar niguna canción" << endl;
		cout << "Regresando al menu principal...";
	}
	else {
		newNode = head;
		while (newNode != NULL) {
			if (existSong == 0) {
				removed.songName = newNode->songName;
				removed.artist = newNode->artist;

				temp = newNode;
				newNode = newNode->prev;
				newNode->next = temp->prev;
				newNode = temp->next;
				newNode->prev = temp->prev;
				delete temp;

				cout << "Canción eliminada: " << endl;
				cout << "Nombre: " << removed.songName << endl;
				cout << "Artista: " << removed.artist << endl;
			}
			else {
				cout << "La cancion " << song << "no se encuentra en la playlist" << endl;
			}
		}
	}
}

void Playlist::show()
{
	if (head == NULL) {
		cout << "La playlist esta vacia" << endl;
	}
	else {
		newNode = head;
		cout << "\nCanciones dentro de esta playlist:" << endl;
		while (newNode != NULL) {
			cout << "Cancion: " << newNode->songName << endl;
			cout << "Artista: " << newNode->artist << "\n" << endl;
			if (newNode == tail) {
				break;
			}
			newNode = newNode->next;
		}
	}
}

string Playlist::getPlaylistTitle()
{
	return playlistTitle;
}
