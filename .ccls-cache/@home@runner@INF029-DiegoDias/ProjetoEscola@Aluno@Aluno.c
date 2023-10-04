#include <stdio.h>
#include "Aluno.h"

Aluno alunos[3];
int i, opA;

int menuAluno(){
	printf("0 - Sair\n");
	printf("1 - Cadastrar aluno\n");
	printf("2 - Listar aluno\n");
	printf("3 - Editar aluno\n");
	printf("4 - Excluir aluno\n");
	scanf("%d", &opA);
	return opA;
}

void cadastrarAluno(Aluno a) {
  alunos[i].matricula[i] = a.matricula[i];
  alunos[i].nome[i] = a.nome[i];
  alunos[i].sexo = a.sexo;
  alunos[i].dataNasc[i] = a.dataNasc[i];
  alunos[i].CPF[i] = a.CPF[i];
}

void listarAluno() {}

void excluirAluno() {}