/* Author: Saumya Saxena
Assignment 1 - Computing in the Small
Date: April 19, 2018
*/

#include <u.h>
#include <libc.h>

int ch = 0; //the mode of the switch

void
main()
{
  //variables
  char buf[16];
  int fd;
  int d = 10;
  vlong gvals;
  vlong pin27;

  bind("#G","/dev",MAFTER); 
  fd=open("/dev/gpio",ORDWR); // open the /dev/gpio file
  fprint(fd, "function 27 out\n"); //set the output gpio pin
  fprint(fd, "function 17 in\n"); //set the input gpio pin

  while(1){
    read(fd, buf, 16); //read from capacitive touch pin 17
    buf[16] = 0;
    gvals = strtoull(buf, nil, 16);
    pint27 = gvals & (1 << 27);
    sleep(300); // wait for 300 ms before taking second input
    if(buf[11] == '2') //if input pin is high, switch the mode
    {
      switch(ch){
        case 0: //mode = ON
        fprint(fd,"set 27 1\n");
        ch = 1;
        break;
        case 1: //mode = OFF
        fprint(fd,"set 27 0\n");
        ch = 2;
        break;
        case 2: //mode = BLINK
        while(d){ //blink for 10 times
        fprint(fd,"set 27 1\n");
        sleep(300);
        fprint(fd,"set 27 0\n");
        sleep(300);
        d--;
        }
        ch = 0;
        break;
        }
               
                 
    }
  }
}