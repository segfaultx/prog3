#!/bin/bash

# (c) 2011 Alexander Baumgärtner
clear
echo ""
echo "     ================================================="
echo "               Probe-Onlinetest Testskript            "
echo "     ================================================="
echo "             (c) 2011 Alexander Baumgärtner           "
echo ""
echo "Programme werden kompiliert, gebunden und getestet. Dateien a1.c und/oder a2.c müssen im Ordner"
pwd
echo "vorhanden sein."
echo "Was soll getestet werden? a1 für Aufgabe 1, a2 für Aufgabe 2 oder beliebige Eingabe für alles."
read eingabe
rm check -f

case $eingabe in
a1)
   #Aufg1
echo "*** Beginn gcc Warnungen Aufgabe 1***"
gcc -ansi -Wall -pedantic -Wextra checkA1.c -o check
echo "*** Ende gcc Warnungen Aufgabe 1***"
echo ""
./check
echo ""
;;
a2)
   #Aufg2
echo "*** Beginn gcc Warnungen Aufgabe 2***"
gcc -ansi -Wall -pedantic -Wextra checkA2.c -o check
echo "*** Ende gcc Warnungen Aufgabe 2***"
echo ""
echo "Der Test wird mit valgrind durchgeführt."
echo ""
valgrind ./check -q
echo ""
;;
*)
#Aufg1
echo "*** Beginn gcc Warnungen Aufgabe 1***"
gcc -ansi -Wall -pedantic -Wextra checkA1.c -o check
echo "*** Ende gcc Warnungen Aufgabe 1***"
echo ""
./check
echo ""


#Aufg2
echo "*** Beginn gcc Warnungen Aufgabe 2***"
gcc -ansi -Wall -pedantic -Wextra checkA2.c -o check
echo "*** Ende gcc Warnungen Aufgabe 2***"
echo ""
echo "Der Test wird mit valgrind durchgeführt."
echo ""
valgrind ./check -q
echo ""
    ;;
esac

echo "Diese Nachricht zerstört sich mit ENTER selbst."
read
clear
