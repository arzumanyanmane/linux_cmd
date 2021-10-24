# Readme about cp instrument
cp source_file target_file

cp program copies the content of source_file to target_file
- as the argument program gets the path of source and target files
- minimal argument count is 2, otherwise, the program will not run
- program tries to open the source file in O_RDONLY mode
- program tries to open target file in O_WRONLY, O_CREAT, S_IRUSR, S_IWUSR modes
- if the program is not able to open any of the desired files, it returns -1 without an error code
- if everything is fine with opening files program tries to write to target files, using source file content