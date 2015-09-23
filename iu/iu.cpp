/*
 * iu.cpp
 *
 *  Created on: Sep 18, 2015
 *      Author: Eduardo Ferreira
 */

#include "iu.h"

iu::iu(int _regFileSize, memory *_mem){

	regFileSize = _regFileSize;
	mem = _mem;

	regFile = (uint32_t*)malloc(regFileSize*sizeof(uint32_t));

	SC_METHOD(iu_comb);
	sensitive;

	SC_METHOD(iu_sync);
	sensitive;

}

iu::iu_comb(void){

/***************************
 *                         *
 *     WRITEBACK STAGE     *
 *                         *
 ***************************/
	if(p.mw.wrReg){
		regFile[p.mw.rd] = p.mw.rd_val;
	}

/***************************
 *                         *
 *   MEMORY ACCESS STAGE   *
 *                         *
 ***************************/
	np.mw.PC = p.em.PC;
	np.mw.rd = p.em.rd;
	np.mw.rd_val = p.em.rd_val;
	np.mw.rs = p.em.rs;
	np.mw.rs_val = p.em.rs_val;
	np.mw.rt = p.em.rt;
	np.mw.rt_val = p.em.rt_val;
	np.mw.wrReg = p.em.wrReg;
	if(p.em.memEn){
		//write op
		if(p.em.rwMem){
			mem->writeWord(p.em.rd_val, p.em.rt_val);
		}
		//read op
		else{
			np.mw.rd_val = mem->readWord(p.em.rd_val);
		}
	}

/***************************
 *                         *
 *     EXECUTION STAGE     *
 *                         *
 ***************************/

/***************************
 *                         *
 *    DISASSEMBLE STAGE    *
 *                         *
 ***************************/

/***************************
 *                         *
 *       FETCH STAGE       *
 *                         *
 ***************************/

}

iu::iu_sync(void){

}
