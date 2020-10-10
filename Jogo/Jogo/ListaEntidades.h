#pragma once
#include "Lista.h"
#include "Entidade.h"
class ListaEntidades
{
private:
	Lista<Entidade*> LE;
public:
	ListaEntidades();
	~ListaEntidades();

	void inserir(Entidade* e);
	void remover(Entidade* e);
	Entidade* getElemento(int i);
	int getNumElementos();

};

