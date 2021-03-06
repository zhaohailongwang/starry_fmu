#include <stdint.h>
#include "FIR.h"

// The code below is automatically generated by the Matlab script firdesign.m
// It is an 10th order (length 11) low pass FIR filter with cutoff frequency 5Hz.
// It is for a digital system with a sampling frequency of 0.10kHz.
// Author: Jiachi Zou   Date: 2017

#define FIR_FILTER_LENGTH 11

const float FIRFilterCoefficients[FIR_FILTER_LENGTH] = {
	0.009967, 0.024862, 0.066837, 0.124889, 0.175592, 0.195707, 0.175592, 0.124889, 
	0.066837, 0.024862, 0.009967
};

int fir_index;
float cir_buffer[FIR_FILTER_LENGTH];

void FIR_Init(void)
{
	int i;
	
	for(i = 0 ; i < FIR_FILTER_LENGTH ; i++){
		cir_buffer[i] = 0.0f;
	}
}

float FIR_Filter(float in)
{
	float out = 0.0f;
	int i;
	
	cir_buffer[fir_index++] = in;
	if(fir_index >= FIR_FILTER_LENGTH)
		fir_index = 0;
	
	for(i = 0 ; i < FIR_FILTER_LENGTH ; i++){
		out += cir_buffer[fir_index] * FIRFilterCoefficients[i];
		if(fir_index != 0){
			fir_index --;
		} else {
			fir_index = FIR_FILTER_LENGTH-1;
		}
	}
	
	return out;
}
