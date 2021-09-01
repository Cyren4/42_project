
# Dockerfile

### Utilities

- wget, php packages
- __Web Server__ : nginx
- __ssl certificate__ : openssl
- __Data_Base__ : mariadb



### ssl certificate 

```bash 
openssl req -x509 -newkey rsa:4096 -keyout key.pem -out cert.pem -days 365 -nodes
```
- req : certificate generating utility
- -x509 : self signed
- -newkey rsa:nbits : create new certificate and new private key + generate an RSA key nbits in size
- -keyout filename : file to write private key ti
- -out filename :  write standard output by default
- -days nb : number of days to certify the certificate for
- -nodes : private key not encrypted


### nginx

Mise en place du serveur : 
- fichier de configuration 

### DataBase

service mysql
1. create database
2. create user
3. flush privilege

```mysql
CREATE DATABASE 42DB default character set utf8 collate ut8_unicode_ci;
GRANT ALL ON cramdaniDB.* to 'cramdani'@'localhost' identified by 'admin';
FLUSH PRIVILEGES;
```

### connect wordpress to db

copy wordpress/wp-conf-samples.php
modification ->  wordpress/wp-conf.php

1. Change data according to our db
2. Generate own secret key (protect website) : https://api.wordpress.org/secret-key/1.1/salt/
3. Edit our nginx conf file (/etc/nginx/sites-available/) : root 
