#include <iostream>
using namespace std;

#define MAX 30

struct Pilha {
	int qtde;
    float pares[15];
    float impares[15];
	float elementos[MAX];
};

Pilha* init() {
	Pilha *p = new Pilha();
	p->qtde = 0;
	return p;
}

int isEmpty(Pilha *p) {
	return (p->qtde == 0);
}

int count(Pilha *p) {
	return (p->qtde);
}

void freePilha(Pilha *p) {
	free(p);
}

int push(Pilha *p, float v) {
	int empilhar = (p->qtde < MAX);
	int maiorUltimo = (v >= p->elementos[p->qtde-1]);
	int podeEmpilhar = (empilhar && maiorUltimo);
	int i = p->qtde;
	
	if (podeEmpilhar) {
		p->elementos[p->qtde++] = v;
		
		int verifica = v;
		if (verifica % 2 == 0) {
			p->pares[i] = verifica;
		} else if (verifica % 2 != 0) {
			p->impares[i] = verifica;
		}
	}
	
	return podeEmpilhar;
}

float pop(Pilha *p) {
	float v;
	int podeDesempilhar = (!isEmpty(p));
	if (podeDesempilhar) {
		v = p->elementos[p->qtde-1];		
		p->qtde--;
		
	}
	else {
		v = -1;
	}
	return v;
}

void print(Pilha *p) {
	cout << "Qtde de elementos: " << count(p) << endl;
	cout << "-----------------------" << endl;
	for(int i=p->qtde-1; i>=0; --i) {
		cout << p->elementos[i] << endl;
	}
	cout << "-----------------------" << endl;
	cout << "Pares:" << endl;
	for(int i=0; i<16; i++) {
		if (p->pares[i] != 0) {
			cout << p->pares[i] << endl;
		}	
	}
	cout << "-----------------------" << endl;
	cout << "Impares:" << endl;
	for(int i=0; i<16; i++) {
		if (p->impares[i] != 0) {
			cout << p->impares[i] << endl;
		}
	}
}

int main(int argc, char** argv)
{
	Pilha *pilhaFloat;
	pilhaFloat = new Pilha();
	pilhaFloat = init();
	
	cout << "Pilha vazia: " << (isEmpty(pilhaFloat)?"S":"N") << endl;
	
	cout << "Valor empilhado: " << (push(pilhaFloat, 10)?"S":"N") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 4)?"S":"N") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 15)?"S":"N") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 20)?"S":"N") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 25)?"S":"N") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 30)?"S":"N") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 35)?"S":"N") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 40)?"S":"N") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 45)?"S":"N") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 50)?"S":"N") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 55)?"S":"N") << endl;
	cout << "Valor empilhado: " << (push(pilhaFloat, 60)?"S":"N") << endl;
	
	cout << "Pilha vazia: " << (isEmpty(pilhaFloat)?"S":"N") << endl;
	print(pilhaFloat);
	
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	print(pilhaFloat);
	freePilha(pilhaFloat);

	return 0;
}