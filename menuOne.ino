void menu_one(){
  Serial.println("menu_one");
  
  while(true){
    myOLED.clrScr();
    myOLED.drawBitmap(8, 1, mark, 120, 64);
    myOLED.update();
    delay(100);
    myOLED.drawBitmap(8, 1, mark_default, 120, 64);
    myOLED.update();

    //Произойдет при нажатии вправо ->
    if(digitalRead(right)){
      Serial.println("gahskdfjghsakj");
      myOLED.drawBitmap(8, 1, mark, 120, 64);
      myOLED.update();
      
      while(!digitalRead(left)){
        //Работа в этом режиме пока не нажата кнопка <- влево
        Serial.println(digitalRead(left));
        digitalWrite(11, HIGH);
      }
      //Произойдет перед выходом
       Serial.println("");
      Serial.println("while break");
      digitalWrite(11, LOW);
      break;
    }
    //для меню
    if(btn_num()==4 || btn_num()==6){
      Serial.println("!!!!!!!!!MENU 1  !!!!!!!!!!");
      break;
    }
  }
}
