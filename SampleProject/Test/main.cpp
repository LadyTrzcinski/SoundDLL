/***********************************************
 * Author: Erin Trzcinski
 * Date: 2012 12 02
 * Purpose: To create a simple DLL that can look 
 *			up different notes and frequencies 
 ***********************************************/

#include <iostream>
#include "Frequencies.h"

using namespace std;
using namespace SoundDLL;

int main()
{
	float myFloat;

	//pass in the note that you want
	myFloat = Frequencies::ConvertNoteToFrequency("C#0/Db0");
	
	string myString;

	//if you know the frequency and want the note, pass that in
	myString = Frequencies::CovertFrequencyToNote(17.32);
	
	cout << myFloat << "Hz is a " << myString;

	cin.get();
	return 0;
}