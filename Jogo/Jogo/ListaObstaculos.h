#pragma once
#include <set>
#include "Obstaculo.h"
using namespace std;
class ListaObstaculos
{
private:
	set<Obstaculo*> listaObstaculos;
	int n_elementos;
public:
	ListaObstaculos();
	~ListaObstaculos();

	void inserir(Obstaculo* obstaculo);
	Obstaculo* getObjeto(int i);
	int getNumElementos();

};

