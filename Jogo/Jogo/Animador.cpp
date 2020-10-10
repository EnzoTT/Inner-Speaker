#include "Animador.h"

Animador::Animador(sf::Sprite& sprite, sf::Texture& texturas)
	:sprite(sprite), texturas(texturas)
{
}

Animador::~Animador()
{
	for (auto &i : this->animacoes)
	{
		delete i.second;
	}
}

void Animador:: addAnimacao(
	const std::string identificador,
	float velocidade,
	int frame_comeco_x, int frame_comeco_y, int frames_x, int frames_y, int largura, int altura)
{
	this->animacoes[identificador] = new Animacao(
		this->sprite, this->texturas,
		velocidade,
		frame_comeco_x, frame_comeco_y, frames_x, frames_y, largura, altura);
}

void Animador::play(const std::string identificador, const float& dt)
{
	this->animacoes[identificador]->play(dt);
}
