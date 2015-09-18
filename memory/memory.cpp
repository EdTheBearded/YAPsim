/*
 * memory.cpp
 *
 *  Created on: Sep 18, 2015
 *      Author: Eduardo Ferreira
 */

#include "memory.h"

SC_HAS_PROCESS(memory);
memory::memory(int _memSize){

	memSize = _memSize;

	mem = (char*)malloc(memSize*sizeof(char));
	if(mem == NULL){
		cout << "Error: could not instantiate memory byte array" << endl;
		exit(1);
	}
}

memory::readWord(uint32_t addr){

	uint32_t *temp = (uint32_t)mem[addr];
	return (*temp);
}

memory::writeWord(uint32_t addr, uint32_t val){

	uint32_t *temp = (uint32_t)mem[addr];
	(*temp) = val;
}
