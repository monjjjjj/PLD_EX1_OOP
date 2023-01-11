/*
 * new.r
 */
#ifndef	NEW_R
#define	NEW_R

#include <stdlib.h>
#include <stdarg.h>

struct Class {
    size_t size;
    void * (* ctor)(void *self, va_list *app);
    void * (* dtor)(void *self);
    void (* draw)(const void *self);
};

#endif