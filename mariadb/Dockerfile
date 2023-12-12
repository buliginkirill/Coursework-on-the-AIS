FROM mariadb:10.10.4

ENV MYSQL_DATABASE db
ENV MYSQL_USER user
ENV MYSQL_PASSWORD password
ENV MYSQL_ROOT_PASSWORD root

COPY commands_1.sql /docker-entrypoint-initdb.d/commands_1.sql
COPY mysql.conf.d/ /etc/mysql/mysql.conf.d/
EXPOSE 3306
