/*
  * Lesson6_2
  *Пример получения и отправки данных
  *на сервер прогноза погоды
 */
#include <SPI.h>
#include <Ethernet.h>
// Укажите MAC адресс вашего контроллера ниже
// В СЕТИ НЕ ДОЛЖНО БЫТЬ НЕСКОЛЬКО УСТРОЙСТВ С ОДИНАКОВЫМ MAC АДРЕСОМ
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
// Укажите статический IP адрес, если в сети не используется DHCP сервис
char server[] = "samples.openweathermap.org";    // адрес сервера прогноза погоды
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
  // если смогли подключиться к серверу, то отправляем запрос:
  if (client.connect(server, 80)) {
    Serial.println("connected");
    // формируем HTTP запрос:
   const String html_cmd1 = "GET /data/2.5/forecast?id=524901&appid=b1b15e88fa797225412429c1c50c122a1 HTTP/1.1";
   const String html_cmd2 = "Host: samples.openweathermap.org";
   const String html_cmd3 = "Connection: close";
   // выполняем HTTP запрос:
    client.println(html_cmd1);
    client.println(html_cmd2);
    client.println(html_cmd3);
    client.println();
  } else {
    // если не смогли подключиться к серверу:
    Serial.println("connection failed");
  }
}
void loop() {
  // выводим на экран все, что получили от сервера
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }
  // если произошло отключение от сервера, останавливаем клиент:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
  }
}



