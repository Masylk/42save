#!/bin/sh

echo "Wordpress started on :9000\n"
/usr/sbin/php-fpm7 -F -R
