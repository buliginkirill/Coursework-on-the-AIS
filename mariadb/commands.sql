GRANT ALL PRIVILEGES ON *.* TO 'user'@'%' IDENTIFIED BY 'password';

drop database if exists db;
create database if not exists db;
use db;

CREATE TABLE IF NOT EXISTS `Author`
    (
	`id` INT NOT NULL AUTO_INCREMENT,
	`first_name` VARCHAR(256) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
	`last_name` VARCHAR(256) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
	`email` VARCHAR(256) CHARACTER SET utf8 COLLATE utf8_unicode_ci NULL,
	`title` VARCHAR(1024) CHARACTER SET utf8 COLLATE utf8_unicode_ci NULL,
	PRIMARY KEY (`id`),
	KEY `fn` (`first_name`),
	KEY `ln` (`last_name`)
    );


create index if not exists email_hash USING HASH  on Author(email);
create index if not exists fn_ln using btree on Author(first_name,last_name);
create index if not exists ln_fn using btree on Author(last_name,first_name);

----------------------------------

CREATE TABLE IF NOT EXISTS `Message_wall`
    (
	`id` INT NOT NULL AUTO_INCREMENT,
	`user_id` INT NOT NULL,
	`content` TEXT CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
	`created_at` DATETIME NOT NULL,
	PRIMARY KEY (`id`),
	KEY `user_id` (`user_id`),
  	FOREIGN KEY (`user_id`) REFERENCES `Author`(`id`) ON DELETE CASCADE
    );
   
CREATE TABLE IF NOT EXISTS `Chat` (
  `id` INT NOT NULL AUTO_INCREMENT, 
  `user_id` INT NOT NULL,
  `message` TEXT CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `created_at` DATETIME NOT NULL,
  PRIMARY KEY (`id`),
  KEY `user_id` (`user_id`),  
  FOREIGN KEY (`user_id`) REFERENCES `Author`(`id`) ON DELETE CASCADE
    );
   
   --  10 пользователей
INSERT INTO Author (first_name, last_name, email, title)
VALUES 
('Иван', 'Иванов', 'ivanov@mail.ru', 'Mr.'),
('Петр', 'Петров', 'petrov@mail.ru', 'Mr.'), 
('Сидор', 'Сидоров', 'sidorov@mail.ru', 'Mr.'),
('Николай', 'Николаев', 'nikolaev@mail.ru', 'Mr.'),
('Анна', 'Андреева', 'andreyeva@mail.ru', 'Mrs.'),
('Мария', 'Попова', 'popova@mail.ru', 'Mrs.'),
('Ольга', 'Смирнова', 'smirnova@mail.ru', 'Mrs.'), 
('Александр', 'Васильев', 'vasilyev@mail.ru', 'Mr.'),
('Дмитрий', 'Михайлов', 'mihailov@mail.ru', 'Mr.'),
('Елена', 'Соколова', 'sokolova@mail.ru', 'Mrs.');

--  5 чатов
INSERT INTO Chat (user_id, message, created_at) 
VALUES
(1, 'Привет!', '2023-02-01 15:00:00'),
(2, 'Здравствуйте!', '2023-02-01 15:01:00'),
(5, 'Добрый день!', '2023-02-01 15:02:00'), 
(7, 'Как дела?', '2023-02-01 15:03:00'),
(9, 'Что нового?', '2023-02-01 15:04:00');

--  5 сообщений на стены
INSERT INTO Message_wall (user_id, content, created_at)
VALUES  
(3, 'Первое сообщение', '2023-02-01 14:00:00'),
(6, 'Второе сообщение', '2023-02-01 14:05:00'),  
(4, 'Третье сообщение', '2023-02-01 14:10:00'),
(8, 'Четвертое сообщение', '2023-02-01 14:15:00'), 
(10, 'Пятое сообщение', '2023-02-01 14:20:00');
