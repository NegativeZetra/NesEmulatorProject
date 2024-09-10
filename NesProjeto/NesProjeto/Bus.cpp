#include "Bus.h"

Bus::Bus() {

	cpu.ConectarBus(this); // Conecta a cpu para se comunicar com o bus vrum vrum

	//Reseta o valor da ram s� pra ter certeza que n�o vai crashar ou coisa assim
	for (auto &i : ram) i = 0x00; //obviamente o 0x00 na tabela hexadecimal � o 0.
}

Bus::~Bus() {}


// Implementa��o de Bodies.
void Bus::write(uint16_t addr, uint8_t data){
	if (addr >= 0x0000 && addr <= 0xFFFF) // Colocando um range maximo para o endere�o
	ram[addr] = data;

}
uint16_t Bus::read(uint16_t addr, bool BusApenasLeitura){
	if (addr >= 0x0000 && addr <= 0xFFFF) // Colocando um range maximo para o endere�o
		return ram[addr]; //retorna o que tem na ram pro endere�o

	return 0x00;

}