# __CUB3D__


## Entry_Point & check format

### main.c

1. Check nb of arguments

2. Check file name and 2nd argument if there is one 
	- 1st arg : *.cub
	- 2nd arg : --save

3. Check cub file 

### check_cub.c

1. Open <file>.cub
2. Check if all conf present in file
	-	Read while not EOF and not all config are present 
		- Split line to get ID : __check_line__
		- According to the ID use the function (text, color, resolution) : __which__
		- If there is a problem print error message and stop reading
		- Once we have all conf, read all empty line
		- Read until the end of file 
3. Check if map is closed


## Start screen & play