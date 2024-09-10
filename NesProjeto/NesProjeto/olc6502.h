#pragma once
#include "Bus.h"
#include <string>
class Bus;

class olc6502
{
public:
	olc6502();
	~olc6502();

public:
	// Agora fudeu vou ter que adicionar os cores components da cpu

	enum FLAGS6502
	{
		C = (1 << 0), // Carry bit eu não entendi muito bem oque isso faz Mas aparentenmente isso só informa o tipo de operação que queremos usar.
		Z = (1 << 1), // Zero isso só seta quando o resultado de uma operação é igual a zero, é serio é só isso.
		I = (1 << 2), // Disable interrupts nome auto explicativo
		D = (1 << 3), // Decimal Mode (Inutilizada no Nes)
		B = (1 << 4), // Break chuto que seja break de parar programação igual switch case
		U = (1 << 5), // Unused
		V = (1 << 6), // Overflow
		N = (1 << 7) // Negative
	};

	uint8_t a = 0x00; // Acumulator register
	uint8_t x = 0x00; // X register
	uint8_t y = 0x00; // Y register
	uint8_t stkp = 0x00; // Stack Pointer (pontos para localizar o bus vrum vrum)
	uint16_t pc = 0x0000; // Program Counter
	uint8_t status = 0x00; // status register


	void ConectarBus(Bus* n) { bus = n; }

	// Bora emular os Addressing mode

	uint8_t IMP(); uint8_t IMM();
	uint8_t ZP0(); uint8_t ZPX();
	uint8_t ZPY(); uint8_t REL();
	uint8_t ABS(); uint8_t ABX();
	uint8_t ABY(); uint8_t IND();
	uint8_t IZX(); uint8_t IZY();

	uint8_t ADC();	uint8_t AND();	uint8_t ASL();	uint8_t BCC();
	uint8_t BCS();	uint8_t BEQ();	uint8_t BIT();	uint8_t BMI();
	uint8_t BNE();	uint8_t BPL();	uint8_t BRK();	uint8_t BVC();
	uint8_t BVS();	uint8_t CLC();	uint8_t CLD();	uint8_t CLI();
	uint8_t CLV();	uint8_t CMP();	uint8_t CPX();	uint8_t CPY();
	uint8_t DEC();	uint8_t DEX();	uint8_t DEY();	uint8_t EOR();
	uint8_t INC();	uint8_t INX();	uint8_t INY();	uint8_t JMP();
	uint8_t JSR();	uint8_t LDA();	uint8_t LDX();	uint8_t LDY();
	uint8_t LSR();	uint8_t NOP();	uint8_t ORA();	uint8_t PHA();
	uint8_t PHP();	uint8_t PLA();	uint8_t PLP();	uint8_t ROL();
	uint8_t ROR();	uint8_t RTI();	uint8_t RTS();	uint8_t SBC();
	uint8_t SEC();	uint8_t SED();	uint8_t SEI();	uint8_t STA();
	uint8_t STX();	uint8_t STY();	uint8_t TAX();	uint8_t TAY();
	uint8_t TSX();	uint8_t TXA();	uint8_t TXS();	uint8_t TYA();

	uint8_t XXX(); // Caso tenha um opcode ilegal esse opcode vai ser chamado hehehe.

	void clock(); // eu não sabia oque era clock mas basicamente é a velocidade da frequencia que a cpu pode exercer por segundo
	void reset();
	void irq(); // Interrupt request signal
	void nmi(); // non-maskable interrupt request signal (Os 3 só podem ser ativados de forma assincronica sem serem ao mesmo tempo)

	uint8_t fetch();
	uint8_t fetched = 0x00;

	// Fazendo uns armazenamento pro addresing mode para poder ler em diferentes partes da memoria
	uint16_t addr_abs = 0x0000;
	uint16_t addr_rel = 0x00;
	uint8_t opcode = 0x00;
	uint8_t cycles = 0;


private:
	Bus* bus = nullptr; // Guarda um pointer para o bus de forma privada para a classe.
	uint8_t read(uint16_t a);
	void write(uint16_t a, uint8_t d);


	// Convenience Functions para acessar o status register (não eu não sei oque caralhos é uma convenience function mas aparentemente serve só pra deixar o codigo mais facil de entender tipo sei lá pegar algo complexo e transformar em uma função).
	uint8_t GetFlag(FLAGS6502 f);
	void SetFlag(FLAGS6502 f, bool v);

	struct INSTRUCTION {
		std::string name;
		uint8_t(olc6502::* operate)(void) = nullptr;
		uint8_t(olc6502::* addrmode)(void) = nullptr;
		uint8_t cycles = 0;
	};

};

