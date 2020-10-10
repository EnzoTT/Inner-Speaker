#pragma once
#include "Estado.h"
#include "Jogador.h"
//#include "Inimigo.h"
#include "Plataforma.h"
#include "BarraDeVida.h"

#include "Caixa.h"
#include "Pneu.h"
#include "Carro.h"

#include "Alterego.h"
#include "Slime.h"
#include "Robo.h"

#include "MenuDePausa.h"


#include "ListaEntidades.h"
#include "ListaInimigos.h"
#include "ListaObstaculos.h"
#include "ListaPlataformas.h"


class EstadoFase :
	public Estado
{
protected:
	//Cria listas
	ListaEntidades LE;
	ListaPlataformas LP;
	ListaInimigos LI;
	ListaObstaculos LO;

	//Cria o menu de pause
	MenuDePausa* menuDePausa;

	//Cria jogadores
	Jogador* P1;//Como eh um poteiro tem que criar dinamicamente
	Jogador* P2;

	//Barra de vida dos jogadores 1 e 2
	BarraDeVida* barraDeVida1;
	BarraDeVida* barraDeVida2;

	//Timer da invencibilidade
	sf::Clock Clock;
	float timer;

	sf::View view;

	int jogadoresVivos;
	sf::Clock* delay;

	bool gameOver;

	sf::RectangleShape planoDeFundo;
	sf::Texture texturaPlanoDeFundo;

	sf::RectangleShape telaDeGameOver;
	sf::Texture texturaTelaDeGameOver;

public:
	EstadoFase(sf::RenderWindow* janela, std::stack<Estado*>* estados, bool ativaCoop, bool carregaFase);
	virtual ~EstadoFase();

	//Funcoes
	void iniMenuDePausa();
	void iniTexturas();//Inicializa as texturas 
	void iniJogadores();//Inicializa os jogadores (Como sao criados dinamicamente, estes sao deletados na destrutora)

	//Definindo funcoes virtuais
	void atualizaBotoes();
	void atualizaTeclas(const float& deltaTime);

	//Virtual pura
	virtual void atualiza(const float& dt) = 0;
	virtual void renderiza(sf::RenderTarget* target = NULL) = 0;//Renderiza os elementos de jogo

	void atualizaView();
	void atualizaListas(const float& deltaTime);
	void gerenciaColisao();

	void salvaFase();
	void carregaFase();

	void contaPontuacao();
};