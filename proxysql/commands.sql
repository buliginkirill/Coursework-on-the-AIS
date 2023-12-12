drop database if exists db; -- sharding:0

drop database if exists db; -- sharding:1

drop database if exists db; -- sharding:2

create database if not exists db; -- sharding:0

create database if not exists db; -- sharding:1

create database if not exists db; -- sharding:2

CREATE TABLE IF NOT EXISTS db.`User_ID` (
	`value` INT
) -- sharding:0

CREATE TABLE IF NOT EXISTS db.`User`(
    `id` INT NOT NULL,
    `first_name` VARCHAR(256) NOT NULL,
    `last_name` VARCHAR(256) NOT NULL,
    `login` VARCHAR(256) NOT NULL,
    `password` VARCHAR(256) NOT NULL,
    `email` VARCHAR(256) NULL,
    `title` VARCHAR(1024) NULL,
    PRIMARY KEY (`id`),KEY `fn` (`first_name`),KEY `ln` (`last_name`)
    ); -- sharding:0

CREATE TABLE IF NOT EXISTS db.`User`(
    `id` INT NOT NULL,
    `first_name` VARCHAR(256) NOT NULL,
    `last_name` VARCHAR(256) NOT NULL,
    `login` VARCHAR(256) NOT NULL,
    `password` VARCHAR(256) NOT NULL,
    `email` VARCHAR(256) NULL,
    `title` VARCHAR(1024) NULL,
    PRIMARY KEY (`id`),KEY `fn` (`first_name`),KEY `ln` (`last_name`)
    );-- sharding:1

CREATE TABLE IF NOT EXISTS db.`User`(
    `id` INT NOT NULL,
    `first_name` VARCHAR(256) NOT NULL,
    `last_name` VARCHAR(256) NOT NULL,
    `login` VARCHAR(256) NOT NULL,
    `password` VARCHAR(256) NOT NULL,
    `email` VARCHAR(256) NULL,
    `title` VARCHAR(1024) NULL,
    PRIMARY KEY (`id`),KEY `fn` (`first_name`),KEY `ln` (`last_name`)
    ); -- sharding:2

create index if not exists email_hash USING HASH  on db.User(email); -- sharding:0

create index if not exists email_hash USING HASH  on db.User(email); -- sharding:1

create index if not exists email_hash USING HASH  on db.User(email); -- sharding:2

create index if not exists fn_ln using btree on db.User(first_name,last_name); -- sharding:0

create index if not exists fn_ln using btree on db.User(first_name,last_name); -- sharding:1

create index if not exists fn_ln using btree on db.User(first_name,last_name); -- sharding:2

create index if not exists ln_fn using btree on db.User(last_name,first_name); -- sharding:0

create index if not exists ln_fn using btree on db.User(last_name,first_name); -- sharding:1

create index if not exists ln_fn using btree on db.User(last_name,first_name); -- sharding:2

CREATE TABLE IF NOT EXISTS db.`Message_wall`
    (
	`id` INT NOT NULL AUTO_INCREMENT,
	`user_id` INT NOT NULL,
	`content` TEXT CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
	`created_at` DATETIME NOT NULL,
	PRIMARY KEY (`id`),
	KEY `user_id` (`user_id`)
    );-- sharding:0

CREATE TABLE IF NOT EXISTS db.`Chat` (
  `id` INT NOT NULL AUTO_INCREMENT, 
  `user_id` INT NOT NULL,
  `message` TEXT CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `created_at` DATETIME NOT NULL,
  PRIMARY KEY (`id`),
  KEY `user_id` (`user_id`) 
);-- sharding:0

INSERT INTO db.User (`id`, `first_name`, `last_name`, `email`, `title`, `login`, `password`) VALUES (1, 'Иван', 'Иванов', 'ivanov@mail.ru', 'Mr.', 'ivanov', 'ivanov'); -- sharding:1

INSERT INTO db.User (id, first_name, last_name, email, title, `login`, `password`) VALUES (2, 'Петр', 'Петров', 'petrov@mail.ru', 'Mr.', 'petrov', 'petrov');  -- sharding:2

INSERT INTO db.User (id, first_name, last_name, email, title, `login`, `password`) VALUES (3, 'Сидор', 'Сидоров', 'sidorov@mail.ru', 'Mr.', 'sidorov', 'sidorov'); -- sharding:0

INSERT INTO db.User (id, first_name, last_name, email, title, `login`, `password`) VALUES (4, 'Николай', 'Николаев', 'nikolaev@mail.ru', 'Mr.','nikolayev','nikolayev'); -- sharding:1

INSERT INTO db.User (id, first_name, last_name, email, title, `login`, `password`) VALUES (5, 'Анна', 'Андреева', 'andreyeva@mail.ru', 'Mrs.','andreeva','andreeva'); -- sharding:2

INSERT INTO db.User (id, first_name, last_name, email, title, `login`, `password`) VALUES (6, 'Мария', 'Попова', 'popova@mail.ru', 'Mrs.','popova','popova'); -- sharding:0

INSERT INTO db.User (id, first_name, last_name, email, title, `login`, `password`) VALUES (7, 'Ольга', 'Смирнова', 'smirnova@mail.ru', 'Mrs.','smirnova','smirnova'); -- sharding:1

INSERT INTO db.User (id, first_name, last_name, email, title, `login`, `password`) VALUES (8, 'Александр', 'Васильев', 'vasilyev@mail.ru', 'Mr.','vasilyev','vasilyev'); -- sharding:2

INSERT INTO db.User (id, first_name, last_name, email, title, `login`, `password`) VALUES (9, 'Дмитрий', 'Михайлов', 'mihailov@mail.ru', 'Mr.','mikhailov','mikhailov'); -- sharding:0

INSERT INTO db.User (id, first_name, last_name, email, title, `login`, `password`) VALUES (10, 'Елена', 'Соколова', 'sokolova@mail.ru', 'Mrs.','sokolova','sokolova'); -- sharding:1

insert into db.User_ID (value) values (11)

INSERT INTO db.Chat (user_id, message, created_at) 
VALUES
(1, 'Привет!', '2023-02-01 15:00:00'),
(2, 'Здравствуйте!', '2023-02-01 15:01:00'),
(5, 'Добрый день!', '2023-02-01 15:02:00'), 
(7, 'Как дела?', '2023-02-01 15:03:00'),
(9, 'Что нового?', '2023-02-01 15:04:00');-- sharding:0

INSERT INTO db.Message_wall (user_id, content, created_at)
VALUES  
(3, 'Первое сообщение', '2023-02-01 14:00:00'),
(6, 'Второе сообщение', '2023-02-01 14:05:00'),  
(4, 'Третье сообщение', '2023-02-01 14:10:00'),
(8, 'Четвертое сообщение', '2023-02-01 14:15:00'), 
(10, 'Пятое сообщение', '2023-02-01 14:20:00');-- sharding:0
