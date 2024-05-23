#pragma once
#include <iostream>
#include <string>

using namespace std;

class Track 
{
public:
	Track() : prev(nullptr), next(nullptr) {}
	~Track();
	string songName;
	string artist;
	Track* prev;
	Track* next;
};