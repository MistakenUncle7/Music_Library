#include "Music_Player.h"

Music_Player::Music_Player()
{
	setlocale(LC_ALL, "");
}

void Music_Player::run()
{
	Library myLibrary(0);

	string playlistTitle;
	int option;

	cout << "\n||| Bienvenido al reproductor de Musica |||\n" << endl;
	cout << "\nIngresando al menu principal...";

	do
	{
		clearScreen(3);
		option = printInitialMenu();
		clearScreen(2);

		if (option == 1) {
			cout << "\nIngrese el nombre de su nueva playlist: ";
			cin.ignore();
			getline(cin, playlistTitle);
			int existPlaylist = myLibrary.searchPlaylist(playlistTitle);
			if (existPlaylist != -1) {
				cout << "La playlist " << playlistTitle << " ya existe." << endl;
				cout << "\nRegresando al menu principal...";
			}
			else {
				Playlist myPlaylist(playlistTitle);
				myLibrary.insert(myPlaylist);
				cout << "\nPlaylist creada exitosamente...";
			}
		}
		else if (option == 2) {
			cout << "\nPlaylists disponibles: " << endl;
			myLibrary.printPlaylists();
			pressEnterToContinue();
		}
		else if (option == 3) {
			int playlistIndex;
			cout << "\nIngrese el nombre de la playlist que quieras entrar: ";
			cin.ignore();
			getline(cin, playlistTitle);
			playlistIndex = myLibrary.searchPlaylist(playlistTitle);
			if (playlistIndex == -1) {
				cout << "La playlist " << playlistTitle << " seleccionada no existe" << endl;
				cout << "\nRegresando al menu principal...";
			}
			else {
				cout << "\nIngresando a la playlist " << playlistTitle << "...";
				playlistOptions(myLibrary, playlistIndex);
			}
		}
		else if (option == 4) {
			cout << "--- Fin del programa ---" << endl;
			exit(0);
		}
		else {
			cout << "Error. Ingrese un indice valido\n" << endl;
		}
	} while (option != 4);
}

int Music_Player::printInitialMenu()
{
	int option;

	cout << "\nSelecciona una de las siguientes opciones" << endl
		<< "1. Crear playlist" << endl
		<< "2. Ver playlists" << endl
		<< "3. Elegir una playlist" << endl
		<< "4. Salir" << endl;

	cout << "\nOpcion: ";
	cin >> option;

	if (cin.fail()){
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Error. Ingrese una opcion valida\n" << endl;
	}
	else {
		return option;
	}
}

int Music_Player::printPlaylistMenu()
{
	int option;

	cout << "\nSelecciona una de las siguientes opciones" << endl
		<< "1. Agregar canción" << endl
		<< "2. Eliminar canción" << endl
		<< "3. Ver canciones en la playlist" << endl
		<< "4. Ver la canción a continuación" << endl
		<< "5. Ver canción anterior" << endl
		<< "6. Buscar una canción" << endl
		<< "7. Salir" << endl;

	cout << "\nOpcion: ";

	cin >> option;

	if (cin.fail()){
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Error. Ingrese una opcion valida\n" << endl;
	}
	else {
		return option;
	}
}

void Music_Player::playlistOptions(Library& library, int playlistIndex)
{
	int option;
	int existSong;
	string songName, artist;
	do
	{
		clearScreen(2);
		option = printPlaylistMenu();
		clearScreen(2);
		cin.ignore();

		switch (option)
		{
		case 1:
			cout << "Ingrese el nombre de la canción que desea agregar: ";
			getline(cin, songName);
			cout << "Ingrese el nombre del artista: ";
			getline(cin, artist);
			library.getPlaylist(playlistIndex).addSong(songName, artist);
			cout << "\Canción agregada exitosamente..." << endl;
			break;
		case 2:
			cout << "Ingrese el nombre de la canción que desea eliminar: ";
			getline(cin, songName);
			library.getPlaylist(playlistIndex).remove(songName);
			break;
		case 3:
			library.getPlaylist(playlistIndex).show();
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			cout << "Ingrese el nombre de la canción que desea buscar: ";
			getline(cin, songName);
			existSong = library.getPlaylist(playlistIndex).search(songName);
			if (existSong == -1) {
				cout << "\nNo hay canciones en esta playlist" << endl;
			}
			else if (existSong == 0) {
				cout << "\nLa canción " << songName << "se encuentra dentro de la playlist" << endl;
			}
			else {
				cout << "\nLa canción " << songName << " no se encuentra en la playlist" << endl;
			}
			cout << "\nRegresando al menú de opciones...";
			break;
		case 7:
			cout << "\nRegresando al menú de opciones...";
			break;
		default:
			cout << "Error. Ingrese un indice valido\n" << endl;
			break;
		}
	} while (option != 7);
}

void Music_Player::clearScreen(int num)
{
	this_thread::sleep_for(chrono::seconds(num));
	system("cls");
}

void Music_Player::pressEnterToContinue()
{
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "\nPresiona enter para continuar...";
	cin.get();
}
