void motorPasso() {
  GPIO_Clock_Enable(GPIOA);
  GPIO_Clock_Enable(GPIOB);


  //bobina 1
  GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT); //INA1
  GPIO_Pin_Mode(GPIOB, PIN_1, OUTPUT); //INB1


  //bobina 2
  GPIO_Pin_Mode(GPIOA, PIN_2, OUTPUT); //INA2
  GPIO_Pin_Mode(GPIOB, PIN_2, OUTPUT); //INB2


  GPIO_Pin_Mode(GPIOA, PIN_4, OUTPUT); //PWM1
  GPIO_Pin_Mode(GPIOA, PIN_5, OUTPUT); //PWM2


  //setar tudo como low
  GPIO_Write_Pin(GPIOA, PIN_1, LOW);
  GPIO_Write_Pin(GPIOB, PIN_1, LOW);


  GPIO_Write_Pin(GPIOA, PIN_2, LOW);
  GPIO_Write_Pin(GPIOB, PIN_2, LOW);


  GPIO_Write_Pin(GPIOA, PIN_4, LOW);
  GPIO_Write_Pin(GPIOA, PIN_5, LOW);


  while (1) {
    //setar a corrente pra ela sempre passar
    GPIO_Write_Pin(GPIOA, PIN_4, HIGH);
    GPIO_Write_Pin(GPIOA, PIN_5 HIGH);




    //esta com um delay de 20ms para cada giro durar 4 segundos
    //girar sentido horario
    //sao necessarios 200 passos para um giro completo
    //logo, 0,02s * 200 = 4s
    //no sentido horario tem que girar 2 vezes
    //dentro de cada iteracao, ocorre 4 passos, logo 100 * 4 = 400 passos(2 giros)
    for (int i = 0; < 100; i++){
      //bobina 1 - diretamente polarizada
      GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
      GPIO_Write_Pin(GPIOB, PIN_1, LOW);
      Delay_ms(20);


      //bobina 2 - diretamente polarizada
      GPIO_Write_Pin(GPIOA, PIN_2, HIGH);
      GPIO_Write_Pin(GPIOB, PIN_2, LOW);
      Delay_ms(20);


      //bobina 1 - reversamente polarizada
      GPIO_Write_Pin(GPIOA, PIN_1, LOW);
      GPIO_Write_Pin(GPIOB, PIN_1, HIGH);
      Delay_ms(20);


      //bobina 2 - reversamente polarizada
      GPIO_Write_Pin(GPIOA, PIN_2, LOW);
      GPIO_Write_Pin(GPIOB, PIN_2, HIGH);
      Delay_ms(20);
    }


    //girar sentido anti-horario(ordem invertida)
    //verificar se eh realmente a ordem totalmente invertida.
    //aqui so precisa dar um giro completo, logo 50 * 4 = 200 passos(1 giro)
    for (int i = 0; < 50; i++){
      //bobina 2 - reversamente polarizada
      GPIO_Write_Pin(GPIOA, PIN_2, LOW);
      GPIO_Write_Pin(GPIOB, PIN_2, HIGH);
      Delay_ms(20);


      //bobina 1 - reversamente polarizada
      GPIO_Write_Pin(GPIOA, PIN_1, LOW);
      GPIO_Write_Pin(GPIOB, PIN_1, HIGH);
      Delay_ms(20);


      //bobina 2 - diretamente polarizada
      GPIO_Write_Pin(GPIOA, PIN_2, HIGH);
      GPIO_Write_Pin(GPIOB, PIN_2, LOW);
      Delay_ms(20);


      //bobina 1 - diretamente polarizada
      GPIO_Write_Pin(GPIOA, PIN_1, HIGH);
      GPIO_Write_Pin(GPIOB, PIN_1, LOW);
      Delay_ms(20);
    }
  }
}
