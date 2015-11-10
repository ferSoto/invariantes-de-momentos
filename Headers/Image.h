/**
* Class that contains a image and its properties.
*/
#include <vector>

#ifndef IMAGE_H
#define IMAGE_H

class Image
{
public:
	typedef unsigned int ui;
	typedef std::vector<int> vi;
	typedef std::vector<vi> vvi;

	//Operator for access to the matrix position easily
	operator ()(ui i, ui j);

	//Constructor
	Image(ui heigh, ui width);

	//Getters
	ui getWidth();
	ui getHeigh();
	ui getXcm();
	ui getYcm();
	//Setter
	void setPixel(ui x, ui y, int value);

	//Apply traslation to the image.
	void traslateImage(ui alpha, ui betha);
	
private:
	vvi matrix;
	ui width;
	ui heigh;
	ui xcm;
	ui ycm;

	//Change the size of the image matrix
	vvi newMatrix(ui x, ui y);
	//Function to get mass center of image.
	void getCM();
	//Function to create image matrix.
	void createMatrix();
};

#endif