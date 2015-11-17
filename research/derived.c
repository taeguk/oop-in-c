#include "derived.h"
#include "derived_inherit.h"
#include "base.h"
#include "base_inherit.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "bool.h"

struct derived {
	/* v-table */
#ifdef DERIVED_USE_V_TABLE
	void (**v_table)(void);
#endif
	
	/* inheritances */
	struct base *base;
	// multiple inheritances are okay :)

	/* private member variables */
	int val;
};

/* class variable */
static int derived_class_variable;

/* v-tables and initializing v-tables */
#ifdef DERIVED_USE_V_TABLE
static bool derived_v_table_inited = false;
static void (*derived_v_table[DERIVED_V_LENGTH])(void);
static void derived_init_v_table (void);
#endif

/* constructor and destructor */
static void derived_constructor (struct derived *obj);
static void derived_destructor (struct derived *obj);

/* private functions */
static void derived_private_function (struct derived *obj);

/* real functions of virtual functions */
static void derived_real_who_am_i (void);

struct derived* derived_new (void)
{
	struct derived *obj = malloc (sizeof(struct derived));
	obj->base = base_new ();
#ifdef DERIVED_USE_V_TABLE
	if (!derived_v_table_inited)
		derived_init_v_table ();
	derived_register_v_table (obj, derived_v_table);
#endif
	derived_constructor (obj);
	return obj;
}

void derived_delete (struct derived *obj)
{
	base_delete (obj->base);
	derived_destructor (obj);
	free (obj);
}

#ifdef DERIVED_USE_V_TABLE
static void derived_init_v_table (void)
{
	derived_v_table_inited = true;

	derived_v_table[BASE_V_WHO_AM_I] = 
		(void(*)(void)) &derived_real_who_am_i;
}
#endif

void derived_register_v_table (struct derived *obj, void (**v_table)(void))
{
	obj->v_table = v_table;
	base_register_v_table (obj->base, v_table + BASE_VSTART + 1);
}

static void derived_constructor (struct derived *obj)
{
	printf ("derived_constructor!!\n");
	obj->val = 10;
}

static void derived_destructor (struct derived *obj)
{
	printf ("derived_destructor!!\n");
}

int derived_get_val (struct derived *obj)
{
	return obj->val;
}

void derived_set_val (struct derived *obj, int val)
{
	obj->val = val;
}

static void derived_private_function (struct derived *obj)
{
	printf ("derived_private_function!!\n");
}

struct base* derived_to_base (struct derived *obj)
{
	return obj->base;
}

struct derived* derived_from_base (struct base *obj)
{
	return (struct derived*) 
			((char*) obj - offsetof (struct derived, base));
}

int derived_get_bval (struct derived *obj)
{
	return base_get_bval (obj->base);
}

void derived_set_bval (struct derived *obj, int bval)
{
	base_set_bval (obj->base, bval);
}

static void derived_real_who_am_i (void)
{
	printf ("I'm derived!\n");
}

void derived_who_am_i (struct derived *obj)
{
	((void(*)(void)) obj->v_table[BASE_V_WHO_AM_I]) ();
}
