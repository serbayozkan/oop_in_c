/*
 * rect.c
 *
 *  Created on: Mar 30, 2020
 *      Author: serbay.ozkan
 */

#include <stdio.h>


#include "rect.h"

#define ENABLE_THIS_FILE  ( 1 )

#if ENABLE_THIS_FILE
static uint32_t rectangle_area(shape_t const *const this_p);
void rectangle_draw (shape_t const *const this_p);

void rectangle_ctor(rectangle_t *const this_p, int16_t x, int16_t y, uint16_t width, uint16_t height)
{
	static struct shape_vtable const vtable = {
			&rectangle_area,
			&rectangle_draw
	};

	shape_ctor(&this_p->shape, x, y);
	this_p->shape.vptr = &vtable;
	this_p->width = width;
	this_p->height = height;
}

static uint32_t rectangle_area(shape_t const *const this_p)
{
	// Explicit Downcast
	rectangle_t const *const this_p_ = (rectangle_t const *)this_p;

	return ((uint32_t)this_p_->width * (uint32_t)this_p_->height);
}

void rectangle_draw (shape_t const *const this_p)
{
	// Explicit Downcast
	rectangle_t const *const this_p_ = (rectangle_t const *)this_p;

	printf("Rectangle Draw: x->%d, y->%d, width->%d, height->%d\n",
			this_p_->shape.x,
			this_p_->shape.y,
			this_p_->width,
			this_p_->height);
}

int main(void)
{
	rectangle_t rect1, rect2;

	rectangle_ctor(&rect1, 10, 20, 30, 40);
	rectangle_ctor(&rect2, 50, 60, 70, 80);

	printf("Rectangle1 Area: %d\n", shape_area(&rect1.shape));
	printf("Rectangle2 Area: %d\n", shape_area(&rect2.shape));

	return 0;
}

#endif
