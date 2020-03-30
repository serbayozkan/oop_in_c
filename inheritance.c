/*
 * inheritance.c
 *
 *  Created on: Mar 30, 2020
 *      Author: serbay.ozkan
 */

/*
 * There are no additional costs using the "inherited" functions for instances of the subclasses.
 * In other words, the cost of calling a function for an object of a subclass is exactly as
 * expensive as calling the same function for an object of superclass. This overhead is also
 * very similar (identical really) as in C++
 */
#include <stdio.h>

#include "rect.h"

#define ENABLE_THIS_FILE  ( 0 )

#if ENABLE_THIS_FILE
void rectangle_ctor(rectangle_t *const this_p, int16_t x, int16_t y, uint16_t width, uint16_t height)
{
	// First call constructor of super class / base class shape
	shape_ctor(&this_p->shape, 10, 20);

	// Next initialize the parameters of sub class / derived class
	this_p->width = width;
	this_p->height = height;
}


int main(void)
{
	rectangle_t rectang1, rectang2;

	rectangle_ctor(&rectang1, 10, 20, 30, 40);
	rectangle_ctor(&rectang2, 50, 60, 70, 80);

	printf("Rectang1 x: %d, y: %d, width: %d, height: %d\n",
			rectang1.shape.x,
			rectang1.shape.y,
			rectang1.width,
			rectang1.height);

	printf("Rectang2 x: %d, y: %d, width: %d, height: %d\n",
				rectang2.shape.x,
				rectang2.shape.y,
				rectang2.width,
				rectang2.height);

	/*
	 * Avoid casting and take the address of the member
	 */

	// shape_move_by(&rectang1.shape, -10, -10);
	// shape_move_by(&rectang2.shape, -20, -20);

	/*
	 * To be strictly correct in C, you should explicitly cast a pointer to the subclass
	 * In OOP such casting is called upcasting is always safe
	 *
	 * Upcasting -> Converting the derived class reference to the base class reference
	 * Downcasting -> Converting the base class reference to the derived class reference
	 */
	shape_move_by((shape_t*)&rectang1, -10, -10);
	shape_move_by((shape_t*)&rectang2, -20, -20);

	printf("Rectang1 x: %d, y: %d, width: %d, height: %d\n",
				rectang1.shape.x,
				rectang1.shape.y,
				rectang1.width,
				rectang1.height);

	printf("Rectang2 x: %d, y: %d, width: %d, height: %d\n",
				rectang2.shape.x,
				rectang2.shape.y,
				rectang2.width,
				rectang2.height);
}
#endif
