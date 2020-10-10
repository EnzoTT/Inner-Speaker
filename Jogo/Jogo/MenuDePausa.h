#pragma once
#include "Botao.h"

class MenuDePausa
{
private:


	sf::RectangleShape planoDeFundo;
	sf::Texture texturaPlanoDefundo;

	map<string, Botao*> botoes;


public:
	MenuDePausa(sf::RenderWindow& janela);
	virtual ~MenuDePausa();


	//Funcoes
	bool estaPressionado(string botao);

	void iniBotoes();
	void atualiza(sf::Vector2f mousePos);
	void atualizaPlanoDeFundo(sf::Vector2f pos);
	void renderiza(sf::RenderTarget& target);

};

