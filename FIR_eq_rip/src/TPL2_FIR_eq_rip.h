/*
 * TPL2_FIR_eq_rip.h
 *
 *  Created on: 15 oct. 2022
 *      Author: bruno
 */

#ifndef TPL2_FIR_EQ_RIP_H_
#define TPL2_FIR_EQ_RIP_H_

#include "arm_math.h"
#include "math_helper.h"
#include "MyDR_ADC.h"
#include "MyDR_DAC.h"
#include "dsp/filtering_functions.h"
#include "dsp/support_functions.h"
/* ----------------------------------------------------------------------
** Macro Defines
** ------------------------------------------------------------------- */

#define TEST_LENGTH_SAMPLES  320

#define BLOCK_SIZE            1

#if defined(ARM_MATH_MVEF) && !defined(ARM_MATH_AUTOVECTORIZE)
/* Must be a multiple of 16 */
#define NUM_TAPS_ARRAY_SIZE              32
#else
#define NUM_TAPS_ARRAY_SIZE              48
#endif

#define NUM_TAPS              			 48

/* ------------------------------------------------------------------
 * Global variables for FIR LPF Example
 * ------------------------------------------------------------------- */
extern q31_t  inputQ31, outputQ31;
extern arm_fir_instance_q31 S;

/* -------------------------------------------------------------------
 * Declare State buffer of size (numTaps + blockSize - 1)
 * ------------------------------------------------------------------- */
#if defined(ARM_MATH_MVEF) && !defined(ARM_MATH_AUTOVECTORIZE)
static float32_t firStateF32[2 * BLOCK_SIZE + NUM_TAPS - 1];
#else
static q31_t firStateQ31[BLOCK_SIZE + NUM_TAPS - 1];
#endif


extern q31_t firCoeffsQ31[NUM_TAPS_ARRAY_SIZE];


#endif /* TPL2_FIR_EQ_RIP_H_ */
