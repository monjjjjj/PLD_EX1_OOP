#include <stdio.h>

#include "Shapes.h"
#include "Shapes.r"
#include "new.h"
#include "new.r"

static void *Circle_ctor(void *_self, va_list *app)
{
    struct Circle *self = ((struct Class*) Point) -> ctor(_self,app);
    self->rad = va_arg(*app, int);
    return _self;
}

static void Circle_draw(const void *_self)
{
    const struct Circle *self = _self;

    printf("Circle at %d, %d rad %d\n", self -> _.x, self -> _.y, self->rad);
}

static const struct Class _Circle = {
    sizeof(struct Circle),
    Circle_ctor,
    0,
    Circle_draw
};

const void *Circle = &_Circle;

static void *Rectangle_ctor(void *_self, va_list *app)
{
    struct Rectangle *self = _self;

    self->Point = va_arg(*app, struct Point*);
    self->width = va_arg(*app, int);
    self->length = va_arg(*app, int);
     
    return self;
}

static void Rectangle_draw(const void *_self)
{
    const struct Rectangle *self = _self;

    printf("Rectangle at %d, %d width %d length %d\n", self->Point->x, self->Point->y, self->width, self->length);
}

static const struct Class _Rectangle = {
    sizeof(struct Rectangle),
    Rectangle_ctor,
    0,
    Rectangle_draw
};

const void *Rectangle = &_Rectangle;

void *pt(void *_self)
{
    struct Rectangle *self = _self;
    return self -> Point;
}




