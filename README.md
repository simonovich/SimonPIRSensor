### Информер для туалета

<img src="https://i.imgur.com/97TygwQ.jpg" width="600" />

#### Область применения

Санузел часто бывает занят и порой внезапно. Каждый раз бегать и проверить его статус лично - неудобно. Этот проект решает проблему при помощи простейшего инфракрасного датчика движения (PIR Sensor HC-SR501) и микроконтроллера на базе ESP-12F от [Амперки](http://wiki.amperka.ru/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:troyka-wi-fi).

#### Принцип действия.

Датчик движения имеет две ручки потенциометров. Первый определяет длительность сигнала после очередного срабатывания. Подбираем такое положение, при котором время очередного срабатывания датчика примерно соответствует времени нахождения объекта в зоне наблюдения. Вторым - подбираем расстояние до наблюдаемого объекта, в нашем случае этот будет наименьшее допустимое значение - 3м.

![PIR Sensor](https://static.chipdip.ru/lib/532/DOC004532250.jpg)

#### Принципиальная схема

<img src="https://i.imgur.com/E29vaJl.png" width="600" />
