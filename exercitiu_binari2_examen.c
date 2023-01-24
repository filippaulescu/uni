#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void print_bit_16 (uint16_t nr)
{
  uint16_t mask = 0x8000; // 0b1000000000000000
  uint8_t i = 0;
  for (i = 0; i < 16; i++)
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

void print_bit_32 (uint32_t nr)
{
  uint32_t mask = 0x80000000; // 0b1000000000000000
  uint32_t i = 0;
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

void functie( uint32_t *src, uint16_t *dst_msw,uint16_t *dst_lsw, int Array_size)
{
	uint32_t mask1= 0xFFFF;
	uint32_t mask2= 0xFFFF0000;
	for( int i=0; i< SIZE; i++)
	{
		dst_lsw[i]= src[i] & mask1;
		dst_msw[i]= (src[i] & mask2)>>16;
		
		print_bit_32(src[i]);
		print_bit_16(dst_lsw[i]);
		print_bit_16(dst_msw[i]);
		printf("\n");
	}
	

}


int main()
{  
	uint32_t src[SIZE];
	uint16_t dst_msw[SIZE], dst_lsw[SIZE];
	
	int n = 0;
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		n = rand();
		src[i]=n;
		printf ("%d\n", src[i]);
	}
	
	functie( src, dst_msw, dst_lsw, SIZE);
   
     
 return 0;
}
