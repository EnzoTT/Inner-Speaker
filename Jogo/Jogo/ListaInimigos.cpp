#include "ListaInimigos.h"

ListaInimigos::ListaInimigos()
{
	n_elementos = 0;
}

ListaInimigos::~ListaInimigos()
{
	listaInimigos.clear();
	n_elementos = 0;
}

void ListaInimigos::inserir(Inimigo* inimigo)
{
	listaInimigos.push_back(inimigo);
	n_elementos++;
}
int ListaInimigos::getTamanho()
{
	return listaInimigos.size();
}
Inimigo* ListaInimigos::getObjeto(int i)
{
	return listaInimigos[i];
}
void ListaInimigos::excluir(Inimigo* inimigo)
{
	int i;
	for (i = 0; i < listaInimigos.size() &&  listaInimigos[i] != inimigo ; i++)
	{
	}
	listaInimigos.erase(listaInimigos.begin() + i);
	n_elementos--;
}

int ListaInimigos::getNumElementos()
{
	return n_elementos;
}
