#### О программе
---
- Программа представляет собой консольный чат в котором одновременно может находиться только один пользователь
- Ввод и вывод информации только через консоль
- Для того чтобы отправлять / получать сообщения пользователь должен войти в чат. Для этого у него должен быть аккаунт.
- У каждого зарегистрированного пользователя есть:
	- Ник - имя по которому он будет известен остальным пользователям
	- Логин
	- Пароль


#### Базовый функционал
---
-   регистрация пользователей - логин, пароль, имя
-   вход в чат по логину/паролю
-   отправка сообщений конкретному пользователю
	- написать сообщение
	- нажать клавишу enter
	- написать Ник адресата
		- если Ник отсутствует в базе данных - просьба ввести Ник заново или нажать `0` чтобы выйти из режима отправки сообщения
- обмен сообщениями между всеми пользователями чата одновременно
	- написать сообщение
	- нажать клавишу enter
	- написать Ник адресата - "all"
- выход из чата осуществляется вводом слова `exit`


#### Cписок участников команды
---
- Герман
- Светлана


#### Описание выбранной идеи решения
---
- Основная логика работы чата реализуется в виде конечного автомата и выносится в отдельный класс `Chat`.
	- Примерное количество состояний автомата ~ 10. Переходы между состояниями осуществляются достаточно редко ~ секунд. Исходя из этого для реализации класса `Chat` целосообразно применить паттерн State.
	- Поскольку чат в программе может быть только один - значит и объект класса `Chat` может быть только один. Поэтому помимо паттерна State нужно применить ещё паттерн Singleton.
- Хранение информации о пользователях и их сообщениях друг друга осуществляется в базе данных. База данных реализуется в виде отдельного модуля `DataBase`, который предоставляет классу `Chat` отдельные функции, в том числе:
	- проверить есть ли в базе заданный Логин
	- проверить соответствует ли Пароль заданному Логину
	- добавить в базу заданного Пользователя
- Информация о конкретном пользователе инкапсулируется в отдельный класс `User`. Класс содержит поля:
	- Ник
	- Логин
	- Пароль


#### Описание пользовательских типов и функций в проекте
---
- Класс `Chat` - центральный блок управления логикой работы взаимодействия пользователя с чатом
- Класс `User` - инкапсуляция данных о пользователе (имя, логин, пароль)
- Модуль `DataBase` - методы чтения / записи в базу данных пользователей и их сообщений


#### Распределение задач в команде
---
Герман:
- общая архитектура
- модуль работы с базой данных (`DataBase`)
- класс пользователь (`User`)
Светлана:
- разработка логики работы чата (`Chat`)