/*
  * Lesson6_1
  *Настройка сетевого интерфейса
  *Ethernet shield
 */
#include <SPI.h>
#include <Ethernet.h>
// Укажите MAC адресс вашего контроллера ниже
// В СЕТИ НЕ ДОЛЖНО БЫТЬ НЕСКОЛЬКО УСТРОЙСТВ С ОДИНАКОВЫМ MAC АДРЕСОМ
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
// Укажите статический IP адрес, если в сети не используется DHCP сервис
IPAddress ip(192, 168, 1,211);
// Инициализация Ethernet контроллера
EthernetClient client;
void setup() { 
  Serial.begin(9600); // Устанавливаем скорость 9600 бит/сек
   // устанавливаем Ethernet соединение:
   Serial.println("Connecting...");
  if (Ethernet.begin(mac) == 0) { //если контроллеру не удалось получить
                                  //настройки по DHCP, выводим сообщение
    Serial.println("Failed to configure Ethernet using DHCP");
    Ethernet.begin(mac, ip); //пытаемся настроить IP адрес вручную
  }
  delay(1000);
  Serial.print("IP address: ");
  Serial.println (Ethernet.localIP()); //выводим текущий IP адрес устройства 
}
void loop() { 
}

