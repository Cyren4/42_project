#ifndef MOVE_H
# define MOVE_H

# ifdef MACOS
#  define KEY_A 0
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_ESC 53
#  define MACOSX 1
#  define PROB 10

# else

#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_ESC 65307
#  define EXIT_EVENT 33
#  define MACOSX 0
#  define PROB 1000
# endif

#endif