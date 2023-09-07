#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<locale.h>

typedef struct{
	char cod_cliente[5];
	char nome[30];
	char valor_venda[12];
	char score[15];
}Cliente;

void ListarClientes(Cliente *cliente, int contador)
{
	
	int quantidade = 0;
	
	for(int c = 0; c < contador; c++)
	{
		quantidade ++;
	//	if(strcmp(cliente[c].cod_cliente,arquivo)==0))	
		printf("%iº -  %s \n", c + 1, cliente[c].cod_cliente);
		printf("%s - \n", cliente[c].nome);
		
	}
	if(quantidade == 0){
		printf("Nenhum registro encontrado");
	}
	else{
		printf("Total de registros encontrados %i", quantidade);
	}
}

void ReceberInfCliente(Cliente *cliente, int contador)
{

	printf("Digite o codigo do cliente:");
	scanf("%s", &cliente[contador - 1].cod_cliente);
	//fflush(stdin);
	
	printf("\nDigite o nome do cliente:");
	scanf("%s", &cliente[contador - 1].nome);
	//fflush(stdin);
	
	//printf("O valor da venda inicial é 0 : ");
	//scanf("%s", cliente[contador - 1].valor_venda);
	//fflush(stdin);
	
	//printf("O valor do Score inicial é : 0" );
	//scanf("%s", cliente[contador - 1].score);
	//fflush(stdin);
}

void AlocaCliente(Cliente ** cliente, int *contador)
{
	*contador = *contador + 1;
	if(*cliente == NULL)
	{
		*cliente = (Cliente *) malloc(sizeof(Cliente)); 
	}
	else
	{	
		printf("realloc\n");
		*cliente = (Cliente *) realloc(*cliente, (*contador)* sizeof(Cliente));
	}
}

void IncluirNovoCliente(Cliente ** cliente, int *contador)
{
	AlocaCliente(cliente,contador);
	ReceberInfCliente(*cliente, *contador);
}


void lerArquivo(Cliente **cliente, int *contador){
	FILE *arquivo;
	arquivo = fopen("C:/Users/55379/Desktop/cliente.txt","r");
	
	if(arquivo != NULL){
		int linha = 0;
		char dadosLinha [500];
		
		while(!feof(arquivo)){
			char *result = fgets(dadosLinha, 500, arquivo);
			if(result)
			{ 
				int mod = linha %2;
				
				if(mod == 0){
					AlocaCliente(cliente,contador);
					(*cliente)[(*contador)- 1].cod_cliente, dadosLinha;
				}
				else
				{	
					//AlocaCliente(cliente,contador);
					(*cliente)[(*contador)- 1].nome, dadosLinha;
				} 
			}			
		}
	}
		else{
		printf("Nenhum registro encontrado\n");
		system("pause");
	}
}

void SalvarArquivo(Cliente *cliente, int contador){
	
	FILE *arquivo;
	arquivo = fopen("C:/Users/55379/Desktop/cliente.txt","w");
	
	if(arquivo != NULL)
	{
		for(int c = 0; c < contador; c++)
		{
			int result = fprintf(arquivo,"%s\n%s\n", cliente[c].cod_cliente, cliente[c].nome);
			if(result == EOF)
			{
				printf("Não foi possível salvar o arquivo\n");
			}
		}
	}else{
		printf("Nenhum registro encontrado\n");
		system("pause");
	}
}

int  main(){
	setlocale(LC_ALL, "Portuguese");
	int opcao = 0;
	Cliente *cliente = NULL;
	int contador = 0;	
	lerArquivo(&cliente, &contador);	
	do{
		printf("cls\n");
		system("cls");
		printf("Selecione uma opção abaixo:\n");
		printf("1 - Cadastrar cliente\n");
		printf("2 - Importar arquivo txt\n");
		printf("3 - Listar clientes\n");
		printf("4 - Sair\n\n");
		scanf("%i", &opcao);

		switch(opcao){
			case 1:
				//Cadastrar cliente
				IncluirNovoCliente(&cliente,&contador);
			break;
			
			case 2:
				//Importar arquivo
				//ImportarArquivoTxt();
			break;
		
			case 3:
				//listar clientes
				ListarClientes(cliente,contador);
			break;
			
			case 4:
				//Sainr
				printf("Obrigado por usar o sistema");
			break;

			default:
				printf("Opcao inválida!\n");
				getch();
			break;
		}
	}while(opcao != 4);	
	
	SalvarArquivo(cliente,contador);	
	free(cliente);
	system("pause");
	return 0;
}
	
	

