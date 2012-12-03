/***********************************************
 * Author: Erin Trzcinski
 * Date: 2012 12 02
 * Purpose: To create a simple DLL that can look 
 *			up different notes and frequencies 
 ***********************************************/

#include <iostream>
#include "Frequencies.h"
#include "Scales.h"

using namespace std;
using namespace SoundDLL;

int main()
{
	float myFloat;

	//For Frequencies:

	//pass in the note that you want
	myFloat = Frequencies::ConvertNoteToFrequency("C#0/Db0");
	
	string myString;

	//if you know the frequency and want the note, pass that in
	myString = Frequencies::CovertFrequencyToNote(17.32);
	
	cout << myFloat << "Hz is a " << myString << "\n\n";


	//For Scales:
	vector<string> myScale;
	vector<float> myFreq;

	//pass in the key in pitch value and what octave you want (don't go above 6)
	myScale = Scales::CalculateScale(4, 2);

	//pass in the scale to get the frequencies
	myFreq = Scales::ConvertScaleToFrequencies(myScale);

	cout << "Here's a Scale: \n\n";
	
	for(int i = 0; i < myScale.size(); i++)
	{
		cout << myScale[i] << " is " << myFreq[i] << "Hz\n";
	}

	cin.get();
	return 0;
}