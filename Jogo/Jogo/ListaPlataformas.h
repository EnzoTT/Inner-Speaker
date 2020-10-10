#pragma once
#include <list>
#include "Plataforma.h"
using namespace std;
class ListaPlataformas
{
private:
	list<Plataforma*> listaPlataformas;
	int n_elementos;


public:
	ListaPlataformas();
	~ListaPlataformas();
	void inserir(Plataforma* plataforma);
	Plataforma* getObjeto(int i);
	int getNumElementos();
};

