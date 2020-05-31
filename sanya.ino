#include <OLED_I2C.h>
#include <EEPROM.h>

#define top 4
#define right 2
#define left 3
#define footer 6 
#define lob 12
#define g1 22
#define g2 24
#define g3 26
#define g4 28
#define led_red 40
#define led_blue 41
#define led_green 42
//#include <OLED_I2C.h>
OLED  myOLED(SDA, SCL, 8); 
unsigned long tima;
int rid, menu_num=0;
boolean flag, flag1, flag2, flag3, flag4, flag_run_grub=false;
int btns[4] = {top, top, footer, right};
int test[4]={0,0,0,0};
int menu[]={0,0,0,0};
int menu_view, menu_grab_if_have_rec, menu_grab_if_empty_rec=0;
int btn;
int cell= EEPROM.read(0);
extern uint8_t mark[];
extern uint8_t mark_default[];
extern uint8_t mark_lob[];
extern uint8_t RusFont[];
extern uint8_t SmallFont[];   
extern uint8_t streli[];   
extern uint8_t clock_[];
extern uint8_t kusok[];
extern uint8_t trash[];
extern uint8_t ya1[];
extern uint8_t ya3[];
extern uint8_t ya2[];
extern uint8_t ya4[];

void setup() {
  myOLED.begin();
  Serial.begin(9600);
  pinMode(g1, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(g3, OUTPUT);
  pinMode(g4, OUTPUT);
 pinMode(left, INPUT);
 pinMode(right, INPUT);
 pinMode(top, INPUT);
 pinMode(footer, INPUT);
 pinMode(5, OUTPUT);
 pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
 digitalWrite(5,1);
 digitalWrite(g1,1);
 digitalWrite(g2,1);
 digitalWrite(g3,1);
 digitalWrite(g4,0);
 tima=millis();
}
 
void loop(){
  myOLED.clrScr();
  myOLED.update();
  if(start()){
    Serial.print("Вошли");
    myOLED.clrScr();
    myOLED.drawBitmap(8, 1, mark_default, 120, 64);
    myOLED.update();
    digitalWrite(g4,1);
    menu_view=1;
    set_menu_action(menu_view);
    program();
  }
  
}

void program(){
  if(btn_num()!=0){
//    Serial.print("btn_num()  ");
//    Serial.println(btn_num());
    btn = check_btn(btn_num());
//    Serial.print("btn  ");
//    Serial.println(btn);
    if(btn==4){
      menu_view+=1;
//      Serial.print("m_num:  ");
//      Serial.println(menu_num);
    }
    if(btn==6){
      menu_view-=1;
//      Serial.print("m_num:  ");
//      Serial.println(menu_num);
    }
    if(menu_view>4) menu_view=1;
    if(menu_view<1) menu_view=4;
//    if(menu_view>0){
//      Serial.print("menu_view:  ");
//      Serial.println(menu_view);
      set_menu_action(menu_view);
//    }
//    Serial.println(set_menu_num(check_btn(btn_num())));
      
    
  }
  program();
    
}
