#ifndef __BASE_H__
#define __BASE_H__

struct base;

/* for creation and elimination of object */
struct base* base_new (void);
void base_delete (struct base *obj);

/* public functions */
int base_get_bval (struct base *obj);
void base_set_bval (struct base *obj, int bval);

/* virtual functions */
void base_who_am_i (struct base *obj);

#endif
