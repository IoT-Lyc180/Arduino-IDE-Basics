/*
  *  Lesson2_2
  * Включает и выключает светодиод (LED) подсоединенный  
  * к выходу 13, в зависимости от расстояния до ближайшего к сенсору расстояния объекта
  *
 */

int Trig = 12;    //Выход TRIG сенсора расстояния  подсоединен к выводу 12
int Echo = 11;    //Выход ECHO сенсора расстояния  подсоединен к выводу 11
int ledPin = 13;  //LED подсоединен к выводу 13

unsigned int time_us=0;     //переменная для хранения времени отклика
unsigned int distance_sm=0; //переменная для хранения расстояния до объекта

void setup() 
{ 
pinMode(Trig, OUTPUT);     //указываем, что вывод Trig - выход
pinMode(Echo, INPUT);      //указываем, что Echo - вход
pinMode(ledPin, OUTPUT);   //указываем, что светодиод - выход
}

void loop() 
{ 
digitalWrite(Trig, HIGH);    // Подаем сигнал на выход TRIG
delayMicroseconds(10);       // Пауза 10 микросекунд 
digitalWrite(Trig, LOW);     // Убираем сигнал на выходе TRIG
time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса 
distance_sm=time_us/58;      // Пересчитываем в сантиметры 

if (distance_sm < 50)        // Если расстояние менее 50 сантиметром 
{ 
   digitalWrite(ledPin, HIGH); // включаем светодиод 
} 
else 
{ 
   digitalWrite(ledPin, LOW); // иначе выключаем светодиод
} 
  
delay(100);   //пауза перед следующим измерением 
}

