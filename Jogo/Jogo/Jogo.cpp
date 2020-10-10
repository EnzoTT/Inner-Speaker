#include "Jogo.h"
#include "EstadoMenuFase.h"

//Funcoes inicializar
void Jogo::iniJanela()
{
	/*Renderiza uma janela na variavel janela*/
	this->janela = new sf::RenderWindow(sf::VideoMode(1280.f, 720.f), "Jogo", sf::Style::Titlebar | sf::Style::Close);
	this->janela->setFramerateLimit(120.f);

}

void Jogo::iniEstados()
{

	//Coloca os estados na pilha de estados (PILHA ORIGINAL) 
	this->Estados.push(new EstadoMainMenu(this->janela, &this->Estados, false));
}

//Construtora/Destrutora
Jogo::Jogo()
{
	this->iniJanela();
	this->iniEstados();
}

Jogo::~Jogo()
{
	//Limpa a execucao
	delete this->janela;

	while (!this->Estados.empty())
	{
		delete this->Estados.top();
		this->Estados.pop();
	}
}


//Funcoes update
void Jogo::atualizaDT()
{
	/*Atualiza o dt com o tempo que leva para atualizar e renderizar um frame*/
	this->dt = this->Clock.restart().asSeconds();
	if (this->dt > 1.0f / 20.0f)
		this->dt = 1.0f / 20.0f;
}

void Jogo::atualizaSFMLEvents()
{
	//Eventos
	while (this->janela->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->janela->close();
	}
}

void Jogo::atualiza()
{
	this->atualizaSFMLEvents();
	this->atualizaMusica();
	//Update o estado
	if (!this->Estados.empty())
	{
		this->Estados.top()->atualiza(this->dt);

		//Tem um pequeno delay pois os botoes atualizam muito rapido causando clicks indesejados
		if (timer.getElapsedTime().asSeconds() > 2)
		{
			//Se o estado atual pediu para fechar fecha ele
			if (this->Estados.top()->getSair())
			{

				this->musicaAnterior = Estados.top()->getMusica();
				if (this->Estados.top()->getGanhou())
				{
					//verifica proxima fase
					if (this->Estados.top()->getProxFase() == 2)
					{
						pontonsAtual = this->Estados.top()->getPontuacao() + pontonsAtual;
						delete this->Estados.top();
						this->Estados.pop();
					
						this->Estados.push(new Fase2(this->janela, &this->Estados, this->Estados.top()->getCoop(),false));
						
						

					}
					else if (this->Estados.top()->getProxFase() == 3)
					{
						pontonsAtual = this->Estados.top()->getPontuacao() + pontonsAtual;
						delete this->Estados.top();
						this->Estados.pop();
						this->Estados.push(new Fase3(this->janela, &this->Estados, this->Estados.top()->getCoop(), false));
					}
					else if (this->Estados.top()->getProxFase() == 4)
					{
						pontonsAtual = this->Estados.top()->getPontuacao() + pontonsAtual;
						cout << "digite seu nome:" << endl;
						cin >> nome;
						

						ifstream in;
						ofstream out;

						in.open("Ranking.txt");
						int p, iaux;
						string n, saux;

						vector<string> nomes;
						vector<int> pontos;
						while (in >> n >> p)
						{
							nomes.push_back(n);
							pontos.push_back(p);
						}
						in.close();
						nomes.push_back(nome);
						pontos.push_back(Estados.top()->getPontuacao());
						

						for (int i = 0; i < pontos.size(); i++)
						{
							for (int j = i + 1; j < pontos.size(); j++)
							{
								if (pontos[i] < pontos[j])
								{
									iaux = pontos[i];
									saux = nomes[i];
									pontos[i] = pontos[j];
									nomes[i] = nomes[j];
									pontos[j] = iaux;
									nomes[j] = saux;
								}
							}
						}

						out.open("Ranking.txt");
						for (int i = 0; i < pontos.size(); i++)
						{
							out << nomes[i] << ' ' << pontos[i] << endl;
						}
						out.close();

						delete this->Estados.top();
						this->Estados.pop();
					}
					
				}
				else
				{
					//se o jogador morreu perde todos os pontos e nao entra no ranking
					if (this->Estados.top()->getPontuacao() == -1)
					{
						this->pontonsAtual = 0;
					}
				delete this->Estados.top();
				this->Estados.pop();

				}

				if (!this->Estados.empty())
				{
					this->Estados.top()->setTrocaMusica(true);
				}
			}
			timer.restart();
		}
	}
	//Finaliza a aplicacao
	else
	{
		this->janela->close();
	}
}


//Funcoes render e run
void Jogo::renderiza()
{
	this->janela->clear();

	//Renderiza o estado da vez (Topo da pilha)
	if (!this->Estados.empty())
	{
		this->Estados.top()->renderiza();
	}

	this->janela->display();
}

void Jogo::run()
{

	while (this->janela->isOpen())
	{
		this->atualizaDT();
		this->atualiza();//Loop Principal
		this->renderiza();//Renderiza
	}
}

void Jogo::atualizaMusica()
{
	if (!this->Estados.empty())
	{
		//Se a musica eh diferente troca de musica
		if (this->Estados.top()->getTrocaMusica() && (this->musicaAnterior != this->Estados.top()->getMusica()))
		{
			if (this->Estados.top()->getMusica() == 1)
			{
				musica.openFromFile("musicas/Tame-Impala-The-Less-I-Know-the-Better-_Instrumental_.ogg");
				musica.setVolume(30);
				musica.setLoop(true);
				musica.play();

			}
			else if (this->Estados.top()->getMusica() == 2)
			{
				musica.openFromFile("musicas/Tame-Impala-Alter-Ego-_8-Bit_.ogg");
				musica.setVolume(70);
				musica.setLoop(true);
				musica.play();
				this->Estados.top()->setMusica(0);
			}

			else if (this->Estados.top()->getMusica() == 3)
			{
				musica.openFromFile("musicas/Tame-Impala-Feels-Like-We-Only-Go-Backwards-_8-Bit_.ogg");
				musica.setVolume(50);
				musica.setLoop(true);
				musica.play();
			}
			else if (this->Estados.top()->getMusica() == 4)
			{
				musica.openFromFile("musicas/Tame-Impala-The-Less-I-Know-The-Better-_8-Bit_.ogg");
				musica.setVolume(50);
				musica.setLoop(true);
				musica.play();
			}
			this->Estados.top()->setTrocaMusica(false);
		}
	}
}
