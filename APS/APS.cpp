#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*
 Versão: 1.0
 Programa de envio de mensagens pela internet de uma empresa através de login.
*/

FILE *arquivo;
FILE *arquivo2;

	typedef struct{
		char login[10];
		char senha[10];
	}usuario;
		usuario login, comparar;
	
	typedef struct{
		char ip[15];
		char assunto[50];
		char msg[100];
	}mensagem;
		mensagem msg;
		
void ler_arquivo();
void verificar_login();
void criar_arquivo2();
void enviar();
void listar();
void apagar();
void limpar();
int main () {
	setlocale(LC_ALL, "");
	
	ler_arquivo();
	
	/*
	admin admin
	teste teste
	unifg 1234
	cco cco123
	gti gitabc
	*/
	
	
	printf("PROGRAMA DE MENSAGENS\n\n");
	fflush(stdin);
	printf("USUARIOS E SENHAS:\n\n");
	printf("admin\t admin\nteste\tteste\nunifg\t1234\ncco\tcco123\ngti\tgitabc\n\n");
	printf("\tLogin: ");
	gets(comparar.login);
	fflush(stdin);
	printf("\tSenha: ");
	gets(comparar.senha);
	fflush(stdin);

	verificar_login();
	
	if(strcmp(comparar.login, login.login)==0 && strcmp(comparar.senha, login.senha)==0){
		limpar();
		criar_arquivo2();
		char op;
		do{
			limpar();
			printf("### MENU ###\n\n");
			printf("1. Enviar mensagem\n");
			printf("2. Listar mensagens enviadas\n");
			printf("3. Apagar arquivo de mensagens enviadas\n");
			printf("0. Sair\n\n");
			printf("Escolha uma opção: ");
			scanf("%d", &op);
			
			switch(op){
				case 1:
					limpar();
					enviar();
					limpar();
					break;	
				case 2:
					limpar();
					listar();
					break;
				case 3:
					limpar();
					apagar();
					break;		
				case 0:
					limpar();
					fclose(arquivo2);
					break;
				default:
					limpar();
					printf("\n\nOpção inválida!\n\n");
					system("pause");
					break;
					
			}
			
		} while (op != 0);
	}
	else{
		printf("SENHA OU USUÁRIO INVALIDO!\n");
}
		

getchar();
return 0;
}

void verificar_login(){
	rewind(arquivo);
	fread(&login,sizeof(usuario),1,arquivo);
	
	while(feof(arquivo)==0){
	if(strcmp(comparar.login, login.login)==0 && strcmp(comparar.senha, login.senha)==0){
		break;
	}
	else{
		fread(&login,sizeof(usuario),1,arquivo);
	}
}
}

void enviar(){
	limpar();
	fflush(stdin);
	printf("ENVIO DE MENSAGENS");
	printf("\n\n\tIP.....: ");
	gets(msg.ip);
	fflush(stdin);
	printf("\tASSUNTO: ");
	gets(msg.assunto);
	fflush(stdin);
	printf("\tMENSAGEM: ");
	gets(msg.msg);
	fflush(stdin);
					
	fseek(arquivo2, 0, SEEK_END);
	fwrite(&msg, sizeof(mensagem), 1, arquivo2);
}

void listar(){
	limpar();
	printf("LISTA DE MENSAGENS ENVIADAS\n\n");
	rewind(arquivo2);
	fread(&msg, sizeof(mensagem), 1, arquivo2);
					
	while(feof(arquivo2)==0){
	printf("IP.....: %s\nASSUNTO: %s\nMENSAGEM: %s\n\n", msg.ip,msg.assunto,msg.msg);
	fread(&msg, sizeof(mensagem), 1, arquivo2);
	}
	getchar();
	printf("Pressione qualquer tecla para continuar...");
	getchar();

}

void ler_arquivo(){
	arquivo = fopen("usuarios.dat", "rb");
		if(arquivo == NULL){
			printf("\nArquivo não existe!\n");
		}
}

void criar_arquivo2(){
	arquivo2 = fopen("mensagens.dat", "r+b");
		if(arquivo2 == NULL){
			arquivo2 = fopen("mensagens.dat", "w+b");
		}
}

void apagar(){
	limpar();
	printf("EXCLUIR BACKUP DE MENSAGENS\n\n");
	getchar();
	fclose(arquivo2);
	remove("mensagens.dat");
	printf("Pressione qualquer tecla para continuar...");
    getchar();
    criar_arquivo2();
}

void limpar(){
	int i;
	
	for(i = 1; i <= 30; i++  ){
		printf("\n");
	}
	
}


