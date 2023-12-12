FROM proxysql/proxysql:2.3.2
RUN apt-get update -y
RUN apt-get install -y default-mysql-client
RUN apt-get install --fix-missing
ADD proxysql.cnf /etc/
