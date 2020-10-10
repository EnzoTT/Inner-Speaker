#include "EstadoFase.h"
static const float VIEW_HEIGHT = 650.0f;

void EstadoFase::iniMenuDePausa()
{
	this->menuDePausa = new MenuDePausa(*this->janela);
}

//Inicializadoras
void EstadoFase::iniTexturas()
{
	sf::Texture temp;
	temp.loadFromFile("img_personagens/player1.png");//Carrega a textura 
	this->texturas["TEXTURA_JOGADOR_1"] = temp;//Coloca ela no map de texturas

	temp.loadFromFile("img_personagens/player2.png");
	this->texturas["TEXTURA_JOGADOR_2"] = temp;

	temp.loadFromFile("img_personagens/alterego.png");
	this->texturas["TEXTURA_ALTER_EGO"] = temp;

	temp.loadFromFile("img_personagens/slime.png");
	this->texturas["TEXTURA_SLIME"] = temp;

	temp.loadFromFile("img_personagens/robo.png");
	this->texturas["TEXTURA_ROBO"] = temp;

	temp.loadFromFile("img_personagens/trevor.png");
	this->texturas["TEXTURA_TREVOR"] = temp;

	temp.loadFromFile("img_plataformas/plataformaFase1.png");
	this->texturas["TEXTURA_PLATAFORMA_1"] = temp;

	temp.loadFromFile("img_plataformas/plataformaFase2.png");
	this->texturas["TEXTURA_PLATAFORMA_2"] = temp;

	temp.loadFromFile("img_plataformas/plataformaFase3.png");
	this->texturas["TEXTURA_PLATAFORMA_3"] = temp;

	temp.loadFromFile("img_obstaculos/caixa.png");
	this->texturas["TEXTURA_CAIXA"] = temp;

	temp.loadFromFile("img_obstaculos/pneu.png");
	this->texturas["TEXTURA_PNEU"] = temp;

	temp.loadFromFile("img_obstaculos/carro.png");
	this->texturas["TEXTURA_CARRO"] = temp;
	

	this->telaDeGameOver.setSize(sf::Vector2f(650 * 1.769 + 10,650));
	this->texturaTelaDeGameOver.loadFromFile("game_over.png");
	this->telaDeGameOver.setTexture(&this->texturaTelaDeGameOver);
	this->telaDeGameOver.setOrigin(sf::Vector2f(janela->getSize().x/2.f, janela->getSize().y/2.f));

	
}

void EstadoFase::iniJogadores()
{
	//Cria jogador 1
	this->P1 = new Jogador(this->texturas["TEXTURA_JOGADOR_1"], sf::Vector2f(147, 792), sf::Vector2f(25, 35), 
		sf::Vector2f(47, 67), 120.0f);
	P1->setInvencivel(false);
	P1->setJogador(false);

	//Cria jogador 2 se for coop
	if (ativaCoop)
	{
		this->P2 = new Jogador(this->texturas["TEXTURA_JOGADOR_2"], sf::Vector2f(260, 790), sf::Vector2f(20, 35), 
			sf::Vector2f(54, 67), 150.0f);
		this->P2->setJogador(true);
	}

	this->barraDeVida1 = new BarraDeVida(140, 35, "img_barra_de_vida/barra_0_P1.png", "img_barra_de_vida/barra_1_P1.png",
		"img_barra_de_vida/barra_2_P1.png", "img_barra_de_vida/barra_3_P1.png", "img_barra_de_vida/barra_4_P1.png",
		"img_barra_de_vida/barra_5_P1.png", "img_barra_de_vida/barra_6_P1.png");

	this->barraDeVida2 = new BarraDeVida(140, 35, "img_barra_de_vida/barra_0_P2.png", "img_barra_de_vida/barra_1_P2.png",
		"img_barra_de_vida/barra_2_P2.png", "img_barra_de_vida/barra_3_P2.png", "img_barra_de_vida/barra_4_P2.png",
		"img_barra_de_vida/barra_5_P2.png", "img_barra_de_vida/barra_6_P2.png");
}

//Construtoras/Destrutoras
EstadoFase::EstadoFase(sf::RenderWindow* janela, std::stack<Estado*>* estados,bool ativaCoop, bool carregaFase)
	:Estado(janela,estados,ativaCoop)
{
	//Inicializa a textura e o player
	this->iniMenuDePausa();
	this->iniTexturas();
	this->iniJogadores();

	this->gameOver = false;

	if (ativaCoop)
		jogadoresVivos = 2;
	else
		jogadoresVivos = 1;

	//if (carregaFase)
	//{
	//	this->carregaFase();
	//}
}

EstadoFase::~EstadoFase()
{
	delete this->menuDePausa;
	delete this->P1;
	delete this->barraDeVida1;
	delete this->barraDeVida2;
}

void EstadoFase::atualizaBotoes()
{
	//Funcoes dos Botoes do menu de pausa
	if (this->menuDePausa->estaPressionado("SAIR_BTO"))
	{
		this->fechaEstado();
	}
	if (this->menuDePausa->estaPressionado("VOLTAR_BTO"))
	{
		this->pausado=false;
	}
}

void EstadoFase::atualizaTeclas(const float & deltaTime)
{	
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))&&!gameOver)
	{
		if (!this->pausado)
			this->pausaEstado();

	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) && gameOver)
	{
		this->fechaEstado();
	}
}

void EstadoFase::atualizaView()
{
	//A barra de vida e o plano de fundo atualizam com a view
	if(P1->getVida() != 0)
	{ 
		if (proxFase == 4)
		{
			if (this->P1->getPosicao().x < 550)
			{
				view.setCenter(650, 570);
			}
			else if (this->P1->getPosicao().x > 800)
			{
				view.setCenter(900, 570);
			}
			else
			{

				view.setCenter(P1->getPosicao().x + 100, 570);
			}
		}
		else
		{

		if (this->P1->getPosicao().x < 550)
		{
		view.setCenter(650, 570);
		}
		else if (this->P1->getPosicao().x > 9237)
		{
			view.setCenter(9337, 570);
		}
		else
		{

			view.setCenter(P1->getPosicao().x + 100, 570);
		}
		}
	}
	else if ((ativaCoop) && P2->getVida() > 0)
	{
		if (proxFase == 4)
		{
			if (this->P2->getPosicao().x < 550)
			{
				view.setCenter(650, 570);
			}
			else if (this->P2->getPosicao().x > 800)
			{
				view.setCenter(900, 570);
			}
			else
			{

				view.setCenter(P2->getPosicao().x + 100, 570);
			}
		}
		else
		{

		if (this->P2->getPosicao().x < 550)
		{
			view.setCenter(650, 570);
		}
		else if (this->P2->getPosicao().x > 9237)
		{
			view.setCenter(9337, 570);
		}
		else
		{

			view.setCenter(P2->getPosicao().x + 100, 570);
		}
		}
	}
	if (ativaCoop)
	{
		this->barraDeVida2->atualizaPos(sf::Vector2f(view.getCenter().x - 569, view.getCenter().y - 275));
	}
		this->barraDeVida1->atualizaPos(sf::Vector2f(view.getCenter().x - 569, view.getCenter().y - 319));

	//this->menuDePausa->atualizaPlanoDeFundo(sf::Vector2f(view.getCenter().x - 580, 245.f));
	this->planoDeFundo.setPosition(view.getCenter().x, 500);
	this->telaDeGameOver.setPosition(view.getCenter().x+58, view.getCenter().y+35);
}

void EstadoFase::atualizaListas(const float& deltaTime)
{
	int i;
	for (i = 0; i < LI.getNumElementos(); i++)
	{
		LI.getObjeto(i)->atualizaMovimento(deltaTime);
		if (LI.getObjeto(i)->getVida() <= 0)
		{
			LI.getObjeto(i)->setMorto(true);
		}

	}
	for (i = 0; i < LO.getNumElementos(); i++)
	{
		LO.getObjeto(i)->atualiza(deltaTime);
	}
}

void EstadoFase::gerenciaColisao()
{
	int i, j;

	sf::Vector2f direcaoJ1;//direcao do jogador 1
	Colisor CJ1 = P1->getColisor();//Colisor do jogador 1

	sf::Vector2f direcaoJ2;//direcao do jogador 2
	Colisor CJ2 = P2->getColisor();//Colisor do jogador 2


	sf::Vector2f direcaoO;//direcao do objeto que esta colidindo
	sf::Vector2f direcaoO2;

	sf::Vector2f direcaoI;//direcao dos inimigos


	//Colisao de tudo com as plataformas
	for (i = 0; i < LP.getNumElementos(); i++)
	{
		Colisor CP = LP.getObjeto(i)->getColisor();//colisor da plataforma

		//verifica colisao da plataforma com o Jogador 1
		CP.verificaColisao(CJ1, direcaoJ1, 1.f);

		//Com jogador 2
		if (ativaCoop)
		{
			CP.verificaColisao(CJ2, direcaoJ2, 1.f);
		}

		//Inimigos com a Plataforma e com o Jogador
		for (j = 0; j < LI.getNumElementos(); j++)
		{
			Colisor CI = LI.getObjeto(j)->getColisor();//Colisor do inimigo

			//Plataforma
			CP.verificaColisao(CI, direcaoI, 1.f);


			LI.getObjeto(j)->emColisao(direcaoI);//atualiza a direcaoI

			
		}

		
	}

	//Inimigos com o jogardor
	for (j = 0; j < LI.getNumElementos(); j++)
	{
		Colisor CI = LI.getObjeto(j)->getColisor();

		CJ1.verificaColisao(CI, direcaoI, 1.f);
		LI.getObjeto(j)->emColisao(direcaoI);//atualiza a direcaoI
		if ((CI.verificaColisao(CJ1, direcaoJ1, 1.f)) && (!LI.getObjeto(j)->getInvencivel()) && (!LI.getObjeto(j)->getDano() && (!LI.getObjeto(j)->getMorto())))
		{

			if (LI.getObjeto(j)->getFoiAtacado())
			{

				P1->setAtacou(true);
			}
			else
				P1->setAtacou(false);
			
			//LI.getObjeto(j)->setInvencivel(false);
			LI.getObjeto(j)->atualizaVida((CI.verificaColisao(CJ1, direcaoJ1, 1.f)) && (!LI.getObjeto(j)->getInvencivel()) && (!LI.getObjeto(j)->getDano()));

			cout << "inimigo levou dano do Jogador 1" << endl;
		}
		
		P1->atualizaVida(((CI.verificaColisao(CJ1, direcaoJ1, 1.f)) && !this->P1->getInvencivel()) && LI.getObjeto(j)->getDano());
		
		if ((CI.verificaColisao(CJ1, direcaoJ1, 1.f)) && !this->P1->getInvencivel() && LI.getObjeto(j)->getDano())
		{
			if (this->proxFase == 4)
			{
				P1->atualizaVida(((CI.verificaColisao(CJ1, direcaoJ1, 1.f)) && !this->P1->getInvencivel()) && LI.getObjeto(j)->getDano());
			}
			P1->setInvencivel(true);
		}
		

		//Com Jogador 2
		if (ativaCoop)
		{
			CJ2.verificaColisao(CI, direcaoI, 1.f);
			LI.getObjeto(j)->emColisao(direcaoI);//atualiza a direcaoI
			if ((CI.verificaColisao(CJ2, direcaoJ2, 1.f)) && (!LI.getObjeto(j)->getInvencivel()) && (!LI.getObjeto(j)->getDano()&& (!LI.getObjeto(j)->getMorto())))
			{

				if (LI.getObjeto(j)->getFoiAtacado())
				{
					P2->setAtacou(true);
				}
				else
					P2->setAtacou(false);

				LI.getObjeto(j)->atualizaVida((CI.verificaColisao(CJ2, direcaoJ2, 1.f)) && (!LI.getObjeto(j)->getInvencivel()) && (!LI.getObjeto(j)->getDano()));
				cout << "inimigo levou dano do Jogador 2" << endl;
			}
			P2->atualizaVida(((CI.verificaColisao(CJ2, direcaoJ2, 1.f)) && !this->P2->getInvencivel()) && LI.getObjeto(j)->getDano());
			if ((CI.verificaColisao(CJ2, direcaoJ2, 1.f)) && !this->P2->getInvencivel() && LI.getObjeto(j)->getDano())
			{
				if (this->proxFase == 4)
				{
					P2->atualizaVida(((CI.verificaColisao(CJ2, direcaoJ2, 1.f)) && !this->P2->getInvencivel()) && LI.getObjeto(j)->getDano());
				}

				P2->setInvencivel(true);
			}
		}
	}

	//Objetos 
		for (i = 0; i < LO.getNumElementos(); i++)
		{

			Colisor CO = LO.getObjeto(i)->getColisor();//Colisor do objeto
			Colisor CP = LP.getObjeto(LO.getObjeto(i)->getIntervalo())->getColisor();
			
			
			//Plataformas
			CO.verificaColisao(CP, direcaoO, 0.f);
		
			//Jogador
			CO.verificaColisao(CJ1, direcaoJ1, LO.getObjeto(i)->getPeso());
			CJ1.verificaColisao(CO, direcaoO, 0.f);

			//Jogador 2
			if (ativaCoop)
			{
				CO.verificaColisao(CJ2, direcaoJ2, LO.getObjeto(i)->getPeso());
				CJ2.verificaColisao(CO, direcaoO, 0.f);
			}
			
			LO.getObjeto(i)->emColisao(direcaoO);//atualiza direcaoO
		}

	P1->emColisao(direcaoJ1);//atualiza direcaoJ1
	if (ativaCoop)
		P2->emColisao(direcaoJ2);//atualiza direcaoJ2

		
	//Deixa um pequeno delay pro player tomar dano
	this->timer = this->Clock.getElapsedTime().asSeconds();
	if (timer > 1.5)
	{
		this->P1->setInvencivel(false);
		if (ativaCoop && P2->getInvencivel())
			this->P2->setInvencivel(false);
		this->Clock.restart();
	}
}

void EstadoFase::salvaFase()
{
}

void EstadoFase::carregaFase()
{
	
}

void EstadoFase::contaPontuacao()
{
	int cont = 1, i;
	for (i = 0; i < LI.getNumElementos(); i++)
	{
		if (LI.getObjeto(i)->getMorto())
		{
			cont++;
		}
	}
	//Cada inimigo morto vale 100 pontos
	this->pontuacao =(cont * 100)-100;
	if (getProxFase() == 4)
	{
		//matou o boss
		this->pontuacao = 1000;
	}

}
