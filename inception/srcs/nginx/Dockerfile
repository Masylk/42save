FROM debian:buster

RUN	apt-get update && apt-get -y upgrade && apt-get -y install \
	nginx openssl

RUN mkdir /etc/nginx/ssl
RUN mkdir /var/www/wordpress

COPY ./nginx.conf /etc/nginx/sites-available/default

RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/nginx/ssl/mtogbe.pem \
	-keyout /etc/nginx/ssl/mtogbe.key \
	-subj "/C=FR/ST=Paris/L=Paris/O=42/OU=mtogbe/CN=mtogbe/"

RUN	chown -R www-data:www-data /var/www/* && \
	chmod 755 /var/www/*
#RUN	adduser -S www-data && \
#	chown -R www-data:www-data /var/www/html

#RUN	adduser -S nginx && addgroup -S www-data && \
#RUN	chown -R nginx:www-data /var/www/html

#RUN mkdir -p /run/nginx/


#RUN ls /var/www/html

EXPOSE 80
EXPOSE 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]
