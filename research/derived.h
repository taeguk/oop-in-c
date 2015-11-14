#ifndef __DERIVED_H__
#define __DERIVED_H__

#include "base.h"

struct derived;

/* for creation and elimination of object */
struct derived* derived_new (void);
void derived_delete (struct derived *obj);

/* public functions */
int derived_get_val (struct derived *obj);
void derived_set_val (struct derived *obj, int val);

/* type casting with base */
struct base* derived_to_base (struct derived *obj);
struct derived* derived_from_base (struct base *obj);

/* wrapping functions to inheritance of base */
int derived_get_bval (struct derived *obj);
void derived_set_bval (struct derived *obj, int bval);

/* overriding virtual functions of base */
void derived_who_am_i (struct derived *obj);

#endif
