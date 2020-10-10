#pragma once

#include "EstadoFase.h"
#include "Botao.h"


class EstadoMenuFase :
	public Estado
{
private:
	//Variaveis 
	//TO DO:Colocar as texturas utilizadas nesse estado no map de texturas do estado
	sf::RectangleShape planoDeFundo;
	sf::Texture texturaPlanoDeFundo;

	std::map<string, Botao*> Botoes;//Map de botoes 

	sf::View view;
	//Funcoes
	void iniBotoes();//Inicializa os botoes colocando ele no map "Botoes"


public:
	EstadoMenuFase(sf::RenderWindow* janela, std::stack<Estado*>* estados, bool ativaCoop);
	~EstadoMenuFase();
	//Funcoes
	//void atualizaTeclas(const float& deltaTime);

	void atualizaBotoes();//Aqui colocamos as respectivas funcoes de cada botao
	void atualiza(const float& dt);//Update MousePos e Botoes
	void renderizaBotoes(sf::RenderTarget& target);//Renderiza os botoes
	void renderiza(sf::RenderTarget* target = NULL);//Chama as funcoes que renderizam
};

