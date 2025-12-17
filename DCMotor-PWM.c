void motorDC() {
  GPIO_Clock_Enable(GPIOA);
  GPIO_Clock_Enable(GPIOB);


  GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT); //INA1
  GPIO_Pin_Mode(GPIOB, PIN_1, OUTPUT); //INB1
  GPIO_Pin_Mode(GPIOA, PIN_2, OUTPUT); //PWM1
 
  while (1){
    //girar sentido horario
    GPIO_Write_Pin(GPIOA, PIN_1, LOW);
    GPIO_Write_Pin(GPIOB, PIN_1, HIGH);
   
    // girar devagar pra rapido
    for (int i = 0; i < 500; i++) {
      GPIO_Write_Pin(GPIOA, PIN_2, HIGH);
      Delay_us(i);
      GPIO_Write_Pin(GPIOA, PIN_2, LOW);
      Delay_us(500 - i);
    }


    // girar rapido pra devagar
    for (int i = 0; i < 500; i++) {
      GPIO_Write_Pin(GPIOA, PIN_2, HIGH);
      Delay_us(500 - i);
      GPIO_Write_Pin(GPIOA, PIN_2, LOW);
      Delay_us(i);
    }


    //girar sentido anti-horario
    GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
    GPIO_Write_Pin(GPIOB, PIN_1, LOW);


    // girar devagar pra rapido
    for (int i = 0; i < 500; i++) {
      GPIO_Write_Pin(GPIOA, PIN_2, HIGH);
      Delay_us(i);
      GPIO_Write_Pin(GPIOA, PIN_2, LOW);
      Delay_us(500 - i);
    }


    // girar rapido pra devagar
    for (int i = 0; i < 500; i++) {
      GPIO_Write_Pin(GPIOA, PIN_2, HIGH);
      Delay_us(500 - i);
      GPIO_Write_Pin(GPIOA, PIN_2, LOW);
      Delay_us(i);
    }
  }
 
}
