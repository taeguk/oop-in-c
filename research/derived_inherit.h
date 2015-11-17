#ifndef __DERIVED_INHERIT_H__

#include "base_inherit.h"

struct derived;

enum {
	DERIVED_BASE_VOFFSET = 0,
	DERIVED_DERIVED_VOFFSET = BASE_V_LENGTH
};

enum {
	/* v-table indexes */

	/* v-table length */
	DERIVED_V_LENGTH = BASE_V_LENGTH
}

#define DERIVED_USE_V_TABLE

void derived_register_v_table (struct derived *obj, void (**v_table)(void) );

#endif
