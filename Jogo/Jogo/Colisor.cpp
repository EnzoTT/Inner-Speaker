#include "Colisor.h"



Colisor::Colisor(sf::Sprite& sprite, sf::RectangleShape &hitbox):
	sprite(sprite),
	hitbox(hitbox)
{
}

Colisor::~Colisor()
{
}

//sf::Sprite& spriteOutroCorpo, sf::Sprite& spriteAtual, sf::Vector2f& direcao
bool Colisor::verificaColisao(Colisor& outroCorpo, sf::Vector2f& direcao, float repulsao)
{
	float tamanhoAtualX, tamanhoAtualY, tamanhoOutroX, tamanhoOutroY;
	tamanhoAtualX = this->hitbox.getSize().x;
	tamanhoAtualY = this->hitbox.getSize().y;
	tamanhoOutroX = outroCorpo.hitbox.getSize().x;
	tamanhoOutroY = outroCorpo.hitbox.getSize().y;



	sf::Vector2f posicaoOutroCorpo = outroCorpo.getPosicao();
	sf::Vector2f meioTamanhoOutroCorpo = outroCorpo.getMetadeDoTamanho();

	sf::Vector2f posicaoAtual = getPosicao();
	sf::Vector2f meioTamanhoCorpoAtual = getMetadeDoTamanho();

	float deltaX = posicaoOutroCorpo.x - posicaoAtual.x  +	((tamanhoOutroX - tamanhoAtualX) / 2);
	float deltaY = posicaoOutroCorpo.y - posicaoAtual.y  +	((tamanhoOutroY - tamanhoAtualY) / 2);

	float interseccaoX = abs(deltaX) - (meioTamanhoOutroCorpo.x + meioTamanhoCorpoAtual.x);
	float interseccaoY = abs(deltaY) - (meioTamanhoOutroCorpo.y + meioTamanhoCorpoAtual.y);

	if (interseccaoX < 0.0f && interseccaoY < 0.0f)
	{
		repulsao = std::min(std::max(repulsao, 0.0f), 1.0f);

		if (interseccaoX > interseccaoY)
		{
			if (deltaX > 0.0f)
			{
				move(interseccaoX * (1.0f - repulsao), 0.0f);
				outroCorpo.move(-interseccaoX * repulsao, 0.0f);

				direcao.x = 1.0f;
				direcao.y = 0.0f;
			}
			else
			{
				move(-interseccaoX * (1.0f - repulsao), 0.0f);
				outroCorpo.move(interseccaoX * repulsao, 0.0f);
				

				direcao.x = -1.0f;
				direcao.y = 0.0f;
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				move(0.0f, interseccaoY * (1.0f - repulsao));
				outroCorpo.move(0.0f, -interseccaoY * repulsao);
			
				direcao.x = 0.0f;
				direcao.y = 1.0f;
			}
			else
			{
				move(0.0f, -interseccaoY * (1.0f - repulsao));
				outroCorpo.move(0.0f, interseccaoY * repulsao);
			
				direcao.x = 0.0f;
				direcao.y = -1.0f;
			}
		}
		return true;
		std::cout << "Esta colidindo" << endl;
	}
	return false;
	std::cout << "Nao esta colidindo" << endl;
	
}
