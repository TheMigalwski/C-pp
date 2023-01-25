// Leonardo Custodio Magalhaes - 42131510

#include <iostream>

class no {
private:
	int v;
	no* prox;
public:
	no(int v) {
		this->v = v;
		this->prox = NULL;
	}

	int recebeV() {
		return v;
	}

	no* recebeProx() {
		return prox;
	}

	void setProx(no* p) {
		prox = p;
	}
};

class lista {
private:
	no* head;
	no* tail;

public:
	lista() {
		head = NULL;
		tail = NULL;
	}

	lista(int v) {
		head = new no(v);
		tail = head;
	}

	bool vazia() {
		return (head == NULL);
	}

	void mostra() {
		no* h = head;
		while (h) {
			std::cout << "array: " << h->recebeV() << "\n";
			h = h->recebeProx();
		}
	}

	void final(int v) {
		no* novo = new no(v);
		if (vazia()) {
			head = novo;
			tail = novo;
		}
		else {
			tail->setProx(novo);
			tail = novo;
		}
	}
};

int main() {
	int tamanho, i, num{}, tamanho2, z;
	char resposta;
	lista l;

	std::cout << "Informe o tamanho do array: ";
	std::cin >> tamanho;
	for (i = 0; i < tamanho; i++) {
		std::cout << "Informe um numero positivo para o elemento " << i << ": ";
		std::cin >> num;
		if (num < 0) {
			num = -1;
			l.final(num);
			break;
		}
		else {
			l.final(num);
		}
	}
	if (num > 0) {
		std::cout << "O limite do array foi atingido. Deseja aumentar o tamanho do array? (S/N)\n";
		std::cin >> resposta;

		if (resposta == 'S' || resposta == 's') {
			std::cout << "Informe o novo tamanho do array (atual: " << tamanho << "): ";
			std::cin >> tamanho2;
			if (tamanho2 <= tamanho) {
				std::cout << "O novo tamanho nao pode ser menor ou igual ao atual!\n Encerrando...\n";
				l.mostra();
			}
			else {
				for (i = tamanho; i < tamanho2; i++) {
					std::cout << "Informe um numero positivo para o elemento " << i << ": ";
					std::cin >> num;
					l.final(num);
				}
				l.mostra();
			}
		}
		if (resposta == 'N' || resposta == 'n') {
			l.mostra();
		}
	}
	else {
		for (z = i; z < tamanho-1; z++) {
			num = -1;
			l.final(num);
		}
		l.mostra();
	}
}

