/*
 * memory.h
 *
 *  Created on: Sep 18, 2015
 *      Author: Eduardo Ferreira
 */

#ifndef MEMORY_H_
#define MEMORY_H_

#include "systemc.h"

SC_MODULE(memory){

	memory(int _memSize);

	uint32_t readWord(uint32_t addr);

	void writeWord(uint32_t addr, uint32_t val);

private:
	int memSize;
	char *mem = NULL;

};



#endif /* MEMORY_H_ */
