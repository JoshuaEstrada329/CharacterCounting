#pragma once
#include <iostream>
using namespace std;
class CharacterFrequency
{
private:
	char character;
	int frequency;

public:	

	CharacterFrequency();
	CharacterFrequency(char);
	~CharacterFrequency();
	void Increment();

	void setCharacter(char);
	char getCharacter();

	void setFrequency(int);
	int getFrequency();

	//operator overloading
	friend ostream& operator<<(ostream& os, const CharacterFrequency& cf);
	//friend bool operator==(const CharacterFrequency& cfl, const CharacterFrequency& cfr);
	//friend bool operator!=(const CharacterFrequency& cf, const int& number);
};

