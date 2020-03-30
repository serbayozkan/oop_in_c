/*
 * shape.c
 *
 *  Created on: Mar 30, 2020
 *      Author: serbay.ozkan
 */

#include <assert.h>

#include "shape.h"

static uint32_t shape_area_(shape_t const * const this_p);
static void shape_draw_(shape_t const * const this_p);

void shape_ctor(shape_t *const this_p, int16_t x, int16_t y)
{
	//Vtable of the shape class

	static struct shape_vtable const vtable = {
			&shape_area_,
			&shape_draw_
	};

	this_p->vptr = &vtable;

	this_p->x = x;
	this_p->y = y;
}

/*
 * Getter Method Imp.
 */
int16_t shape_get_x(shape_t *const this_p)
{
	return this_p->x;
}

/*
 * Getter Method Imp.
 */
int16_t shape_get_y(shape_t *const this_p)
{
	return this_p->y;
}

void shape_move_by(shape_t *const this_p, int16_t x, int16_t y)
{
	this_p->x += x;
	this_p->y += y;
}

/* Shape class implementations of its virtual functions... */
static uint32_t shape_area_(shape_t const * const this_p)
{
	assert(0); /* purely-virtual function should never be called */
	return 0U; /* to avoid compiler warnings */
}

static void shape_draw_(shape_t const * const this_p)
{
	assert(0); /* purely-virtual function should never be called */
}
