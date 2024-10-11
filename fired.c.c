#include <stdio.h> //comunição com o usuário 
#include <stdlib.h> //alocação de espaço em memória
#include <locale.h> //alocação de texto por região
#include <string.h> //responsavel por cuidar das strings

int registro()
{   
 char arquivo[40];
 char cpf[40];
 char nome[40];
 char sobrenome [40];
 char cargo[40];
 
 printf("Digite o CPF a ser cadastrado: ");
 scanf("%s", cpf);
 
 strcpy (arquivo, cpf); //copia os valores de uma string
 
 FILE *file; //cria o arquivo
 file = fopen(arquivo, "w"); //cria o arquivo
 fprintf(file,cpf); //salva op valor da variavel
 fclose(file); //fecha o arquivo
 file = fopen(arquivo,"a");
 fprintf(file,",");
 fclose(file);
 
 printf("Digite o nome a ser cadastrado: ");
 scanf("%s",nome);
 file = fopen(arquivo,"a");
 fprintf(file,nome);
 fclose(file);
 file = fopen(arquivo,"a");
 fprintf(file,",");
 fclose(file);
 
 printf("Digite o sobrenome a ser cadastrado: ");
 scanf("%s",sobrenome);
 file = fopen(arquivo,"a");
 fprintf(file,sobrenome);
 fclose(file);
 file = fopen(arquivo,"a");
 fprintf(file,",");
 fclose(file);
 
 printf("Digite o cargo a ser cadastrado: ");
 scanf("%s",cargo);
 file = fopen(arquivo,"a");
 fprintf(file,cargo);
 fclose(file);
 file = fopen(arquivo,"a");
 fprintf(file,",");
 fclose(file);
 
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");
	char cpf[40];
	char conteudo[200];
	
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("Não foi possivel localizar o arquivo! \n");
	}
	
    while(fgets(conteudo, 200, file) !=NULL)
    
    {
    	printf("\nEssas são as informações do usuário: ");
    	printf("%s",conteudo);
    	printf("\n\n");
	}
    system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
    if (file == NULL)
    {
    	printf("Usuário não encontrado no sistema! \n");
    	system("pause");
	}
	
}


int main()
{

	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
 {
     	
    system("cls");

	setlocale(LC_ALL, "portuguese");
	
       printf("### Lista para futuras demissões ###\n\n");
       printf("escolha a opção desejada do menu\n\n");
       printf("\t1 - registrar nomes\n");
       printf("\t2 - consultar nomes\n");
       printf("\t3 - deletar nomes\n"); 
       printf("made by gabe\n"); 
   	   printf("opção: ");         //fim do menu
    
    scanf("%d", &opcao); //armazenando a escolha do usuário
    
    system("cls");
    
    switch (opcao)
    
    {
		case 1:
    	registro();
        break;
        
        case 2:
        consulta();
        break;
        
        case 3:
        deletar();
        break;
        
        default:
        printf("Opção não está disponivel\n");
        system("pause");
        break;    
        
	}	
    
  }
}


 
