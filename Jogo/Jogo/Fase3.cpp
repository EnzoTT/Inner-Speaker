#include "Fase3.h"
#include "Trevor.h"


Fase3::Fase3(sf::RenderWindow* janela, std::stack<Estado*>* estados, bool ativaCoop, bool carregaFase)
	:EstadoFase(janela,estados,ativaCoop, carregaFase)
{

	Plataforma* plataforma;
	plataforma = new Plataforma(this->texturas["TEXTURA_PLATAFORMA_3"], sf::Vector2f(0, 800), sf::Vector2f(10, 50), sf::Vector2f(1490, 133), false);
	LP.inserir(plataforma);
	LE.inserir(plataforma);

	plataforma = new Plataforma(this->texturas["TEXTURA_PLATAFORMA_1"], sf::Vector2f(1475, 0), sf::Vector2f(0, 50), sf::Vector2f(50, 1842), true);
	LP.inserir(plataforma);//F

	plataforma = new Plataforma(this->texturas["TEXTURA_PLATAFORMA_1"], sf::Vector2f(25, 0), sf::Vector2f(0, 50), sf::Vector2f(50, 1842), true);
	LP.inserir(plataforma);//F

	//Coloca o Boss
	Trevor* trevor;
	trevor = new Trevor(this->texturas["TEXTURA_TREVOR"], sf::Vector2f(978, 797), sf::Vector2f(0, 0), sf::Vector2f(80, 90));
	LI.inserir(trevor);
	LE.inserir(trevor);

	//Inicializa Background
	this->planoDeFundo.setSize(sf::Vector2f(janela->getSize().x, janela->getSize().y));
	this->texturaPlanoDeFundo.loadFromFile("img_backgrounds/BackgroundFase2.png");
	this->planoDeFundo.setTexture(&this->texturaPlanoDeFundo);
	this->planoDeFundo.setOrigin(this->planoDeFundo.getSize().x / 2, 370);

	this->musica = 4;
	this->trocaMusica = true;
	
	this->ganhou = false;
	this->proxFase = 4;

	//delay do game over
	this->delay = new sf::Clock();
}


Fase3::~Fase3()
{
	delete this->delay;
}



void Fase3::atualiza(const float& deltaTime)
{
	this->atualizaPosMouse();
	this->atualizaTeclas(deltaTime);//Tecla de pause e do game over

	//Atualiza nao pausado
	if (!this->pausado)
	{

		this->atualizaTeclas(deltaTime);

		this->atualizaView();

		this->atualizaPosMouse();

		//Printa posicao do mouse PODE SER UTIL DEPOIS
		//cout << this->posMouseView.x << " " << this->posMouseView.y << endl;
		//system("cls");

		this->P1->atualizaMovimento(deltaTime);
		this->barraDeVida1->atualiza(P1->getVida());


		if (ativaCoop)
		{

			

			this->P2->atualizaMovimento(deltaTime);
			this->barraDeVida2->atualiza(P2->getVida());

			//Configuracao do game over caso de 2 jogadores
			if ((P1->getPosicao().y > 800) && (jogadoresVivos > 0))
			{
				P1->setVida(0);
			}
			if ((P2->getPosicao().y > 800) && (jogadoresVivos > 0))
			{
				P2->setVida(0);
			}
			if ((P1->getVida() <= 0) && (P2->getVida() <= 0))
			{
				jogadoresVivos = 0;
				gameOver = true;
			}
			if ((P2->getVida() <= 0) && (jogadoresVivos == 0))
			{
				
				gameOver = true;
			}
		}
		else
		{
			

			//Configuracao de game over caso de 1 jogador
			if ((P1->getPosicao().y > 890) && (jogadoresVivos > 0))
			{
				P1->setVida(0);
			}
			if (P1->getVida() == 0)
			{
				jogadoresVivos = 0;
			}
			if ((P1->getVida() == 0) && (jogadoresVivos == 0))
			{
				delay->restart();
				jogadoresVivos--;
				P1->setVida(-1);
				gameOver = true;
			}


		}
		//Se o Boss Morreu voce ganhou
			if (LI.getObjeto(0)->getMorto()&&(!gameOver))
			{
				ganhou = true;
				contaPontuacao();
				fechaEstado();
			}
		atualizaListas(deltaTime);
		gerenciaColisao();

	}

	//Atualiza pausado
	else
	{
		this->menuDePausa->atualiza(this->posMouseView);
		this->atualizaBotoes();
	}

}

void Fase3::renderiza(sf::RenderTarget * target)
{
	int i;
	if (!target)
		target = this->janela;
	target->draw(this->planoDeFundo);

	for (i = 0; i < LE.getNumElementos(); i++)
	{
		LE.getElemento(i)->renderiza(*target);
	}


	this->P1->renderiza(*target);
	this->barraDeVida1->renderiza(*target);
	if (ativaCoop)
	{
		this->P2->renderiza(*target);
		this->barraDeVida2->renderiza(*target);
	}


	//Configuracao da view
	target->setView(view);

	float aspectRatio = float(target->getSize().x) / float(target->getSize().y);
	view.setSize(650 * aspectRatio, 650);

	if (this->pausado)//renderiza o menu de pausa
	{
		this->menuDePausa->renderiza(*target);
	}

	//Atualiza pos do plano de fundo do menu
	this->menuDePausa->atualizaPlanoDeFundo(sf::Vector2f(view.getCenter().x - 580, 245.f));

	if (gameOver && (delay->getElapsedTime().asSeconds() > 1))
	{
		this->pontuacao = -1;//Perdeu todos os pontos
		target->draw(this->telaDeGameOver);
	}



}