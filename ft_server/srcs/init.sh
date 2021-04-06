# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtogbe <mtogbe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/10 12:25:15 by mtogbe            #+#    #+#              #
#    Updated: 2021/02/10 12:48:51 by mtogbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

chown -R www-data:www-data *
chmod -R 755 /var/www/*

#phpmyadmin
cd /var/www/html/
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz
mv phpMyAdmin-5.0.1-english phpmyadmin

#wordpress
wget https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz && rm -rf latest.tar.gz

#ssl self signed key
openssl req -x509 -nodes -days 365 -subj "/C=FR/ST=France/L=Paris/O=in/OU=42Paris/CN=mtogbe" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt;

#index listing
if "$AUTOINDEX" == "ON"
then
	cp /tmp/nginx.conf /etc/nginx/sites-avalaible
else	
	cp /tmp/nginxoff.conf /etc/nginx/sites-avalaible
fi
#run nginx server
service nginx start
service mysql start
service php7.3-fpm start

# Configure a wordpress database
echo "CREATE DATABASE wordpress;"| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;"| mysql -u root --skip-password
echo "FLUSH PRIVILEGES;"| mysql -u root --skip-password
echo "update mysql.user set plugin='' where user='root';"| mysql -u root --skip-password

bash
