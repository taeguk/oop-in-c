#ifndef __BASE_INHERIT_H__

struct base;

enum {
	BASE_BASE_VOFFSET = 0
};

enum { 
	/* v-table indexes */
	V_WHO_AM_I = BASE_BASE_VOFFSET,
		
	/* v-table length */
	BASE_V_LENGTH
};

#define BASE_USE_V_TABLE

void base_register_v_table (struct base *obj, void (**v_table)(void));

#endif
