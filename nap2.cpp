#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <fstream>
#include <locale.h>
#include <math.h>

using namespace std;

struct login {
	char usuario [10];
	char senha [10];
};

void cadastro(){

	struct login acesso;

	system ("cls");    

	ofstream out("login.txt");

	cout << " Insira seu Login \n";
	cout << " login: " ;
	cin >> acesso.usuario;
	cout << " senha: " ;
	cin >> acesso.senha;

	out << acesso.usuario;
	out << acesso.senha;

	out.close();
}

void exit(){
	cout << " encerrando...\n       at� breve...\n\n";
}

void menuprincipal(){

	int op;

	cout << "BEM VINDO AO MENU PRINCIPAL\n";
	cout << "--calculadora de bin�rios--\n convers�o\n";
	cout << "[1]decimal para bin�rio \n[2]brin�rio para decimal \n[3] sair \n";

	switch(op) { //corrigir
	case '1':
		cout << "\n       CONVERS�O:\n";
		cout << " decimal para bin�rio\n";
		cout << " informe um numero: \n";
		int x, i, b[8];
		cin >> x;

		for(i == 0; i <= 7 ; i++) {

			if(x >= 1) {
				b[i] = (x % 2);
				x /= 2;
			} else {
				b[i] = 0;
			}
		}

		for(i = 7; i >= 0; i--) {
			cout << b[i];
		}
		
		break;
		
	case '2': 
		char bin[100];
        unsigned long dec = 0;
        int n = 0;
        int s;
		cout << "\n         CONVERS�O:\n";
		cout << "     bin�rio para decimal\n";
		cout << "..............................\n\n";
		cout << " informe um numero: \n";
		fgets( bin, sizeof(bin), stdin);
        s = strlen( bin );
    while( s-- ) {
        if( bin[s] == '0' || bin[s] == '1' ) {
            dec = dec + pow(2, i++) * (bin[s] - '0');
        }
    };
    printf("\nconversao em decimal: \t %u\n", dec);
		break;
		
	}
}

void fazerLogin(){
	
	struct login acesso;

	cout << "Usu�rio: ";
	cin >> acesso.usuario;

	cout << "Senha: ";
	cin >> acesso.senha;

	ifstream fin;
	fin.open("login.txt");

	char verificaUsuario[100]; //array

	while(fin) {

		fin.getline(verificaUsuario, 100); // l� a linha do arquivo

	}

	char *retorno;

	retorno = verificaUsuario;

	if(retorno == acesso.usuario, acesso.senha) {

		cout << "Seja bem-vindo(a)!\n pressione [enter] para continuar...\n\n";
		menuprincipal();

	}

	else

		cout << "\n Login inv�lido!\n    Tente novamente...\n\n";

}


int main()
{
	setlocale(LC_ALL, "Portuguese");

	struct login acesso;
	void menuprincipal();
	void exit();

	int opcao;

	cout << " MENU INICIAL \n";
	cout << " [1] Fazer cadastro \n [2] Login \n [3] Sair\n";
	opcao = getch();

	switch (opcao) {

	case '1':

		system("cls");

		cadastro();
		system("cls");
		break;

	case '2':

		fazerLogin();
		system("cls");
		menuprincipal();
		break;

	case '3':
		exit();
		break;
	
	default:
		cout << " OP��O INV�LIDA.... \n      TENTE NOVAMENTE...\n";
		
	}

	return 0;
}