#ifndef __DERIVED_INHERIT_H__

enum {
	/* v-table indexes */

	/* v-table length */
	DERIVED_V_LENGTH
}

#if (DERIVED_V_LENGTH != 0)
#define DERIVED_USE_V_TABLE
#endif

#endif
