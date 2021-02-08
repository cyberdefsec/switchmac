#include "mainwindow.h"

LISTDEVICE *get_interfaces(void){
    LISTDEVICE *tmp = NULL;
    if((tmp = (LISTDEVICE*)malloc(sizeof(LISTDEVICE))) != NULL){
        strcpy(tmp->name, "aleks");
        tmp->index = 0;
        tmp->next = NULL;
        return tmp;
    }
    return NULL;
}

void main_window(){
    GtkWidget *win = NULL;
    GtkWidget *list_interfaces = NULL;
    GtkWidget *btn_reload = NULL;
    GtkWidget *vbox = NULL;
    GtkWidget *hbox_lab = NULL;
    GtkWidget *hbox_combo_btn = NULL;
    GtkWidget *lab_name_interface = NULL;
    LISTDEVICE *list_device = NULL;
    GtkWidget *btn_image = gtk_image_new_from_file("reload.png");
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
    list_device = get_interfaces();
    gtk_combo_box_append_text(GTK_COMBO_BOX(list_interfaces), list_device->name);
    gtk_combo_box_set_active(GTK_COMBO_BOX(list_interfaces), list_device->index);
    gtk_container_add(GTK_CONTAINER(hbox_combo_btn), list_interfaces);

    btn_reload = gtk_button_new();
    gtk_button_set_image(GTK_BUTTON(btn_reload), btn_image);
    gtk_box_pack_start(GTK_BOX(hbox_combo_btn), btn_reload, false, false, 2);

    gtk_widget_show_all(win);
    g_signal_connect(G_OBJECT(win), "destroy", GTK_SIGNAL_FUNC(gtk_main_quit), NULL);
}
