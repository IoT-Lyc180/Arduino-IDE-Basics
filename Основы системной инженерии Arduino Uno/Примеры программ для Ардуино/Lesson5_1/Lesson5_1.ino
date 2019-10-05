/*
  * Lesson5_1
  * Управление работой светодиодной ленты
  * при помощи реле
 */
int relay1 = 2; //реле 1 подсоеденено к выводу 2
int relay2 = 3; //реле 2 подсоеденено к выводу 3
int relay3 = 4; //реле 3 подсоеденено к выводу 4

void setup()
 { 
  pinMode(relay1, OUTPUT); //указываем,что пин реле1 используется на вывод
  pinMode(relay2, OUTPUT); //указываем,что пин реле2 используется на вывод
  pinMode(relay3, OUTPUT); //указываем,что пин реле3 используется на вывод
 }
void loop()
{
 digitalWrite(relay1, HIGH); //включаем реле1
 delay(1000); //ждем 1 секунду
 digitalWrite(relay1, LOW); //выключаем реле1
 digitalWrite(relay2, HIGH); //включаем реле2
 delay(1000); //ждем 1 секунду
 digitalWrite(relay2, LOW); //выключаем реле2
 digitalWrite(relay3, HIGH); //включаем реле3
 delay(1000); //ждем 1 секунду
 digitalWrite(relay1, HIGH); //выключаем реле1
 digitalWrite(relay2, HIGH); //выключаем реле2
 digitalWrite(relay3, HIGH); //выключаем реле3
 delay(1000); //ждем 1 секунду
 digitalWrite(relay1, LOW); //выключаем реле1
 digitalWrite(relay2, LOW); //выключаем реле2
 digitalWrite(relay3, LOW); //выключаем реле3
 delay(1000); //ждем 1 секунду
}
