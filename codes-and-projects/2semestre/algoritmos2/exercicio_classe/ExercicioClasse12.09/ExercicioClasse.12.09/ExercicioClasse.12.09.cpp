#include <iostream>

// Código feito por Matheus Baron Lauritzen

using namespace std;

class conta{
	float saldo = 0, divida = 0;

public:

	bool saque(conta &c, float valor) {
		if (valor <= c.saldo) {
			c.saldo = c.saldo - valor;
			return true;
		}
		else {
			return false;
		}
	}
	
	bool deposito(conta &c, float valor) {
		if (valor > 0) {
			c.saldo = c.saldo + valor;
			return true;
		}
		else {
			return false;
		}
	}

	bool transferencia(conta &c1, conta &c2,float valor) {
		if (valor <= c1.saldo) {
			c1.saldo = c1.saldo - valor;
			c2.saldo = c2.saldo + valor;
			return true;
		}
		else {
			return false;
		}
	}
	
	bool emprestimo(conta &c, float valor) {
		if (valor <= 1000) {
			if (c.divida <= 1000) {
				c.divida = c.divida + valor;
				c.saldo = c.saldo + c.divida;
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	bool pagar_divida(conta &c, float valor) {
		if (valor > 0) {
			if (c.divida > 0) {
				if (valor > c.divida) {
					return false;
				}
				else {
					c.divida = c.divida - valor;
					return true;
				}
			}
		}
	}

	float visualizar_saldo(conta c) {
		return c.saldo - c.divida;
	}
};

int main()
{
	int escolha;
	conta conta_usuario;
	conta conta_transferencia;
	float valor;

	do{
		system("cls");
		cout << "O que voce deseja fazer?\n";
		cout << "1 - Saque\n";
		cout << "2 - Deposito\n";
		cout << "3 - Tranferencia\n";
		cout << "4 - Emprestimo\n";
		cout << "5 - Pagar Divida\n";
		cout << "6 - Visualizar Saldo\n";
		cout << "7 - Sair\n";
		cin >> escolha;

		switch (escolha) {
		case 1:
			system("cls");
			cout << "Qual o valor: \n";
			cin >> valor;
			cout << conta_usuario.saque(conta_usuario, valor);
			break;
		case 2:
			system("cls");
			cout << "Qual o valor: \n";
			cin >> valor;
			cout << conta_usuario.deposito(conta_usuario, valor);
			break;
		case 3:
			system("cls");
			cout << "Qual o valor: \n";
			cin >> valor;
			cout << conta_usuario.transferencia(conta_usuario, conta_transferencia, valor);
			break;
		case 4:
			system("cls");
			cout << "Qual o valor: \n";
			cin >> valor;
			cout << conta_usuario.emprestimo(conta_usuario, valor);
			break;
		case 5:
			system("cls");
			cout << "Qual o valor: \n";
			cin >> valor;
			cout << conta_usuario.pagar_divida(conta_usuario, valor);
			break;
		case 6:
			system("cls");
			cout << conta_usuario.visualizar_saldo(conta_usuario);

			break;
		default:
			cout << "Valor invalido\n";
			break;
		}
	} while (escolha != 7);
}