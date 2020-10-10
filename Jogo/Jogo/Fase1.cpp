#include "Fase1.h"

Fase1::Fase1(sf::RenderWindow* janela, std::stack<Estado*>* estados, bool ativaCoop,bool carregaFase)
	:EstadoFase(janela,estados,ativaCoop,carregaFase)
{
	int i;
	//INICIALIZA TUDO
	//Inicializa Plataformas NAO RANDOMICAS
	Plataforma* plataforma;
	plataforma = new Plataforma(this->texturas["TEXTURA_PLATAFORMA_1"], sf::Vector2f(0, 795), sf::Vector2f(10, 50), sf::Vector2f(1463, 133),false);
	LP.inserir(plataforma);//0

	plataforma = new Plataforma(this->texturas["TEXTURA_PLATAFORMA_1"], sf::Vector2f(0, 795), sf::Vector2f(1630, 50), sf::Vector2f(1630, 133),true);
	LP.inserir(plataforma);//1

	plataforma = new Plataforma(this->texturas["TEXTURA_PLATAFORMA_1"], sf::Vector2f(0, 795), sf::Vector2f(3753, 50), sf::Vector2f(1585, 133), true);
	LP.inserir(plataforma);//2

	plataforma = new Plataforma(this->texturas["TEXTURA_PLATAFORMA_1"], sf::Vector2f(0, 795), sf::Vector2f(5496, 50), sf::Vector2f(1160, 133), true);
	LP.inserir(plataforma);//3
	
	plataforma = new Plataforma(this->texturas["TEXTURA_PLATAFORMA_1"], sf::Vector2f(0, 795), sf::Vector2f(7734, 50), sf::Vector2f(1266, 133), true);
	LP.inserir(plataforma);//4

	plataforma = new Plataforma(this->texturas["TEXTURA_PLATAFORMA_1"], sf::Vector2f(0, 795), sf::Vector2f(3420, 50), sf::Vector2f(176, 133), true);
	LP.inserir(plataforma);//F

	plataforma = new Plataforma(this->texturas["TEXTURA_PLATAFORMA_1"], sf::Vector2f(0, 795), sf::Vector2f(6820, 50), sf::Vector2f(295, 133), true);
	LP.inserir(plataforma);//F

	plataforma = new Plataforma(this->texturas["TEXTURA_PLATAFORMA_1"], sf::Vector2f(0, 795), sf::Vector2f(7270, 50), sf::Vector2f(295, 133), true);
	LP.inserir(plataforma);//F

	plataforma = new Plataforma(this->texturas["TEXTURA_PLATAFORMA_1"], sf::Vector2f(0, 795), sf::Vector2f(9163, 50), sf::Vector2f(837, 133), true);
	LP.inserir(plataforma);//F

	plataforma = new Plataforma(this->texturas["TEXTURA_PLATAFORMA_1"], sf::Vector2f(9913, 0), sf::Vector2f(0, 50), sf::Vector2f(50, 1842), true);
	LP.inserir(plataforma);//F

	plataforma = new Plataforma(this->texturas["TEXTURA_PLATAFORMA_1"], sf::Vector2f(25, 0), sf::Vector2f(0, 50), sf::Vector2f(50, 1842), true);
	LP.inserir(plataforma);//F

	
	
	int numeroInstancias;
	int intervalo=0;
	int pos;
	
//Se nao carrega fase	
	//inicializa Obstaculos
	//Pneus
	intervalo = 0;
	numeroInstancias = rand(5,10);
	for (i = 0; i < numeroInstancias; i++)
	{
		if ((intervalo == 0) && numeroInstancias != 0)
		{
			pos = rand(760, 1238);
			Pneu* pneu = new Pneu(this->texturas["TEXTURA_PNEU"], sf::Vector2f(pos, 700), sf::Vector2f(46, 0), sf::Vector2f(80, 100), 0);
			LO.inserir(pneu);
			intervalo++;
			numeroInstancias--;
		}
		if ((intervalo == 1) && numeroInstancias != 0)
		{
			pos = rand(1863, 3031);
			Pneu* pneu = new Pneu(this->texturas["TEXTURA_PNEU"], sf::Vector2f(pos, 700), sf::Vector2f(46, 0), sf::Vector2f(80, 100), 1);
			LO.inserir(pneu);
			intervalo++;
			
			numeroInstancias--;
		}
		if ((intervalo == 2) && numeroInstancias != 0)
		{
			pos = rand(3955, 5163);
			Pneu* pneu = new Pneu(this->texturas["TEXTURA_PNEU"], sf::Vector2f(pos, 700), sf::Vector2f(46, 0), sf::Vector2f(80, 100), 2);
			LO.inserir(pneu);
			intervalo++;
		
			numeroInstancias--;
		}
		if( (intervalo == 3) && numeroInstancias != 0)
		{
			pos = rand(5552, 6547);
			Pneu* pneu = new Pneu(this->texturas["TEXTURA_PNEU"], sf::Vector2f(pos, 700), sf::Vector2f(46, 0), sf::Vector2f(80, 100), 3);
			LO.inserir(pneu);
			intervalo++;
		
			numeroInstancias--;

		}
		if ((intervalo == 4) && numeroInstancias != 0)
		{
			pos = rand(7961, 8787);
			Pneu* pneu = new Pneu(this->texturas["TEXTURA_PNEU"], sf::Vector2f(pos, 700), sf::Vector2f(46, 0), sf::Vector2f(80, 100), 4);
			LO.inserir(pneu);
			intervalo++;
			numeroInstancias--;
		}
		if (intervalo >= 5)
		{
			intervalo = 0;
		}
	}

	//Caixas
	numeroInstancias =rand(5,10);
	for (i = 0; i < numeroInstancias; i++)
	{
		
		//Ve qual intervalo foi sorteado e da spawn nele
		if ((intervalo == 0)&& numeroInstancias!=0)
		{
			pos = rand(760, 1238);
			Caixa* caixa = new Caixa(this->texturas["TEXTURA_CAIXA"], sf::Vector2f(pos, 700), sf::Vector2f(7, 0), sf::Vector2f(63, 50), 0);
			intervalo++;
			LO.inserir(caixa);
			numeroInstancias--;
		}
		if ((intervalo == 1) && numeroInstancias != 0)
		{
			pos = rand(1863, 3031);
			Caixa* caixa = new Caixa(this->texturas["TEXTURA_CAIXA"], sf::Vector2f(pos, 700), sf::Vector2f(7, 0), sf::Vector2f(63, 50), 1);
			intervalo++;
			LO.inserir(caixa);
			numeroInstancias--;
		}
		if ((intervalo == 2) && numeroInstancias != 0)
		{
			pos = rand(3955, 5163);
			Caixa* caixa = new Caixa(this->texturas["TEXTURA_CAIXA"], sf::Vector2f(pos, 700), sf::Vector2f(7, 0), sf::Vector2f(63, 50), 2);
			intervalo++;
			LO.inserir(caixa);
			numeroInstancias--;
		}
		if ((intervalo == 3) && numeroInstancias != 0)
		{
			pos = rand(5552, 6547);
			Caixa* caixa = new Caixa(this->texturas["TEXTURA_CAIXA"], sf::Vector2f(pos, 700), sf::Vector2f(7, 0), sf::Vector2f(63, 50), 3);
			intervalo++;
			LO.inserir(caixa);
			numeroInstancias--;
			
		}
		if ((intervalo == 4) && numeroInstancias != 0)
		{
			pos = rand(7961, 8787);
			Caixa* caixa = new Caixa(this->texturas["TEXTURA_CAIXA"], sf::Vector2f(pos, 700), sf::Vector2f(7, 0), sf::Vector2f(63, 50),4);
			intervalo++;
			LO.inserir(caixa);
			numeroInstancias--;
		}
		if (intervalo >= 5)
		{
			intervalo = 0;
		}
	}
	
	
	//Colocar os inimigos
	//Alterego
	intervalo = 0;
	numeroInstancias = rand(5, 10);
	for (i = 0; i < numeroInstancias; i++)
	{
		if( (intervalo == 0) && numeroInstancias != 0)
		{
			pos = rand(760, 1238);
			Alterego* alterego = new Alterego(this->texturas["TEXTURA_ALTER_EGO"], sf::Vector2f(pos, 730), sf::Vector2f(40, 35), sf::Vector2f(75, 70));
			LI.inserir(alterego);
			intervalo++;
			numeroInstancias--;
		}
		if ((intervalo == 1) && numeroInstancias != 0)
		{
			pos = rand(1863, 3031);
			Alterego* alterego = new Alterego(this->texturas["TEXTURA_ALTER_EGO"], sf::Vector2f(pos, 730), sf::Vector2f(40, 35), sf::Vector2f(75, 70));
			LI.inserir(alterego);
			intervalo++;

			numeroInstancias--;
		}
		if ((intervalo == 2) && numeroInstancias != 0)
		{
			pos = rand(3955, 5163);
			Alterego* alterego = new Alterego(this->texturas["TEXTURA_ALTER_EGO"], sf::Vector2f(pos, 730), sf::Vector2f(40, 35), sf::Vector2f(75, 70));
			LI.inserir(alterego);
			intervalo++;

			numeroInstancias--;
		}
		if( (intervalo == 3) && numeroInstancias != 0)
		{
			pos = rand(5552, 6547);
			Alterego* alterego = new Alterego(this->texturas["TEXTURA_ALTER_EGO"], sf::Vector2f(pos, 730), sf::Vector2f(40, 35), sf::Vector2f(75, 70));
			LI.inserir(alterego);
			intervalo++;

			numeroInstancias--;

		}
		if ((intervalo == 4) && numeroInstancias != 0)
		{
			pos = rand(7961, 8787);
			Alterego* alterego = new Alterego(this->texturas["TEXTURA_ALTER_EGO"], sf::Vector2f(pos, 730), sf::Vector2f(40, 35), sf::Vector2f(75, 70));
			LI.inserir(alterego);
			intervalo++;
			numeroInstancias--;
		}
		if (intervalo >= 5)
		{
			intervalo = 0;
		}
	}
	//Slime
	intervalo = 0;
	numeroInstancias = rand(5, 10);
	for (i = 0; i < numeroInstancias; i++)
	{
		if( (intervalo == 0) && numeroInstancias != 0)
		{
			pos = rand(760, 1238);
			Slime* slime = new Slime(this->texturas["TEXTURA_SLIME"], sf::Vector2f(pos, 700), sf::Vector2f(24, 12), sf::Vector2f(50, 56));
			LI.inserir(slime);
			intervalo++;
			numeroInstancias--;
		}
		if( (intervalo == 1) && numeroInstancias != 0)
		{
			pos = rand(1863, 3031);
			Slime* slime = new Slime(this->texturas["TEXTURA_SLIME"], sf::Vector2f(pos, 700), sf::Vector2f(24, 12), sf::Vector2f(50, 56));
			LI.inserir(slime);
			intervalo++;

			numeroInstancias--;
		}
		if ((intervalo == 2) && numeroInstancias != 0)
		{
			pos = rand(3955, 5163);
			Slime* slime = new Slime(this->texturas["TEXTURA_SLIME"], sf::Vector2f(pos, 700), sf::Vector2f(24, 12), sf::Vector2f(50, 56));
			LI.inserir(slime);
			intervalo++;

			numeroInstancias--;
		}
		if ((intervalo == 3) && numeroInstancias != 0)
		{
			pos = rand(5552, 6547);
			Slime* slime = new Slime(this->texturas["TEXTURA_SLIME"], sf::Vector2f(pos, 700), sf::Vector2f(24, 12), sf::Vector2f(50, 56));
			LI.inserir(slime);
			intervalo++;

			numeroInstancias--;

		}
		if ((intervalo == 4) && numeroInstancias != 0)
		{
			pos = rand(7961, 8787);
			Slime* slime = new Slime(this->texturas["TEXTURA_SLIME"], sf::Vector2f(pos, 700), sf::Vector2f(24, 12), sf::Vector2f(50, 56));
			LI.inserir(slime);
			intervalo++;
			numeroInstancias--;
		}
		if (intervalo >= 5)
		{
			intervalo = 0;
		}
	}
	
	//Coloca plataformas na lista de entidades
	for (i = 0; i < LP.getNumElementos(); i++)
	{
		LE.inserir(LP.getObjeto(i));
	}
	//Coloca objetos na lista de entidades
	for (i = 0; i < LO.getNumElementos(); i++)
	{
		LE.inserir(LO.getObjeto(i));
	}
	//Coloca os inimigos na lista de entidades
	for (i = 0; i < LI.getNumElementos(); i++)
	{
		LE.inserir(LI.getObjeto(i));
	}

	//Inicializa Background
	this->planoDeFundo.setSize(sf::Vector2f(janela->getSize().x, janela->getSize().y));
	this->texturaPlanoDeFundo.loadFromFile("img_backgrounds/BackgroundFase1.png");
	this->planoDeFundo.setTexture(&this->texturaPlanoDeFundo);
	this->planoDeFundo.setOrigin(this->planoDeFundo.getSize().x / 2, 370);

	//inicializa musica
	this->musica = 2;
	this->trocaMusica = true;
	//delay do game over
	this->delay = new sf::Clock();

	this->ganhou = false;
	this->proxFase = 2;//Fase dois
}

Fase1::~Fase1()
{
	delete this->delay;
}

void Fase1::atualiza(const float& deltaTime)
{
	this->atualizaPosMouse();
	this->atualizaTeclas(deltaTime);//Tecla de pause e do game over

	//Atualiza nao pausado
	if (!this->pausado)
	{

		this->atualizaView();
		
		this->atualizaTeclas(deltaTime);

		this->atualizaPosMouse();
	
		//Printa posicao do mouse PODE SER UTIL DEPOIS
		// cout << this->posMouseView.x << " " << this->posMouseView.y << endl;
		//system("cls");
		
		this->P1->atualizaMovimento(deltaTime);
		this->barraDeVida1->atualiza(P1->getVida());

		


		if (ativaCoop)
		{
			//se o p1 morreu primeiro
			if ((P1->getVida() <= 0)&& (P2->getVida() > 0))
			{
				if (P2->getPosicao().x > 9700)
				{
					ganhou = true;
					contaPontuacao();
					fechaEstado();
				}
			}
			//se o p2 morreu primeiro
			else if ((P2->getVida() <= 0) && (P1->getVida() > 0))
			{
				if (P1->getPosicao().x > 9700)
				{
					ganhou = true;
					contaPontuacao();
					fechaEstado();
				}
			}
			//se os dois estao vivos
			else if (P1->getVida() > 0 && P2->getVida() > 0)
			{
				if ((P1->getPosicao().x > 9700)&& (P2->getPosicao().x > 9700))
				{
				ganhou = true;
				contaPontuacao();
				fechaEstado();
				}

			}
			
			this->P2->atualizaMovimento(deltaTime);
			this->barraDeVida2->atualiza(P2->getVida());
			
			//Configuracao do game over caso de 2 jogadores
			if ((P1->getPosicao().y > 800)&&(jogadoresVivos > 0))
			{
				P1->setVida(0);
			}
			if ((P2->getPosicao().y > 800) && (jogadoresVivos > 0))
			{
				P2->setVida(0);
			}
			if ((P1->getVida() == 0)&& (P2->getVida() == 0))
			{
				jogadoresVivos=0;
			}
			if ((P2->getVida() == 0) && (jogadoresVivos == 0))
			{
				delay->restart();
				jogadoresVivos--;
				P2->setVida(-1);
				gameOver = true;
			}
		}
		else
		{
			//Jogador ganha
			if (P1->getPosicao().x > 9700)
			{
			ganhou = true;
			contaPontuacao();
			fechaEstado();
			}

			//Configuracao de game over caso de 1 jogador
			if ((P1->getPosicao().y > 890) && (jogadoresVivos > 0))
			{
				P1->setVida(0);
			}
			if (P1->getVida() == 0)
			{
				jogadoresVivos=0;
			}
			if ((P1->getVida() == 0) && (jogadoresVivos == 0))
			{
				delay->restart();
				jogadoresVivos--;
				P1->setVida(-1);
				gameOver = true;
			}
			

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

void Fase1::renderiza(sf::RenderTarget* target)
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