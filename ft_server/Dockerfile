#image de base
FROM debian:buster

#signature
MAINTAINER cramdani <cramdani@student.42.fr>

#utilities
RUN apt-get update\
	&& apt-get upgrade -y\
	&& apt-get install -y wget nginx openssl\
	&& apt-get install -y php7.3 php-mysql php7.3-fpm php7.3-mysql php-common php7.3-cli php7.3-common php7.3-json php7.3-opcache php7.3-readline php-mbstring php-zip php-gd \
	&& apt-get install -y mariadb-server mariadb-client 


#download wordpress et phpmyadmin
RUN wget -cO - https://wordpress.org/latest.tar.gz > wordpress.tar.gz\ 
 	&& wget -cO - https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz > phpmyadmin.tar.gz \
	&& tar -xzvf wordpress.tar.gz \ 
	&& mkdir phpmyadmin && tar xf phpmyadmin.tar.gz -C phpmyadmin --strip-components 1

COPY srcs/script.sh ./
COPY srcs/info.php ./
COPY srcs/config.inc.php phpmyadmin/
COPY srcs/wp-config.php wordpress/
COPY srcs/default /etc/nginx/sites-available/

RUN mkdir /var/www/localhost /etc/nginx/ssl\
	&& mv wordpress /var/www/localhost/wordpress\
	&& mv phpmyadmin /var/www/localhost/phpmyadmin\
	&& mv info.php /var/www/localhost/

#access and rights
RUN chown -R www-data /var/www/* \
	&& chmod -R 765 /var/www/* 

CMD bash script.sh

EXPOSE 80 
EXPOSE 443
