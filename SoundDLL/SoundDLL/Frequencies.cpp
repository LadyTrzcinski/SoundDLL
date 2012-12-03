/***********************************************
 * Author: Erin Trzcinski
 * Date: 2012 12 02
 * Purpose: To create a simple DLL that can look 
 *			up different notes and frequencies 
 ***********************************************/

#include "Frequencies.h"
#include <fstream>

namespace SoundDLL
{
	multimap<float, string> Frequencies::freqToNote;
	multimap<string, float> Frequencies::noteToFreq;

	//Take the note names and return the frequency
	float Frequencies::ConvertNoteToFrequency(string note)
	{
		//if the maps haven't been initialized, do so
		if(noteToFreq.size() == 0)
		{
			loadNotes();
		}

		multimap <string, float> :: const_iterator mapIter;

		mapIter = noteToFreq.find(note);
		
		//if we didn't find it, return NULL
		if(mapIter == noteToFreq.end())
		{
			return NULL;
		}
		else
		{
			//found it
			return mapIter->second;
		}
	}
	
	//get the note value of a frequency
	string Frequencies::CovertFrequencyToNote(float frequency)
	{
		if(freqToNote.size() == 0)
		{
			loadNotes();
		}
		multimap <float, string> :: const_iterator mapIter;

		mapIter = freqToNote.find(frequency);

		//wasn't able to find it
		if(mapIter == freqToNote.end())
		{
			return "NULL";
		}
		else
		{
			//found it
			return mapIter->second;
		}
	}

	//get the note from the text file
	void Frequencies::loadNotes()
	{
		fstream fin;

		fin.open("notes.txt", ios::in);

		while(!fin.eof())
		{
			string note = "";
			string junk = "";
			float freq = 0;
			
			getline(fin, note);
			fin >> freq;
			getline(fin, junk);

			//add them to the maps
			freqToNote.insert(pair<float, string>(freq, note));
			noteToFreq.insert(pair<string, float>(note, freq));
	
		}
	}
}