# Readme about rm instrument
rm file_path -f

rm program removes specified file, and all files in it recursively
- as the argument program gets the path of file
- minimal argument count is 2, otherwise, the program will not run (should always give a -f flag)
- program checks whether given path is for a regular file or not 
- if it is a directory, program removes content of the directory recursively
- if path is for a regular file it removes file