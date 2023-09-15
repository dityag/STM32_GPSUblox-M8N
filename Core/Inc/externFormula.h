/*
 * externFormula.h
 *
 *  Created on: Sep 14, 2023
 *      Author: HP GAMING
 */

#ifndef INC_EXTERNFORMULA_H_
#define INC_EXTERNFORMULA_H_

#include <stdint.h>

long map(long x, long in_min, long in_max, long out_min, long out_max);
double haversineDistance(double lat1, double long1, double lat2, double long2);
short calculatePID(short setpoint, float actual_value, float kp, float ki, float kd, short maxval, short minval,float errornow, float errorbfr, float max_err, float min_err, float dt);

#endif /* INC_EXTERNFORMULA_H_ */
