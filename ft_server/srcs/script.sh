#!/bin/sh

openssl req -x509 -newkey rsa:4096 -keyout /etc/nginx/ssl/localhost.key -out /etc/nginx/ssl/localhost.pem -days 365 -nodes -subj "/C=FR/ST=Paris/L=Paris/O=42Paris/OU=cramdani/CN=localhost"


#database 

service mysql start
echo "CREATE DATABASE wordpressDB DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;" | mysql -u root
echo "GRANT ALL ON wordpressDB.* TO 'admin'@'localhost' IDENTIFIED BY 'admin';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root 

#set autoindex 

if [ ! -z $index ]  && [ $index = "off" ]; then
	 sed -i 's/autoindex on;/autoindex off;/' /etc/nginx/sites-available/default
fi

# launch 

service nginx start
service mysql restart
service php7.3-fpm start
sleep infinity
