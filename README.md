# PMI_T_3_H_Cpp
Предмет «Технология разработки программного обеспечения» 

Иcпользуется язык программирования С++, версия 20.

### Страница программы курса [CLICK](https://imcs.dvfu.ru/cats/?f=wiki;name=cpp-course-2020) | [CLICK](/CATS_files)

#### [Контест №1](/tournament%201) на классы.
#### [Контест №2](/tournament%202) на указатели.
#### [Контест №3](/tournament%203) на многопоточность.
#### [Лабораторная работа №1](/LAB%201) на комплексные числа.
#### [Лабораторная работа №2](/LAB%202) на хеш таблицу.
#### [Лабораторная работа №3](/LAB%203) на создание игры Rogue-like.

### Полезные инструкции, которые могут пригодится при использовании лабораторных проектов:
#### Установка системы юнит-тестирования - Catch в Clion
**Во-первых**, вот ссылка на саму установку [Coverage(покрытие кода)](https://plugins.jetbrains.com/plugin/11031-c-c--coverage) и [ссылка на git](https://github.com/zero9178/C-Cpp-Coverage-for-CLion). Он нам понадобиться чтобы красиво все нам показывало и запускалось.  
**Во-вторых**, вот ссылка на сам [Catch](https://github.com/catchorg/catch2/releases), скачиваем `catch.hpp` и закидываем в наш проект(как это сделано у меня.  
Теперь дело за малым, мы должны настроить Cmake, вот код который необходимо вставить в `CmakeList.txt`:
```
# add coverage
# https://plugins.jetbrains.com/plugin/11031-c-c--coverage
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options(-fprofile-instr-generate -fcoverage-mapping)
    add_link_options(-fprofile-instr-generate)
    #Uncomment in case of linker errors
    #link_libraries(clang_rt.profile-x86_64)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options(--coverage)
    #Uncomment in case of linker errors
    #link_libraries(gcov)
endif ()
```
Осталось заинклюлудить в файл, где будут находится тесты. *Пример кода теста:*
```
TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(10) == 3628800 );
}
```
#### Установка pdcurses на Windows
Вот нормальная [статья](https://code-live.ru/post/installing-pdcurses/#pdcurses) как это сделать, хотя у меня не получилось. Поэтому расскажу как я запускаю это.  
У меня установлена WSL Ubuntu 18.04 LTS, на нее я поставил библиотеку `Cmake`, но к сожелению разработчик ограничил версию его только до 10, но это сильно старая и у вас не заведется, поэтому нужно было установить 16 и выше версию(сейчас расскажу как). Если же у вас Ubuntu 20 версии, то у можно воспользоваться командой:  
```
sudo apt-get install cmake
```  
**Как установить Cmake версии выше 16 вручную:**  
**A-1** Удалите версию по умолчанию, предоставленную менеджером пакетов и конфигурацией Ubuntu, с помощью:  
```
sudo apt remove --purge --auto-remove cmake
```
or:
```
sudo apt purge --auto-remove cmake
```
**A-2** Перейдите на [официальную веб-страницу CMake](http://www.cmake.org/download) и узнайте какую версию вы хотите установить, измените `version` и `build` в следующей команде, чтобы получить желаемую версию:
```
version=3.19
build=1
mkdir ~/temp
cd ~/temp
wget https://cmake.org/files/v$version/cmake-$version.$build.tar.gz
tar -xzvf cmake-$version.$build.tar.gz
cd cmake-$version.$build/
```
**A-3** Установите извлеченный источник, запустив:
```
./bootstrap
make -j$(nproc)
sudo make install
```
**A-4** Проверьте установленную версию Cmake:
```
$ cmake --version
```
Результат `cmake --version`:
```
cmake version 3.19.X

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```
Теперь осталось прописать в CmakeList.txt в вашем проекте данные строчки и подключить библиотеку в нужном файле:
```
#add_link_options(-fsanitize=address -g -Wall -Werror -lncurses)
```
Надеюсь я Вам помог.


Преподователи курса:
1) [Алексей Щуров](https://github.com/alexiskhb)
2) [Игорь Блинов]()
3) [Константин Федоров]()

***The project was released for my University course***

##### My contacts:
1. [Telegram](https://tgmsg.ru/princepepper)
2. [Вконтакте](https://vk.com/princepepper)
3. [Instargam](https://www.instagram.com/prince_pepper_official/?hl=ru)
4. <sereda.wk@gmail.com>
