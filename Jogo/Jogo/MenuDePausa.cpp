#include "MenuDePausa.h"



bool MenuDePausa::estaPressionado(string botao)
{
	return this->botoes[botao]->estaPressionado();
}
void MenuDePausa::iniBotoes()
{

	this->botoes["SAIR_BTO"] = new Botao(619, 721, 110, 43, "img_menu_pause/sair_IDLE.png",
		"img_menu_pause/sair.png", "img_menu_pause/sair.png");
	this->botoes["SALVAR_BTO"] = new Botao(506, 541, 289, 41, "img_menu_pause/salvar_jogo_IDLE.png",
		"img_menu_pause/salvar_jogo.png", "img_menu_pause/salvar_jogo.png");
	this->botoes["VOLTAR_BTO"] = new Botao(425, 595, 457, 41, "img_menu_pause/voltar_para_o_jogo_IDLE.png",
		"img_menu_pause/voltar_para_o_jogo.png", "img_menu_pause/voltar_para_o_jogo.png");
}

MenuDePausa::MenuDePausa(sf::RenderWindow& janela)
{
	this->iniBotoes();

	//Load a textura
	this->texturaPlanoDefundo.loadFromFile("img_menu_pause/menu_pause.png");

	//Inicializa conteiner
	this->planoDeFundo.setSize(sf::Vector2f(
		650*1.769+10,
		650));
	//this->planoDeFundo.setFillColor(sf::Color(20, 20, 20, 200));
	this->planoDeFundo.setPosition((sf::Vector2f(
		650,
		245.f)));
	this->planoDeFundo.setTexture(&this->texturaPlanoDefundo);

}

MenuDePausa::~MenuDePausa()
{
	//Deleta todos botoes do map
	auto it = this->botoes.begin();
	for (it = this->botoes.begin(); it != this->botoes.end(); it++)
	{
		delete it->second;
	}
}


//Funcoes
void MenuDePausa::atualiza(sf::Vector2f mousePos)
{
	for (auto& it : this->botoes)
	{
		it.second->atualiza(mousePos);
	}

	//Atualiza a posicao dos botoes com o plano de fundo
	this->botoes["SAIR_BTO"]->setPosicao(sf::Vector2f(this->planoDeFundo.getPosition().x + 528.f, 645.f));
	this->botoes["SALVAR_BTO"]->setPosicao(sf::Vector2f(this->planoDeFundo.getPosition().x + 434.f, 540.f));
	this->botoes["VOLTAR_BTO"]->setPosicao(sf::Vector2f(this->planoDeFundo.getPosition().x + 352.f, 593.f));
}

void MenuDePausa::atualizaPlanoDeFundo(sf::Vector2f pos)
{
	this->planoDeFundo.setPosition(pos);
}


void MenuDePausa::renderiza(sf::RenderTarget& target)
{
	target.draw(planoDeFundo);
	target.draw(planoDeFundo);

	for (auto& i : this->botoes)
	{
		i.second->renderiza(target);
	}
}
