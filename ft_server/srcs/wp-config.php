<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpressDB' );

/** MySQL database username */
define( 'DB_USER', 'admin' );

/** MySQL database password */
define( 'DB_PASSWORD', 'admin' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'PU+ZY;(zEAMIiTZ[+SJ/L?D9<_}|}dH~aw4@!UU-3sZR>v$8qar*86>KP+yN-vv8');
define('SECURE_AUTH_KEY',  '12y(V@*KFY] 0-1%Qc1G&KmB;O7>ha_/@?%P@fcwZ-W:&LsyDsp-ItUsk=NA_7*;');
define('LOGGED_IN_KEY',    '*y^KaX;A8[hH.3Zv>rK^GLG*<7#qfk|#](wc~czYzg-E8)P_9-D0+RI;K>E(oG;B');
define('NONCE_KEY',        'A/yIjaXosr%_|e+L7A)K?-{)C`8NXQ.-S7eLBMZWt^JUYesvvv=J-}>M-8U|IYCb');
define('AUTH_SALT',        '+uQjOOz=}d%%Nyq~%:4#etg|r]k2+TNU|Bksz(2W:~@g4R-)Vp}WHKi!XU!VB0i+');
define('SECURE_AUTH_SALT', 'nT}sZ(qYP2c%iA|f1-[)Wrxnwm<p`}CgG2aC]p5z qJs@r*g2[ct7wRBR`}}$Ynt');
define('LOGGED_IN_SALT',   '+;?|AUS_xSb3{=&@xu}T7P~^%A%d+Vh:1W{f8g *QD9NFq5-3e8)WHr1%T+yZ^Vk');
define('NONCE_SALT',       'Ip{mI!W{y<V;WjK:=|=XzGX#RnuKZGPkxo|I=PsD#--sg2vv!E)FITW$mSf6Nl+)');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
