#include "system.h"
#include "periphs.h"
#include "iob-uart.h"
#include "stdint.h"

int main()
{ 
  int n = 100; // Fibonacci sequence numbers
  unsigned long f_lsd[n], f_msd[n];
  
  int i;
  
  f_lsd[0] = 0; f_lsd[1] = 1;
  for(i = 2; i < n; i++){
      f_lsd[i] = f_lsd[i-1] + f_lsd[i-2];
  }
  
  //init uart 
  uart_init(UART_BASE,FREQ/BAUD);   
  uart_printf("\n\n\nHello world!\n\n\n");
  uart_printf("First %d numbers of the Fibonacci sequence:\n\n\n", n);

for(i = 46; i < n; i++){
    if(f_msd[i]==0)
	uart_printf("nº%d:\t%d\n", i+1, f_lsd[i]);
    else
	uart_printf("nº%d:\t%d%d\n", i+1,f_msd[i], f_lsd[i]);
 }

}
