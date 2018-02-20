#include "stdafx.h"
#include "CharacterFrequency.h"


CharacterFrequency::CharacterFrequency()
{
	character = '\0';
	frequency = 0;
}

CharacterFrequency::CharacterFrequency(char Character)
{
	setCharacter(Character);
	frequency = 0;
}


CharacterFrequency::~CharacterFrequency()
{

}

void CharacterFrequency::Increment()
{
	frequency++;
}

void CharacterFrequency::setCharacter(char Character)
{
	character = Character;
}

char CharacterFrequency::getCharacter()
{
	return character;
}

void CharacterFrequency::setFrequency(int freq)
{
	frequency = freq;
}

int CharacterFrequency::getFrequency()
{
	return frequency;
}
//overloading of the << operator so we can output our character frequency class without having to make a print function
ostream& operator<<(ostream& os, const CharacterFrequency& cf)
{
	os << cf.character << " (" << (int)cf.character << ") " << cf.frequency;
	return os;
}
