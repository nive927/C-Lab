#include<stdio.h>

void main()
{ float celsius, fahrenheit=0, kelvin=0;
  
  printf("Enter the temperature in celsius: ");
  scanf("%f", &celsius);

  fahrenheit=((celsius*9)/5)+32;
  kelvin=celsius+273.15;

  printf("Temperature in FAHRENHEIT: %.2f\n", fahrenheit);
  printf("Temperature in KELVIN: %.2f\n", kelvin);

}
