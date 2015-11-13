/**
* Implementation Image
*/

#include "../Headers/Image.h"
#include <vector>
#include <iostream>
#include <cstring>
#include <iostream>

Image::Image(){
	
}

Image::Image(ui heigh, ui width){
	this->heigh = heigh;
	this->width = width;
	createMatrix();
}

/////////////////////////Getters & Setters///////////////////////////

//Getters
unsigned int Image::getWidth(){ return this->width; }
unsigned int Image::getHeigh(){ return this->heigh; }
unsigned int Image::getXmc(){ return this->xmc; }
unsigned int Image::getYmc(){ return this->ymc; }

//Setter
void Image::setPixel(ui x, ui y, int value){
	this->matrix.at(x).at(y) = value;
}

////////////////////////////Functions///////////////////////////////

//For easy access to the matrix.
Image::operator ()(ui i, ui j){
	return this->matrix.at(i).at(j);
}

//Creates the matrix that contains the image.
void Image::createMatrix(){
	this->matrix.resize(this->heigh);
	for (unsigned int i = 0; i < this->heigh; ++i){
		this->matrix.at(i).resize(this->width);
	}
}

//Get the Mass Center of the image.
void Image::getMC(){
	unsigned int xs = 0,
		 		 ys = 0,
		 		 ones = 0;
	for(unsigned int i = 0; i < this->heigh; i++){
		for (unsigned int j = 0; j < this->width; j++){
			if(this->matrix[i][j]){
				xs += i;
				ys += j;
				ones += 1;
			}
		}
	}
	this->xmc = (unsigned int)(xs/ones);
	this->ymc = (unsigned int)(ys/ones);
}

/**
* Return an image matrix of (heigh+x)*(width+y)
*/
typedef std::vector<std::vector<int> > vvi;
vvi Image::newMatrix(ui x, ui y){
	vvi new_matrix;
	new_matrix.resize(this->heigh+x);
	for (unsigned int i = 0; i < this->heigh+x; ++i){
		new_matrix.at(i).resize(this->width+y);
	}
	return new_matrix;
}

/**
* Traslate object in image matrix alpha in x and beta in y.
*/
void Image::traslateImage(ui alpha, ui beta){
	vvi temp_matrix;
	//Creating a new image matrix to traslate the object in this->matrix.
	temp_matrix = newMatrix(alpha, beta);
	//Copying this->matrix traslated to temp_matrix.
	for(unsigned int i = 0; i < this->heigh; i++){
		for(unsigned int j = 0; j < this->width; j++){
			if(this->matrix[i][j])
				temp_matrix.at(i+alpha).at(j+beta) = 1;
		}
	}
	//Replacing this->matrix with temp_matrix.
	this->matrix = temp_matrix;
	//Updating all the other properties of the image.
	this->heigh += alpha;
	this->width += beta;
	getMC();
}

void Image::printMC(){
	std::cout<<"Xmc = "<<this->xmc;
	std::cout<<"\nYmc = "<<this->ymc<<std::endl;
}
