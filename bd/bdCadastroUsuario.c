/*
 * bdCadastroUsuario.c
 *
 *  Created on: 10/03/2014
 *      Author: robson
 */
#include <stdio.h>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>
#include <string.h>
#include "conexao.h"

PGresult *result;
int i;
void cadastrarUsuarioBanco(char* nome,char *cpf,int telefone,char* endereco,char *email,int ativo){

	verificaConexao();

	result = PQexec(conn,"Select id from cliente");
	if(PQntuples(result) == 0) i=PQntuples(result);
	else i=atol(PQgetvalue(result, PQntuples(result)-1, 0))+1;

	PQclear(result);

	char querry[200];
	sprintf(querry,"INSERT INTO cliente VALUES ('%d','%s', '%s', '%d', '%s', '%s', '%d')",i,nome,cpf,telefone,endereco,email,ativo);

	result = PQexec(conn, querry);

	if(!result)
	{
		printf("Erro executando comando. ");
		//return 0;
	}
	else
		PQclear(result);
		//printf("Usuario adicionado com sucesso!");

		if(conn != NULL)
			PQfinish(conn);

		//return 1;

}


