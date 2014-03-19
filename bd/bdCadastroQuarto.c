/*
 * bdCadastroQuarto.c
 *
 *  Created on: 10/03/2014
 *      Author: robson
 */

#include <stdio.h>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>
#include <string.h>
#ifndef CONEXAO_H
#define CONEXAO_H

PGresult *result;

void cadastrarQuartoBanco(int nQuarto,int tipoQuarto,int ativo,char *diaria){

	verificaConexao();

	char querry[200];

	sprintf(querry,"INSERT INTO quarto VALUES (%d,%d, '0', '%d', %s)",nQuarto,tipoQuarto,ativo,diaria);
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

#endif
