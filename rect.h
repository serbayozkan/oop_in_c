/*
 * rect.h
 *
 *  Created on: Mar 30, 2020
 *      Author: serbay.ozkan
 */

#ifndef RECT_H_
#define RECT_H_

#include "shape.h"

typedef struct
{
	// Inherits Shape Class
	shape_t shape;

	uint16_t width;
	uint16_t height;
}rectangle_t;

void rectangle_ctor(rectangle_t *const this_p, int16_t x, int16_t y, uint16_t width, uint16_t height);

#endif /* RECT_H_ */
