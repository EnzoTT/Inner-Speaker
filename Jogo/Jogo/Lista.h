#pragma once
template<class TL> class Lista
{
private:
	template <class TE> class Elemento
	{
	public:
		Elemento() 
		{
			pProximo = nullptr;
		}
		~Elemento()
		{
			pProximo = nullptr;
		}

		void setProximo(Elemento<TE>* pP)
		{
			this->pProximo = pP;
		}
		Elemento<TE>* getProximo()
		{
			return this->pProximo;
		}

		void setInformacao(TE pI)
		{
			informacao = pI;
		}
		TE getInformacao()
		{
			return informacao;
		}

	private:
		Elemento<TE>* pProximo;
		TE informacao;
	};
protected:
	Elemento<TL>* pPrimeiro;
	Elemento<TL>* pUltimo;
	int n_elementos;

public:
	//construtora e destrutora
	Lista();
	~Lista();
	
	void inserir(TL pInfo);
	
	void remover(TL pInfo);

	TL getElemento(int i);
	int getNumElementos();
};

template<class TL>
Lista<TL>::Lista()
{
	pPrimeiro = nullptr;
	pUltimo = nullptr;
	n_elementos = 0;
}

template<class TL>
Lista<TL>::~Lista()
{
	Elemento<TL>* pProximo;
	while (pPrimeiro)
	{
		pProximo = pPrimeiro->getProximo();
		delete pPrimeiro;
		pPrimeiro = pProximo;
	}
}

template<class TL>
void Lista<TL>::inserir(TL pInfo)
{
	Elemento<TL>* atual = pPrimeiro;
	Elemento<TL>* novo = new (Elemento<TL>);

	novo->setInformacao(pInfo);
	novo->setProximo(nullptr);

	pUltimo = novo;
	n_elementos++;

	if (pPrimeiro == nullptr)
	{
		pPrimeiro = novo;
		return;
	}
	else
	{
		while (atual->getProximo() != nullptr)
			atual = atual->getProximo();
		atual->setProximo(novo);
	}
}

template<class TL>
void Lista<TL>::remover(TL pInfo)
{
	Elemento<TL>* atual = pPrimeiro;
	Elemento<TL>* excluir = nullptr;

	if (pPrimeiro == nullptr)
		return;
	n_elementos--;
	if (pPrimeiro->getInformacao() == pInfo)
	{
		pPrimeiro = atual->getProximo();
		delete atual;
		return;
	}
	while (atual->getProximo() != nullptr && atual->getProximo()->getInformacao() != pInfo)
		atual = atual->getProximo();

	excluir = atual->getProximo();

	atual->setProximo(excluir->getProximo());
	delete(excluir);
}

template<class TL>
TL Lista<TL>::getElemento(int i)
{
	Elemento<TL>* atual = pPrimeiro;

	for (int j = 0; j < i; j++)
		atual = atual->getProximo();
	return atual->getInformacao();
}
template<class TL>
int Lista<TL>::getNumElementos()
{
	return n_elementos;
}