#include <stdio.h>
#define tam 3

int main(void){
	int op;
	
	typedef struct {
		char matricula[20];
		char nome[30];
		char sexo;
		char dataNasc[8];
		char CPF[11];
	}Aluno;

	printf("Informe a opcao que deseja: \n\n");
	printf("0 - Sair\n");
	printf("1 - Aluno\n");
	printf("2 - Porfessor\n");
	printf("3 - Disciplina\n");
	scanf("%d", &op);
	switch(op){
		case 0:
			
		break;
		case 1: 
			printf("\nMódulo Aluno\n\n");
			printf("");
		break;
		case 2:
			printf("\nMódulo Professor\n\n");
			printf("");
		break;
		case 3:
			printf("\nMódulo Disciplina\n\n");
			printf("");
		break;
	}
	
	
	return 0;
}