void menu_two(){
  Serial.println("menu_two");
  myOLED.clrScr();
   while(true){
    myOLED.clrScr();
    myOLED.drawBitmap(8, 1, mark_lob, 120, 64);
    myOLED.update();
    myOLED.drawBitmap(8, 1, mark_default, 120, 64);
    myOLED.update();
    //Произойдет при нажатии вправо ->
    if(digitalRead(right)){
      myOLED.drawBitmap(8, 1, mark_lob, 120, 64);
      myOLED.update();
      while(!digitalRead(left)){
        //Работа в этом режиме пока не нажата кнопка <- влево
        Serial.println("_");
        digitalWrite(12, HIGH);
      }
      //Произойдет перед выходом
       Serial.println("");
      Serial.println("while2 break");
      digitalWrite(12, LOW);
      break;
    }
    
   //для меню
    if(btn_num()==4 || btn_num()==6){
      Serial.println("!!!!!!!!!MENU 2 !!!!!!!!!!");
      break;
    }
  }
}
