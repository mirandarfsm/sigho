/*
 * bdEditarUsuario.c
 *
 *  Created on: 19/03/2014
 *      Author: robson
 */

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <postgresql/libpq-fe.h>
#include <string.h>
#ifndef CONEXAO_H
#define CONEXAO_H

PGresult *result;

enum{
  COL_NAME = 0,
  COL_CPF,
  COL_TEL,
  COL_END,
  COL_EMAIL,
  COL_ATIVO,
  NUM_COLS
} ;

gchar *title[] = { "Nome", "Cpf", "Telefone", "Endereco","Email", "Ativo" };

void editarUsuarioDados(GtkTreeView * view){
    GtkTreeStore *model;
    GtkTreeIter toplevel;
    GtkTreeViewColumn *column;
    GtkTreeSelection *selection;
    GtkCellRenderer *renderer;
    guint i;
    int j,cont;

    model = gtk_tree_store_new (NUM_COLS, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING);

    verificaConexao();

    result = PQexec(conn,"Select * from cliente");
    cont=PQntuples(result);

    for(j=0;j<cont;i++) {
		gtk_tree_store_append (model, &toplevel, NULL);
		gtk_tree_store_set(model, &toplevel, COL_NAME, PQgetvalue(result, j, 1), COL_CPF, PQgetvalue(result, j, 2),COL_TEL, PQgetvalue(result, j, 3),COL_END, PQgetvalue(result, j, 4),COL_EMAIL, PQgetvalue(result, j, 5),COL_ATIVO, PQgetvalue(result, j, 6), -1);
    }

	if (conn != NULL)
		PQclear(result);
		PQfinish(conn);

    gtk_tree_view_set_model(view, GTK_TREE_MODEL(model));

    selection = gtk_tree_view_get_selection(view);

    for (i = 0; i < NUM_COLS; i++) {

        renderer = gtk_cell_renderer_text_new ();

        column = gtk_tree_view_column_new_with_attributes (title[i], renderer,"text",i,NULL);

        gtk_tree_view_append_column (view, column);

    }

}

#endif
