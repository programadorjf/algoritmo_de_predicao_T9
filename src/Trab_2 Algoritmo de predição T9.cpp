//============================================================================
// Name        : Trab_2 Algoritmo de predicao T9.cpp
// Author      : Joao Fabricio Radmann dos Santos
// Version     : Agosto/2021
// Copyright   : IFSul - Campus Pelotas-RS
// Description : Prog II - Prof.: Andre Geraldo
//============================================================================

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>
#include <locale.h>
#include <iomanip>
#include <conio.h>
#include "conio2.h"
#include <map>

using namespace std;

//_____________________________________________________________________________________
//              CORRECOES:
// criado funcao saveNew - para incluir nova palavra caso nao esteja na lista a lista;
// criado if(tecla == 43) + - condicao para incluir palavras novas a qualquer momento;
// criado if(tecla == 42) * - condicao para limpar texto digitado e recomecar;
// criado if(tecla == 83 or tecla == 115)83(S) ou 115(s) - condicao para salvar frase digitada com data/hora atual;
// criado if(tecla == 67 or tecla == 99)67(C) ou 99(c) - condicao para copiar frase para area de transferencia;
// aumentado o numero de palavras mostradas no display para 20;
// criado variavel int lp = int(palavra.size()); com isso, a seta de selecao acompanha a quantidade de palavras no display;
// criado funcao contador e saveMaisUsadas, para armazenar quantidade de vezes que a palavra e escolhida;
//_____________________________________________________________________________________

class Elemento{ //classe com ponteiros para os numeros e vetor para palavra
public:
	Elemento *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9;
	vector <string> palaras;
	Elemento(){ //construtor padrao
		p1 = NULL;
		p2 = NULL;
		p3 = NULL;
		p4 = NULL;
		p5 = NULL;
		p6 = NULL;
		p7 = NULL;
		p8 = NULL;
		p9 = NULL;
	}
};

class Arvore{
public:
	Elemento *raiz;
	Arvore(){ //construtor padrao
		raiz = new Elemento;
	}

void insere(string palavra){
	Elemento *onde = raiz; //comeca busca da posicao com ponteiro na raiz
	for(unsigned int i=0; i<palavra.size(); i++){

		switch(palavra[i]){ //passa por todas as posicoes da string palavra

		case 'a': case 'b': case 'c': // tecla 2
			if(onde->p2 == NULL){ onde->p2 = new Elemento; }
			onde = onde->p2;
			break;

		case 'd': case 'e': case 'f': // tecla 3
			if(onde->p3 == NULL){ onde->p3 = new Elemento; }
			onde = onde->p3;
			break;

		case 'g': case 'h': case'i': // tecla 4
			if(onde->p4 == NULL){ onde->p4 = new Elemento; }
			onde = onde->p4;
		    break;

		case 'j': case 'k': case 'l': // tecla 5
			if(onde->p5 == NULL){ onde->p5 = new Elemento; }
			onde = onde->p5;
		    break;

		case 'm': case 'n': case'o': // tecla 6
			if(onde->p6 == NULL){ onde->p6 = new Elemento; }
			onde = onde->p6;
		    break;

		case 'p': case 'q': case 'r': case 's': // tecla 7
			if(onde->p7 == NULL){ onde->p7 = new Elemento; }
			onde = onde->p7;
		    break;

		case 't': case 'u': case 'v': // tecla 8
			if(onde->p8 == NULL){ onde->p8 = new Elemento; }
			onde = onde->p8;
			break;

		case 'w': case 'x': case 'y': case 'z': // tecla 9
			if(onde->p9 == NULL){ onde->p9 = new Elemento; }
			onde = onde->p9;
			break;

		}
		onde->palaras.push_back(palavra); //inclui um elemento no fim do vetor
	}
}
};

void display(vector<string> palavra, char tecla, int seta, string str){
	char c=24, b=25;
	clrscr();
	cout << "                                         ______________________________ " << endl;
	cout << "    Algoritmo de Predicao T9            |                              |" << endl;
	cout << "       _________________                |                              |" << endl;
	cout << "      |  1  |  2  |  3  |               |                              |" << endl;
	cout << "      |     | abc | def |               |                              |" << endl;
	cout << "      |-----|-----|-----|               |                              |" << endl;
	cout << "      |  4  |  5  |  6  |               |                              |" << endl;
	cout << "      | ghi | jkl | mno |               |                              |" << endl;
	cout << "      |-----|-----|-----|               |                              |" << endl;
	cout << "      |  7  |  8  |  9  |               |                              |" << endl;
	cout << "      | pqrs| tuv | wxyz|               |                              |" << endl;
	cout << "      |-----|-----|-----|               |                              |" << endl;
	cout << "      |  *  |  0  |  #  |               |                              |" << endl;
	cout << "      |_____|_____|_____|               |                              |" << endl;
	cout << " 0 -> Aceitar palavra.                  |                              |" << endl;
	cout << " 1 -> Encerrar programa.                |                              |" << endl;
	cout << " * -> Apagar texto digitado.            |                              |" << endl;
	cout << " + -> Inserir nova palavra.             |                              |" << endl;
	cout << " C -> Copiar texto para area de transf. |                              |" << endl;
	cout << " S -> Salvar texto digitado em arquivo. |                              |" << endl;
	cout << "-> Digite um numero para iniciar: " << tecla << "     |                              |" << endl;
	cout << "-> Utilize as setas para navegar: " << b << c << "    |______________________________|" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "Texto: " << str << endl;
	//cout << "------------------------------------------------------------------------" << endl;

	// imprime as palavras do vector<string> palavra
	if(seta == 0){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 0){gotoxy(44, 2); cout << palavra[0] << endl;	}
	if(seta == 1){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 1){gotoxy(44, 3); cout << palavra[1] << endl;	}
	if(seta == 2){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 2){gotoxy(44, 4); cout << palavra[2] << endl;	}
	if(seta == 3){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 3){gotoxy(44, 5); cout << palavra[3] << endl;	}
	if(seta == 4){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 4){gotoxy(44, 6); cout << palavra[4] << endl;	}
	if(seta == 5){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 5){gotoxy(44, 7); cout << palavra[5] << endl;	}
	if(seta == 6){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 6){gotoxy(44, 8); cout << palavra[6] << endl;	}
	if(seta == 7){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 7){gotoxy(44, 9); cout << palavra[7] << endl;	}
	if(seta == 8){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 8){gotoxy(44, 10); cout << palavra[8] << endl;	}
	if(seta == 9){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 9){gotoxy(44, 11); cout << palavra[9] << endl;	}
	if(seta == 10){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 10){gotoxy(44, 12); cout << palavra[10] << endl;	}
	if(seta == 11){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 11){gotoxy(44, 13); cout << palavra[11] << endl;	}
	if(seta == 12){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 12){gotoxy(44, 14); cout << palavra[12] << endl;	}
	if(seta == 13){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 13){gotoxy(44, 15); cout << palavra[13] << endl;	}
	if(seta == 14){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 14){gotoxy(44, 16); cout << palavra[14] << endl;	}
	if(seta == 15){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 15){gotoxy(44, 17); cout << palavra[15] << endl;	}
	if(seta == 16){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 16){gotoxy(44, 18); cout << palavra[16] << endl;	}
	if(seta == 17){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 17){gotoxy(44, 19); cout << palavra[17] << endl;	}
	if(seta == 18){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 18){gotoxy(44, 20); cout << palavra[18] << endl;	}
	if(seta == 19){gotoxy(42, 2+seta); cout << "->"; }
	if(palavra.size() > 19){gotoxy(44, 21); cout << palavra[19] << endl;	}
}

void saveMaisUsadas(string palavra, int x){
	ofstream escreve; //cria um objeto de escrita
	escreve.open("mais_usadas.txt", ios::app); //abre o arquivo para escrita (ios::app adiciona ao final do arquivo)
	if(!escreve.is_open()){ //verifica se o arquivo abriu conrretamente
		cout << "Erro ao abrir o arquivo!" << endl;
		escreve.clear();
	}
	escreve << palavra << " x " << x << endl; //escreve no arquivo mais_usadas.txt
	escreve.close();
}

void contador(string palavra, map<string, int> *mapa){
	//map<string, int> mapa; //container para salvar palavras mais_usadas
	map<string, int>::iterator itmapa; //iterador para busca no mapa
	int x=1;
	itmapa = mapa->find(palavra);
	if(itmapa != mapa->end()){ //condicao para verificar se a palavra ja consta no mapa
		x = itmapa->second + 1;
		mapa->erase(palavra); //apaga posicao do mapa pela chave (first)
		mapa->insert(pair<string, int>(palavra, x)); //insere a palavra e a quantidade de vezes no mapa
	}
	else{
		mapa->insert(pair<string, int>(palavra, x)); //insere a palavra e a quantidade de vezes no mapa
	}
}

void openFile(string arquivo, Arvore *a){
	string palavra;
	ifstream leitura; //cria um objeto de leitura
	leitura.open(arquivo); //abre o arquivo passado como paramentro para leitura
	if(!leitura.is_open()){ //verifica se o arquivo abriu conrretamente
		cout << "Erro ao abrir o arquivo com as palavras!" << endl;
		leitura.clear();
	}
	while(!leitura.eof()){ //enquanto nao chega no final do arquivo
		palavra.clear();
		leitura >> palavra;
		a->insere(palavra); //chama a funcao para inserir a palavra na arvore
	}
	leitura.close();
}

void saveNovas(Arvore *a){
	clrscr();
	cout << endl;
	char nova[30];
	ofstream escreve; //cria um objeto de escrita
	escreve.open("novas.txt", ios::app); //abre o arquivo para escrita (ios::app adiciona ao final do arquivo)
	if(!escreve.is_open()){ //verifica se o arquivo abriu conrretamente
		cout << "Erro ao abrir o arquivo!" << endl;
		escreve.clear();
	}
	cout << "Digite a palavra nova: " << endl << endl;
	cin >> nova;
	escreve << nova << endl; //escreve no arquivo novas.txt
	a->insere(nova); //chama a funcao para inserir a palavra na arvore
	escreve.close();
}

void saveNew(Arvore *a){ //caso a combinacao de teclas nao apresente a palavra desejada
	char n;
	clrscr();
	//do{
		cout << endl << "Deseja incluir nova palavra?" << endl;
		cout << endl << "          Y / N" << endl;
		n = getch();
	//}while(n!=121 or n!=89 or n!=110 or n!=78);
	if(n == 'y' or n == 'Y'){ saveNovas(a); }
	else{ clrscr(); }
}

string datahora(){ //funcao para fornecer data e hora atual
	char strdata[20];
	time_t tempo; //inicializa a variavel tempo
	time(&tempo); //retorna na variavel tempo, os segundos desde 1 de jan de 1970
	struct tm *infoTempo; //cria um ponteiro para receber
	infoTempo = localtime(&tempo); //retorna no ponteiro infoTempo, as informacoes referente a data local
	//strdata = asctime(infoTempo); //asctime converte infoTempo para string = Fri Jul 30 17:43:16 2021
	strftime(strdata,20, "%Y%m%d%H%M%S", infoTempo);
	return strdata;
}

void saveTxt(string texto, string data){ //funcao para salvar texto digitado com data/hora atual
	ofstream txt_digitado("txt_digitado.txt", ios::app);
	ofstream escreve; //cria um objeto de escrita
	escreve.open("txt_digitado.txt", ios::app); //abre o arquivo para escrita (ios::app adiciona ao final do arquivo)
	if(!escreve.is_open()){ //verifica se o arquivo abriu conrretamente
		cout << "Erro ao abrir o arquivo!" << endl;
		escreve.clear();
	}
	escreve << data << texto << endl; //escreve no arquivo txt_digitado.txt
	escreve.close();
}

int main() {
	map<string, int> mapa; //container para salvar palavras mais_usadas
	Arvore a; //cria um objeto class Arvore
	vector<string> palavra;
	ifstream novas("novas.txt", ios::app); // ios::app (adiciona ao final do arquivo)
	ifstream mais_usadas("mais_usadas.txt", ios::app);
	Elemento *no;
	string aux, str;
	char tecla=99;
	int x=0, seta=0;
	openFile("Base.txt", &a); //chama a funcao openFile para inserir as palavras do base.txt na arvore
	openFile("novas.txt", &a);
	openFile("mais_usadas.txt", &a);
	no = a.raiz; //inicia com no na raiz
	cout << "Digite Enter para abrir o Algoritmo de Predicao T9" << endl;
	cin.get(); //aguarda tecla ser pressionada

	while(tecla != '1'){ //enquanto tecla for diferente de 1

		if(tecla == '2'){
			x = 0;
			palavra.clear(); //limpa o vector palavra
			if(no->p2 != NULL){ no = no->p2; } //avanca ate o no correspondente a tecla 2
			else{ saveNew(&a); } //condicao para inserir nova palavra caso termine a lista
			while(x<fmin(20, no->palaras.size())){ //fmin retorna o menor valor entre x e y; carrega as palavras do *p2, vector palavras, no vector palavra, limite max 20
				aux = no->palaras[x]; //carrega palavra da posicao x na string aux
				palavra.push_back(aux); //insere string aux no vector palavra
				seta = 0; //volta a seta para a primeira posicao
				x++; //contador de palavras carregadas
			}
		}

		if(tecla == '3'){
			x = 0;
			palavra.clear();
			if(no->p3 != NULL){ no = no->p3; }
			else{ saveNew(&a); }
			while(x<fmin(20, no->palaras.size())){
				aux = no->palaras[x];
				palavra.push_back(aux);
				seta = 0;
				x++;
			}
		}

		if(tecla == '4'){
			x = 0;
			palavra.clear();
			if(no->p4 != NULL){ no = no->p4; }
			else{ saveNew(&a); }
			while(x<fmin(20, no->palaras.size())){
				aux = no->palaras[x];
				palavra.push_back(aux);
				seta = 0;
				x++;
			}
		}

		if(tecla == '5'){
			x = 0;
			palavra.clear();
			if(no->p5 != NULL){ no = no->p5; }
			else{ saveNew(&a); }
			while(x<fmin(20, no->palaras.size())){
				aux = no->palaras[x];
				palavra.push_back(aux);
				seta = 0;
				x++;
			}
		}

		if(tecla == '6'){
			x = 0;
			palavra.clear();
			if(no->p6 != NULL){ no = no->p6; }
			else{ saveNew(&a); }
			while(x<fmin(20, no->palaras.size())){
				aux = no->palaras[x];
				palavra.push_back(aux);
				seta = 0;
				x++;
			}
		}

		if(tecla == '7'){
			x = 0;
			palavra.clear();
			if(no->p7 != NULL){ no = no->p7; }
			else{ saveNew(&a); }
			while(x<fmin(20, no->palaras.size())){
				aux = no->palaras[x];
				palavra.push_back(aux);
				seta = 0;
				x++;
			}
		}

		if(tecla == '8'){
			x = 0;
			palavra.clear();
			if(no->p8 != NULL){ no = no->p8; }
			else{ saveNew(&a); }
			while(x<fmin(20, no->palaras.size())){
				aux = no->palaras[x];
				palavra.push_back(aux);
				seta = 0;
				x++;
			}
		}

		if(tecla == '9'){
			x = 0;
			palavra.clear();
			if(no->p9 != NULL){ no = no->p9; }
			else{ saveNew(&a); }
			while(x<fmin(20, no->palaras.size())){
				aux = no->palaras[x];
				palavra.push_back(aux);
				seta = 0;
				x++;
			}
		}

		display(palavra, tecla, seta, str); //chama funcao display
		tecla = getch(); //carrega tecla pressionada na variavel tecla
		int lp = int(palavra.size());
		if(tecla == 72){ seta = seta - 1; } //72 - movimenta a seta para cima
		if(seta < 0){ seta = lp - 1; } //coloca seta na primeira posicao
		if(tecla == 80){ seta = seta + 1; } //80 - movimenta a seta para baixo
		if(seta > lp - 1){ seta = 0; } //coloca seta na ultima posicao
		if(tecla == '0'){
			contador(palavra[seta], &mapa); //chama funcao contador de palavar mais usadas
			str = str + " " + palavra[seta]; //monta str com a palavra selecionada
			no = a.raiz; //reposiciona o no para a raiz
			seta = 0; //volta a seta para a primeira posicao
		}
		if(tecla == 43){ saveNovas(&a); } //43 (+) - chama a funcao saveNovas
		if(tecla == 42){ //42 (*) - limpa o texto digitado
			str.clear(); //limpa string str
			palavra.clear(); //limpa o vector palavra
			no = a.raiz; //reposiciona o no para a raiz
			seta = 0; //volta a seta para a primeira posicao
		}
		if(tecla == 83 or tecla == 115){ //83(S) ou 115(s) - condicao para salvar frase digitada e data/hora atual
			saveTxt(str, datahora()); //chama funcao para salvar texto digitado e data/hora atual
		}
		if(tecla == 67 or tecla == 99){ //67(C) ou 99(c) - condicao para copiar frase para area de transferencia
			const char *output = str.c_str();
			const size_t len = strlen(output) + 1;
			HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
			memcpy(GlobalLock(hMem), output, len);
			GlobalUnlock(hMem);
			OpenClipboard(0);
			EmptyClipboard();
			SetClipboardData(CF_TEXT, hMem);
			CloseClipboard();
		}
	}
	for(auto it : mapa){ //salva as palavras mais usadas no arquivo mais_usadas.txt
			saveMaisUsadas(it.first, it.second);
	}
	novas.close();
	mais_usadas.close();
	return EXIT_SUCCESS;
}
