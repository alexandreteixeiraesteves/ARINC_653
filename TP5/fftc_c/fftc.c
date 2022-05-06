#include <math.h>
#include <string.h>
#include "fftc.h"

// Storage for the HANN window value and for the twiddles
float Fftc__hann[Constants__fft_size] ;
Complex__complex Fftc__twiddle[Constants__fft_size] ;

void Fftc__init_fft_step(void) {
  int i,span ;
  // Init the Hann window
  for(i=0;i<Constants__fft_size;i++) {
    Fftc__hann[i] = (1-cosf((float)Complex__pi*2*i/Constants__fft_size))/2 ;
  }
  // Init the twiddles
  for(span=1;span<=Constants__fft_size2;span<<=1) {
    float primitive_root = -Complex__pi/span ;
    for(i=0;i<span;i++) {
      Complex__complex twiddle =
  	{
  	  .re = cosf(primitive_root*i) ,
  	  .im = sinf(primitive_root*i)
  	} ;
      Fftc__twiddle[span+i] = twiddle ;
    }
  }
}


void Fftc__hann_step(int i,Fftc__hann_out*_out) {
  assert((0<=i)&&(i<Constants__fft_size)) ;
  _out->o = Fftc__hann[i] ;
}
void Fftc__twiddle_step(int i,Fftc__twiddle_out*_out) {
  assert((0<=i)&&(i<Constants__fft_size)) ;
  _out->o = Fftc__twiddle[i] ;
}


#define datatype Complex__complex
static inline void swap(unsigned int forward,
			unsigned int rev,
			datatype *data) {
  datatype tmp;
  tmp = data[forward];
  data[forward] = data[rev];
  data[rev] = tmp;
}
void bitrev(datatype *data, unsigned int logN)
{
  // Initialization of frequently used constants
  const unsigned int N = 1<<logN;
  const unsigned int halfn = N>>1;
  const unsigned int quartn = N>>2;
  const unsigned int nmin1 = N-1;

  // Variables
  unsigned int i, forward, rev, zeros;
  unsigned int nodd, noddrev;

  // Variable initialization
  forward = halfn;
  rev = 1;

  // start of bitreversed permutation loop, N/4 iterations
  for(i=quartn; i; i--) {
    // Gray code generator for even values:
    nodd = ~i;                                  // counting ones is easier
    for(zeros=0; nodd&1; zeros++) nodd >>= 1;   // find trailing zeros in i
    forward ^= 2 << zeros;                      // toggle one bit of forward
    rev ^= quartn >> zeros;                     // toggle one bit of rev
    
    // swap even and ~even conditionally
    if(forward<rev) {
      swap(forward, rev, data);
      nodd = nmin1 ^ forward;                   // compute the bitwise negations
      noddrev = nmin1 ^ rev;
      swap(nodd, noddrev, data);                // swap bitwise-negated pairs
    }
      
    nodd = forward ^ 1;                         // compute the odd values from the even
    noddrev = rev ^ halfn;
    swap(nodd, noddrev, data);                  // swap odd unconditionally
  }
}

void Fftc__bitrev8_step(Complex__complex*i,Fftc__bitrev8_out*_out) {
  memcpy(_out->o,i,8*sizeof(Complex__complex)) ;
  bitrev(_out->o,3) ;
}
void Fftc__bitrev_step(Complex__complex*i,Fftc__bitrev_out*_out) {
  memcpy(_out->o,i,Constants__fft_size*sizeof(Complex__complex)) ;
  bitrev(_out->o,Constants__fft_size_log) ;
}
