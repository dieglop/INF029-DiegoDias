#ifndef PROJETOESCOLA_ALUNO_H
#define PROJETOESCOLA_ALUNO_H

#define mat_tam 6
#define nome_tam 30
#define data_tam 8
#define cpf_tam 11

typedef struct {
  char matricula[mat_tam];
  char nome[nome_tam];
  char sexo;
  char dataNasc[data_tam];
  char CPF[cpf_tam];
} Aluno;

extern Aluno alunos[3];
extern int i, opA;

int menuAluno();
void cadastrarAluno(Aluno a);
void listarAluno();
void excluirAluno();

#endif