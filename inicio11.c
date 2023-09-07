#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<locale.h>

typedef struct cliente CLIENTE;
struct cliente{
	char cod_cliente;
	char nome[30];
	char valor_venda[12];
	char score[15];
};

void cabecalho();

main(){
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	/*
	(1) cadastrar cliente,
	(2) importar arquivo txt,
	(3) listar clientes,
	(4) Sair;
	*/
	do{
		cabecalho();
		printf("1 - Cadastrar cliente\n");
		printf("2 - Importar arquivo txt\n");
		printf("3 - Listar clientes\n");
		printf("4 - Sair\n\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
				//Cadastrar cliente
				inputData();
			break;
			
			case 2:
				//Importar arquivo
			break;
			
			case 3:
				//listar clientes
			break;
			
			case 4:
				//Sainr
			break;

			default:
				printf("Opcao inválida!\n");
				getch();
			break;
		}
	}while(opcao != 4);
}
void cabecalho(){
	system("cls");
	printf("\n-------------------------------------------------\n");
	printf("CADASTRO DE CLIENTE");
	printf("\n-------------------------------------------------\n");

}
void inputData(){
	FILE *arquivo;
	CLIENTE cli;
	
	arquivo = fopen("C:/Users/55379/Desktop/adsa.txt", "ab");
	
	if(arquivo == NULL){
		printf("Problemas na abertura do arquivo!\n");
	}
	else{
		do{
			cabecalho();
			fflush(stdin);
			printf("Digite o codigo do cliente:");
			gets(cli.cod_cliente);
			
			//fflush(stdin);
			printf("\nDigite o nome:");
			gets(cli.nome);
			
			//fflush(stdin);
			printf("Scorre : 0");
			//gets(cli.valor_venda(0));
			fwrite(&cli, sizeof(CLIENTE), 1, arquivo);
			
			printf("Deseja continuar(s/n)?");
					
		}while(getche() == 's');
		fclose(arquivo);
	}
}
