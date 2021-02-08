#include <stdlib.h>
#include <gtk/gtk.h>

#include "mainwindow.h"

int main(int argc, char *argv[]){
    gtk_init(&argc, &argv);
    main_window();
    gtk_main();
    return 0;
}
