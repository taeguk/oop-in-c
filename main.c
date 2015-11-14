#include <stdio.h>
#include "base.h"
#include "derived.h"

int main (void)
{
	struct base *base;
	struct derived *derived;

	printf ("\n---- base test ----\n");

	base = base_new ();

	printf ("base's bval = %d\n", base_get_bval (base));
	base_set_bval (base, 10);
	printf ("base's bval = %d\n", base_get_bval (base));

	printf ("base says...");
	base_

	base_delete (base);

	printf ("\n---- derived test ----\n");

	derived = derived_new ();

	printf ("derived's val = %d\n", derived_get_val (derived));
	derived_set_val (derived, 20);
	printf ("derived's val = %d\n", derived_get_val (derived));

	printf ("derived's bval = %d\n", derived_get_bval (derived));
	derived_set_val (derived, 10);
	printf ("derived's bval = %d\n", derived_get_bval (derived));

	base = derived_
	
	derived_delete (b);

	return 0;
}
