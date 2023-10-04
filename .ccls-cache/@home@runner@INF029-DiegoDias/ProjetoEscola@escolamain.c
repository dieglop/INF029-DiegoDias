#include <stdio.h>
#include "Aluno/Aluno.h"
#include "Professor/Professor.h"
#include "Disciplina/Disciplina.h"
#define tam 3

int main(void){
	int op, op2, sair;
	Aluno a;
	

	while(!sair){
		sair = 0;
		printf("Informe a opcao que deseja: \n\n");
		printf("0 - Sair\n");
		printf("1 - Aluno\n");
		printf("2 - Professor\n");
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
					printf("1 - Cadastrar aluno");
					scanf("%d", &op2);
					switch(op2){
						case 0:
							sair = 1;
							break;
						case 1:
							
							printf("Informe o nome do aluno: ");
							fgets(a.nome,nome_tam,stdin);
					}
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

