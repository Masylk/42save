FROM	debian:buster

RUN	apt-get update && apt-get -y install apt-utils \
	mariadb-client mariadb-server \
	&& chown -R mysql:mysql /var/lib/mysql

COPY	tools/start.sh	/tmp/start.sh
COPY	tools/dump.sql ./
EXPOSE	3306

ENTRYPOINT ["sh", "/tmp/start.sh"]
