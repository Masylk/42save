FROM debian:buster

RUN apt-get update -yq && apt-get install -y wget
RUN apt-get install nginx
RUN apt-get install mariadb-server
RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring

COPY ./srcs/wp-config.php /var/www/html
COPY ./srcs/config.inc.php phpmyadmin
COPY ./srcs/init.sh ./
COPY ./srcs/nginx.conf ./tmp/nginx.conf

CMD bash init.sh
