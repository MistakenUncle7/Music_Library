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
	cout << "\nIngresando al menu principal..." << endl;

	do
	{
		clearScreen(3);
		option = printInitialMenu();
		clearScreen(2);

		if (option == 1) {
			cout << "\nIngrese el nombre de su nueva playlist: ";
			cin.ignore();
			getline(cin, playlistTitle);


			// Revisar si el nombre de la playlist ya existe
			Playlist myPlaylist(playlistTitle);

			myLibrary.insert(myPlaylist);
			cout << "Playlist creada exitosamente..." << endl;
		}
		else if (option == 2) {
			cout << "\nPlaylists disponibles: " << endl;
			myLibrary.printPlaylists();
			pressEnterToContinue();
		}
		else if (option == 3) {
			int playlistIndex;
			cout << "Ingrese el nombre de la playlist que quieras entrar: ";
			cin.ignore();
			getline(cin, playlistTitle);
			playlistIndex = myLibrary.searchPlaylist(playlistTitle);
			if (playlistIndex == -1) {
				cout << "La playlist seleccionada no existe" << endl;
			}
			else {
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

		switch (option)
		{
		case 1:
			cout << "Ingrese el nombre de la canción que desea agregar: ";
			cin >> songName;
			cout << "Ingrese el nombre del artista: ";
			cin >> artist;
			library.getPlaylist(playlistIndex).addSong(songName, artist);
			break;
		case 2:
			cout << "Ingrese el nombre de la canción que desea eliminar: ";
			cin >> songName;
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
			cin >> songName;
			existSong = library.getPlaylist(playlistIndex).search(songName);
			if (existSong == -1) {
				cout << "No hay canciones en esta playlist" << endl;
				cout << "\nRegresando al menu principal..." << endl;
			}
			else if (existSong == 0) {
				cout << "La canción " << songName << "se encuentra dentro de la playlist" << endl;
			}
			else {
				cout << "La canción " << songName << " no se encuentra en la playlist" << endl;
			}
			break;
		case 7:
			cout << "\nRegresando a la biblioteca..." << endl;
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
	cout << "\nPresiona enter para continuar...";
	getchar();
	cin.clear();
	cin.ignore(1000, '\n');
}
