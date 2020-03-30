/*
 * User need to initialize each instance with the constructor function
 * this_p pointer acts like this pointer in c++
 * Since this keyword is specified in cpp, this_p is used like this
 */

#include <stdio.h>

#include "shape.h"

#define ENABLE_THIS_FILE  ( 0 )

#if ENABLE_THIS_FILE
/*
 * Constructor Imp.
 */
void shape_ctor_(shape_t *const this_p, int16_t x, int16_t y)
{
	this_p->x = x;
	this_p->y = y;
}

/*
 * Move-By Operation Imp.
 */
void shape_move_by_(shape_t *const this_p, int16_t x, int16_t y)
{
	this_p->x += x;
	this_p->y += y;
}

/*
 * Getter Method Imp.
 */
int16_t shape_get_x_(shape_t *const this_p)
{
	return this_p->x;
}

/*
 * Getter Method Imp.
 */
int16_t shape_get_y_(shape_t *const this_p)
{
	return this_p->y;
}

/*
 * Main Program
 */

int main(void)
{
	shape_t shape1, shape2;

	// Constructor Inits.
	shape_ctor_(&shape1, 10, 20);
	shape_ctor_(&shape2, 30, 40);

	// Move-by shape objects
	shape_move_by_(&shape1, 10, 10);
	shape_move_by_(&shape2, 20, 20);

	printf("shape1 x: %d, y: %d\n", shape_get_x_(&shape1), shape_get_y_(&shape1));
	printf("shape2 x: %d, y: %d\n", shape_get_x_(&shape2), shape_get_y_(&shape2));

	return 0;
}
#endif
