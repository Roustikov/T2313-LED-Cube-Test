C:\SinaProg\avrdude.exe -C C:\SinaProg\avrdude.conf -c usbtiny -b 115200 -p t2313 -U flash:w:"%~dp0Exe\test.hex":a -q
pause