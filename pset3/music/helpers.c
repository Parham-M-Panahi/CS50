// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#include "helpers.h"

int note_index(char note);

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int X = fraction[0] - '0';
    int Y = fraction[2] - '0';

    return (X * (8 / Y));
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char key;
    int octave;
    char accidental;

    if (strlen(note) == 2)
    {
	if (note[0] >= 'A' && note[0] <= 'G' && note[1] >= '0' && note[1] <= '8')
	{
	    key = note[0];
	    octave = note[1] - '0';
	    accidental = '\0';
	}
	else
	{
	    fprintf(stderr, "wrong note format\n");
	    return -1;
	}
    }
    else if (strlen(note) == 3)
    {
	if (
	    (note[0] >= 'A' && note[0] <= 'G' && note[2] >= '0' && note[2] <= '8') &&
	    (note[1] == '#' || note[1] == 'b')
	   )
	{
	    key = note[0];
	    octave = note[2] - '0';
	    accidental = note[1];
	}
	else
	{
	    fprintf(stderr, "wrong note format\n");
	    return -1;
	}
    }
    else
    {
	fprintf(stderr, "wrong note format\n");
	return -1;
    }

    // computes semitones to A4
    double semitones = 0;

    semitones += (octave - 4) * 12;

    semitones += note_index(key) - note_index('A');

    if (accidental == '#')
    {
	semitones++;
    }
    else if(accidental == 'b')
    {
	semitones--;
    }

    // compute frequency, using f(A4) = 440 hz
    double f = 440 * pow(2, semitones / 12.0);

    return (int) round(f);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
	return 1;
    }
    else
    {
        return 0;
    }
}

int note_index(char note)
{
    char notes[] = {'C','c','D','d','E','F','f','G','g','A','a','B'};

    for (int i = 0; i < 12; i++)
    {
        if (notes[i] == note)
	{
	    return i;
	}
    }
    return -1;
}
