# CourseProjectEltex
- - -
<span id="docs-internal-guid-89ddf6aa-7fff-0381-5a21-77c6ed1cb040">

<span style="font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-variant-numeric: normal; font-variant-east-asian: normal; vertical-align: baseline; white-space: pre-wrap;">**ONT CONNECTIONS** - это функционал для сохранения состояний ONT (Optical Network Terminal). Данный функционал используется провайдерами, для отслеживания состояний терминалов и сбора статистики работы.&nbsp;&nbsp;</span>

<span style="font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-variant-numeric: normal; font-variant-east-asian: normal; vertical-align: baseline; white-space: pre-wrap;">  
</span>

<span style="font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-variant-numeric: normal; font-variant-east-asian: normal; vertical-align: baseline; white-space: pre-wrap;"><span style="font-size: 14.6667px; font-weight: 700; white-space: pre-wrap;">       </span>Сохраняется следующая информация - Serial Number - серийный номер ONT, Equipment ID - наименование ONT, Firmware version - версия ПО терминала, LinkUP - время активации ONT, LinkDown - время деактивации ONT. Last State - состояние ONT на момент деактивации. Всего ONT может быть 2048 штук - 16 портов, по 128 ONT на каждом порту. Соответственно ONT индексируются парой значение - индекс порта/индекс ONT на порту. Сохраняется не более 10 событий.</span>

<span style="font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-variant-numeric: normal; font-variant-east-asian: normal; vertical-align: baseline; white-space: pre-wrap;"></span>
- - -
### <span style="font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-variant-numeric: normal; font-variant-east-asian: normal; vertical-align: baseline; white-space: pre-wrap;"></span>
</span>

<span></span>
### **Библиотека содержать следующий функционал:**
<span></span>

- <span style="background-color: transparent;"><font color="#000000" face="Arial"><span style="font-size: 11pt; white-space: pre-wrap;">Инициализация/деиницилизация библиотеки(</span><span style="font-size: 14.6667px; white-space: pre-wrap;">**_init**</span><span style="font-size: 11pt; white-space: pre-wrap;">и </span><span style="font-size: 14.6667px; white-space: pre-wrap;">**_fini**</span><span style="font-size: 11pt; white-space: pre-wrap;">) - создания и очистки ресурсов при начале и завершение работы с библиотекой.</span></font></span>
- <span style="font-weight: 400; font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-style: normal; font-variant-alternates: normal; font-variant-caps: normal; font-variant-east-asian: normal; font-variant-ligatures: normal; font-variant-numeric: normal; font-variant-position: normal; text-decoration-line: none; vertical-align: baseline; white-space: pre-wrap;">Обновление записи(</span><span style="font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-style: normal; font-variant-alternates: normal; font-variant-caps: normal; font-variant-east-asian: normal; font-variant-ligatures: normal; font-variant-numeric: normal; font-variant-position: normal; text-decoration-line: none; vertical-align: baseline; white-space: pre-wrap;">**ont__add_card**</span><span style="font-weight: 400; font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-style: normal; font-variant-alternates: normal; font-variant-caps: normal; font-variant-east-asian: normal; font-variant-ligatures: normal; font-variant-numeric: normal; font-variant-position: normal; text-decoration-line: none; vertical-align: baseline; white-space: pre-wrap;">): обновление подразумевает как добавление новой записи, так и обновление текущей.</span>

- <span style="font-weight: 400; font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-style: normal; font-variant-alternates: normal; font-variant-caps: normal; font-variant-east-asian: normal; font-variant-ligatures: normal; font-variant-numeric: normal; font-variant-position: normal; text-decoration-line: none; vertical-align: baseline; white-space: pre-wrap;">Получения данных по одной ONT(</span><span style="font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-style: normal; font-variant-alternates: normal; font-variant-caps: normal; font-variant-east-asian: normal; font-variant-ligatures: normal; font-variant-numeric: normal; font-variant-position: normal; text-decoration-line: none; vertical-align: baseline; white-space: pre-wrap;">**ont__get_card**</span><span style="font-weight: 400; font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-style: normal; font-variant-alternates: normal; font-variant-caps: normal; font-variant-east-asian: normal; font-variant-ligatures: normal; font-variant-numeric: normal; font-variant-position: normal; text-decoration-line: none; vertical-align: baseline; white-space: pre-wrap;">) - получить все записи по данной ONT.&nbsp;</span>

- <span style="font-weight: 400; font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-style: normal; font-variant-alternates: normal; font-variant-caps: normal; font-variant-east-asian: normal; font-variant-ligatures: normal; font-variant-numeric: normal; font-variant-position: normal; text-decoration-line: none; vertical-align: baseline; white-space: pre-wrap;">Получение данных по одной ONT c фильтром(</span><span style="font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-style: normal; font-variant-alternates: normal; font-variant-caps: normal; font-variant-east-asian: normal; font-variant-ligatures: normal; font-variant-numeric: normal; font-variant-position: normal; text-decoration-line: none; vertical-align: baseline; white-space: pre-wrap;">**ont__get_card_filter**</span><span style="font-weight: 400; font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-style: normal; font-variant-alternates: normal; font-variant-caps: normal; font-variant-east-asian: normal; font-variant-ligatures: normal; font-variant-numeric: normal; font-variant-position: normal; text-decoration-line: none; vertical-align: baseline; white-space: pre-wrap;">) - </span><span style="background-color: transparent; font-size: 11pt; white-space: pre;"> получить запись по данной ONT с </span><span style="background-color: transparent; font-size: 11pt; white-space: pre-wrap;">фильтром по времени и по статус</span>
- - -
### <span style="font-weight: 700;">Установка для UNIX системах:</span>
****

**Для сборки динамической библиотеки необходимо в главной директории прописать команду:**

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;make

**Для очистки используйте :**

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;make clean

**Собранный файл находиться в директории bin/. API находится в include/.**

****
- - -
### <span style="font-weight: 700;">Функции:</span>
#### <span style="color: rgb(0, 0, 0); font-family: Arial; font-size: 14.6667px; white-space: pre-wrap;">**Обновление записи:**</span>
<font color="#000000" face="Arial"><span style="font-size: 14.6667px; white-space: pre-wrap;"> </span></font><span style="font-weight: 700;">&nbsp; &nbsp;</span><span style="font-weight: 700;">&nbsp;</span><span style="font-size: 14.6667px; white-space: pre-wrap; color: rgb(0, 0, 0); font-family: Arial;">int ont__add_card(struct Ont_info const *const ont_info);</span>

<span style="color: rgb(0, 0, 0); font-family: Arial; font-size: 14.6667px; white-space: pre-wrap;">**Получения данных по одной ONT:**</span>

&nbsp; &nbsp; int ont__get_card(

&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;uint32_t const num_port,

&nbsp; &nbsp;&nbsp; &nbsp;&nbsp;&nbsp;uint32_t const num_ont,

&nbsp; &nbsp;&nbsp; &nbsp;&nbsp;&nbsp;struct Ont_connection ont_connection[NUM_OF_RECORDS]);

<span style="font-weight: 700; color: rgb(0, 0, 0); font-family: Arial; font-size: 14.6667px; white-space: pre-wrap;">Получения данных по одной ONT c </span><span style="color: rgb(0, 0, 0); font-family: Arial; font-size: 14.6667px; white-space: pre-wrap;"><b>фильтром</b></span><span style="color: rgb(0, 0, 0); font-family: Arial; font-size: 14.6667px; font-weight: 700; white-space: pre-wrap;">:</span>

int ont__get_card_filter(

&nbsp; &nbsp; uint32_t const num_port,

&nbsp; &nbsp; uint32_t const num_ont,

&nbsp; &nbsp; void *const key,

&nbsp; &nbsp; struct Ont_connection * const ont_connection,

&nbsp; &nbsp; enum Card_filter filter);

****
