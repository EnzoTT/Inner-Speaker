#include "ListaObstaculos.h"

ListaObstaculos::ListaObstaculos()
{
	n_elementos = 0;
}

ListaObstaculos::~ListaObstaculos()
{
	listaObstaculos.clear();
	n_elementos = 0;
}

void ListaObstaculos::inserir(Obstaculo* obstaculo)
{
	listaObstaculos.insert(obstaculo);
	n_elementos++;
}

Obstaculo* ListaObstaculos::getObjeto(int i)
{
	auto comeco = listaObstaculos.begin();
	advance(comeco, i);
	return(*comeco);
	
}

int ListaObstaculos::getNumElementos()
{
	return n_elementos;
}
