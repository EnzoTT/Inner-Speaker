#pragma once
#include "EstadoFase.h"
class Fase3 :
	public EstadoFase
{
public:
	Fase3(sf::RenderWindow* janela, std::stack<Estado*>* estados, bool ativaCoop, bool carregaFase);
	~Fase3();
	void atualiza(const float& deltaTime);
	void renderiza(sf::RenderTarget* target);
};

