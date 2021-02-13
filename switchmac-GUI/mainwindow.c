#include "mainwindow.h"

static GtkWidget *list_interfaces = NULL;

void main_window(){
    GtkWidget *win = NULL;
    GtkWidget *btn_reload = NULL;
    GtkWidget *btn_random = NULL;
    GtkWidget *btn_change = NULL;
    GtkWidget *check_on_rand = NULL;
    GtkWidget *vbox = NULL;
    GtkWidget *hbox_lab = NULL;
    GtkWidget *hbox_combo_btn = NULL;
    GtkWidget *lab_name_interface = NULL;

    win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(win), "Switchmac-GUI");

    vbox = gtk_vbox_new(false, 0);
    gtk_container_add(GTK_CONTAINER(win), vbox);

    hbox_lab = gtk_hbox_new(false, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox_lab, false, false, 0);

    lab_name_interface = gtk_label_new("Interfaces");
    gtk_box_pack_start(GTK_BOX(hbox_lab), lab_name_interface, false, false, 0);

    hbox_combo_btn = gtk_hbox_new(false, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox_combo_btn, false, false, 0);

    list_interfaces = gtk_combo_box_new_text();

    gtk_container_add(GTK_CONTAINER(hbox_combo_btn), list_interfaces);

    btn_reload = gtk_button_new();
    gtk_box_pack_start(GTK_BOX(hbox_combo_btn), btn_reload, false, false, 2);

    check_on_rand = gtk_check_button_new_with_label("Random");
    gtk_container_add(GTK_CONTAINER(vbox), check_on_rand);

    gtk_widget_show_all(win);
    g_signal_connect(G_OBJECT(win), "destroy", GTK_SIGNAL_FUNC(gtk_main_quit), NULL);
}
