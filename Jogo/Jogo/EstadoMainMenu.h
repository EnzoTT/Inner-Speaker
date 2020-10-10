#pragma once

#include "EstadoFase.h"
#include "Fase1.h"
#include "Fase2.h"
#include "Fase3.h"
#include "EstadoMenuFase.h"
#include "Botao.h"
#include <fstream>


class EstadoMainMenu :
	public Estado
{
private:
	//Variaveis 
	//TO DO:Colocar as texturas utilizadas nesse estado no map de texturas do estado
	sf::RectangleShape planoDeFundo;
	sf::Texture texturaPlanoDeFundo;

	std::map<string, Botao*> Botoes;//Map de botoes 
	
	sf::Clock clock;

	sf::View view;
	//Funcoes
	void iniBotoes();//Inicializa os botoes colocando ele no map "Botoes"
	


public:
	EstadoMainMenu(sf::RenderWindow* janela, std::stack<Estado*>* estados, bool ativaCoop);
	virtual ~EstadoMainMenu();

	//Funcoes

	void atualizaBotoes();//Aqui colocamos as respectivas funcoes de cada botao
	//void atualizaTeclas(const float& dt);
	void atualiza(const float& dt);//Update MousePos e Botoes
	void renderizaBotoes(sf::RenderTarget& target);//Renderiza os botoes
	void renderiza(sf::RenderTarget* target = NULL);//Chama as funcoes que renderizam // 
	
};

