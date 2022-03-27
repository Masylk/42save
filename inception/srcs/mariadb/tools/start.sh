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

	echo "\n[i] start mysqld_safe it is a wrapper that starts mysqld with some extra safety features. 
	For example, if mysqld_safe notices that mysqld has crashed, then mysqld_safe will automatically restart mysqld.\n"
	mysqld_safe &

	sleep 2

	echo "\n[i] Delete useless stuff\n[i] Set password for root\n[i] Create database\n[i] Create user\n"
	#connecte as root without password then set password at root 
	mysql -u  root  --skip-password <<- EOF 
		USE mysql;
		FLUSH PRIVILEGES;
		DELETE FROM	mysql.user WHERE User='';
		DROP DATABASE test;
		DELETE FROM mysql.db WHERE Db='test';
		DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
		
		ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';

		CREATE DATABASE  IF NOT EXISTS $MYSQL_DATABASE CHARACTER SET utf8 COLLATE utf8_general_ci;
		CREATE USER  IF NOT EXISTS '$WORDPRESS_DB_USER'@'%' IDENTIFIED by '$WORDPRESS_DB_PASSWORD';
		GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$WORDPRESS_DB_USER'@'%';
		FLUSH PRIVILEGES;
	EOF
	sleep 2
#	echo "[i] Insert back up databases '$MYSQL_DATABASE'"
#	mysql -u root -p"$MYSQL_ROOT_PASSWORD" wordpress < ./dump.sql
	sleep 2
	echo "[i] Shut down the server with mysqladmin"
	mysqladmin -uroot -p"$MYSQL_ROOT_PASSWORD" shutdown

	echo "[i] database restarting\n"
	sleep 2
else
	echo "\n[i] Skipping initialization cause Mysql database is already created"
fi

cat <<EOF 
#######################	 User Identifiant ##########################
#		user sql	:
#					 login		: $WORDPRESS_DB_USER
#					 password 	: $WORDPRESS_DB_PASSWORD 
#
#
#####################################################################
EOF
sleep 5

echo "[i] Starting mariadb server\n"
exec mysqld -u root
