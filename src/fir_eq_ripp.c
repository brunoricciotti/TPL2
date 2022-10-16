/*
===============================================================================
 Name        : fir_eq_rip.c
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

#include "TPL2_FIR_eq_rip.h"

/* ----------------------------------------------------------------------
** FIR Coefficients buffer generated using fir1() MATLAB function.
** fir1(28, 6/24)
** ------------------------------------------------------------------- */
const float32_t firCoeffs32[NUM_TAPS_ARRAY_SIZE] = {
	0.010405,0.007894,0.010593,0.013653,0.017030,0.020651,0.024432,0.028284,
	0.032103,0.035769,0.039171,0.042209,0.044763,0.046766,0.048137,0.048837,
	0.048837,0.048137,0.046766,0.044763,0.042209,0.039171,0.035769,0.032103,
	0.028284,0.024432,0.020651,0.017030,0.013653,0.010593,0.007894,0.010405
};

q31_t  inputQ31, outputQ31;
arm_fir_instance_q31 S;
q31_t firCoeffsQ31[NUM_TAPS_ARRAY_SIZE];

/* ----------------------------------------------------------------------
 * FIR LPF Example
 * ------------------------------------------------------------------- */

int32_t main(void)
{
  InicializarPLL();

  arm_float_to_q31(firCoeffs32,firCoeffsQ31,BLOCK_SIZE);

  /* Call FIR init function to initialize the instance structure. */
  arm_fir_init_q31(&S, NUM_TAPS, (q31_t *)&firCoeffsQ31[0], &firStateQ31[0], BLOCK_SIZE);

  DAC_Init();
  ADC_Init();

  //status = (snr < SNR_THRESHOLD_F32) ? ARM_MATH_TEST_FAILURE : ARM_MATH_SUCCESS;
  while (1);

}
