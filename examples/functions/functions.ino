#include <MiniRelay.h>

Relay relay(12);
// Relay relay(12, 0);

void setup()
{
  Serial.begin(9600);

  // включить
  relay.set(1);
  delay(1000);
  // выключить
  relay.set(0);
  delay(1000);

  // переключить (на данном этапе включит реле)
  relay.change();
  delay(1000);

  // Выводим в порт текущее состояние
  Serial.println(relay.getState());

  if (relay.set(1))
  {
    Serial.println("Включилось") // Не сработает, так как реле уже включено и состояние не меняется
  }

  if (relay.set(0))
  {
    Serial.println("Выключилось") // Сработает, так как изменилось состояние
  }
}

void loop()
{
}
