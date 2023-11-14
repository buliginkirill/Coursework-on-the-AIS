FROM mariadb

ENV MYSQL_DATABASE db
ENV MYSQL_USER user
ENV MYSQL_PASSWORD password
ENV MYSQL_ROOT_PASSWORD root

COPY commands.sql /docker-entrypoint-initdb.d/commands.sql
COPY mysql.conf.d/ /etc/mysql/mysql.conf.d/

EXPOSE 3306
