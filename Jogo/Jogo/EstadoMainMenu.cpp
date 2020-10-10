#include "EstadoMainMenu.h"




void EstadoMainMenu::iniBotoes()
{
	this->Botoes["ESTADO_NOVO_JOGO_BTO"] = new Botao(510, 267, 260, 44, "img_main_menu/novo_jogo_IDLE.png",
		"img_main_menu/novo_jogo.png", "img_main_menu/novo_jogo.png");

	this->Botoes["ESTADO_SAIR_BTO"] = new Botao(578, 557, 125, 43, "img_main_menu/sair_IDLE.png",
		"img_main_menu/sair.png", "img_main_menu/sair.png");

	this->Botoes["ESTADO_NOVO_JOGO_COOP_BTO"] = new Botao(443, 326, 392, 43, "img_main_menu/novo_jogo_coop_IDLE.png",
		"img_main_menu/novo_jogo_coop.png", "img_main_menu/novo_jogo_coop.png");

	this->Botoes["ESTADO_CARREGAR_JOGO_BTO"] = new Botao(439, 384, 400, 44, "img_main_menu/carregar_jogo_IDLE.png",
		"img_main_menu/carregar_jogo.png", "img_main_menu/carregar_jogo.png");

	this->Botoes["ESTADO_FASES_BTO"] = new Botao(564, 442, 149, 43, "img_main_menu/fases_IDLE.png",
		"img_main_menu/fases.png", "img_main_menu/fases.png");

	this->Botoes["ESTADO_RANKING_BTO"] = new Botao(521, 500, 238, 42, "img_main_menu/ranking_IDLE.png",
		"img_main_menu/ranking.png", "img_main_menu/ranking.png");

	this->ganhou = false;
	this->proxFase = 0;
}


EstadoMainMenu::EstadoMainMenu(sf::RenderWindow* janela,std::stack<Estado*>* estados, bool ativaCoop)
	:Estado(janela, estados,ativaCoop)
{
	this->iniBotoes();

	this->planoDeFundo.setSize(sf::Vector2f(janela->getSize().x, janela->getSize().y));
	this->texturaPlanoDeFundo.loadFromFile("img_main_menu/BackgroundMainMenu.png");
	this->planoDeFundo.setTexture(&this->texturaPlanoDeFundo);
	
	this->musica = 1;
	this->trocaMusica = true;
}

EstadoMainMenu::~EstadoMainMenu()
{
	//Deleta todos botoes do map
	auto it = this->Botoes.begin();
	for (it = this->Botoes.begin(); it != this->Botoes.end(); it++)
	{
		delete it->second;
	}
}

void EstadoMainMenu::atualizaBotoes()
{
	//Atualiza todos os botoes do estado e aplica suas funcionalidades
	for (auto& it : this->Botoes)
	{
		it.second->atualiza(this -> posMouseView);
	}
	
	//Funcoes dos Botoes
	//Novo Jogo
	

	if (this->Botoes["ESTADO_NOVO_JOGO_BTO"]->estaPressionado())
	{
		this->estados->push(new Fase1(this->janela, this->estados,false,false));
	}
	if (this->Botoes["ESTADO_NOVO_JOGO_COOP_BTO"]->estaPressionado())
	{
		this->estados->push(new EstadoMenuFase(this->janela, this->estados, true));
	}
	if (this->Botoes["ESTADO_FASES_BTO"]->estaPressionado())
	{
		this->estados->push(new EstadoMenuFase(this->janela, this->estados, false));
	}
	if (this->Botoes["ESTADO_RANKING_BTO"]->estaPressionado())
	{
		ifstream entrada;
		entrada.open("Ranking.txt");
		vector<string> nomes;
		vector<int> pontos;

		int p, iaux;
		string n, saux;
		while (entrada >> n >> p)
		{
			nomes.push_back(n);
			pontos.push_back(p);
		}
		entrada.close();
		system("cls");
		cout << "RANKING:" << endl;
		for (int i = 0; i < pontos.size(); i++)
		{
			cout << nomes[i] << ' ' << pontos[i] << endl;
		}


	}
	//Sai do Jogo
	
		if (this->Botoes["ESTADO_SAIR_BTO"]->estaPressionado())
		{
			this->fechaEstado();
		}
	

}

/*void EstadoMainMenu::atualizaTeclas(const float& deltaTime)
{

}*/

void EstadoMainMenu::atualiza(const float& deltaTime)
{
	//this->atualizaTeclas(deltaTime);
	this->atualizaPosMouse();

	this->atualizaBotoes();

	
	//Printa posicao do mouse PODE SER UTIL DEPOIS
	//system("cls");
	//cout << this->posMouseView.x <<" "<< this->posMouseView.y << endl;

}

void EstadoMainMenu::renderizaBotoes(sf::RenderTarget& target)
{
	for (auto& it : this->Botoes)
	{
		it.second->renderiza(target);
	}
}

void EstadoMainMenu::renderiza(sf::RenderTarget* target)
{
	if (!target)
		target = this->janela;
	this->view.setSize(this->planoDeFundo.getSize().x, this->planoDeFundo.getSize().y);
	this->view.setCenter(this->planoDeFundo.getSize().x / 2, this->planoDeFundo.getSize().y / 2);
	target->setView(view);

	target->draw(this->planoDeFundo);
	this->renderizaBotoes(*target);
}
