FROM alpine:3.13

RUN apk update && apk upgrade && apk add --no-cache nginx openssl

RUN mkdir /etc/nginx/ssl

RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/nginx/ssl/mtogbe.pem \
	-keyout /etc/nginx/ssl/mtogbe.key \
	-subj "/C=FR/ST=Paris/L=Paris/O=42/OU=mtogbe/CN=mtogbe/"

#RUN	adduser -S nginx && addgroup -S www-data && \
#RUN	chown -R nginx:www-data /var/www/html

RUN mkdir -p /run/nginx/

COPY ./nginx.conf /etc/nginx/conf.d/default.conf

#RUN ls /var/www/html

ENTRYPOINT ["nginx", "-g", "daemon off;"]
