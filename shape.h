/*
 * shape.h
 *
 *  Created on: Mar 30, 2020
 *      Author: serbay.ozkan
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <stdint.h>

/* Shape Attributes */
typedef struct
{
	int16_t x;
	int16_t y;
}shape_t;

/* Shape's interface */
void shape_ctor(shape_t *const this_p, int16_t x, int16_t y);
void shape_move_by(shape_t *const this_p, int16_t x, int16_t y);
int16_t shape_get_x(shape_t *const this_p);
int16_t shape_get_y(shape_t *const this_p);

#endif /* SHAPE_H_ */
