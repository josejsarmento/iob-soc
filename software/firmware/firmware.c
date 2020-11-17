#include "system.h"
#include "periphs.h"
#include "iob-uart.h"
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main()
{
  int n=100;
  int i, max;
  int random_number[100];
  srand(time(NULL));

  //init uart 
  uart_init(UART_BASE,FREQ/BAUD);   
  uart_printf("\n\n\nHello world!\n\n\n");

  random_number[0]=rand();
  for(i=1; i<n; i++){
      random_number[i]=rand();
      if(random_number[i]>random_number[i-1])
	  max = random_number[i];
  }

  uart_printf("Max number is: %d\n\n", max);

}
