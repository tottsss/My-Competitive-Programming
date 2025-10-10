g++ -o slow slow.cpp
g++ -o fast fast.cpp
g++ -o gen gen.cpp

pause

:loop 

gen.exe > text.txt
slow.exe < text.txt > slow.txt
fast.exe < text.txt > fast.txt

fc slow.txt fast.txt 

if errorlevel 1 (
goto exit
)

goto loop
:exit