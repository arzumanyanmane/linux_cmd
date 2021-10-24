# Readme about mv instrument
mv source_file target_file

mv program renames source_file to target_files
- as the argument program gets the path of source and target files
- minimal argument count is 2, otherwise, the program will not run
- program tries to open the source file in O_RDONLY mode
- program tries to create target file with 0777 
- if everything is fine with opening files program tries to write to target files, using source file content
- if the program is not able to open any of the desired files, it returns -1 without an error code
- at the end program closes files, and removes source_file