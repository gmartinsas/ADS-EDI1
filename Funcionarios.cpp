#include <iostream>
using namespace std;

struct Funcionario {
	int pront;
	string nome;
	double sal;
	struct Funcionario *prox;
}

Funcionario* init() {
	return NULL;
}

Funcionario* incluir(Funcionario* func, string n, int p, double s) {
	Funcionario* novo = new Funcionario();
	
	novo->pront = p;
	novo->nome = n;
	novo->sal = s;
	novo->prox = func;
	return novo;
}

Funcionario* buscar(Funcionario* func, int p) {
	Funcionario* aux = func;
	
	while (aux != NULL && aux->pront != p) 	{
		aux = aux->prox;
	}
	return mostrar(aux);
}

Funcionario* excluir(Funcionario* func, int p) {
	Funcionario* ant = NULL;
	Funcionario* aux = func;
	
	while (aux != NULL && aux->pront != p) 	{
		ant = aux;
		aux = aux->prox;
	}
	if (aux == NULL) {
		return func;
	}
	if (ant == NULL) {
		func = aux->prox;	
	}
	else {
		ant->prox = aux->prox;
	}
	free(aux);
	return func;
}

Funcionario* mostrar(Funcionario* func) {
	Funcionario* aux = func;
	double saldo;
	
	while (aux != NULL) {
		cout << "Nome: " << aux->nome << endl;
		cout << "Prontu�rio: " << aux->pront << endl;
		cout << "Sal�rio: " << aux->sal << endl;
		
		aux = aux->prox;
		aux->sal += saldo;
	}
	cout << "Total de sal�rios: R$" << saldo;
}

int main(int argc, char** argv)
{
	int opc;
	
	cout << "Menu -- Cadastro de Funcionarios" << endl;
	cout << "0. Sair\n1. Incluir\n2. Excluir\n3. Pesquisar\n4. Listar" << endl;
	cout << "\nOp��o desejada: ";
		cin >> opc;
			if(opc < 0 || opc > 4) {
				cout << "Op��o inv�lida. Digite novamente!";
				cin >> opc;
			} else {
				  switch (opc) {
					    case 0:
					    break;
					
					    case 1:
                        	string n;
                        	double s;
                        	int p;
							
							Funcionario *Funcionarios;
                        	Funcionarios = init();
                        	
                        	cout << "Digite o nome do funcion�rio: ";
                        	cin >> n;
                        	cout << "Digite o prontu�rio do funcion�rio: ";
                        	cin >> s;
                        	cout << "Digite o sal�rio do funcion�rio: ";
                        	cin >> p;
                        	Funcionarios = incluir(Funcionarios, n, s, p);
					    break;
					    
					    case 2:
					    	Funcionarios = excluir(Funcionarios, 1);
					    break;
					    
					    case 3:
					    	Lista *procurado;
							procurado = find(Funcionarios, 1);
							if (procurado != NULL) {
								cout << mostrar(procurado) << endl;
							} else {
								cout << "Nao foi poss�vel encontrar!" << endl;
							}
					    break;
					    
					    case 4:
					    	mostrar(Funcionarios);
					    break;
					    
					    default:
					    cout << "Valor invalido!\n";
					  }
			}
	return 0;
}
