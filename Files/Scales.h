/***********************************************
 * Author: Erin Trzcinski
 * Date: 2012 12 02
 * Purpose: To create a simple DLL that can look 
 *			up different notes and frequencies 
 ***********************************************/

#include <iostream>
#include <string>
#include <vector>

#define EXPORT __declspec(dllexport)

using namespace std;

namespace SoundDLL
{
	class Scales
	{
	public:
		//pass in the key you want in pitch-class number (0 - 11)
		static EXPORT vector<string> CalculateScale(int pitch, int octave);

		//pass in your vector of notes
		static EXPORT vector<float> ConvertScaleToFrequencies(vector<string> scale);
	};
}