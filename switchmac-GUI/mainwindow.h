#include <gtk/gtk.h>
#include <stdbool.h>

#define LEN_DEVICE 32

typedef struct _LISTDEVICE{
    guint index;
    gchar name[LEN_DEVICE];
    struct _LISTDEVICE *next;
} LISTDEVICE;

void main_window(void);

LISTDEVICE *get_interfaces(void);


