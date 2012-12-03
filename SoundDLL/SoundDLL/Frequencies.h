/***********************************************
 * Author: Erin Trzcinski
 * Date: 2012 12 02
 * Purpose: To create a simple DLL that can look 
 *			up different notes and frequencies 
 ***********************************************/

#include <iostream>
#include <string>
#include <map>

#define EXPORT __declspec(dllexport) 

using namespace std;

namespace SoundDLL
{
	class Frequencies
	{
	private:
		static multimap<string, float> noteToFreq;
		static multimap<float, string> freqToNote;
		
		static void loadNotes();

	public:
		static EXPORT float ConvertNoteToFrequency(string note);
		static EXPORT string CovertFrequencyToNote(float frequency);

	};
}