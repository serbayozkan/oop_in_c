/*
 * User need to initialize each instance with the constructor function
 * this_p pointer acts like this pointer in c++
 * Since this keyword is specified in cpp, this_p is used like this
 */

#include <stdio.h>

#include "shape.h"

#define ENABLE_THIS_MAIN  ( 0 )

/*
 * Constructor Imp.
 */
void shape_ctor(shape_t *const this_p, int16_t x, int16_t y)
{
	this_p->x = x;
	this_p->y = y;
}

/*
 * Move-By Operation Imp.
 */
void shape_move_by(shape_t *const this_p, int16_t x, int16_t y)
{
	this_p->x += x;
	this_p->y += y;
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

/*
 * Main Program
 */
#if ENABLE_THIS_MAIN
int main(void)
{
	shape_t shape1, shape2;

	// Constructor Inits.
	shape_ctor(&shape1, 10, 20);
	shape_ctor(&shape2, 30, 40);

	// Move-by shape objects
	shape_move_by(&shape1, 10, 10);
	shape_move_by(&shape2, 20, 20);

	printf("shape1 x: %d, y: %d\n", shape_get_x(&shape1), shape_get_y(&shape1));
	printf("shape2 x: %d, y: %d\n", shape_get_x(&shape2), shape_get_y(&shape2));

	return 0;
}
#endif
