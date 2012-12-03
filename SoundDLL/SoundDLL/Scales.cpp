/***********************************************
 * Author: Erin Trzcinski
 * Date: 2012 12 02
 * Purpose: To create a simple DLL that can look 
 *			up different notes and frequencies 
 ***********************************************/

#include "Scales.h"
#include "Frequencies.h"
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

namespace SoundDLL
{
	//calculate a scale based off a starting pitch
	vector<string> Scales::CalculateScale(int pitch, int octave)
	{
		vector<string> scale;

		//to add the octave number to the string
		string myString;		
		ostringstream convert;
		convert << octave;
		string octaveString = convert.str();

		//to increase the octave if you return to C
		bool gotToEnd = false;

		//double checks
		if(pitch < 0)
		{
			pitch = 0;
		}
		else if(pitch > 11)
		{
			pitch = 11;
		}

		//double check
		if(octave < 0)
		{
			octave = 0;
		}
		else if (octave > 6)
		{
			octave = 6;
		}

		//loop through the scale
		for(int i = 0; i < 7; i++)
		{
			if(pitch%12 == 0)
			{
				scale.push_back("C" + octaveString);
			}
			else if (pitch%12 == 1)
			{
				myString = "C#" + octaveString + "/Db" + octaveString;
				scale.push_back(myString);
			}
			else if (pitch%12 == 2)
			{
				scale.push_back("D" + octaveString);
			}
			else if (pitch%12 == 3)
			{
				myString = "D#" + octaveString + "/Eb" + octaveString;
				scale.push_back(myString);
			}
			else if (pitch%12 == 4)
			{
				scale.push_back("E" + octaveString);
			}
			else if (pitch%12 == 5)
			{
				scale.push_back("F" + octaveString);
			}
			else if (pitch%12 == 6)
			{
				myString = "F#" + octaveString + "/Gb" + octaveString;
				scale.push_back(myString);
			}
			else if (pitch%12 == 7)
			{
				scale.push_back("G" + octaveString);
			}
			else if (pitch%12 == 8)
			{
				myString = "G#" + octaveString + "/Ab" + octaveString;
				scale.push_back(myString);
			}
			else if (pitch%12 == 9)
			{
				scale.push_back("A" + octaveString);
			}
			else if (pitch%12 == 10)
			{
				myString = "A#" + octaveString + "/Bb" + octaveString;
				scale.push_back(myString);
			}
			else
			{
				scale.push_back("B" + octaveString);
			} 


			if(i != 2)
				pitch += 2;
			else
				pitch++;

			//need to go up an octave
			if((pitch%12 == 0 || pitch%12==1))
			{
				if(gotToEnd == false)
				{
					gotToEnd = true;
					octave++;
					ostringstream newConvert;
					newConvert << octave;
					octaveString = newConvert.str();
				}
			}
		}

		return scale;
	}


	//covert a scale into its frequencies
	vector<float> Scales::ConvertScaleToFrequencies(vector<string> scale)
	{
		vector<float> frequencies;

		for(unsigned int i = 0; i < scale.size(); i++)
		{
			frequencies.push_back(Frequencies::ConvertNoteToFrequency(scale[i]));
		}

		return frequencies;
	}
}