#include "ListaEntidades.h"

ListaEntidades::ListaEntidades()
{
}
ListaEntidades::~ListaEntidades()
{
}
void ListaEntidades::inserir(Entidade* e)
{
	LE.inserir(e);
}
void ListaEntidades::remover(Entidade* e)
{
	LE.remover(e);
}
Entidade* ListaEntidades::getElemento(int i)
{
	return LE.getElemento(i);
}

int ListaEntidades::getNumElementos()
{
	return LE.getNumElementos();
}
