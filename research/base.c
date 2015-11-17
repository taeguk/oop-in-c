#include "base.h"
#include "base_inherit.h"
#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

struct base {
	/* v-table */
#ifdef BASE_USE_V_TABLE
	void (**v_table)(void);
#endif

	/* inheritances */
		// nothing
	
	/* private member variable */
	int bval;
};

/* class variable */
static int base_class_variable;

/* v-tables and initializing v-tables */
#ifdef BASE_USE_V_TABLE
static bool base_v_table_inited = false;
static void (*base_v_table[BASE_V_LENGTH])(void);
static void base_init_v_table (void);
#endif

/* constructor and destructor */
static void base_constructor (struct base *obj);
static void base_destructor (struct base *obj);

/* private functions */
static void base_private_function (struct base *obj);

/* real functions of virtual functions */
static void base_real_who_am_i (void);

struct base* base_new (void)
{
	struct base *obj = malloc (sizeof(struct base));
	base_base_v_table (obj);
#ifdef BASE_USE_V_TABLE
	if (base_v_table_inited)
		base_init_v_table ();
	base_register_v_table (obj, base_v_table);
#endif
	base_constructor (obj);
	return obj;
}

void base_delete (struct base *obj)
{
	base_destructor (obj);
	free (obj);
}

#ifdef BASE_USE_V_TABLE
static void base_init_v_table (void)
{
	base_v_table[BASE_V_WHO_AM_I] = base_real_who_am_i;
}
#endif

void base_register_v_table (struct base *obj, void (**v_table)(void))
{
	obj->v_table = v_table;
}

static void base_constructor (struct base *obj)
{
	printf ("base_constructor!!\n");
	obj->bval = 5;
}

static void base_destructor (struct base *obj)
{
	printf ("base_destructor!!\n");
}

int base_get_bval (struct base *obj)
{
	return obj->bval;
}

void base_set_bval (struct base *obj, int bval)
{
	obj->bval = bval;
}

static void base_private_function (struct base *obj)
{
	printf ("base_private_function!!\n");
}

static void base_real_who_am_i (void)
{
	printf ("I'm base!\n");
}

void base_who_am_i (struct base *obj)
{
	(((void)(*)(void)) obj->v_table[BASE_V_WHO_AM_I]) ();
}
