// Recover JPEG from a .raw file

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(int argc, char* argv[])
{
	// ensure proper usage
	if (argc != 2)
	{
		fprintf(stderr, "Usage: recover image\n");
		return 1;
	}

	// remember image name
	char* file = argv[1];

	// open input file
	FILE* ptr = fopen(file, "r");
	if (ptr == NULL)
	{
		fprintf(stderr, "Could not open %s.\n", file);
		return 2;
	}

	BYTE buffer[512];
	bool foundJpeg = false;
	int numberOfJpegsFound = 0;
	char nameOfJpeg[8];
	// ###.jpg\0

	FILE* img;

	while (fread(buffer, 1, 512, ptr) == 512)
	{
		if (buffer[0] == 0xff &&
		    buffer[1] == 0xd8 &&
		    buffer[2] == 0xff &&
		    (buffer[3] & 0xf0) == 0xe0)
		{
			if (foundJpeg)
			{
				// close jpeg
				fclose(img);
				numberOfJpegsFound += 1;
				// open new jpeg
				sprintf(nameOfJpeg, "%03i.jpg", numberOfJpegsFound);
				img = fopen(nameOfJpeg, "w");
				// write buffer to new jpeg
				fwrite(buffer, sizeof(buffer), 1, img);
			}
			else
			{
				foundJpeg = true;
				numberOfJpegsFound += 1;
				// open first jpeg
				sprintf(nameOfJpeg, "%03i.jpg", numberOfJpegsFound);
				img = fopen(nameOfJpeg, "w");
				// write buffer to jpeg
				fwrite(buffer, sizeof(buffer), 1, img);

			}
		}
		else
		{
			if (foundJpeg)
			{
				// keep writing buffer to jpeg
				fwrite(buffer, sizeof(buffer), 1, img);
			}
		}
	}

	// close any open jpeg
	if (img != NULL)
		fclose(img);

	

	// close file
	fclose(ptr);
	
	// success
	return 0;
}
