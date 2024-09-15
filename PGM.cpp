// You don't need to modify this file

#include "PGM.h"

bool openPGM(string fileName) { //{{{
	// Open the file
	pgmFile = new ifstream(fileName);
	
	// If open is successful, then proceed to read header information
	if (pgmFile->is_open()) {		
		setPGMHeader();		
	} else {
		return false;
	}

	return true;
} //}}}

void closePGM() { //{{{
	// Close the File
	pgmFile->close();		
} //}}}

bool writePGM(string fileName, int** data) { //{{{
	// Open the output stream
	ofstream myWriteFile;
	myWriteFile.open(fileName);

	// Check if file open ok
	if (myWriteFile.is_open()) {
		// Write the header first
		myWriteFile << header;

		// iterate through the data and output to the file
		for(int j=0; j<pgmHeight; j++){
			for(int k=0; k<pgmWidth; k++){
				myWriteFile << data[j][k] << " ";
			}
			myWriteFile << endl;
		}
	
	} else {
		return false;
	}

	// Done writing, close the file
	myWriteFile.close();
	
  return true;
} //}}}

void setPGMHeader() { //{{{
	cout << "Reading in File\n";
	
  if (pgmFile->is_open()) {
		// Clear the memory of the header
		memset(&header[0], 0, sizeof(header));
		
    // Set the magic number
		setPGMMagic();
    
		// Set the comment
		setPGMComment();
    
		// Set the size
		setPGMSize();

		// Set the max pixel size
		setPGMMaxPixelSize();

		// Concat everything together for the full header
		sprintf(header,"%s\n%s\n%d %d\n%d\n", magicNumber, comment, pgmWidth, pgmHeight, pgmMaxPix); 
	}
	
	cout << "Done Reading in File\n";
} //}}}

void setPGMMagic() { //{{{
	// Clear memory
	memset(&magicNumber[0], 0, sizeof(magicNumber));

	// Two character magic number
	*pgmFile>>*magicNumber;
	*pgmFile>>*(magicNumber+1);
} //}}}

void setPGMComment() { //{{{
	// clear the memory 
	memset(&comment[0], 0, sizeof(comment));
  int i =0;	

	// read in the comment till end of the line
	do { 
		*pgmFile>>*(comment+i);
  	i++;
	} while ((pgmFile->peek()!='\n'));
} //}}}

void setPGMSize() { //{{{
		// Clear the buffer
		int i=0;		
		memset(&buffer[0], 0, sizeof(buffer));

		// Read first size, ended by a space
		do {
			*pgmFile>>buffer[i];	
			i++;
		} while (pgmFile->peek()!=' ');

		// Convert to an integer
		sscanf(buffer,"%d",&pgmWidth);

		// Clear the buffer
		i=0;
		memset(&buffer[0], 0, sizeof(buffer));

		// Read the next number, ended by newline
		do {
			*pgmFile>>buffer[i];	
			i++;
		} while (pgmFile->peek()!='\n');

		// Convert to integer
		sscanf(buffer,"%d",&pgmHeight);
} //}}}

void setPGMMaxPixelSize() { //{{{
		// Clear the buffer
		int i=0;
		memset(&buffer[0], 0, sizeof(buffer));

		// Read in the number, ended by newline
		do {
			*pgmFile>>buffer[i];	
			i++;
		} while (pgmFile->peek()!='\n');

		// Convert to an integer
		sscanf(buffer,"%d",&pgmMaxPix);
} //}}}

void getPGMData(int** data) { //{{{
	// Read in the image into data
	int i;
	int cNum;

	// Loop across rows and columns base don previously read header information
	for(int j=0; j<pgmHeight; j++){
		for(int k=0; k<pgmWidth; k++){
			// Clear the buffer
			i=0;
			memset(&buffer[0], 0, sizeof(buffer));

			// Read in a number, space or newline terminated
			do {
				*pgmFile>>buffer[i];
				i++;
			} while ((pgmFile->peek()!=' ') && (pgmFile->peek()!='\n'));

			// Convert to a number
			sscanf(buffer,"%d",&cNum);	
	
			// Store in data
			data[j][k] = cNum;
		}
	}
} //}}}

int getPGMMaxPixelSize() { //{{{
		return pgmMaxPix;
} //}}}

int getPGMWidth() { //{{{
		return pgmWidth;
} //}}}

int getPGMHeight() { //{{{
		return pgmHeight;
} //}}}
