/*
 * editarUsuario.c
 *
 *  Created on: 19/03/2014
 *      Author: robson
 */

int editarUsuario(){
	GtkWidget  *window;
    GtkBuilder *builder;
    GtkTreeView *view;

    int argc;
    char **argv;

    gtk_init (&argc, &argv);

    builder = gtk_builder_new ();
    gtk_builder_add_from_file (builder, "editarUsuario.glade", NULL);

    window = GTK_WIDGET (gtk_builder_get_object (builder, "wEditarUsuario"));
    view = GTK_TREE_VIEW (gtk_builder_get_object (builder, "tvEditarUsuario"));

    gtk_builder_connect_signals (builder, NULL);

    //g_object_unref(builder);

    //gtk_tree_view_set_model(view,GTK_TREE_MODEL(create_and_fill_model()));
    editarUsuarioDados(view);

    gtk_widget_show (window);
    gtk_main ();
    return 0;
}
