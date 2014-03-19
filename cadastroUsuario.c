//gcc -Wall -g -o tutorial main.c `pkg-config --cflags --libs gtk+-2.0` -export-dynamic

#include <stdlib.h>
#include <gtk/gtk.h>
#include"bd/bdCadastroUsuario.c"

GtkBuilder      *builder;

void on_wCadastroUsuario_destroy(GtkObject *object, gpointer user_data){

}

void on_btCancelarUsuario_clicked(GtkObject *object, gpointer user_data){
	on_wCadastroUsuario_destroy(object,user_data);
}

void on_btCadastrarUsuario_clicked(GtkObject *object, gpointer user_data){
	char *nome,*cpf,*endereco,*email;
	int telefone,ativo=0;

	//pegando dados
	nome = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder,"etNome")));
	cpf = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder,"etCpf")));
	telefone = atol(gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder,"etTelefone"))));
	endereco = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder,"etEndereco")));
	email = gtk_entry_get_text(GTK_ENTRY(gtk_builder_get_object(builder,"etEmail")));
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON((gtk_builder_get_object(builder,"cbAtivo"))))) ativo=1;

	//Salvando em BD
	cadastrarUsuarioBanco(nome,cpf,telefone,endereco,email,ativo);

	//zerando dados
	gtk_entry_set_text(GTK_ENTRY(GTK_ENTRY(gtk_builder_get_object(builder,"etNome"))), "");
	gtk_entry_set_text(GTK_ENTRY(GTK_ENTRY(gtk_builder_get_object(builder,"etCpf"))), "");
	gtk_entry_set_text(GTK_ENTRY(GTK_ENTRY(gtk_builder_get_object(builder,"etTelefone"))), "");
	gtk_entry_set_text(GTK_ENTRY(GTK_ENTRY(gtk_builder_get_object(builder,"etEndereco"))), "");
	gtk_entry_set_text(GTK_ENTRY(GTK_ENTRY(gtk_builder_get_object(builder,"etEmail"))), "");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"cbAtivo")),0);
}
 
int cadastroUsuario(){
	int argc;
	char *argv;

    GtkWidget       *window;
 
    gtk_init (&argc, &argv);
 
    builder = gtk_builder_new ();
    gtk_builder_add_from_file (builder, "cadastroUsuario.glade", NULL); //Carrega as informações do projeto glade para o GtkBuilder
    window = GTK_WIDGET(gtk_builder_get_object (builder, "wCadastroUsuario"));   //Retorna o objeto Window, para mostrá-lo mais tarde
    gtk_builder_connect_signals (builder, NULL); //Conecta todos os eventos dentro do projeto do glade.
 
    //g_object_unref (G_OBJECT (builder)); //Exclui o GtkBuilder, pois não iremos mais usá-lo nesse exemplo.
 
    gtk_widget_show_all(window);   //Mostra a janela com seus objetos
    gtk_main ();
 
    return 0;
}
