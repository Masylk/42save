FROM debian:buster
RUN apt-get update && apt-get upgrade -y
RUN apt-get -y install wget
RUN apt install -y wget nginx
RUN mkdir -p /var/www/localhost
RUN apt install -y mariadb-server
RUN apt-get -y install php7.3-fpm php7.3-common php7.3-mysql php7.3-gmp php7.3-curl php7.3-intl php7.3-mbstring php7.3-xmlrpc php7.3-gd php7.3-xml php7.3-cli php7.3-zip php7.3-soap php7.3-imap
RUN apt install -y php-json
RUN apt-get install -y libnss3-tools
RUN apt-get -y install php-mysql

#right for nginx

RUN chown -R www-data:www-data /var/www/*
RUN chmod -R 775 /var/www/*

#NGINX setup

ADD ./srcs/nginx-host-conf /etc/nginx/sites-available/localhost
RUN rm /etc/nginx/sites-enabled/default
RUN ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled
RUN touch /var/www/localhost/test.php && echo "<?php phpinfo(); ?>" >> /var/www/localhost/test.php
#SSL setup

RUN mkdir ~/mkcert
RUN cd ~/mkcert
RUN wget https://github.com/FiloSottile/mkcert/releases/download/v1.1.2/mkcert-v1.1.2-linux-amd64
RUN mv mkcert-v1.1.2-linux-amd64 mkcert
RUN chmod +x mkcert
RUN ./mkcert -install
RUN ./mkcert localhost
RUN cd
RUN mv localhost.pem  /root/mkcert/
RUN mv localhost-key.pem /root/mkcert/
#MYSQL set up

RUN service mysql start && echo "CREATE DATABASE wordpress;" |mysql -u root && echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost';" | mysql -u root && echo "FLUSH PRIVILEGES;" | mysql -u root && echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root
#wordpress

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz
RUN rm -rf latest.tar.gz
RUN mv wordpress/ /var/www/localhost/
ADD ./srcs/wp-config.php /var/www/localhost/wordpress

#php myadmin

RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN mv phpMyAdmin-4.9.0.1-all-languages.tar.gz /var/www/localhost/
WORKDIR /var/www/localhost/
RUN tar -xf phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN mv phpMyAdmin-4.9.0.1-all-languages phpmyadmin && rm -rf phpMyAdmin-4.9.0.1-all-languages.tar.gz
COPY ./srcs/config.inc.php /var/www/localhost/phpmyadmin/

COPY srcs/init.sh ./

CMD bash init.sh && rm init.sh && service mysql restart && service php7.3-fpm start && service nginx restart && tail -f /dev/null
