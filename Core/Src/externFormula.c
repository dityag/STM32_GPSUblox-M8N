/*
 * externFormula.c
 *
 *  Created on: Sep 14, 2023
 *      Author: HP GAMING
 */

#include <externFormula.h>
#include "math.h"

long map(long x, long in_min, long in_max, long out_min, long out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

double haversineDistance(double lat1, double long1, double lat2, double long2){
	double nRadius = 6370997.0; // Earth’s radius in Kilometers
	double rad = 0.0174532925199433;
	double nDLat = (lat2 - lat1) * rad;
	double nDLon = (long2 - long2) * rad;
	lat1 *= rad;
	lat2 *= rad;

	double nA =   pow( sin(nDLat / 2), 2 ) + cos(lat1) * cos(lat2) * pow( sin(nDLon / 2), 2 );
	double nC = 2 * atan2( sqrt(nA), sqrt( 1 - nA ));
	double nD = nRadius * nC;
	return nD;
}

short calculatePID(short setpoint, float actual_value, float kp, float ki, float kd, short maxval, short minval,float errornow, float errorbfr, float max_err, float min_err, float dt){
	short output;
	static float integral;
	static float derivative;

	errornow = setpoint - actual_value;

	integral += errornow;
	derivative = (errornow - errorbfr) / dt;

	integral = integral + errornow * dt;

	if(integral > max_err){
		integral = max_err;
	}else if(integral < min_err){
		integral = min_err;
	}

	output = kp*errornow + ki*integral + kd*derivative;

	if (output > maxval){
		output = maxval;
	}else if(output < minval){
		output = minval;
	}

	errorbfr = errornow;
	return output;
}
