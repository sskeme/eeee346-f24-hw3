// You don't need to modify this file

#ifndef PGM_H__ // header guard: to avoid the problem of multiple inclusion
#define PGM_H__

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

/**
 * File Stream object used through the program for image input
 */
static ifstream *pgmFile;

/**
 * Contains the full PGM Header
 */
static char header[500];

/**
 * Contains the Magic Number of the PGM file
 */
static char magicNumber[10];

/**
 * Contains the PGM image comment
 */
static char comment[100];

/**
 * Buffer to be used for storing temporary data
 */
static char buffer[10];

/**
 * Width of the PGM File
 */
static int pgmWidth;

/**
 * Height of the PGM file
 */
static int pgmHeight;

/**
 * Maximum value of pixels in the PGM file
 */
static int pgmMaxPix;

/**
 * Opens the PGM file and sets all information,
 * Does not read the data!
 *
 * @fileName - name of the file to be read
 * @return true if everything when ok, else false
 */
bool openPGM(string fileName);

/**
 * Closes the opened PGM file
 */
void closePGM();

/**
 * Reads the data in the PGM File that was opened.
 * Requires that openPGM is called first!
 *
 * @data - data location to store the data read
 */
void getPGMData(int** data);

/**
 * Writes out data to a new PGM file
 * New file must have same header information and size
 *
 * @fileName - name of the file to be written
 * @data - data to be written 
 * @return true if everything when ok, else false
 */
bool writePGM(string fileName, int** data);

/*
 * Sets the header information into variables
 * Automatically calls setPGMMagic, setPGMComment, 
 * setPGMMaxPixelSize, and setPGMSize.
 */
void setPGMHeader();

/*
 * Sets the magic number information into variables
 */
void setPGMMagic();
/*
 * Sets the commment information into variables
 */
void setPGMComment();

/*
 * Sets the max pixel size information into variables
 */
void setPGMMaxPixelSize();

/*
 * Gets the max pixel size information
 */
int getPGMMaxPixelSize();

/*
 * Sets the image size information into variables
 */
void setPGMSize();

/*
 * Returns the width of the PGM image data (columns)
 */
int getPGMWidth();

/*
 * Returns the height of the PGM image data (rows)
 */
int getPGMHeight();

#endif
