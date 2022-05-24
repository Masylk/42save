#!/bin/sh

echo "\n[i] Set Configuration for Mysql\n"
cat <<-EOF > /etc/mysql/my.cnf
	[mysqld]
	user = root
	port = 3306
	datadir = /var/lib/mysql
	bind-address = 0.0.0.0
	skip-bind-address
	skip-networking = false
	pid-file = /run/mysqld/mysqld.pid
	socket = /run/mysqld/mysqld.sock
EOF

if [ ! -d $DATADIR/mysql ]; then #check if database is not already created
	echo "\n[i]Initialization of database\n"
	mysql_install_db --datadir=$DATADIR   > /dev/null

	mysqld_safe &

	sleep 2

	mysql -u root --skip-password <<- EOF 
		USE mysql;
		FLUSH PRIVILEGES;
		DELETE FROM	mysql.user WHERE User='';
		DROP DATABASE test;
		DELETE FROM mysql.db WHERE Db='test';
		DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', 'mtogbe.42.fr', '::1');
		
		ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';

		CREATE DATABASE  IF NOT EXISTS $MYSQL_DATABASE CHARACTER SET utf8 COLLATE utf8_general_ci;
		CREATE USER  IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED by '$MYSQL_PASSWORD';
		FLUSH PRIVILEGES;
		GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';
		FLUSH PRIVILEGES;
	EOF
	sleep 2
	mysql -u root -p"$MYSQL_ROOT_PASSWORD" $MYSQL_DATABASE < ./dump.sql
	sleep 2
	mysqladmin -uroot -p"$MYSQL_ROOT_PASSWORD" shutdown

	echo "[i] database restarting\n"
	sleep 2
else
	echo "\n[i] Skipping initialization cause Mysql database is already created"
fi

cat <<EOF 
#######################	 User Identifiant ##########################
#		user sql	:
#					 login		: $WP_ADMIN_USER
#					 password 	: $WP_ADMIN_PWD 
#
#
#		user wordpress	:
#					 login		: maxime
#					 password 	: maxime
#
#					 login		: axel
#					 password 	: axel
#
#####################################################################

EOF
sleep 5

echo "[i] Starting mariadb server\n"
exec mysqld -u root
exec "$@"
