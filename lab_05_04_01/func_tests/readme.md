# Тесты для лабораторной работы №5 задание №4

## Входные данные
ft - Текстовый файл in, подстрока

sb - Двоичный файл

## Выходные данные
ft - Текстовый файл out

sb - Отсортированный двоичный файл 

## Позитивные тесты:
- 01 - ft - все фамилии начинаются с подстроки;
- 02 - ft - одна фамилия начинается с подстроки;
- 03 - sb - неупорядоченный файл;
- 04 - sb - упорядоченный файл;
- 05 - sb - одна запись.

## Негативные тесты:
- 01 - Не передано ни одного аргумента;
- 02 - Не передано название файла;
- 03 - Переданный режим работы не существует;
- 04 - Файл не существует;
- 05 - ft - некорректно заполненный файл;
- 06 - ft - пустой файл;
- 07 - sb - некорректно заполненный файл;
- 08 - sb - пустой файл;
- 09 - ft - пустая подстрока;
- 10 - ft - слишком длинная подстрока;
- 11 - ft - ни одна фамилия не начинаются с подстроки.