#include <stdio.h>
#include <libpq-fe.h>

PGconn *conn = NULL;

int ExecutaComando(const char *, PGresult **);

void verificaConexao(){
	    /*realiza a conexão*/
	
	    conn = PQconnectdb("host=localhost dbname=sigho user=postgres password=123456");
	    if(PQstatus(conn) != CONNECTION_OK){
	        printf("Falha na conexão. Erro: %s", PQerrorMessage(conn));
	        PQfinish(conn);
	    }
	

}

int ExecutaComando(const char *comando, PGresult **ptr_resultado) {
	PGresult *resultado_local;

	resultado_local = PQexec(conn, comando);
	if (resultado_local) {
		*ptr_resultado = resultado_local;
		return 1;
	}
	return 0;
}
