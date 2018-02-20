// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "CharacterFrequency.h"
using namespace std;

int main(int argc, char* args[])
{
	//if the user does not input the parameters for the program then kick them out
	if (argc != 3)
	{
		cout << "usage: <inputFile> <outputFile>" << endl;
		return -2;
	}
	else
	{
		cout << "Reading from file!" << endl;

		ifstream ifile;
		//args[1]
		ifile.open(args[1]);
		//checking to see if the fule can be opened
		if (!ifile.is_open())
		{
			cout << "File could not be opened!" << endl;
			return -1;
		}

		//use the memory if the file can be opened
		CharacterFrequency cf[255];
		//initalizing the cf array	length of the array
		for (int i = 0; i < (sizeof(cf) / sizeof(cf[0])); i++)
		{
			cf[i] = CharacterFrequency((char)i);
		}

		char c;
		//reading of the file
		while (ifile.get(c))
		{
			cf[(int)c].Increment();
		}
		//closing the input file
		ifile.close();

		ofstream ofile;
		//args[2]
		ofile.open(args[2]);
		if (!ofile.is_open())
		{
			cout << "File could not be opened!" << endl;
			delete cf;
			return -1;
		}
		//writing to file
		for (int i = 0; i < (sizeof(cf) / sizeof(cf[0])); i++)
		{
			//only print the characters that where in the file
			if (cf[i].getFrequency() != 0)
				ofile << cf[i] << endl;
		}

		ofile.close();

	}
	return 0;
}

