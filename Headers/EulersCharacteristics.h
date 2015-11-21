/**
* Class to obtain euler's characteristics.
*/

#include "Image.h"

#ifndef EULERCHARACTERISTICS_H
#define EULERCHARACTERISTICS_H

class EulersCharacteristics : Image
{
public:
	//typedef unsigned int ui;

	////////////////////////////Constructors/////////////////////////////
	EulersCharacteristics();
	EulersCharacteristics(ui heigh, ui width);

	////////////////////////////////Getters//////////////////////////////
	ui getOutlinePerimeter();
	ui getContactPerimeter();
	int getHoleNumber();
	ui getTetrapixelsNumber();
	ui getVertexNumber();
	ui getFacesNumber();
	///////////////////////////Bad used setters/////////////////////////
	void setOutlinePerimeter();
	void setContactPerimeter();
	void setHoleNumber();
	void setTetrapixelsNumber();
	void setVertexNumber();
	//////////////////////////////functions///////////////////////////
	void setPixel(ui i, ui j, ui value);


private:
	ui outline_perimeter;
	ui contact_perimeter;
	int hole_number;
	ui tetrapixels_number;
	ui Vertex_number;
	ui faces_number;

	

};

#endif
