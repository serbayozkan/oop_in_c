/*
 * shape.h
 *
 *  Created on: Mar 30, 2020
 *      Author: serbay.ozkan
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <stdint.h>

struct shape_vtable;

/* Shape Attributes */
typedef struct
{
	struct shape_vtable const *vptr;
	int16_t x;
	int16_t y;
}shape_t;

/* Shape's virtual table */
struct shape_vtable
{
	// Virtual Functions
	uint32_t (*area) (shape_t const *const this_p);
	void (*draw) (shape_t const *const this_p);
};

/* Shape's interface */
void shape_ctor(shape_t *const this_p, int16_t x, int16_t y);
void shape_move_by(shape_t *const this_p, int16_t x, int16_t y);

int16_t shape_get_x(shape_t *const this_p);
int16_t shape_get_y(shape_t *const this_p);

static inline uint32_t shape_area(shape_t const *const this_p)
{
	return (*this_p->vptr->area)(this_p);
}

static inline void shape_draw(shape_t const *const this_p)
{
	(*this_p->vptr->draw)(this_p);
}

#endif /* SHAPE_H_ */
