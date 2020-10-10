#pragma once
#include <iostream>
#include <vector>
#include "Inimigo.h"
using namespace std;
class ListaInimigos
{
private:
	vector<Inimigo*> listaInimigos;
	int n_elementos;

public:
	ListaInimigos();
	~ListaInimigos();
	void inserir(Inimigo* inimigo);
	int getTamanho();
	Inimigo* getObjeto(int i);
	void excluir(Inimigo* inimigo);
	int getNumElementos();

};

