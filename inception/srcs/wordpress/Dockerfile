FROM	alpine:3.13.4

RUN	apk -U upgrade && apk add\
	php7 php7-fpm php7-phar php7-json php-intl\
	php7-mysqli php7-curl php7-iconv php-gd\
	php7-pecl-mailparse php-cli php-curl\
	php7-pdo php7-pdo_mysql\
	php7-pdo_pgsql php7-pdo_sqlite\
	wget tar\
	mariadb-client\
	bash


WORKDIR /var/www

RUN	wget http://fr.wordpress.org/latest-fr_FR.tar.gz && \
	tar -xvzf latest-fr_FR.tar.gz

RUN	adduser -S nginx && addgroup -S www-data && \
	chown -R nginx:www-data /var/www/wordpress

WORKDIR /var/www/wordpress

#HEALTHCHECK --interval=20s --timeout=10s \
#	CMD mariadbprout -h$MYSQL_HOST -P$MYSQL_PORT -u$WORDPRESS_DB_USER -p$MYSQL_ROOT_PASSWORD \
#	|| exit 1

RUN	rm ./wp-config-sample.php
#RUN	mkdir /var/log/php-fpm
COPY	./config/php-fpm.conf /etc/php7/php-fpm.conf
COPY	./config/www.conf /etc/php7/php-fpm.d/www.conf

COPY	./config /config
COPY	./config/wp-config.php ./
COPY	./tools/start.sh /start.sh

#HEALTHCHECK

CMD	/bin/bash /start.sh
#ENTRYPOINT ["bash", "/start.sh"]
