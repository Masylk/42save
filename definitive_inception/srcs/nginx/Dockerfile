FROM debian:buster

RUN	apt-get update && apt-get -y upgrade && apt-get -y install \
	nginx openssl

RUN mkdir /etc/nginx/ssl
RUN mkdir /var/www/wordpress


COPY nginx.conf /etc/nginx/sites-enabled/default

RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/nginx/ssl/mtogbe.pem \
	-keyout /etc/nginx/ssl/mtogbe.key \
	-subj "/C=FR/ST=Paris/L=Paris/O=42/OU=mtogbe/CN=mtogbe/"

ENTRYPOINT ["nginx", "-g", "daemon off;"]
