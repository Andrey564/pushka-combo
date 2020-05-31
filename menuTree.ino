void menu_tree(){
  cell= EEPROM.read(0);
  Serial.println("menu_tree");
  myOLED.clrScr();
  while(true){
     myOLED.clrScr();
    myOLED.drawBitmap(8, 1, mark_default, 120, 64);
    myOLED.update();
  for (int i=0; i<20; i+=4)
  {
    if(btn_num()==4 || btn_num()==6){
      myOLED.clrScr();
      myOLED.drawBitmap(8, 1, mark_default, 120, 64);
      myOLED.update();
      Serial.println("!!!!!!!!!MENU 3 !!!!!!!!!!");
      break;
    }
    myOLED.drawCircle(50, 18, i*3);
    myOLED.update();
  }  
//      delay(50);
    //Произойдет при нажатии вправо ->
    if(digitalRead(right)){
      if(!flag_run_grub) start_grab();
      check_record:
      tima=millis();
      while(true){
        //если ячека не пустая
        
        if(check_rec()){
          Serial.println("Запись найдена!!!");
          menu_grab_if_have_rec=1; 
          while(!digitalRead(left)){
//            Serial.println(menu_grab_if_have_rec);
            if(btn_num()==4 || btn_num()==6){
              while(btn_num()){}
              menu_grab_if_have_rec++;
              if(menu_grab_if_have_rec>4) menu_grab_if_have_rec=1;
            }
            grab_menu_is_have_record(menu_grab_if_have_rec);
            if(digitalRead(right)){
              set_mode_action_grab(menu_grab_if_have_rec);
              goto check_record;
            }
          }
          
        }else{
          Serial.println("Записей нет");
          menu_grab_if_empty_rec=2;
          while(!digitalRead(left)){
            if(btn_num()==4 || btn_num()==6){
              while(btn_num()){}
              menu_grab_if_empty_rec++;
              if(menu_grab_if_empty_rec>4) menu_grab_if_empty_rec=2;
            }
              grab_menu_is_empty_record(menu_grab_if_empty_rec);
              if(digitalRead(right)){
                if(menu_grab_if_empty_rec!=2){
                  set_mode_action_grab(menu_grab_if_empty_rec);
                  
                  goto check_record;
                }
                
            }
          }
        }
        break;
      }
      //Произойдет перед выходом
       Serial.println("");
      Serial.println("while3 break");
      digitalWrite(9, LOW);
      break;
      
    }


    
   //для меню
    if(btn_num()==4 || btn_num()==6){
      myOLED.clrScr();
      myOLED.drawBitmap(8, 1, mark_default, 120, 64);
      myOLED.update();
      Serial.println("!!!!!!!!!MENU 3 !!!!!!!!!!");
      break;
    }
  }
}
