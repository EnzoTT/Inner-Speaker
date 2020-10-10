#pragma once
#include "EstadoFase.h"
class Fase2 :
	public EstadoFase
{
public:
	Fase2(sf::RenderWindow* janela, std::stack<Estado*>* estados, bool ativaCoop, bool carregaFase);
	~Fase2();
	void atualiza(const float& deltaTime);
	void renderiza(sf::RenderTarget* target);
};

