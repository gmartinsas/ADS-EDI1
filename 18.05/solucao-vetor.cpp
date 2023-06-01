#include <iostream>
using namespace std;

#define MAX 5

struct Fila {
	int ini;
	int fim;
	float nos[MAX];
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = 0;
	f->fim = 0;
	return f;
}

int isEmpty(Fila *f) {
	return (f->ini == f->fim);
}

int incrementa(int i) {
	return (i==MAX?0:++i);
}

int count(Fila *f) {
	int qtde = 0;
	int i = f->ini;
	while (i != f->fim) {
		qtde++;
		i = incrementa(i);
	}
	return qtde;
}

void print(Fila *f) {
	int i = f->ini;
	cout << "------------" << endl;
	while (i != f->fim) {
		cout << f->nos[i] << endl;
		i = incrementa(i);
	}
    cout << "------------" << endl;
}

void freeFila(Fila *f) {
	free(f);
}

int enqueue(Fila *f, float v) {
	int podeEnfileirar = (incrementa(f->fim) != f->ini);
	if (podeEnfileirar) {
		f->nos[f->fim] = v;
		f->fim = incrementa(f->fim);
	}
    return podeEnfileirar;	
}

float dequeue(Fila *f) {
	float ret;
	if (isEmpty(f)) {
		ret = -1;
	}
	else {
		ret = f->nos[f->ini];
		f->ini = incrementa(f->ini);
	}
	return ret;
}

void fimDeAtendimento(Fila *f) {
	cout << "Senhas aguardando atendimento: " << count(f) << endl;
	print(f);
}

void novaSenha(Fila *f, int q) {
    enqueue(f, q);
	cout << "Senha gerada!\n";
	fimDeAtendimento(f);
}

void tiraSenha(Fila *f, Fila *a) {
	enqueue(a, f->ini);
	dequeue(f);
	fimDeAtendimento(f);
}

int main(int argc, char** argv)
{
	Fila *senhasGeradas;
	senhasGeradas = init();

    Fila *senhasAtendidas;
	senhasAtendidas = init();

	int opc = 0;
	int contagem = 0;
	int historico = 0;
	int senhaBase = 0;
	
	cout << "Gerador de senhas - Menu" << endl;
	cout << "0. Sair\n1. Gerar senha\n2. Realizar atendimento" << endl;
	cout << "------------" << endl;
	
	while (opc == 0 || opc == 1 || opc == 2) {
		cout << "Digite a opcao desejada: ";
	    cin >> opc;
		switch (opc) {
        case 0:
            contagem = count(senhasGeradas);
            if (contagem != 0) {
				cout << "Nao e possivel encerrar o programa. Fila em andamento." << endl;
                break;
			} else {
                cout << "Numero de senhas atendidas: " << historico;
				opc = 5;
				break;
            }
        case 1:
            novaSenha(senhasGeradas, senhaBase++);
            historico++;
            break;
        case 2:
        	tiraSenha(senhasGeradas, senhasAtendidas);
            break;
        default:
            break;
		}
    }
	
	return 0;
}