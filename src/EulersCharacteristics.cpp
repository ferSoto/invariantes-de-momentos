/**
* Implementatons of EulersCharacteristics.h
*/
#include <algorithm>
#include "../Headers/EulersCharacteristics.h"

////////////////////////////////Constructors//////////////////////////////
EulersCharacteristics::EulersCharacteristics()
: Image::Image(){

}

EulersCharacteristics::EulersCharacteristics(ui heigh, ui width)
: Image::Image(heigh, width){
	this->outline_perimeter = 0;
	this->contact_perimeter = 0;
	this->hole_number = 0;
	this->tetrapixels_number = 0;
	this->Vertex_number = 0;
	this->faces_number = 0;
}


//////////////////////////////////Getters//////////////////////////////////
unsigned int EulersCharacteristics::getOutlinePerimeter(){ return this->outline_perimeter; }
unsigned int EulersCharacteristics::getContactPerimeter(){ return this->contact_perimeter; }
int EulersCharacteristics::getHoleNumber(){ return this->hole_number; }
unsigned int EulersCharacteristics::getTetrapixelsNumber(){ return this->tetrapixels_number; }
unsigned int EulersCharacteristics::getVertexNumber(){ return this->Vertex_number; }
unsigned int EulersCharacteristics::getFacesNumber(){ return this->faces_number; }

////////////////////////////////Functions///////////////////////////////////

/**
* This function sets outline perimeter and number of pixels/faces of the
* image.
*/
void EulersCharacteristics::setOutlinePerimeter(){
	for (unsigned int i = 0; i < this->heigh; ++i){
		for (unsigned int j = 0; j < this->width; ++j){
			//Counting 1-pixels.
			if(this->matrix[i][j]){
				this->faces_number++;
				//Counting outline perimeter
				for (int h = 0; h < 2; ++h){
					for (int k = 0; k < 2; ++k){
						if(k*h == 0 && (k != 0 || h != 0)
							&& !this->matrix[i+h][j+k]){
							this->outline_perimeter++;
						}
					}
				}
			}else{
				for (unsigned int h = i; h < std::min(this->heigh, i+2); ++h){
					for (unsigned int k = j; k < std::min(this->width, j+2); ++k){
						if((k != j || h != i) && (h == i || k == j) 
							&& this->matrix[h][k]){
							this->outline_perimeter++;
						}
					}
				}
			}
		}
	}
}

/**
* Count tetrapixels number.
*/
void EulersCharacteristics::setTetrapixelsNumber(){
	for (unsigned int i = 0; i < this->heigh-1; ++i){
		for (unsigned int j = 0; j < this->width-1; ++j){
			if(this->matrix[i][j] && this->matrix[i+1][j] 
				&& this->matrix[i][j+1] && this->matrix[i+1][j+1]){
				this->tetrapixels_number++;	
			}
		}
	}
	
}

/**
* sets contact perimeter.
*/
void EulersCharacteristics::setContactPerimeter(){
	this->contact_perimeter = (4*this->faces_number - this->outline_perimeter)/2;
}

/**
*
*/
void EulersCharacteristics::setHoleNumber(){
	this->hole_number = (2*this->faces_number - this->outline_perimeter)/2 
		+ 1 - this->tetrapixels_number;
}

/**
* 
*/
void EulersCharacteristics::setVertexNumber(){
	this->Vertex_number = this->tetrapixels_number + this->outline_perimeter;
}

/**
*
*/
void EulersCharacteristics::setPixel(ui i, ui j, ui value){
	this->matrix.at(i).at(j) = value;
}
