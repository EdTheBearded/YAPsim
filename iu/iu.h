/*
 * iu.h
 *
 *  Created on: Sep 18, 2015
 *      Author: Eduardo Ferreira
 */

#ifndef __IU_H__
#define __IU_H__

#include "systemc.h"
#include "../memory/memory.h"

typedef struct {
	uint32_t 	PC;
	uint32_t 	instruction;
} fd_t;

typedef struct {
	uint32_t 	PC;
	char 		rs;
	uint32_t 	rs_val;		//value from reg file
	char		rt;
	uint32_t	rt_val;		//value from reg file
	char		rd;
	uint32_t	imm;
	uint32_t	bigImm;
	char		aluop;
	char		shift;
	bool		isShift;	//set if bit movement is shift
	bool		isRotate;	//set if bit movement is rotation
	bool		useImm;		//0 - ALU op2 is rt | 1 - ALU op2 is imm
	bool		memEn;		//enable memory operation
	bool		rwMem;		//0 - read memory | 1 - write memory
	bool		wrReg;		//1 - write to reg file | 0 - do nothing
} de_t;

typedef struct {
	uint32_t 	PC;
	char 		rs;
	uint32_t 	rs_val;
	char		rt;
	uint32_t	rt_val;
	char		rd;
	uint32_t	rd_val;
	/* may be useless */
	bool		useImm;		//0 - ALU op2 is rt | 1 - ALU op2 is imm
	bool		memEn;		//enable memory operation
	bool		rwMem;		//0 - read memory | 1 - write memory
	bool		wrReg;		//1 - write to reg file | 0 - do nothing

} em_t;

typedef struct {
	uint32_t 	PC;
	char 		rs;
	uint32_t 	rs_val;
	char		rt;
	uint32_t	rt_val;
	char		rd;
	uint32_t	rd_val;
	bool		wrReg;		//1 - write to reg file | 0 - do nothing
} mw_t;

typedef struct {
	fd_t fe;
	de_t de;
	em_t em;
	mw_t mw;
} pipeline_t;

SC_MODULE(iu){

	sc_in<bool> clk;

	iu(int _regFileSize, memory *_mem);

	void iu_comb(void);

	void iu_sync(void);

private:

	memory *mem;
	pipeline_t p, np;
	int regFileSize;
	uint32_t *regFile;
	uint32_t PC;
	uint32_t statusReg;
	uint32_t LowReg, HighReg;


};

#endif
