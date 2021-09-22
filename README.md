# CourseProjectEltex
- - -
<span id="docs-internal-guid-89ddf6aa-7fff-0381-5a21-77c6ed1cb040">

<span style="font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-variant-numeric: normal; font-variant-east-asian: normal; vertical-align: baseline; white-space: pre-wrap;"><span style="color: rgb(51, 51, 51); font-family: &quot;Helvetica Neue&quot;, Helvetica, Arial, sans-serif; font-size: 14px;">&nbsp; &nbsp; &nbsp; &nbsp;</span><span style="color: rgb(51, 51, 51); font-family: &quot;Helvetica Neue&quot;, Helvetica, Arial, sans-serif; font-size: 14px;">&nbsp;</span>**ONT CONNECTIONS** - это функционал для сохранения состояний ONT (Optical Network Terminal). Данный функционал используется провайдерами, для отслеживания состояний терминалов и сбора статистики работы.&nbsp;&nbsp;</span>

<span style="font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-variant-numeric: normal; font-variant-east-asian: normal; vertical-align: baseline; white-space: pre-wrap;">  
</span>

<span style="font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-variant-numeric: normal; font-variant-east-asian: normal; vertical-align: baseline; white-space: pre-wrap;"><span style="color: rgb(51, 51, 51); font-family: &quot;Helvetica Neue&quot;, Helvetica, Arial, sans-serif; font-size: 14px;">&nbsp; &nbsp; &nbsp; &nbsp;</span><span style="color: rgb(51, 51, 51); font-family: &quot;Helvetica Neue&quot;, Helvetica, Arial, sans-serif; font-size: 14px;">&nbsp;</span>Сохраняется следующая информация - Serial Number - серийный номер ONT, Equipment ID - наименование ONT, Firmware version - версия ПО терминала, LinkUP - время активации ONT, LinkDown - время деактивации ONT. Last State - состояние ONT на момент деактивации. Всего ONT может быть 2048 штук - 16 портов, по 128 ONT на каждом порту. Соответственно ONT индексируются парой значение - индекс порта/индекс ONT на порту. Сохраняется не более 10 событий.</span>

<span style="font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-variant-numeric: normal; font-variant-east-asian: normal; vertical-align: baseline; white-space: pre-wrap;"></span>
- - -
### <span style="font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-variant-numeric: normal; font-variant-east-asian: normal; vertical-align: baseline; white-space: pre-wrap;"></span>
</span>


<span></span>
### **Библиотека содержит следующий функционал:**
<span></span>


- 
    
    <span style="background-color: transparent;"><font color="#000000" face="Arial"><span style="font-size: 11pt; white-space: pre-wrap;">**Инициализация/деиницилизация библиотеки**</span><span style="font-size: 11pt; white-space: pre-wrap;"> - создания и очистки ресурсов при начале и завершение работы с библиотекой.</span></font></span>


- 
    
    <span style="font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-style: normal; font-variant-alternates: normal; font-variant-caps: normal; font-variant-east-asian: normal; font-variant-ligatures: normal; font-variant-numeric: normal; font-variant-position: normal; text-decoration-line: none; vertical-align: baseline; white-space: pre-wrap;">**Обновление записи**</span><span style="font-weight: 400; font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-style: normal; font-variant-alternates: normal; font-variant-caps: normal; font-variant-east-asian: normal; font-variant-ligatures: normal; font-variant-numeric: normal; font-variant-position: normal; text-decoration-line: none; vertical-align: baseline; white-space: pre-wrap;"> - </span><span style="font-weight: 400; font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-style: normal; font-variant-alternates: normal; font-variant-caps: normal; font-variant-east-asian: normal; font-variant-ligatures: normal; font-variant-numeric: normal; font-variant-position: normal; text-decoration-line: none; vertical-align: baseline; white-space: pre-wrap;"> обновление подразумевает как добавление новой записи, так и обновление текущей.</span>


- 
    **<span style="font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-style: normal; font-variant-alternates: normal; font-variant-caps: normal; font-variant-east-asian: normal; font-variant-ligatures: normal; font-variant-numeric: normal; font-variant-position: normal; text-decoration-line: none; vertical-align: baseline; white-space: pre-wrap;">Получения данных по одной ONT</span><span style="font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-style: normal; font-variant-alternates: normal; font-variant-caps: normal; font-variant-east-asian: normal; font-variant-ligatures: normal; font-variant-numeric: normal; font-variant-position: normal; text-decoration-line: none; vertical-align: baseline; white-space: pre-wrap;"> </span>**<span style="font-weight: 400; font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-style: normal; font-variant-alternates: normal; font-variant-caps: normal; font-variant-east-asian: normal; font-variant-ligatures: normal; font-variant-numeric: normal; font-variant-position: normal; text-decoration-line: none; vertical-align: baseline; white-space: pre-wrap;">- получить все записи по данной ONT.&nbsp;</span>


- 
    
    <span style="font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-style: normal; font-variant-alternates: normal; font-variant-caps: normal; font-variant-east-asian: normal; font-variant-ligatures: normal; font-variant-numeric: normal; font-variant-position: normal; text-decoration-line: none; vertical-align: baseline; white-space: pre-wrap;">**Получение данных по одной ONT c фильтром**</span><span style="font-weight: 400; font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-style: normal; font-variant-alternates: normal; font-variant-caps: normal; font-variant-east-asian: normal; font-variant-ligatures: normal; font-variant-numeric: normal; font-variant-position: normal; text-decoration-line: none; vertical-align: baseline; white-space: pre-wrap;"> </span><span style="font-weight: 400; font-size: 11pt; font-family: Arial; color: rgb(0, 0, 0); background-color: transparent; font-style: normal; font-variant-alternates: normal; font-variant-caps: normal; font-variant-east-asian: normal; font-variant-ligatures: normal; font-variant-numeric: normal; font-variant-position: normal; text-decoration-line: none; vertical-align: baseline; white-space: pre-wrap;">- </span><span style="background-color: transparent; font-size: 11pt; white-space: pre;"> получить запись по данной ONT с </span><span style="background-color: transparent; font-size: 11pt; white-space: pre-wrap;">фильтром по времени и по статус</span>


- - -
### <span style="font-weight: 700;">Установка для UNIX системах:</span>
****

&nbsp; &nbsp; &nbsp; &nbsp;&nbsp;<span style="font-weight: 700;">Собранный файл находиться в директории bin/.&nbsp;</span><span style="font-weight: 700;">API находится в include/.&nbsp;</span>**Для сборки динамической библиотеки необходимо в главной директории прописать команду:**
>  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;make

&nbsp; &nbsp; &nbsp; &nbsp;&nbsp;<span style="font-weight: 700;">Для очистки используйте :</span>
> &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;make clean
- - -
### **Тестирование:**
**&nbsp;&nbsp;**&nbsp; &nbsp; &nbsp; &nbsp;&nbsp; **Для проверки работоспособности&nbsp;библиотеки можно зайти в папку test/ и ввести&nbsp;**
> <span style="font-size: 17.5px;">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;make</span>

> &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;./test

&nbsp; &nbsp; &nbsp; &nbsp; **&nbsp;Тесты демонстрируют:**

<span id="docs-internal-guid-9b323834-7fff-e504-4792-30ab6aff00e3"></span>

- <span style="font-size: 11pt; background-color: transparent; font-variant-numeric: normal; font-variant-east-asian: normal; vertical-align: baseline; white-space: pre-wrap;">Валидность входных аргументов для внешнего API</span>

- <span style="font-size: 11pt; background-color: transparent; font-variant-numeric: normal; font-variant-east-asian: normal; vertical-align: baseline; white-space: pre-wrap;">Демонстрацией работы: имитация нескольких добавлени и т.п., получение карточек и сравнение с эталоном.</span>
- - -
> <br>Пример:
> <br>&nbsp; &nbsp; struct Ont_info ont_info = {0};
> <br>&nbsp; &nbsp; enum Errors errors = NO_ERRORS;  
> <br> &nbsp; &nbsp; ont_info.num_port = 0;
> <br>&nbsp; &nbsp; ont_info.num_ont = 0;
> <br>&nbsp; &nbsp; strncpy(ont_info.serial, "serial0", ONT_SERIAL_SIZE);
> <br>&nbsp; &nbsp; strncpy(ont_info.eq_id, "eq_id0", ONT_EQ_ID_SIZE);
> <br>&nbsp; &nbsp; strncpy(ont_info.fw_version, "fw_version0", ONT_FW_VERSION_SIZE);
> <br>
> <br>&nbsp; &nbsp; for(size_t i = 0; i &lt; 15; i++)
> <br>&nbsp; &nbsp; {
> <br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;ont_info.link_up = i;
> <br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;ont_info.status = ACTIVATION ;
> <br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;sended_cards[i].status = ont_info.status;
> <br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;errors = ont__add_card(&amp;ont_info);
> <br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;if(errors &lt; 0)
> <br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;{
> <br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;exit(<span style="font-weight: 700;">errors</span>);
> <br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;}
> <br>&nbsp; &nbsp; }
> <br>
> <br> &nbsp; &nbsp; errors = ont__get_card(0, 0, received_cards, 10);
> <br> &nbsp; &nbsp; if(errors &lt; 0)
> <br> &nbsp; &nbsp; {
> <br> &nbsp; &nbsp; &nbsp; &nbsp;<span style="font-weight: 700;">exit(</span><span style="font-weight: 700;">errors</span><span style="font-weight: 700;">);</span> 
> <br> &nbsp; &nbsp; }
- - -
### <span style="font-weight: 700;">Функции:</span>
#### &nbsp; **Обновление записи**:&nbsp;&nbsp;<span style="font-weight: 700;">&nbsp;</span>
> <font color="#000000" face="Arial"><span style="font-size: 14.6667px; white-space: pre-wrap;"> </span></font><span style="font-weight: 700;">&nbsp;&nbsp;</span>**&nbsp;** int ont__add_card(struct Ont_info const *const ont_info);&nbsp;

#### &nbsp; &nbsp;&nbsp;<span style="font-weight: 700;">&nbsp;Описание:&nbsp;&nbsp;</span>
&nbsp; &nbsp; &nbsp; &nbsp; Функция добавления нового события в базовую структуру.&nbsp;При успешном добавлении, функция возвращает NO_ERRORS и&nbsp;новое событие сохранено в базовой структуре, в соответствующем&nbsp;для него месте в структуре.&nbsp;При наличии ошибки, функция возвращает код, соответствующий ошибке.&nbsp;<span style="white-space: pre-wrap; color: rgb(0, 0, 0); font-family: Arial; font-size: 14.6667px;">Получения данных по одной ONT c </span><span style="white-space: pre-wrap; color: rgb(0, 0, 0); font-family: Arial; font-size: 14.6667px;">фильтром</span><span style="white-space: pre-wrap; color: rgb(0, 0, 0); font-family: Arial; font-size: 14.6667px;">:</span>
#### &nbsp; &nbsp;&nbsp;<span style="font-weight: 700;">&nbsp;</span>**Получения данных по одной ONT:**
> <span style="font-weight: 700;">&nbsp; &nbsp; &nbsp;&nbsp;</span>int ont__get_card(uint32_t const num_port, uint32_t const num_ont, struct Ont_connection ont_connection[NUM_OF_RECORDS]);

#### &nbsp; &nbsp;&nbsp;<span style="font-weight: 700;">&nbsp;Описание:&nbsp;&nbsp;</span>
&nbsp; &nbsp; &nbsp; &nbsp; Функция получения всех событий по одной ont. При успешном выполнении, функция возвращает код ошибки NO_ERRORS, а указатель ont_connection, имеет копию данных связанных с нужной ont. При наличии ошибки, функция возвращает код, соответствующий ошибке.
#### &nbsp; &nbsp; &nbsp;**Прототип функции:**
> &nbsp; &nbsp; &nbsp;&nbsp;int ont__get_card_filter(&nbsp; uint32_t const num_port,&nbsp; uint32_t const num_ont,&nbsp; void *const key, struct Ont_connection * const ont_connection, enum Card_filter filter);&nbsp;

#### &nbsp; &nbsp; **&nbsp;Описание:&nbsp;&nbsp;**
&nbsp; &nbsp; &nbsp; &nbsp; Функция получения карточек по одной ONT с фильтром. При успешном выполнении, функция возвращает rод ошибки NO_ERRORS, а в аргумент&nbsp;<span style="font-size: 17.5px;">ont_connection</span>&nbsp;типа Ont_connection помещает, копию данных связанных с нужной ont по соответствующему фильтру. При наличии ошибки, функция возвращает код, соответствующий ошибке. Для сортировки необходимо использовать&nbsp;FIND_STATUS - для поиска по состояниям и&nbsp;FIND_TIME для поиска&nbsp; по времени.
- - -
### **&nbsp; &nbsp; &nbsp;Ошибки:**
&nbsp; &nbsp; При работе с библиотекой могут возникнуть следующие ошибки:

**&nbsp; &nbsp;NO_ERRORS**= 0, код выполнился без ошибок.

&nbsp; &nbsp; **NUM_PORT_ERROR**= -1, неверно указан порт ONT.

&nbsp; &nbsp; **NUM_ONT_ERROR**= -2, неверно указан номер ONT

&nbsp; &nbsp; **NULL_PTR_ERROR**= -3, передан указатель на NULL.

&nbsp; &nbsp; **NOT_FOUND_ERROR**= -4, функция поиска не нашла элементы подходящие под условие.

&nbsp; &nbsp; **VALUE_NULL_ERROR**= -5, значение ключа имеет значение NULL.

&nbsp; &nbsp; **LIST_NULL_ERROR**= -6, передан нулевой указатель на список.&nbsp;

&nbsp; &nbsp; **ARRAY_SIZE_ERROR**= -7, передано неверное количество элементов массива.

&nbsp; &nbsp; **WRONG_VALUE_ERROR**= -8, переданы некорректные значения&nbsp;&nbsp;

&nbsp; &nbsp; **MUTEX_ERROR**= -9, ошибка захвата mutex.
- - -
### **&nbsp; &nbsp;Структуры:**
#### <span style="font-weight: 700;">&nbsp; &nbsp;Структура ONT событий.</span>
**typedef struct Ont_connection&nbsp;&nbsp;** **{**

**&nbsp; &nbsp; char serial[ONT_SERIAL_SIZE]; -&nbsp;**<span style="background-color: transparent; color: rgb(0, 0, 0); font-family: Arial; font-size: 11pt; white-space: pre-wrap;">Серийный номер ONT в текстовом формате</span>

**&nbsp; &nbsp; char eq_id[ONT_EQ_ID_SIZE]; -&nbsp;**<span style="background-color: transparent; color: rgb(0, 0, 0); font-family: Arial; font-size: 11pt; white-space: pre-wrap;">Наименование ONT в текстовом формате</span>

**&nbsp; &nbsp; char fw_version[ONT_FW_VERSION_SIZE]; -&nbsp;**<span style="background-color: transparent; color: rgb(0, 0, 0); font-family: Arial; font-size: 11pt; white-space: pre-wrap;">Версия прошивки ONT в текстовом формате</span>

**&nbsp; &nbsp; time_t link_up; -&nbsp;**<span style="background-color: transparent; color: rgb(0, 0, 0); font-family: Arial; font-size: 11pt; white-space: pre-wrap;">время активации. День, год, час, минута, секунда</span>

**&nbsp; &nbsp; time_t link_down; -&nbsp;**<span style="background-color: transparent; color: rgb(0, 0, 0); font-family: Arial; font-size: 11pt; white-space: pre-wrap;">время деактивации. День, год, час, минута, секунда</span>

**&nbsp; &nbsp; enum Ont_status status; -&nbsp;**<span style="background-color: transparent; color: rgb(0, 0, 0); font-family: Arial; font-size: 11pt; white-space: pre-wrap;">Статус ONT. Возможные статусы: Activation, Working, CfgFail, Block.</span>

**} Ont_connection;**

****
#### **&nbsp; &nbsp;Структура с данными об ONT, которая поступает извне**
**typedef struct Ont_info&nbsp;** **{**

**&nbsp; &nbsp; uint32_t num_port; -**Номер порта.

**&nbsp; &nbsp; uint32_t num_ont; -**Номер ONT.

<span style="font-weight: 700;">&nbsp; &nbsp; char serial[ONT_SERIAL_SIZE]; -&nbsp;</span><span style="white-space: pre-wrap; background-color: transparent; color: rgb(0, 0, 0); font-family: Arial; font-size: 11pt;">Серийный номер ONT в текстовом формате</span>

<span style="font-weight: 700;">&nbsp; &nbsp; char eq_id[ONT_EQ_ID_SIZE]; -&nbsp;</span><span style="white-space: pre-wrap; background-color: transparent; color: rgb(0, 0, 0); font-family: Arial; font-size: 11pt;">Наименование ONT в текстовом формате</span>

<span style="font-weight: 700;">&nbsp; &nbsp; char fw_version[ONT_FW_VERSION_SIZE]; -&nbsp;</span><span style="white-space: pre-wrap; background-color: transparent; color: rgb(0, 0, 0); font-family: Arial; font-size: 11pt;">Версия прошивки ONT в текстовом формате</span>

<span style="font-weight: 700;">&nbsp; &nbsp; time_t link_up; -&nbsp;</span><span style="white-space: pre-wrap; background-color: transparent; color: rgb(0, 0, 0); font-family: Arial; font-size: 11pt;">время активации. День, год, час, минута, секунда</span>

<span style="font-weight: 700;">&nbsp; &nbsp; time_t link_down; -&nbsp;</span><span style="white-space: pre-wrap; background-color: transparent; color: rgb(0, 0, 0); font-family: Arial; font-size: 11pt;">время деактивации. День, год, час, минута, секунда</span>

<span style="font-weight: 700;">&nbsp; &nbsp; enum Ont_status status; -&nbsp;</span><span style="white-space: pre-wrap; background-color: transparent; color: rgb(0, 0, 0); font-family: Arial; font-size: 11pt;">Статус ONT. Возможные статусы: Activation, Working, CfgFail, Block.</span>

**} Ont_info;**
- - -
### **Константы:**
&nbsp; &nbsp; **ONT_SERIAL_SIZE**= 16, размер в байтах&nbsp;<span style="font-weight: 700;">с</span><span style="background-color: transparent; white-space: pre-wrap; color: rgb(0, 0, 0); font-family: Arial; font-size: 11pt;">ерийного номера ONT.</span>

&nbsp; &nbsp; **ONT_EQ_ID_SIZE**= 18, размер в байтах н<span style="color: rgb(0, 0, 0); font-family: Arial; font-size: 14.6667px; white-space: pre-wrap;">аименования ONT.</span>

&nbsp; &nbsp; **ONT_FW_VERSION_SIZE**= 32, размер в байтах в<span style="color: rgb(0, 0, 0); font-family: Arial; font-size: 14.6667px; white-space: pre-wrap;">ерсии прошивки ONT.</span>

&nbsp; &nbsp; **NUM_OF_PORTS**= 16, количество портов.&nbsp;

&nbsp; &nbsp; **NUM_OF_ONT_ON_PORT**= 128, количество ONT на одном порту.&nbsp;

&nbsp; &nbsp; **NUM_OF_RECORDS**= 10, количество событий в карточке.&nbsp;

&nbsp; &nbsp; **NUM_OF_ONT_CONNECTIONS**= 2048, общее количество ONT

<br>

<br>
