#pragma once
#include "Array.h"
#include "List.h"
#include "Music_Player.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

class Music_Player
{
public:
	Music_Player();
	void run();
	int printInitialMenu();
	int printPlaylistMenu();
	void playlistOptions(Library&, int);
	void clearScreen(int);
	void pressEnterToContinue();
};