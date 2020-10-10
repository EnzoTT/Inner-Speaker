#include "ListaPlataformas.h"

ListaPlataformas::ListaPlataformas()
{
	n_elementos = 0;
}

ListaPlataformas::~ListaPlataformas()
{
	listaPlataformas.clear();
	n_elementos = 0;
}

void ListaPlataformas::inserir(Plataforma* plataforma)
{
	listaPlataformas.push_back(plataforma);
	n_elementos++;
}

Plataforma* ListaPlataformas::getObjeto(int i)
{
	auto comeco = listaPlataformas.begin();
	advance(comeco, i);
	return(*comeco);
}

int ListaPlataformas::getNumElementos()
{
	return n_elementos;
}
