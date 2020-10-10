#pragma once
#include"Entidade.h"

/*Basicamente essa clase define em que estado esta o jogo, como estado de menu ou estado de jogo*/
class Estado
{
private:

protected:

	std::stack<Estado*>* estados;//Pilha de ponteiros de estados (utillizada para mudanca de estado)
	sf::RenderWindow* janela;//Janela do respectivo estado
	bool sair;//Variavel que mostra se o estado deve ser fechado

	bool pausado;//Variavel que mostra se o jogo esta pausado

	//Recursos
	std::map<string, sf::Texture> texturas;//Map de textura para ficar compacto

	//Configuracoes da posicao do mouse
	sf::Vector2i posMouseTela;
	sf::Vector2i posMouseJanela;
	sf::Vector2f posMouseView;

	bool ativaCoop;//Variavel que serve para iniciar o modo cooperativo

	//Para gerenciar a musica
	int musica;
	bool trocaMusica;

	int proxFase;
	bool ganhou;

	int pontuacao;

public:

	Estado(sf::RenderWindow*janela,std::stack<Estado*>* estados, bool ativaCoop);
	virtual ~Estado();

	const bool& getSair() const;

	void fechaEstado();//Muda variavel sair para fechar o jogo
	void pausaEstado();
	void despausaEstado();

	int rand(int min, int max);//gera um numero aleatorio em um intervalo

	virtual void atualizaPosMouse();//Atualiza sempre a posicao do mouse

	//Funcoes virtuais puras (Sao definidas em cada estado)
	virtual void atualizaTeclas(const float& deltaTime);
	virtual void atualiza(const float& deltaTime) = 0;//Atualiza o estado com base no delta time
	virtual void renderiza(sf::RenderTarget* target = NULL) = 0;//Renderiza o estado 

	int getMusica() { return this->musica; };
	void setMusica(int musica) { this->musica = musica; }

	bool getTrocaMusica() { return this->trocaMusica; }
	void setTrocaMusica(bool trocaMusica) { this->trocaMusica = trocaMusica; }

	bool getGanhou() { return this->ganhou; }
	int getProxFase() { return this->proxFase; }

	bool getCoop() { return this->ativaCoop; }

	void setPontos(int pontos) { this->pontuacao = pontos; }
	int getPontuacao() { return this->pontuacao; }
};

