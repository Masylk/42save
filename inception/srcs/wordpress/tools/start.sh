#!/bin/sh

# wait for mysql
while ! mariadb -h$WORDPRESS_DB_HOST -u$WORDPRESS_DB_USER -p$WORDPRESS_DB_PASSWORD $WORDPRESS_DB_NAME &>/dev/null; do
   sleep 3
done

#if [ ! -f "/var/www/html/index.html" ]; then

    # static website
#    mv /tmp/index.html /var/www/html/index.html

#fi

echo "$MYSQL_HOST : $MYSQL_PORT"
echo "Wordpress started on :9000"
/usr/sbin/php-fpm7 -F -R
