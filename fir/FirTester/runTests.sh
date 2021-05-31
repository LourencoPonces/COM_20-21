#!/bin/bash

# -------- CHANGE --------

TESTDIR="tests-entrega-final"
NONSTOP="1"

# -------- COLORS --------

RED="31"
GREEN="32"
BOLDGREEN="\e[1;${GREEN}m"
BOLDRED="\e[1;${RED}m"
ENDCOLOR="\e[0m"
OKTXT="${BOLDGREEN}OK!${ENDCOLOR}"
ERTXT="${BOLDRED}ERROR!${ENDCOLOR}"

# ------ FUNCTIONS -------

function askContinue {
    if [ $NONSTOP -eq 0 ]
    then
        read -p "Continue? (Y/N)" yn
        case $yn in
            [Yy]* ) return;;
            [Nn]* ) exit;;
            * ) exit;;
        esac
    fi
}

function totalColor() {
    totalTests=$(ls *.fir | wc -l)
    if [ $1 -eq $totalTests ]
    then
        echo $BOLDGREEN
    else
        echo $BOLDRED
    fi
}

# -------- CLEAN ---------

./cleanTests.sh
sleep 0.1

# -------- START ---------

totalXML=$((0))
totalASM=$((0))
totalYASM=$((0))
totalLD=$((0))
totalDIFF=$((0))

cd $TESTDIR;
for testfir in $(ls *.fir)
do
    testname=$(basename $testfir .fir)
    echo "-------- $testname --------"
    ./../../fir $testfir --target xml &> $testname.xmllog
    res=$(grep -i error $testname.xmllog)
    if [ -z "$res" ] && [ $? -eq 0 ]
    then
        echo -e "(XML) ${OKTXT}"
        totalXML=$(($totalXML+1))
    else
        echo "$res"
        echo -e "(XML) ${ERTXT}"
        askContinue
        continue
    fi
    ./../../fir $testfir &> $testname.asmlog
    res=$(cat $testname.asm)
    if [ ! -z "$res" ] && [ $? -eq 0 ]
    then
        echo -e "(ASM) ${OKTXT}"
        totalASM=$(($totalASM+1))
    else
        echo "$res"
        echo -e "(ASM) ${ERTXT}"
        askContinue
        continue
    fi
    yasm -felf32 $testname.asm
    if [ $? -eq 0 ]
    then
        echo -e "(YASM) ${OKTXT}"
        totalYASM=$(($totalYASM+1))
    else
        echo -e "(YASM) ${ERTXT}"
        askContinue
        continue
    fi
    ld -m elf_i386 $testname.o -o $testname.exec -L$HOME/compiladores/root/usr/lib -lrts
    if [ $? -eq 0 ]
    then
        echo -e "(LD) ${OKTXT}"
        totalLD=$(($totalLD+1))
    else
        echo -e "(LD) ${ERTXT}"
        askContinue
        continue
    fi
    ./$testname.exec >$testname.out
    res=$(diff <(tr -d ' \n' <$testname.out) <(tr -d ' \n' <expected/$testname.out))
    if [ -z "$res" ]
    then
        echo -e "(DIFF) ${OKTXT}"
        totalDIFF=$(($totalDIFF+1))
    else
        echo "$res"
        echo -e "(DIFF) ${ERTXT}"
        askContinue
        continue
    fi
done

echo ------------------- RESULTS --------------------
echo -e "\
$(totalColor $totalXML)(XML)$totalXML$ENDCOLOR | \
$(totalColor $totalASM)(ASM)$totalASM$ENDCOLOR | \
$(totalColor $totalYASM)(YASM)$totalYASM$ENDCOLOR | \
$(totalColor $totalLD)(LD)$totalLD$ENDCOLOR | \
$(totalColor $totalDIFF)(DIFF)$totalDIFF$ENDCOLOR \
"
echo ------------------------------------------------