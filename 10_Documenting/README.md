/// @mainpage
## Documenting test
Документация + перевод документации

Пытался сделать сборку в Latex, но что-то сломал. Поэтому построение графиков и красивых схем отключено.

У меня на машине man собирается, но less выводит его очень криво (Судя по raw тексту, в конце не генерируется закрывающий тэг. "Но это не точно").

## Assembly
1. autoreconf -fisv
2. ./configure
3. make - создаст перевод и положит его в папку ru, создаст документацию
4. make gitclean

## Programm descriprion
Main programm. Guesses a human-conceived number by dividing by 2.

## Reference
* `main.c`
* `roman.h`

## Features
* *make doc_server* - запускает локальный сервер с документацией (порт: 8500)
* *make help* - запускает man
* *make test* - запускает приложение
* *make test_local* - запускает приложение на русском
* *make test_help* - выводит help и version
* *make test_help_local* - выводит help и version на русском
* *make test_roman* - запускает приложение с римскими цифрами 

![alt text](https://memegenerator.net/img/images/14760331.jpg)
