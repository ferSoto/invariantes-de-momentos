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
	* 2.- This option receives the number 2, then 2 integer and the image 
	*     matrix (twice, the two images from different distance.)
	* 3.- Option 3 begins with 1, next two integers (heigh and width)
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

			ui heigh, width;
			//reading image dimensions.
			cin>>heigh>>width;
			Image my_image(heigh, width);
			//Reading image pixels.
			for (ui i = 0; i < heigh; ++i){
				for (ui j = 0; j < width; ++j){
					int temp_pixel;
					cin>>temp_pixel;
					my_image.setPixel(i, j, temp_pixel);
				}
			}//cout<<"hola";
			//Getting mass center
			my_image.getMC();
			cout<<"Xmc = "<<my_image.getXmc();
			cout<<"\nYmc = "<<my_image.getYmc();
			cout<<"\n\nCentral moments (original image): \n\n";
			for (int i = 0; i < 3; ++i){
				for (int j = 0; j < 3; ++j){
					cout<<"p = "<<i;
					cout<<" q = "<<j<<endl;
					cout<<"M = "<<Moments::centralMoment(my_image, i, j)<<"\n\n";
				}
			}
			cout<<"/////////////////////////////////////////////////////\n\n";
			//We're traslating the image
			my_image.traslateImage(1+rand()%200, 1+rand()%200);
			//Inside Image::traslateImage all its properties are updated.
			//Printing properties of our new image.
			cout<<"New Mass center:\nXmc = "<<my_image.getXmc();
			cout<<"\nYmc = "<<my_image.getYmc();
			cout<<"\n\nCentral moments (traslated image): \n";
			for (int i = 0; i < 3; ++i){
				for (int j = 0; j < 3; ++j){
					cout<<"p = "<<i;
					cout<<" q = "<<j<<endl;
					cout<<"M = "<<Moments::centralMoment(my_image, i, j)<<"\n\n";
				}
			}
		break;
		/*case 2:
			//Cool code stuffs
		break;
		case 3:
			//Cool code stuffs
		break;
		case 4:
			//Even cooler code stuffs
		break;
		default:
			//Not so awesome cool code
		break;*/
	}
	return 0;
}