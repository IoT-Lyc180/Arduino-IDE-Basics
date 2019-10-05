/*
  * Lesson3_1
  * Вывод значений температуры и влажности воздуха, 
  * полученных с датчика DHT11, в Монитор порта
 */
#include "DHT.h" //Подключаем библиотеку для работы с DHT11
int DHTPIN = 12;  //DHT11 подсоединен к выводу 12
DHT dht(DHTPIN, DHT11); //Создание объекта с DHT11
void setup() 
{
  Serial.begin(9600); //Устанавливаем скорость 9600 бит/сек
  dht.begin(); //Инициализация датчика DHT11
}

void loop() 
{
  delay(2000); // Задержка 2 секунды между измерениями
  float h = dht.readHumidity(); //Считываем влажность
  float t = dht.readTemperature(); // Считываем температуру
  Serial.print("Humidity:");
  Serial.print (h);
  Serial.print (" %");
  Serial.print("   Temperature:");
  Serial.print(t); //Вывод данных в Монитор порта
  Serial.println(" C");
}

