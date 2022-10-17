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
0.008834,0.004536,0.005625,0.006827,0.008139,0.009549,0.011047,0.012621,
0.014259,0.015940,0.017642,0.019346,0.021039,0.022695,0.024279,0.025791,
0.027190,0.028468,0.029599,0.030572,0.031367,0.031978,0.032391,0.032597,
0.032597,0.032391,0.031978,0.031367,0.030572,0.029599,0.028468,0.027190,
0.025791,0.024279,0.022695,0.021039,0.019346,0.017642,0.015940,0.014259,
0.012621,0.011047,0.009549,0.008139,0.006827,0.005625,0.004536,0.008834
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
