FROM	alpine:3.13.4

RUN	apk -U upgrade && apk add \
	php7 php7-fpm php7-phar php7-json \
	php7-msqli php7-curl php7-iconv \
	php7-pecl-mailparse \
	curl \
	mariadb-client \
	bash \

RUN	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && cp wp-cli.phar /usr/bin/wp

WORKDIR	/var/www/wordpress

RUN	wp core download

RUN	adduser -S nginx && addgroup -S nginx

RUN	mkdir /var/log/php-fpm
COPY	./confing/php-fpm.conf /etc/php7/php-fpm.conf
COPY	./config/www.conf /etc/php7/php-fpm.d/www.conf

COPY	./config /config
COPY	./confing/wp-config.php ./
COPY	./scripts/entrypoint.sh /entrypoint.sh

ENTRYPOINT ["bash", "/entrypoint.sh"]
