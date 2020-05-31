void grab_menu_is_empty_record(int mode){
  myOLED.clrScr();                                    
  myOLED.setFont(RusFont);   
  myOLED.print("Crfybhetv", CENTER, 5);
  //-------------------------------------------------------
  if(cell==1)myOLED.print("1", RIGHT, 0);
  if(cell==2)myOLED.print("2", RIGHT, 0);
  if(cell==3)myOLED.print("3", RIGHT, 0);
  if(cell==4)myOLED.print("4", RIGHT, 0);
  //-------------------------------------------------------
  if(mode==2){
    Serial.print("mode= ");
    Serial.print(mode);
    Serial.println("   Ждем сигнал");
    myOLED.print(":LTV CBUYFK", CENTER, 32);  
  }else if(mode==3){
    Serial.print("mode= ");
    Serial.print(mode);
    Serial.println("   Переключить ячейку");
    myOLED.print("Gthtrk.xbnm", CENTER, 22);
    myOLED.print("zxtqre", CENTER, 34);
  }
  else if(mode==4){
    myOLED.print("Ghjdthbnm", CENTER, 22);
    myOLED.print("`ne zxtqre", CENTER, 34);
  }
  myOLED.drawBitmap(8, 1, streli, 8, 54);
  myOLED.print("Dsqnb", LEFT, 56);
  myOLED.print("Ghtvtybnm", RIGHT, 55);  
  myOLED.update();  
}
void grab_menu_is_have_record(int mode){
  myOLED.clrScr();                                    
  myOLED.setFont(RusFont);
  //-------------------------------------------------------
  if(cell==1)myOLED.print("1", RIGHT, 0);
  if(cell==2)myOLED.print("2", RIGHT, 0);
  if(cell==3)myOLED.print("3", RIGHT, 0);
  if(cell==4)myOLED.print("4", RIGHT, 0);
  //-------------------------------------------------------
  myOLED.print("Tcnm pfgbcm", CENTER, 5);  
  myOLED.drawBitmap(8, 1, streli, 8, 54); 
  if(mode==1){
    myOLED.print("BCGJKMPJDFNM", CENTER, 27);
  }else if(mode==2){
    myOLED.print("ELFKBNM&", CENTER, 27);
  }else if(mode==3){
    myOLED.print("Gthtrk.xbnm", CENTER, 17);
    myOLED.print("zxtqre", CENTER, 27);
  }else if(mode==4){
    myOLED.print("Ghjdthbnm", CENTER, 17);
    myOLED.print("`ne zxtqre", CENTER, 27);
  }
  myOLED.print("Dsqnb", LEFT, 55);
  myOLED.print("Ghtvtybnm", RIGHT, 55);  
  myOLED.update();
}

void set_mode_action_grab(int x){
  switch(x){
      case 1: return acive_signal(); break;
      case 2: return delete_cell(); break;
      case 3: flag4=false; return select_cell(); break;
      case 4:  break;
  }
}
void delete_cell(){
  myOLED.clrScr();
  myOLED.drawBitmap(40, 5, kusok, 5, 5); 
  myOLED.drawBitmap(50, 29, trash, 30, 35); 
  myOLED.update();
  press_btn_grab(g4);
  myOLED.clrScr();
  myOLED.drawBitmap(50, 15, kusok, 5, 5); 
  myOLED.drawBitmap(50, 29, trash, 30, 35); 
  myOLED.update();
  press_btn_grab(g4);
  myOLED.clrScr();
  myOLED.drawBitmap(60, 25, kusok, 5, 5); 
  myOLED.drawBitmap(50, 29, trash, 30, 35); 
  myOLED.update(); 
  press_btn_grab(g1);
}
void acive_signal(){
  digitalWrite(g1, LOW);
  myOLED.clrScr();
    myOLED.update();
  for (int i=0; i<26; i+=4)
  {
    myOLED.drawCircle(64, 64, i*3);
    myOLED.update();
    delay(50);
  }
  digitalWrite(g1, HIGH);
}
void select_cell(){
  flag4=false;
  while(true){
    myOLED.clrScr();                          
  myOLED.print("J:BLFYBT", CENTER, 5);
  myOLED.print("YF:FNBZ", CENTER, 15);
  myOLED.print("RYJGRB", CENTER, 25);
  myOLED.print("DS<JHF", CENTER, 35);
  myOLED.print("ZXTQRB", CENTER, 45);
  myOLED.print("1   2   3   4", CENTER, 55);  
  myOLED.update(); 
  if(btn_num() && !flag4){
    while(btn_num()){}
  }
//  while(btn_num()){Serial.print("while");}
  if(btn_num() && flag4){
//    Serial.print("button   ");
//    Serial.println(btn_num());
    toogle_cell(btn_num());
    while(btn_num()){}
    break;
  }
  flag4=true;
  }
}
void start_grab(){
  Serial.println("enter grab");
  press_btn_grab(g4);
  press_btn_grab(g4);
  press_btn_grab(g2);
  flag_run_grub=true;
}

void toogle_cell(int x){
  myOLED.clrScr(); 
  switch(x){
    case 4:
      myOLED.drawBitmap(40, 0, ya1, 50, 60);
      myOLED.update(); 
      triple_click();
      press_btn_grab(g1);
      EEPROM.write(0, 1);
      Serial.println("one1"); break;
    case 6:
      myOLED.drawBitmap(40, 0, ya2, 50, 60);
      myOLED.update();
      triple_click();
      press_btn_grab(g2);
      EEPROM.write(0, 2);
      Serial.println("two2"); break;
    case 3:
      myOLED.drawBitmap(40, 0, ya3, 50, 60);
      myOLED.update(); 
      triple_click();
      press_btn_grab(g3);
      EEPROM.write(0, 3);
      Serial.println("tre3"); break;
    case 2:
      myOLED.drawBitmap(40, 0, ya4, 50, 60);
      myOLED.update(); 
      triple_click();
      press_btn_grab(g4);
      EEPROM.write(0, 4);
      Serial.println("fou4"); break;
  }
}
void triple_click(){
  for(byte i=0; i<3; i++){
    press_btn_grab(g4);
  }
}
boolean check_rec(){
  myOLED.clrScr();
  myOLED.drawBitmap(50, 10, clock_, 40, 50);
  myOLED.update();
  if(millis()-tima<3000){
    Serial.println("Check Record");
    if(digitalRead(led_blue) || digitalRead(led_green)){
            Serial.println("123true");
            return true;
          }
          if(digitalRead(led_red)){
           flag3=true;
           if(!digitalRead(led_red)){
            flag3=false;
           }
          }
          if(millis()-tima>3000 && flag3){
            Serial.println("true");
            return true;
          }
     check_rec();
  }else{
    Serial.println("false");
    return false;
  }
  
}

void press_btn_grab(int x){
  digitalWrite(x, LOW);
  delay(500);
  digitalWrite(x, HIGH);
  delay(500);
}
