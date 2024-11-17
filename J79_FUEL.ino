volatile float counter_oil = 0;  // переменная-счётчик
volatile float counter_way = 0;  // переменная-счётчик
float Speed = 0;                 // скорость ам
float way = 0;                   // путь целые
float use_oil = 0;               // использованное топливо
float liter = 0;                 // литры целые
float liter_low = 0;             // литры дробные
float way_low = 0;               // литры дробные


float litre_way = 0;  //литры на 100 км

void setup() {
  Serial.begin(9600);  // открыли порт для связи

  pinMode(2, INPUT_PULLUP);  // вход прерывания СРТ
  pinMode(3, INPUT_PULLUP);  // вхлд прерывания ДС

  attachInterrupt(0, btnIsr, FALLING);
  attachInterrupt(1, btnIsr1, FALLING);
}
void btnIsr() {
  counter_oil++;  // счетчик имульсов СРТ
}
void btnIsr1() {
  counter_way++;  // счетчик импульсов ДС
}


void loop() {
  if (counter_oil >= 16000) {
    liter++;
    counter_oil = 0;
  }

  if (counter_way >= 6000) {
    way++;
    counter_way = 0;
  }

  liter_low = counter_oil / 16000;

  way_low = counter_way / 6000;


  litre_way = (liter + liter_low) / (way + way_low) * 100; // считаем литры на 100км

  Serial.print("l/100km ");
  Serial.println(litre_way);  // выводим
  /*
  Serial.print("way ");
  Serial.println(way);  // выводим
  Serial.print("liter ");
  Serial.println(liter);  // выводим
  Serial.print("liter_low ");
  Serial.println(liter_low);  // выводим
  Serial.print("way_low ");
  Serial.println(way_low);  // выводим
*/

  delay(1000);  // ждём
}