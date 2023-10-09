@startuml

!include https://raw.githubusercontent.com/plantuml-stdlib/C4-PlantUML/master/C4_Container.puml

AddElementTag("microService", $shape=EightSidedShape(), $bgColor="CornflowerBlue", $fontColor="white")
AddElementTag("storage", $shape=RoundedBoxShape(), $bgColor="lightSkyBlue", $fontColor="white")

Person(user, "Пользователь", $tags="user")
Person(moderator, "Модератор", $tags="user")
Person(admin, "Администратор", $tags="user")

System_Ext(web, "Веб-клиент", "JavaScript")  

System_Boundary(social_network, "Социальная сеть") {

Container(auth, "Сервис управления пользователями", "", "С++", $tags="microService")
Container(wall, "Сервис стены", "Управление стеной пользователя", "C++", $tags="microService")
Container(chat, "Сервис чата", "Управление чатом пользователя", "C++", $tags="microService")

ContainerDb(db, "База данных MariaDB", $tags="storage")


}

Rel(admin, web, "Просмотр, добавление и редактирование информации о пользователях")
Rel(moderator, web, "Модерация пользователей")
Rel(user, web, "Регистрация, просмотр и редактирование стены, общение с другими пользователями")

Rel(web, auth, "Работа с пользователями")  
Rel(web, wall, "Работа со стеной пользователя")
Rel(web, chat, "Работа с чатом пользователя")

Rel(auth, db, "INSERT/SELECT/UPDATE", "SQL") 
Rel(wall, db, "INSERT/SELECT/UPDATE", "SQL")
Rel(chat, db, "INSERT/SELECT/UPDATE", "SQL")


@enduml


## Список компонентов

### Сервис управления пользователями

**API**:

- Создание нового пользователя
  - Входные параметры: логин, пароль, имя, фамилия, email 
  - Выходные параметры: идентификатор пользователя
- Поиск пользователя по логину
  - Входные параметры: логин
  - Выходные параметры: идентификатор, имя, фамилия, email
- Поиск пользователя по имени/фамилии
  - Входные параметры: имя, фамилия 
  - Выходные параметры: идентификатор, логин, имя, фамилия, email

### Сервис стены

**API**:

- Добавление записи на стену 
  - Входные параметры: идентификатор пользователя, текст записи
  - Выходные параметры: идентификатор записи 
- Получение записей со стены пользователя
  - Входные параметры: идентификатор пользователя
  - Выходные параметры: массив записей со стены

### Сервис чата

**API**:

- Отправка сообщения 
  - Входные параметры: идентификаторы отправителя и получателя, текст сообщения
  - Выходные параметры: идентификатор сообщения
- Получение сообщений для пользователя
  - Входные параметры: идентификатор пользователя
  - Выходные параметры: массив сообщений

@startuml

class User {
  id
  login
  first_name 
  last_name
  email
}

class WallPost {
  id 
  user_id
  text
  date  
}

class ChatMessage {
  id
  from_user_id
  to_user_id 
  text
  date
}

User "1" -- "N" WallPost
User "1" -- "N" ChatMessage

@enduml