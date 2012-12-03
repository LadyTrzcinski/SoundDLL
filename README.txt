Author: Erin Trzcinski
Date: 2012 12 02

To use SoundDLL:

Frequencies:
	ConvertNoteToFrequency(string note)
		Pass in the note that you want
		Make sure to include the octave
			ex. C4 or B5
		If you want a sharp or a flat, use the following format:
			C#4/Bb4 <- this is the same note and must be called
				   as #/b

	ConvertFrequencyToNote(float frequency)
		Pass in the frequency you want 
		Make sure to go out to the hundredth place
			ex. 440.00 or 19.45

	
	You need to include notes.txt in your folder so that they can be loaded.


Scales:
	CalculateScale(int pitch, int octave)
		Pass in the pitch (0-11) and the octave(0-6) that you want
		
	ConvertScaleToFrequencies(vector<string> scale)
		Pass in the scale you created with CalculateScale or even
			one that you made on your own