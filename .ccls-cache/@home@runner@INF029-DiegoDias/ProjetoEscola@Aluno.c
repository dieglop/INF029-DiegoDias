#include <stdio.h>
#define mat_tam 6
#define nome_tam 30
#define data_tam 8
#define cpf_tam 11

int l, op;

typedef struct {
  char matricula[mat_tam];
  char nome[nome_tam];
  char sexo;
  char dataNasc[data_tam];
  char CPF[cpf_tam];
} Aluno;

Aluno alunos[3];

int menuAluno(){
	printf("");
	printf("");
	scanf("%d", &op);
	return op;
}

void cadastrarAluno(Aluno a) {
  alunos[l].matricula[mat_tam] = a.matricula[mat_tam];
  alunos[l].nome[nome_tam] = a.nome[nome_tam];
  alunos[l].sexo = a.sexo;
  alunos[l].dataNasc[data_tam] = a.dataNasc[data_tam];
  alunos[l].CPF[cpf_tam] = a.CPF[cpf_tam];
}

void listarAluno() {}

void excluirAluno() {}