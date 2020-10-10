#pragma once
#include "EstadoFase.h"
#include "EstadoMainMenu.h"
#include <fstream>




using namespace std;

class Jogo
{
private:

	//Variaveis
	sf::RenderWindow* janela;//Renderiza a janela (Essa janela sera utilizada nas construtoras dos estados)
	sf::Event sfEvent;//Evento do SFML

	sf::Clock Clock;
	sf::Clock timer;
	float dt; //Vai medir o tempo de um frame 

	std::stack <Estado*> Estados; //Todos os estados dentro do jogo, colocado dentro de uma pilha (PILHA ORIGINAL)

	int pontonsAtual;

	sf::Music musica;
	int musicaAnterior;

	//Inicializar
	void iniJanela();
	void iniEstados();

	string nome;
public:

	//Construtora/Destrutora
	Jogo();
	~Jogo();

	//Funcoes

	//Atualiza
	void atualizaDT();//Atualiza o tempo de um frame
	void atualizaSFMLEvents();//Atualiza os eventos do SFML
	void atualiza();//Loop principal da execucao

	//Renderiza
	void renderiza();

	//Roda
	void run();

	void atualizaMusica();
};

