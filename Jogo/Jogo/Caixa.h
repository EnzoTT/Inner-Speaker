#pragma once
#include "Obstaculo.h"
class Caixa :
	public Obstaculo
{
private:
	
public:
	Caixa(sf::Texture& textura, sf::Vector2f posicao, sf::Vector2f desHitbox, sf::Vector2f tamanhoHitbox, int intervalo);
	~Caixa();



};

