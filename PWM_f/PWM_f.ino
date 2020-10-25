
int p;
void setup() {
  //pinMode(3, OUTPUT); 
  pinMode(9, OUTPUT); 
//TCCR1B = TCCR1B & B11111000 | B00000001;    // set timer 1 divisor to     1 for PWM frequency of 31372.55 Hz
//TCCR1B = TCCR1B & B11111000 | B00000010;    // set timer 1 divisor to     8 for PWM frequency of  3921.16 Hz
//TCCR1B = TCCR1B & B11111000 | B00000011;    // set timer 1 divisor to    64 for PWM frequency of   490.20 Hz (The DEFAULT)
//TCCR1B = TCCR1B & B11111000 | B00000100;    // set timer 1 divisor to   256 for PWM frequency of   122.55 Hz
//TCCR1B = TCCR1B & B11111000 | B00000101;    // set timer 1 divisor to  1024 for PWM frequency of    30.64 Hz// put your setup code here, to run once:
  Serial.begin(9600);

  //TCCR1A = _BV(COM1A0) | _BV(COM1B1) | _BV(WGM11) | _BV(WGM10); //Set Timer2 to varying top limit fast PWM mode
  //TCCR1B = _BV(WGM12) | _BV(CS12) | _BV(CS11) | _BV(CS10);//another way to set prescaler CS2=fff
  //TCCR1A = _BV (COM1A1 )| _BV (COM1B1 ) | _BV (WGM20 )| _BV ( WGM21); 
  //TCCR1B = _BV (CS12 ); 

  //TCCR2A = _BV （ COM2A1 ） | _BV （ COM2B1 ） | _BV （ WGM21 ） | _BV （ WGM20 ）; 
  //TCCR2B = _BV （ CS22 ）; 

  //OCR1A = 120; //Top value A
  //OCR1B = 90; //Toggle value B, Output at pin 3

    //记住默认情况下未声明的寄存器保持零...
    TCCR1A =((1 << WGM11)|(1 << COM1B1)|(1 << COM1A1)); //请阅读DataSheet的第131页，我们正在将WGM11，COM1B1，COM1A1的寄存器设置更改为1，即全部...
    TCCR1B =(1 << WGM13)|(1 << WGM12)|(1 << CS11); //将预分频器设置为8，使我们的分辨率为0.5us，请阅读数据表的第134页
    // OCR1A = 3000; // PB5，没有
    OCR1B = 3000; // PB6，OUT2
    OCR1A = 3000; // PB7 OUT3
    ICR1 = 5250; // 380hz频率...
    analogWrite(9, 2850); //2850-3050 54.29% 58.10%   380.65HZ


  
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {   // 串口收到字符数大于零。
    p = Serial.parseInt();      // 在串口数据流中查找一个有效整数。
    //Serial.println(p);         //打印接收到的数字
    analogWrite(9, p);
  }
}
