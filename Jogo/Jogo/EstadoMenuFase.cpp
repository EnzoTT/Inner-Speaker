#include "EstadoMenuFase.h"
#include "Fase1.h"
#include "Fase2.h"
#include "Fase3.h"


void EstadoMenuFase::iniBotoes()
{
	this->Botoes["ESTADO_FASE_1"] = new Botao(475, 269, 336, 45, "img_menu_fases/fase1_IDLE.png",
		"img_menu_fases/fase1.png", "img_menu_fases/fase1.png");
	this->Botoes["ESTADO_FASE_2"] = new Botao(332, 326, 615, 105, "img_menu_fases/fase2_IDLE.png",
		"img_menu_fases/fase2.png", "img_menu_fases/fase2.png");
	this->Botoes["ESTADO_FASE_3"] = new Botao(362, 441, 558, 103, "img_menu_fases/fase3_IDLE.png",
		"img_menu_fases/fase3.png", "img_menu_fases/fase3.png");
	this->Botoes["ESTADO_VOLTAR"] = new Botao(549, 558, 192, 45, "img_menu_fases/voltar_IDLE.png",
		"img_menu_fases/voltar.png", "img_menu_fases/voltar.png");

	this->ganhou = false;
	this->proxFase = 0;
}

EstadoMenuFase::EstadoMenuFase(sf::RenderWindow* janela, std::stack<Estado*>* estados, bool ativaCoop)
	:Estado(janela,estados,ativaCoop)
{
	this->iniBotoes();

	this->planoDeFundo.setSize(sf::Vector2f(janela->getSize().x, janela->getSize().y));
	this->texturaPlanoDeFundo.loadFromFile("img_menu_fases/menu_fases.png");
	this->planoDeFundo.setTexture(&this->texturaPlanoDeFundo);

	this->musica = 1;
	this->trocaMusica = false;
}

EstadoMenuFase::~EstadoMenuFase()
{
	//Deleta todos botoes do map
	auto it = this->Botoes.begin();
	for (it = this->Botoes.begin(); it != this->Botoes.end(); it++)
	{
		delete it->second;
	}
}

/*void EstadoMenuFase::atualizaTeclas(const float& deltaTime)
{
}*/

void EstadoMenuFase::atualizaBotoes()
{
	//Atualiza todos os botoes do estado e aplica suas funcionalidades
	for (auto& it : this->Botoes)
	{
		it.second->atualiza(this->posMouseView);
	}

	
	//Funcoes dos Botoes
	//Novo Jogo
	if (this->Botoes["ESTADO_FASE_1"]->estaPressionado())
	{
		this->estados->push(new Fase1(this->janela, this->estados, this->ativaCoop,false));//Teste
	}
	if (this->Botoes["ESTADO_FASE_2"]->estaPressionado())
	{
		this->estados->push(new Fase2(this->janela, this->estados, this->ativaCoop,false));//Teste
	}
	if (this->Botoes["ESTADO_FASE_3"]->estaPressionado())
	{
		this->estados->push(new Fase3(this->janela, this->estados, this->ativaCoop, false));//Teste
	}

	//Sai do Jogo
	if (this->Botoes["ESTADO_VOLTAR"]->estaPressionado())
	{
		this->fechaEstado();
	}
}

void EstadoMenuFase::atualiza(const float& dt)
{
	//this->atualizaTeclas(dt);
	this->atualizaPosMouse();

	this->atualizaBotoes();

	//Printa posicao do mouse PODE SER UTIL DEPOIS
	//system("cls");
	//cout << this->posMouseView.x <<" "<< this->posMouseView.y << endl;

}

void EstadoMenuFase::renderizaBotoes(sf::RenderTarget& target)
{
	for (auto& it : this->Botoes)
	{
		it.second->renderiza(target);
	}
}

void EstadoMenuFase::renderiza(sf::RenderTarget* target)
{
	if (!target)
		target = this->janela;

	target->draw(this->planoDeFundo);

	this->view.setSize(this->planoDeFundo.getSize().x, this->planoDeFundo.getSize().y);
	this->view.setCenter(this->planoDeFundo.getSize().x / 2, this->planoDeFundo.getSize().y / 2);
	target->setView(view);

	this->renderizaBotoes(*target);
}
