// #include "samples/prototypes.h"
// #include <error.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long signed_min(int bitwidth) {
  return ~0L << (bitwidth-1);
}

long signed_max(int bitwidth) {
  return (1L << (bitwidth-1)) - 1;
}

long sat_add(long operand1, long operand2, int bitwidth)
{
  long c = operand1 + operand2; // candidate
  long msb = 1L << (bitwidth-1);
  if (!(operand1 & msb) && !(operand2 & msb) && (c & msb)) {
    // overflow as a positive, b positive, c negative
    return signed_max(bitwidth);
  } else if ((operand1 & msb) && (operand2 & msb) && !(c & msb)) {
    // underflow as a negative, b negative, c positive
    return signed_min(bitwidth);
  }
  return c;
}


// ------- DO NOT EDIT ANY CODE BELOW THIS LINE (but do add comments!)  -------


long convert_arg(const char *str, long low, long high, const char *argname)
{
    char *end;
    long n = strtol(str, &end, 0);
    if (*end != '\0') 
        fprintf(stderr,"Invalid number '%s': %s", str,strerror(errno));
    if (n < low || n > high || errno == ERANGE) 
        fprintf(stderr,"Illegal value %s. %s must be in range [%ld, %ld]: %s", str, argname, low, high, strerror(errno));
    return n;
}

// long sat_add(long a, long b, int bitwidth){
// // saturation add. get a candidate. detect overflow and underflow
//   long c = a + b;// candidate
//   long msb = 1L << (bitwidth-1);
//   if (!(a & msb) && !(b & msb) && (c & msb)){
//     // overflow:
//     //  a positive    b positive   c negative
//     c = signed_max(bitwidth);
//   }else if ((a & msb) && (b & msb) && !(c & msb)){
//     // underflow:
//     //       a negative   b negative    c positive
//     c = signed_min(bitwidth);
//   }
//   return c;
// }

int main(int argc, char *argv[])
{
    if (argc < 2) fprintf(stderr, "Missing argument. Please specify the bitwidth: %s\n",strerror(errno));
    
    int bitwidth = convert_arg(argv[1], 4, sizeof(long)*8, "Bitwidth");
    long min = signed_min(bitwidth);
    long max = signed_max(bitwidth);

    if (argc < 4)  {
        printf("%d-bit signed integer range\n", bitwidth);
        printf("min: %ld   %#018lx\n", min, min);
        printf("max:  %ld   %#018lx\n", max, max);
    } else {
        long a = convert_arg(argv[2], min, max, "Operand");
        long b = convert_arg(argv[3], min, max, "Operand");
        printf("%ld + %ld = %ld\n", a, b, sat_add(a, b, bitwidth));   
    }
    return 0;
}
