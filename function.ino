boolean start(){
//  Serial.println("start");
  
  if(btn_num()!=0 && flag==false){
//    Serial.println("first if()");
    if(btn_num()!=0){
//      Serial.println("two if");
      test[rid]=btn_num();
      rid++;
      Serial.print(rid);
      flag=true;  
    }
    
  }
  if(btn_num()==0 &&flag==true){
    flag=false;
  }
  if(rid>3){
//    Serial.println("if rid");
    rid=0;
    if(check_code()) 
    return true;
    else return false;
  }
  return false;
  
}
boolean check_code(){
  for(int i=0; i<4; i++){
    if(test[i]==btns[i]){
      Serial.print("backe ");
      Serial.print(test[i]);
      test[i]=0;
      Serial.print("now ");
      Serial.println(test[i]);
    }
    else return false;
  }
  return true;
}
int check_btn(int x){
  if(x==0) return 0;
  boolean flag_btn = false;
  if(digitalRead(x) && !flag_btn){
    delay(15);
    flag_btn = true;
  }
//  Serial.println("while start");
  while(flag_btn){
//    Serial.print("x ");
//    Serial.print(x);
//    Serial.print("  press ");
//    Serial.println(digitalRead(x));
    if(!digitalRead(x)&&flag_btn){
      delay(15);
      flag_btn=false;
      break;
      }
  }
//  Serial.println("while stop");
  return x;
}
int btn_num(){
     if(digitalRead(4)){
      delay(15);
      return 4;
     }
     if(digitalRead(6)){
      delay(15);
      return 6;
     }
     if(digitalRead(3)){
      delay(15);
      return 3; 
     }
     if(digitalRead(2)){
      delay(15);
      return 2;
     }
     return 0;
}
void set_menu_action(int x){
  switch(x){
      case 1: return menu_one(); break;
      case 2: return menu_two(); break;
      case 3: return menu_tree(); break;
      case 4: return menu_four(); break;
  }
}
