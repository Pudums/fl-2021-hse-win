# Абстрактный синтаксис языка M

## Программы

Программой на языке M является возможно пустая последовательность определений отношений и одна цель.

## Определение отношения

Любое отношение содержит имя отношения, список ее аргументов и тело. Телом отношения является некоторая цель.

## Атом

Атом это либо переменная, либо некоторый конструктор, примененный к возможно пустой последовательности атомов.

## Цель

Существует несколько типов целей:

* Унификация двух термов.
* Конъюнкция двух целей.
* Дизъюнкция двух целей.
* Вызов отношения по имени. Аргументами отношения может быть потенциально пустая последовательность атомов.