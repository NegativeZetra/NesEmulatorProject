#include "Bus.h"

Bus::Bus() {

	cpu.ConectarBus(this); // Conecta a cpu para se comunicar com o bus vrum vrum

	//Reseta o valor da ram só pra ter certeza que não vai crashar ou coisa assim
	for (auto &i : ram) i = 0x00; //obviamente o 0x00 na tabela hexadecimal é o 0.
}

Bus::~Bus() {}


// Implementação de Bodies.
void Bus::write(uint16_t addr, uint8_t data){
	if (addr >= 0x0000 && addr <= 0xFFFF) // Colocando um range maximo para o endereço
	ram[addr] = data;

}
uint16_t Bus::read(uint16_t addr, bool BusApenasLeitura){
	if (addr >= 0x0000 && addr <= 0xFFFF) // Colocando um range maximo para o endereço
		return ram[addr]; //retorna o que tem na ram pro endereço

	return 0x00;

}