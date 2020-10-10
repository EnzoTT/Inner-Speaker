#pragma once
#include "Estado.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Plataforma.h"
#include "BarraDeVida.h"



class EstadoJogo :
	public Estado
{
private:
	Jogador* P1;//Como eh um poteiro tem que criar dinamicamente
	Inimigo* Ini1;
	Plataforma* plat;

	BarraDeVida* barraDeVida;

	sf::Clock Clock;
	float timer;
	


	sf::View view;

	

	sf::RectangleShape planoDeFundo;
	sf::Texture texturaPlanoDeFundo;
	

public:
	EstadoJogo(sf::RenderWindow* janela, std::stack<Estado*>* estados);
	virtual ~EstadoJogo();
	
	//Funcoes
	void iniTexturas();//Inicializa as texturas 
	void iniJogadores();//Inicializa os jogadores (Como sao criados dinamicamente, estes sao deletados na destrutora)
	
	//Definindo funcoes virtuais
	void atualizaTeclas(const float& dt);//Atualiza as teclas com relacao ao estado de jogo
	void atualiza(const float& dt);//Chama os devidos atualizas(MousePos, atualizaTeclas, atualizaJogadores "Animacao")
	void atualizaView();
	void renderiza(sf::RenderTarget* target = NULL);//Renderiza os elementos de jogo
};

