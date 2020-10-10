#include "Botao.h"


//Construtora/Destrutora
Botao::Botao(float x, float y, float comprimento, float altura, string texturaPadrao, string texturaSobre, string texturaAtivo)
{
	this->retangulo.setPosition(sf::Vector2f(x, y));
	this->retangulo.setSize(sf::Vector2f(comprimento, altura));

	this->estadoBotao = BTO_PADRAO;



	this->texturaPadrao.loadFromFile(texturaPadrao);
	this->texturaSobre.loadFromFile(texturaSobre);
	this->texturaAtivo.loadFromFile(texturaAtivo);

}

Botao::~Botao()
{
}

//Acessos
const bool Botao::estaPressionado() const
{
	if (this->estadoBotao == BTO_ATIVO)
	{
		return true;
	}

	return false;
}


void Botao::setPosicao(sf::Vector2f pos)
{
	this->retangulo.setPosition(pos);
}

//Funcoes
void Botao::atualiza(const sf::Vector2f posicaoMouse)
{
	/*Atualiza os booleanos de Sobre e Pressionado*/

	//Inativo
	this->estadoBotao = BTO_PADRAO;

	//Sobre
	if (this->retangulo.getGlobalBounds().contains(posicaoMouse))
	{
		this->estadoBotao = BTO_SOBRE;

		//Pressionado
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->estadoBotao = BTO_ATIVO;
		}
	}

	switch (this->estadoBotao)
	{
	case BTO_PADRAO:
	
		this->retangulo.setTexture(&texturaPadrao);

			break;
	case BTO_SOBRE:
	
		this->retangulo.setTexture(&texturaSobre);
				break;
	case BTO_ATIVO:
		this->retangulo.setTexture(&texturaAtivo);
		break;

	default:
		this->retangulo.setFillColor(sf::Color::Red);
		break;
	}


}

void Botao::renderiza(sf::RenderTarget& target)
{
	target.draw(this->retangulo);
}
