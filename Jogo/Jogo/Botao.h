#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<stack>
#include<vector>   
#include<map>

using namespace std;

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"

enum estado_botao{BTO_PADRAO = 0 , BTO_SOBRE, BTO_ATIVO};

class Botao
{
private:
	short unsigned estadoBotao;
	
	sf::RectangleShape retangulo;//Forma do botao
	sf::Texture texturaPadrao;
	sf::Texture texturaSobre;
	sf::Texture texturaAtivo;


public:
	//construtora e destrutora
	Botao(float x, float y, float comprimento, float altura, string texturaPadrap, string texturaSobre, string texturaAtivo);
	~Botao();

	//Acessos
	const bool estaPressionado() const;

	//Funcoes
	void setPosicao(sf::Vector2f pos);
	void atualiza(const sf::Vector2f mousePos);
	void renderiza(sf::RenderTarget& target);

};

