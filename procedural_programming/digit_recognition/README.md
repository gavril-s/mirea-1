# Digit Recognition
Нейронная сеть для распознования рукописных цифр

### Как запустить
Для запуска нужно скомпилировать и запустить `server.cpp` (`server/source/server.cpp`) и запустить `client.py` (`client/client.py`). Для запуска нужен фреймворк Для `C++` `Drogon`. Его можно установить с помощью `vcpkg` вот так: `make dpnds` (ну или просто скопируйте и выполните команды из `Makefile`).

### Какие параметры у нейросети?
Функция активации - логистическая функция
Обучение - простой backpropagation в один поток 
Слои - `748-32-32-10` (748 = 28 x 28)

### Структура проекта
* `network` - проект с нейросетью
    * `picture` - класс для считывания и хранения bmp-картинок
    * `network_node` - нейрон
    * `netwok` - нейросеть

* `server` - проект с сервером
    * `server` - сервер, принимающий GET-запросы с картинками и возвращающий ответ нейросети

* `client` - проект с демонстрацией работы нейросети (визуализация)
    * `client` - простое десктопное приложение, которое посылает запросы на сервер, в качестве картинки отправляя изображение, которое нарисовал пользователь.