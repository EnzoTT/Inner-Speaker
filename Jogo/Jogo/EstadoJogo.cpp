#include "EstadoJogo.h"
static const float VIEW_HEIGHT = 600.0f;

//Inicializadoras
void EstadoJogo::iniTexturas()
{
	sf::Texture temp, temp1, temp2;
	temp.loadFromFile("img_personagens/player1.png");//Carrega a textura 
	this->texturas["TEXTURA_JOGADOR"] = temp;//Coloca ela no map de texturas

	temp1.loadFromFile("img_personagens/alterego.png");
	this->texturas["TEXTURA_INIMIGO"] = temp1;

	temp2.loadFromFile("chao.png");
	this->texturas["TEXTURA_PLATAFORMA"] = temp2;


	this->planoDeFundo.setSize(sf::Vector2f(janela->getSize().x, janela->getSize().y));
	this->texturaPlanoDeFundo.loadFromFile("img_backgrounds/Background2.jpg");
	this->planoDeFundo.setTexture(&this->texturaPlanoDeFundo);
	this->planoDeFundo.setOrigin(this->planoDeFundo.getSize().x / 2, 370);


}

void EstadoJogo::iniJogadores()
{
	this->P1 = new Jogador(this->texturas["TEXTURA_JOGADOR"],sf::Vector2f(300,500), sf::Vector2f(20, 35), sf::Vector2f(54, 67),80.0f);//Cria jogador 1
	//this->P1 = new Jogador(this->texturas["TEXTURA_JOGADOR"], sf::Vector2f(300, 500), sf::Vector2f(0,38), sf::Vector2f(112, 82), 100.0f);
	this->Ini1 = new Inimigo(this->texturas["TEXTURA_INIMIGO"], sf::Vector2f(400, 600), sf::Vector2f(18, 20), sf::Vector2f(40, 50));//Cria inimigo
	this->plat = new Plataforma(this->texturas["TEXTURA_PLATAFORMA"], sf::Vector2f(1, 663), sf::Vector2f(0, 0), sf::Vector2f(6750, 200));
	P1->setInvencivel(false);
	this->Ini1->setInvencivel(false);

	this->barraDeVida = new BarraDeVida(140, 35, "img_barra_de_vida/barra_0_P2.png", "img_barra_de_vida/barra_1_P2.png", "img_barra_de_vida/barra_2_P2.png", "img_barra_de_vida/barra_3_P2.png", "img_barra_de_vida/barra_4_P2.png", "img_barra_de_vida/barra_5_P2.png", "img_barra_de_vida/barra_6_P2.png");

}

//Construtoras/Destrutoras
EstadoJogo::EstadoJogo(sf::RenderWindow* janela, std::stack<Estado*>* estados)
	:Estado(janela,estados)
{
	//Inicializa a textura e o player
	this->iniTexturas();
	this->iniJogadores();

}


EstadoJogo::~EstadoJogo()
{
	delete this->P1;
	delete this->Ini1;
	delete this->plat;
	delete this->barraDeVida;
}



void EstadoJogo::atualizaTeclas(const float & deltaTime)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->fechaEstado();
	}
	
}


void EstadoJogo::atualiza(const float & deltaTime)
{
	this->atualizaPosMouse();

	this->atualizaTeclas(deltaTime);

	this->atualizaView(); 


	/*this->atualizaPosMouse();

	//Printa posicao do mouse PODE SER UTIL DEPOIS
	cout << this->posMouseView.x <<" "<< this->posMouseView.y << endl;*/

	//system("cls");
	this->planoDeFundo.setPosition(P1->getPosicao().x,550);

	
	this->P1->atualizaMovimento(deltaTime);
	this->P1->atualiza(deltaTime);
	this->Ini1->atualizaHitbox();

	//Colisao
	sf::Vector2f direcao;
	sf::Vector2f direcaoI;
	Colisor CP = P1->getColisor();
	Colisor CI = Ini1->getColisor();
	Colisor CPlat = plat->getColisor();
	
	
	//Deixa um pequeno delay pro player tomar dano
	this->timer = this->Clock.getElapsedTime().asSeconds();

	//if ((CI.verificaColisao(CP, direcao, 1.f))&&(!this->P1->getInvencivel()))
	//{
	
	this->P1->atualizaVida((CI.verificaColisao(CP, direcao, 1.f)) && (!this->P1->getInvencivel())&& (this->Ini1->getDano()));
			//this->P1->setInvencivel(true);

	
	
		
	//}
	this->Ini1->atualizaVida((CI.verificaColisao(CP, direcao, 1.f)) && (!this->Ini1->getInvencivel()&&(this->Ini1->getDano())));
	if ((CI.verificaColisao(CP, direcao, 1.f)) && (!this->Ini1->getInvencivel()) && (!this->Ini1->getDano()))
	{
		
			this->P1->setVelocidadeVetorialX(0.0f);
			P1->atacou = true;
			//this->P1->somaVelocidadeVetorialY(981.0f * deltaTime);
			this->P1->moveSprite(this->P1->getVelocidadeVetorial() * deltaTime);
		cout << "inimigo levou dano" << endl;
	}


	CP.verificaColisao(CI, direcaoI, 0.f);
	//cout << this->Ini1->getVida()<<endl;
	cout << this->P1->getVida() << endl;
	
	if (timer > 1.5)
	{
		this->P1->setInvencivel(false);
		this->Ini1->setInvencivel(false);
		this->Clock.restart();
	}
	

	
	CPlat.verificaColisao(CP, direcao, 1.f);
	CPlat.verificaColisao(CI, direcao, 1.f);
	P1->emColisao(direcao);
	Ini1->emColisao(direcaoI);

	this->barraDeVida->atualiza(P1->getVida());

}

void EstadoJogo::atualizaView()
{
	view.setCenter(P1->getPosicao().x, P1->getPosicao().y);
}

void EstadoJogo::renderiza(sf::RenderTarget* target)
{
	if (!target)
		target = this->janela;
	target->draw(this->planoDeFundo);
	
	//Renderiza as variaveis do estado jogo
	this->plat->renderiza(*target);
	this->P1->renderiza(*target);
	this->Ini1->renderiza(*target);
	this->barraDeVida->renderiza(*target);
	
	target->setView(view);
	
	float aspectRatio = float(target->getSize().x) / float(target->getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}