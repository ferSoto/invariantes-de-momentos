/**
* Program to get the moment invariants of images.
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <tuple>
#include "Headers/Image.h"
#include "Headers/Moments.h"
#include "Headers/EulersCharacteristics.h"

using namespace std;

typedef unsigned int ui;
typedef tuple<double, double, double> tddd;

/**
* Read image width, heigh and its pixels.
*/
Image readImage(){
	//heigh and width of image
	ui heigh, width;
	int temp_pixel;
	//reading image dimensions.
	cin>>heigh>>width;
	Image my_image(heigh, width);
	//Reading image pixels.
	for (ui i = 0; i < heigh; ++i){
		for (ui j = 0; j < width; ++j){
			cin>>temp_pixel;
			my_image.setPixel(i, j, temp_pixel);
		}
	}
	return my_image;
}

/**
* Get and print central moments of the image.
*/
void printCentralMoments(Image img){
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			cout<<"p = "<<i;
			cout<<" q = "<<j<<endl;
			printf("M = %0.5lf\n\n",Moments::centralMoment(img, i, j));
		}
	}
}

/**
* Print the scaling moments of the image.
*/
void printScalingMoments(Image img, double M00){
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			cout<<"\n\np = "<<i<<", q = "<<j<<endl;
			printf("Npq = %0.50lf",Moments::getScalingMoment(img, i, j, M00));
			cout<<"\nNpq rounded = "<<Moments::getScalingMoment(img, i, j, M00);
		}
	}
}

/**
*
*/
void printRotationMoments(Image img){
	auto rotationMoments = Moments::getRotationMoments(img);
	printf(
		"\nRI1: %0.0lf\nRI2: %0.0lf\nRI3: %0.0lf",
		get<0>(rotationMoments), 
		get<1>(rotationMoments),
		get<2>(rotationMoments)
	);
}

int main(int argc, char const *argv[])
{
	/**
	* Options:
	* 1.- Invariants for translation
	* 2.- Invariants for scaling
	* 3.- Invariants for rotation
	*/
	////////////////////////////////////////////////////////////////////////
	/**
	* Each case has his own read format.
	* 1.- Begins with 1, then two integers (heigh and width) and finally 
	* 	  the matrix of the image.
	* 2.- This option receives the number 2, then 2 integer (heigh, width)
	*     and the image matrix (twice), the two images from different
	*     distance (50cm and 1m).
	* 3.- Option 3 begins with 3, next two integers (heigh and width)
	*     and the image matrix (four times cause we're going to work with
	*     that number of images).
	* 4.- Receives the number 4, then two integer (heigh and width) and 
	* 	  finally the matrix image.
	* Each option will print the moments for each image or their euler's 
	* characteristics.
	*/
	///////////////////////////////////////////////////////////////////////
	/**
	* To use this program easily, redirect the input from text files.
	*/
	srand(time(NULL));
	int option;
	cin>>option;
	switch(option){
		case 1:
		{	
			Image my_image;
			my_image = readImage();
			//Getting mass center
			my_image.getMC();
			my_image.printMC();
			cout<<"\nCentral moments (original image): \n\n";
			printCentralMoments(my_image);
			cout<<"/////////////////////////////////////////////////////\n\n";
			//We're traslating the image
			my_image.traslateImage(1+rand()%200, 1+rand()%200);
			//Inside Image::traslateImage all its properties are updated.
			//Printing properties of our new image.
			cout<<"New Mass center:\n";
			my_image.printMC();
			cout<<"\n\nCentral moments (traslated image): \n";
			printCentralMoments(my_image);
			break;
		}
		case 2:	
		{
			/**This block of code can be optimized using a for cycle 
			insted of two Image objects.*/
			Image imgD1, imgD2;
			double M00;
			//Reading images and getting their mass center (Used to
			//calculate their central moment).
			imgD1 = readImage();
			imgD1.getMC();
			imgD2 = readImage();
			imgD2.getMC();
			//Getting M00 for image 1.
			M00 = Moments::getM00(imgD1);
			//Getting and printing Scaling moments for image 1.
			cout<<"Scaling moments for 50cm:";
			printScalingMoments(imgD1, M00);
			cout<<"\n\n/////////////////////////////////////////////////////////\n\n";
			//Getting M00 for image 2.
			M00 = Moments::getM00(imgD2);
			//Getting and printing scaling moments for image 2.
			cout<<"Scaling moments for 1m:";
			printScalingMoments(imgD2, M00);
			break;
		}	
		case 3:
		{
			//Text to show with the data obtained.
			string degrees[4]= {"0: ", "45: ", "90: ", "180: "};
			cout<<"Rotarion moments:";
			for (int i = 0; i < 4; ++i){
				//Reading images and gettins thier mass center.
				Image img;
				img = readImage();
				img.getMC();
				cout<<"\n\n"<<degrees[i];
				printRotationMoments(img);
				cout<<"\n\n/////////////////////////////////////////////////////";
			}
		}
		break;
		case 4:
		{
			ui heigh, width;
			int temp_pixel;
			//Reading image.
			cin>>heigh>>width;
			EulersCharacteristics img(heigh, width);
			for (ui i = 0; i < heigh; ++i){
				for (ui j = 0; j < width; ++j){
					cin>>temp_pixel;
					img.setPixel(i, j, temp_pixel);
				}
			}
			//Setting euler characteristics
			img.setOutlinePerimeter();
			img.setTetrapixelsNumber();
			img.setContactPerimeter();
			img.setHoleNumber();
			img.setVertexNumber();
			//Printing euler characteristics
			cout<<"Euler's Characteristics:\n\n";
			cout<<"Outline perimeter: "<<img.getOutlinePerimeter();
			cout<<"\nContact perimeter: "<<img.getContactPerimeter();
			cout<<"\nHole number: "<<img.getHoleNumber();
			cout<<"\nTetrapixels: "<<img.getTetrapixelsNumber();
			cout<<"\nVertexs: "<<img.getVertexNumber();
			cout<<"\nFaces: "<<img.getFacesNumber();
		}
		break;
		default:
		{
			cout<<"/nInput error.";
		}
		break;
	}
	return 0;
}