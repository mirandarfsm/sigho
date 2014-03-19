/*
 * login.c
 *
 *  Created on: 10/03/2014
 *      Author: robson
 */
#include <gtk/gtk.h>
#include <string.h>
#include "bd/bdLogin.c"
#include "menuPrincipal.c"

GtkBuilder      *builder;

void on_wLogin_destroy (GtkObject *object, gpointer user_data){
    gtk_main_quit ();
}

void on_btLogin_clicked(GtkObject *object, gpointer user_data){
	char *etnome;
	char *etsenha;

	etnome = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder,"etLogin")));
	etsenha = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder,"etSenha")));

	if(verificarSenha(etnome,etsenha)){
		g_print("Logado!");
		menuPrincipal();
		//gtk_widget_destroy(GTK_WIDGET (gtk_builder_get_object (builder, "wLogin")));

	}
	else g_print("Erro!");

}

int main (int argc, char *argv[]){

    GtkWidget       *window;

    gtk_init (&argc, &argv);

    builder = gtk_builder_new ();
    gtk_builder_add_from_file (builder, "login.glade", NULL);
    window = GTK_WIDGET (gtk_builder_get_object (builder, "wLogin"));
    gtk_builder_connect_signals (builder, NULL);

    //g_object_unref (G_OBJECT (builder));

    gtk_widget_show (window);
    gtk_main ();

    return 0;
}
