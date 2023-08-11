#include <stdio.h>
#define tam 3

int main(void){
	int op, op2, sair;
	
	typedef struct {
		char matricula[20];
		char nome[30];
		char sexo;
		char dataNasc[8];
		char CPF[11];
	}Aluno;

	while(!sair){
		sair = 0;
		printf("Informe a opcao que deseja: \n\n");
		printf("0 - Sair\n");
		printf("1 - Aluno\n");
		printf("2 - Porfessor\n");
		printf("3 - Disciplina\n");
		scanf("%d", &op);
		switch(op){
			case 0:
				sair = 1;
			break;
			case 1: 
				while(!sair){
					printf("\nMódulo Aluno\n\n");
					printf("0 - Sair");
					printf("1 - ");
				}
			break;
			case 2:
				while(!sair){
					printf("\nMódulo Professor\n\n");
					printf("0 - Sair");
					printf("1 - ");
				}
			break;
			case 3:
				while(!sair){
					printf("\nMódulo Disciplina\n\n");
					printf("0 - Sair");
					printf("1 - ");
				}
			break;
		}
	}
	
	return 0;
}