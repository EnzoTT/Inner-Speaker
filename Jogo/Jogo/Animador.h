#pragma once
#include <map>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"

class Animador
{
private:
	class Animacao
	{
	public:
		sf::Sprite& sprite;
		sf::Texture& texturas;
		float velocidade;
		float temporizador;
		int largura;
		int altura;
		sf::IntRect retanguloInicio;
		sf::IntRect retanguloAtual;
		sf::IntRect retanguloFinal;

		Animacao(sf::Sprite& sprite,sf::Texture& texturas, 
			float velocidade, 
			int frame_comeco_x, int frame_comeco_y, int frames_x, int frames_y, int largura, int altura)
			: sprite(sprite), texturas(texturas), velocidade(velocidade), largura(largura), altura(altura)
		{

			this->temporizador = 0.f;

			this->retanguloInicio = sf::IntRect(frame_comeco_x * largura, frame_comeco_y * altura, largura, altura);
			this->retanguloAtual = this->retanguloInicio;
			this->retanguloFinal = sf::IntRect(frames_x * largura, frames_y * altura, largura, altura);

			this->sprite.setTexture(this->texturas, true);
			this->sprite.setTextureRect(this->retanguloInicio);
		}
		~Animacao()
		{
		}

		void play(const float& dt)
		{
			this->temporizador += 350.f * dt;
			if (this->temporizador >= this->velocidade)
			{
				this->temporizador = 0.f; // reset temporizador

				//animar
				if (this->retanguloAtual != this->retanguloFinal)
				{
					this->retanguloAtual.left += this->largura;
				}
				//reset
				else
				{
					this->retanguloAtual.left = this->retanguloInicio.left;
				}
				this->sprite.setTextureRect(this->retanguloAtual);
			}
		}

		void reset()
		{
			this->temporizador = 0.f;
			this->retanguloAtual.left = this->retanguloInicio.left;
		}

	};
	sf::Sprite& sprite;
	sf::Texture& texturas;
	std::map<std::string, Animacao*> animacoes;


public:
	Animador(sf::Sprite& sprite, sf::Texture& texturas);
	virtual ~Animador();

	void addAnimacao(
		const std::string identificador, 
		float velocidade,
		int frame_comeco_x, int frame_comeco_y, int frames_x, int frames_y, int largura, int altura);
	
	void play(const std::string identificador, const float& dt);

};

