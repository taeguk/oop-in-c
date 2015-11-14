#ifndef __BASE_INHERIT_H__

enum {
	/* v-table indexes */
	BASE_V_WHO_AM_I,

	/* v-table length */
	BASE_V_LENGTH
}

#if (BASE_V_LENGTH != 0)
#define BASE_USE_V_TABLE
#endif

#endif
