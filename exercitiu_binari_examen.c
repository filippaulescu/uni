#include <stdio.h>
#include <stdint.h>

void print_bit_8(uint8_t nr)
{
  uint8_t mask = 0x80; // 0b1000000000000000
  uint8_t i = 0;
  for (i = 0; i < 8; i++)
    {
      if ((nr & mask) == 0)
        {
          printf ("0");
        }
      else
        {
          printf ("1");
        }
      mask = mask >> 1; // mask >>= 1;
    }
  printf ("\n");
}


void print_bit_int(unsigned int nr)
{
  unsigned int mask = 0x80000000; // 0b1000000000000000
  int i = 0;
  for (i = 0; i < 32; i++)
    {
      if ((nr & mask) == 0)
        {
          printf ("0");
        }
      else
        {
          printf ("1");
        }
      mask = mask >> 1; // mask >>= 1;
    }
  printf ("\n");
}


int main()
{  
    unsigned int a,b;
    scanf("%d%d", &a,&b);
    print_bit_int(a);
    print_bit_int(b);
    int mask= 0xF;
    int nibble1= a&mask;
    int nibble2= b&mask;
    uint8_t c= nibble1|((nibble2)<<4);
    print_bit_8(c);
    
    
     
 return 0;
}
