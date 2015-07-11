# BlackBox-cli

Command-line mode for BlackBox Component Builder

### Running interpreted commands

Commands can be interpreted and executed at run time.

#### Example

Run command through pipe: ```echo "PrivHello.SayHello" | ./bbcli.exe``` (Linux)

### Building executable

- execute ```runBB``` (run BlackBox in "server" mode):  ```BB_ROOT=~/.wine/drive_c/Program\ Files/BlackBox ./runBB``` (Linux)
- Open Build-Tool.odc and follow instructions
- run ```bbcli.exe``` as in example above
