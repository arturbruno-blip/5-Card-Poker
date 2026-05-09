#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

//==================================
//	versão 0.1: problemas ao mostrar as cartas finais
//	versão 0.2: 
//==================================

//	versão 0.2: mudei comprar cartas de um loop for para loop while
//	a lógica é que ele vai passar por toda a quantidade e depois deletar o primeiro elemento



struct carta
{
	std::string valor;
	std::string naipe;
};

void criar_baralho(std::vector<carta>& baralho)
{
	std::string valores[13] = {" A", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", " J", " Q", " K"};
	std::string naipes[4] {"ESPADAS","  PAUS "," COPAS "," OUROS "};
	
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 13; j++)
		{
			baralho.push_back({valores[j],naipes[i]});
		}
	}
}

void embaralhar_baralho(std::vector<carta>& baralho)
{
	for(size_t i = 0; i < baralho.size(); i++)
	{
		int temp = rand() % baralho.size();
		std::swap(baralho[i],baralho[temp]);	
	}
}

int bonus()
{
	bool repeat = true;
	int bonus {0};
	
	do
	{
	std::cout<<"Digite o seu bônus:\n";
	std::cin>>bonus;
	
	if(bonus < 0 || bonus > 4)
	{
		std::cout<<"\nBônus inválido. Tente novamente\n";
		continue;
	}
	else
	{
		repeat = false;
	}
	
	}while(repeat == true);
	
	return bonus;
}

void mostrar_baralho(std::vector<carta>& baralho)
{
	for(size_t i = 0; i < baralho.size(); i++)
	{
		std::cout<<"\n"<<baralho[i].valor<<" "<<baralho[i].naipe;
	}
}

void comprar_cartas(std::vector<carta>& baralho, std::vector<carta>& compras, int bonus)
{
	int quantidade = 5 + bonus;
	int fim = baralho.size();
	
	for(int i = 0; i < quantidade; i++)
	{
		compras.push_back(baralho.back());
		baralho.pop_back();
	}
}

void mostrar_compras(std::vector<carta>& compras, int bonus)
{
	int tamanho[2] = {5, bonus};
	int numb = 1;
	int coiso = -1;
	
	for(int j = 0; j < 2; j++)
	{
		for(int i = 0; i < tamanho[j]; i++)
		{
			std::cout<<numb<<") _________\t";
			numb++;
		}
		std::cout<<"\n";
		for(int i = 0; i < tamanho[j]; i++)
		{
			coiso++;
			std::cout<<"  | "<<compras[coiso].naipe<<" |\t";
		}
		coiso -= tamanho[j];
		std::cout<<"\n";
		for(int i = 0; i < tamanho[j]; i++)
		{
			std::cout<<"  |         |\t";
		}
		std::cout<<"\n";
		for(int i = 0; i < tamanho[j]; i++)
		{
			coiso++;
			std::cout<<"  |   "<<compras[coiso].valor<<"    |\t";
		}
		coiso -= tamanho[j];
		std::cout<<"\n";
		for(int i = 0; i < tamanho[j]; i++)
		{
			std::cout<<"  |         |\t";
		}
		std::cout<<"\n";
		for(int i = 0; i < tamanho[j]; i++)
		{
			coiso++;
			std::cout<<"  | "<<compras[coiso].naipe<<" |\t";
		}
		coiso = tamanho[j] - 1;
		std::cout<<"\n";
		for(int i = 0; i < tamanho[j]; i++)
		{
			std::cout<<"  |_________|\t";
		}
		std::cout<<"\n\n";
	}
}

void mao_final(std::vector<carta>& compras, std::vector<carta>& mao)
{
	int numb = 0;
	bool receba[9] = {false,false,false,false,false,false,false,false,false}; //false vazio ; true ocupado
	
	for(int i = 0; i < 5; i++)
	{
		std::cout<<"Digite o número de índice da carta que deseja adicionar a sua mão\n";
		std::cin>>numb;
		
		if(numb < 1 || numb > compras.size())
		{
			std::cout<<"Índice de carta inválida. Tente novamente\n";
			i--;
			continue;
		}
		if(receba[numb-1] == false)
		{
			mao.push_back(compras[numb-1]);
			receba[numb-1] = true;
		}
		else
		{
			std::cout<<"Esta carta ja foi escolhida, escolha outra\n";
			i--;
			continue;
		}
	}
}

void mostrar_mao(std::vector<carta>& mao)
{
	int numb = 1;
		
		for(size_t i = 0; i < mao.size(); i++)
		{
			std::cout<<numb<<") _________\t";
			numb++;
		}
		std::cout<<"\n";
		for(size_t i = 0; i < mao.size(); i++)
		{
			std::cout<<"  | "<<mao[i].naipe<<" |\t";
		}
		std::cout<<"\n";
		for(size_t i = 0; i < mao.size(); i++)
		{
			std::cout<<"  |         |\t";
		}
		std::cout<<"\n";
		for(size_t i = 0; i < mao.size(); i++)
		{
			std::cout<<"  |   "<<mao[i].valor<<"    |\t";
		}
		std::cout<<"\n";
		for(size_t i = 0; i < mao.size(); i++)
		{
			std::cout<<"  |         |\t";
		}
		std::cout<<"\n";
		for(size_t i = 0; i < mao.size(); i++)
		{
			std::cout<<"  | "<<mao[i].naipe<<" |\t";
		}
		std::cout<<"\n";
		for(size_t i = 0; i < mao.size(); i++)
		{
			std::cout<<"  |_________|\t";
		}
}

/*
//fazer combinação
void combinacao(std::vector<carta>& mao)
{
	int comb = 0;
	bool receba[5] = {false,false,false,false,false};	//false nao escolheu, true escolheu 
	bool loop = true;
	std::vector<carta> combinacao;
	
	do
	{
	int escolha = 0;
	
	std::cout<<"\nEscolha cartas para fazer combinações";
	std::cout<<"Digite 0 para terminar de escolher";
	std::cin>>escolha;
	
	if(escolha < 0 || escolha > mao.size())
	{
		std::cout<<"Opção inválida. Tente novamente";
		continue;
	}
	if(escolha == 0)
	{
		loop = false;
	}
	else
	{
		if(receba[escolha] == true)
		{
			std::cout<<"\nEssa carta já foi escolhida. escolha outra";
			continue;
		}
		else
		{
			receba[escolha] = true;
		}
	}
	
	for(size_t i = 0; i < mao.size(); i++)
	{
		if(receba[i] == true)
		{
			combinacao.push_back(mao[i]);
		}
	}
	}while(loop == true)
}
*/
int main()
{
	srand(time(0));
	std::vector<carta> baralho;
	std::vector<carta> compras;
	std::vector<carta> mao;
	char ab = 'b';
	
	std::cout<<baralho.size();
	
	do
	{
		system("cls");
		mao.clear();
		compras.clear();
		
		if(baralho.size() < 10)
		{
			baralho.clear();
			criar_baralho(baralho);
			embaralhar_baralho(baralho);
			//mostrar_baralho(baralho);
		}
		
		int b = bonus();
		comprar_cartas(baralho,compras, b);
		//mostrar_baralho(baralho);
		mostrar_compras(compras,b);
		mao_final(compras, mao);
	
		std::cout<<"\n\n";
		mostrar_mao(mao);
		std::cout<<"\nAperte qualquer tecla para continuar. Aperte 'a' para encerrar o programa";
		std::cin>>ab;
	}while(ab != 'a');
	return 0;
}
