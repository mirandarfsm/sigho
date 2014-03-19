//gcc -Wall -g -o tutorial main.c `pkg-config --cflags --libs gtk+-2.0` -export-dynamic

#include <stdlib.h>
#include <gtk/gtk.h>
#include"bd/bdCadastroQuarto.c"

GtkBuilder      *builder;

void on_wCadastroQuarto_destroy(GtkObject *object, gpointer user_data){
}

void on_btCancelarQuarto_clicked(GtkObject *object, gpointer user_data){
}
void on_btCadastrarQuarto_clicked(GtkObject *object, gpointer user_data){
		int nQuarto,tipoQuarto,ativo=0;
		char* diaria;

		//pegando dados
		nQuarto = atol(gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder,"etNumQuarto"))));
		//Tipo de Quarto
		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"rdSolteiro")))) tipoQuarto = 1;
		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"rdCasal")))) tipoQuarto = 2;
		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"rdTriplo")))) tipoQuarto = 3;

		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"cbAtivo")))) ativo=1;

		diaria = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder,"etDiaria")));

		//Salvando em BD
		cadastrarQuartoBanco(nQuarto,tipoQuarto,ativo,diaria);

		//zerando dados
		gtk_entry_set_text(GTK_ENTRY(GTK_ENTRY(gtk_builder_get_object(builder,"etNumQuarto"))), "");

		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"rdSolteiro")),1);

		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"cbAtivo")),0);

		gtk_entry_set_text(GTK_ENTRY(GTK_ENTRY(gtk_builder_get_object(builder,"etDiaria"))), "");
}


int cadastroQuarto(){
	int argc;
	char *argv;

    GtkWidget       *window;

    gtk_init (&argc, &argv);

    builder = gtk_builder_new ();
    gtk_builder_add_from_file (builder, "cadastroQuarto.glade", NULL); //Carrega as informações do projeto glade para o GtkBuilder
    window = GTK_WIDGET(gtk_builder_get_object (builder, "wCadastroQuarto"));   //Retorna o objeto Window, para mostrá-lo mais tarde
    gtk_builder_connect_signals (builder, NULL); //Conecta todos os eventos dentro do projeto do glade.

    //g_object_unref (G_OBJECT (builder)); //Exclui o GtkBuilder, pois não iremos mais usá-lo nesse exemplo.

    gtk_widget_show_all(window);   //Mostra a janela com seus objetos
    gtk_main ();

    return 0;
}
