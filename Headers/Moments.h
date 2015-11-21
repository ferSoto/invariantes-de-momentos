/**
* Class with invariants functions
*/

#include "Image.h"
#include <tuple>

#ifndef MOMENTS_H
#define MOMENTS_H

class Moments
{
public:
	//Function to get the central moment of an image.
	static double centralMoment(Image img, int p, int q);
	
	//Function to get M00 used in central moments for scaling
	static double getM00(Image img);

	//Function to get central moment for scaling transformation.
	static double getScalingMoment(Image img, int p, int q, double M_00);

	//Function that return the first 3 invariants for rotation.
	static std::tuple<double, double, double>getRotationMoments(Image img);

private:
	//Return M_00^((p+q)/2 + 1)
	static double getM00some(double M_00, int p, int q);

	//Rotation Invariant 1.
	static double firstRI(Image img);

	//Rotation Invariant 2.
	static double secondRI(Image img);

	//Rotation Invariant 3.
	static double thirdRI(Image img);

};
#endif