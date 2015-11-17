/**
* Implementation of Moments.h
*/

#include "../Headers/Moments.h"
#include "../Headers/Image.h"
#include <cmath>
#include <iostream>

typedef unsigned int ui;

/**
* Receives an image and p and q to return the value of the 
* pq-th central moment order.
* 
*/
double Moments::centralMoment(Image img, int p, int q){
	double Mpq = 0;
	for(ui xi = 0; xi < img.getHeigh(); xi++)
		for(ui yj = 0; yj < img.getWidth(); yj++)
		if(img(xi,yj) == 1)				 
			Mpq += (pow((double)xi-(double)img.getXmc(),(double)p)
				*pow((double)yj-(double)img.getYmc(),(double)q));
	return Mpq;
}

/**
* Simplified: M_00 = sumi(sumj(p(x,y)))
*/
double Moments::getM00(Image img){
	double M_00 = 0;
	for(ui i = 0; i < img.getHeigh(); i++)
		for(ui j = 0; j < img.getWidth(); j++)
			M_00 += (double)img(i,j);
	return M_00;
}

/**
* Used as factor in getScalingMoment.
*/
double Moments::getM00some(double M_00, int p, int q){
	return pow((double)M_00,1.0 + (((double)p+(double)q)/2.0));
}

/**
* Receives an image and p and q to return the value of its pq-th
* central moment order for scaling.
* Scaling Moment = Mpq/(M00^((p+q)/2 + 1))
*/
double Moments::getScalingMoment(Image img, int p, int q, double M_00){
	return (double)centralMoment(img, p, q)/(double)getM00some(M_00, p, q);
}