/**
* Program to get the moment invariants of images.
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include "Headers/Image.h"
#include "Headers/Moments.h"

using namespace std;

typedef unsigned int ui;

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
			cout<<"M = "<<Moments::centralMoment(img, i, j)<<"\n\n";
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
			cout<<"Npq = "<<Moments::getScalingMoment(img, i, j, M00);
		}
	}
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
	* 1.- Begins with 1, then two integers (heigh and widthg) and finally 
	* 	  the matrix of the image.
	* 2.- This option receives the number 2, then 2 integer (heigh, width)
	*     and the image matrix (twice), the two images from different
	*     distance (50cm and 1m).
	* 3.- Option 3 begins with 3, next two integers (heigh and width)
	*     and the image matrix (for times cause we're going to work with
	*     four images).
	* 4.- Receives the all 7 images in the same format as before.
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
			Image imgD1, imgD2;
			double M00;
			//Reading images.
			imgD1 = readImage();
			imgD2 = readImage();
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
		/*case 3:
			//Cool code stuffs
		break;
		case 4:
			//Even cooler code stuffs
		break;*/
		default:
			cout<<"/nError en la entrada de los datos."
		break;
	}
	return 0;
}