#include <iostream>
using namespace std;

struct No {
	float dado;
	struct No *prox;
};

struct Fila {
	No *ini;
	No *fim;
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int isEmpty(Fila *f) {
	return (f->ini == NULL);
}

int count(Fila *f) {
	int qtde = 0;
	No *no;
	no = f->ini;
	while(no != NULL) {
		qtde++;
		no = no->prox;
	}
	return qtde;
}

void print(Fila *f) {
	No *no;
	no = f->ini;
	cout << "------------" << endl;
	while(no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "------------" << endl;
}

void enqueue(Fila *f, float v) {
	No *no = new No;
	no->dado = v;
	no->prox = NULL;
	if (isEmpty(f)) {
	   f->ini = no;
	}
	else {
		f->fim->prox = no;
	}
	f->fim = no;
}

float dequeue(Fila *f) {
	float ret;
	if (isEmpty(f)) {
		ret = -1;
	}
	else {
		No *no = f->ini;
		ret = no->dado;
		f->ini = no->prox;
		if (f->ini == NULL) {
			f->fim = NULL;
		}
        free(no);
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
	enqueue(a, (int) f->ini->dado);
	dequeue(f);
	fimDeAtendimento(f);
}

void freeFila(Fila *f) {
	No *no = f->ini;
	while (no != NULL) {
		No *temp = no->prox;
		free(no);
		no = temp;
	}
	free(f);
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