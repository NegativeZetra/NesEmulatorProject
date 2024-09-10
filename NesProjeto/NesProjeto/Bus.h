#pragma once
#include <cstdint> // C STANDARD INTEGER LIBRARY Isso transforma os tipos normais como int, char, float em tipos explicitos, no c++ ele converte automaticamente tipos para fazer o programa rodar (Tipo implicito) oque pode ser um problema, então o explicito não faz essa conversão.
#include <array> // até pra usar array tem que tere biblioteca é foda.


#include "olc6502.h"
class Bus // Explicação do que é bus: Basicamente a parte fisica como cabos que servem para se comunicar entre o hardware.
{
public:
	Bus();
	~Bus();

public: // Componentes do Bus
	olc6502 cpu; //primary device

	// FAKE RAM só para dizer que tem um componente de ram se não num roda computador burrokkkkkkk
	std::array<uint16_t, 64 * 1024> ram;

public: // BUS READ & WRITE o motivo de não ser necessario emular o sinal da leitura e escrita do bus pela cpu, é porque as funções já fazem isso automaticamente no c++
	void write(uint16_t addr, uint8_t data); // resumindo de forma porca esse codigo está emulando a cpu do nes criando um endereço com um valor sem numero negativo, e uma data com 255 bits que retorna a leitura. ESCREVENDO PARA O BUS
	uint16_t read(uint16_t addr, bool BusApenasLeitura = false); // Ignorar Flag por enquanto para ser usada mais tarde >:). LENDO O BUS.
};

