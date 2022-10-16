/*
===============================================================================
 Name        : TPL2_IIR_butterworth.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

/* ----------------------------------------------------------------------
** Include Files
** ------------------------------------------------------------------- */
#if defined(SEMIHOSTING)
#include <stdio.h>
#endif

#include "TPL2_IIR_butterworth.h"

/* ----------------------------------------------------------------------
** FIR Coefficients buffer generated using fir1() MATLAB function.
** fir1(28, 6/24)
** ------------------------------------------------------------------- */
const float32_t firCoeffs32[NUM_TAPS_ARRAY_SIZE] =
{0.03384885894391999328,0.03384885894391999328,0,-0.93230228211215993,0};//{b10, b11, b12, a11, a12}

q31_t  inputQ31, outputQ31;
arm_biquad_casd_df1_inst_q31 S;
q31_t firCoeffsQ31[NUM_TAPS_ARRAY_SIZE];

/* ----------------------------------------------------------------------
 * FIR LPF Example
 * ------------------------------------------------------------------- */

int32_t main(void)
{
  InicializarPLL();

  arm_float_to_q31(firCoeffs32,firCoeffsQ31,BLOCK_SIZE);

  /* Call FIR init function to initialize the instance structure. */
  arm_biquad_cascade_df1_init_q31(&S,NUM_STAGES,(q31_t *)&firCoeffsQ31[0], &firStateQ31[0], BLOCK_SIZE);

  DAC_Init();
  ADC_Init();

  while (1);

}

