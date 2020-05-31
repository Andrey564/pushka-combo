void menu_four(){
  Serial.println("menu_four");
  myOLED.clrScr();
  while(true){
     myOLED.clrScr();
     myOLED.drawBitmap(8, 1, mark_default, 120, 64);
    myOLED.update();
    //Произойдет при нажатии вправо ->
    if(digitalRead(right)){
      menuFour:
      myOLED.invert(true);
        myOLED.clrScr();
        for (int i=0; i<12; i++)
        {
          myOLED.drawRoundRect(i*3, i*3, 127-(i*3), 63-(i*3));
          myOLED.setBrightness(255-21);
          myOLED.update();
        }
        myOLED.invert(false);
        myOLED.clrScr();
        myOLED.setFont(RusFont);
        myOLED.print("FYJYBVYJCNM", CENTER, 0);
        myOLED.print("lkz nt[ rnj wtybn", CENTER, 10);
        myOLED.setFont(SmallFont);
        myOLED.print("LIL JON", CENTER, 28);
        myOLED.drawRect(42, 26, 86, 36);
        for (int i=0; i<6; i++)
        {
          myOLED.drawLine(87, 26+(i*2), 105-(i*3), 26+(i*2));
          myOLED.drawLine(22+(i*3), 36-(i*2), 42, 36-(i*2));
        }
        myOLED.setFont(RusFont);
        myOLED.print("Cfyz `ktrnhbr", CENTER, 45);
        myOLED.print("+7 964 215-21-05", CENTER, 56);
        myOLED.update();
        for (int i=0; i<256; i++)
        {
          myOLED.setBrightness(i);
          delay(5);
        }
      while(!digitalRead(left)){
        if(digitalRead(right)) goto menuFour;
        //Работа в этом режиме пока не нажата кнопка <- влево
        
      }
      //Произойдет перед выходом
       Serial.println("");
      Serial.println("while4 break");
      digitalWrite(8, LOW);
      break;
    }

    
   //для меню
    if(btn_num()==4 || btn_num()==6){
      Serial.println("!!!!!!!!!MENU 4 !!!!!!!!!!");
      break;
    }
  }
}
