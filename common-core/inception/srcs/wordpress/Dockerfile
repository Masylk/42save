FROM	debian:buster

RUN	apt-get -y update && apt-get -y upgrade\
	&& apt-get update && apt-get install -y \
	wget \
	php7.3-fpm php7.3-mysql php7.3-json php7.3-xmlrpc \
	php7.3-curl php7.3-gd php7.3-xml php7.3-mbstring expect


#COPY	./config/wp-config.php ./

WORKDIR /var/www/

#RUN	wget http://fr.wordpress.org/latest-fr_FR.tar.gz && \
#	tar -xvzf latest-fr_FR.tar.gz

COPY ./latest.tar.gz /var/www/
COPY	./config/php-fpm.conf /etc/php/7.3/fpm/php-fpm.conf
COPY	./config/www.conf /etc/php/7.3/fpm/pool.d/www.conf

#COPY	./tools/start.sh /tmp/start.sh

#RUN	cp /wp-config.php /var/www/wordpress

#RUN	chown -R www-data:www-data /var/www/* && \
#	chmod -R 755 /var/www/*

#ENTRYPOINT tar -xzf latest.tar.gz && cp /wp-config.php  /var/www/wordpress && chown -R www-data:www-data /var/www/* && chmod -R 755 /var/www/* &&  exec php-fpm7.3 -F
ENTRYPOINT tar -xzf latest.tar.gz && chown -R www-data:www-data /var/www/* && chmod -R 755 /var/www/* &&  exec php-fpm7.3 -F
