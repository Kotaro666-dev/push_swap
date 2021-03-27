#!/bin/sh

RESET="\033[0m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"

OK="OK"
KO="KO"
ERROR="Error"

function run_test()
{
	ARG=`$1`
	/bin/echo $ARG
	COUNT=$(.././push_swap $ARG | wc -l | tr -d ' ')
	RESULT=$(.././push_swap $ARG | .././checker $ARG)
	printf "$BLUE%s$RESET" "[COMMANDS]"
	/bin/echo ": $COUNT"
	if [ $RESULT == $OK ]; then
		printf "$GREEN%s\n$RESET" "[OK]"
	elif [ $RESULT == $KO ]; then
		printf "$RED%s\n$RESET" "[KO]"
	elif [ $RESULT == $ERROR ]; then
		printf "$YELLOW%s\n$RESET" "[Error]"
	fi
	TOTAL=$(( $TOTAL+$COUNT ))
}

function run_test_for_5_numbers()
{
	ARG=`$1`
	/bin/echo $ARG
	COUNT=$(.././push_swap $ARG | wc -l | tr -d ' ')
	if [ $COUNT -ge 12 ]; then
		printf "$RED%s\n$RESET" "[NG - MORE THAN 12]"
		let MORE_THAN_12++
	fi
	RESULT=$(.././push_swap $ARG | .././checker $ARG)
	printf "$BLUE%s$RESET" "[COMMANDS]"
	/bin/echo ": $COUNT"
	if [ $RESULT == $OK ]; then
		printf "$GREEN%s\n$RESET" "[OK]"
	elif [ $RESULT == $KO ]; then
		printf "$RED%s\n$RESET" "[KO]"
	elif [ $RESULT == $ERROR ]; then
		printf "$YELLOW%s\n$RESET" "[Error]"
	fi
	TOTAL=$(( $TOTAL+$COUNT ))
}

if [ $# -eq 0 ] || [ $1 == '3' ]; then
	echo "Random Number 3"
	TOTAL=0
	TIMES=18
	for i in `seq $TIMES`
	do
	run_test 'python3 generate_random_numbers.py 3'
	done
	AVERAGE_THREE=$(( $TOTAL/$TIMES ))
	printf "$CYAN%s$RESET%s\n" "[NUMBER OF COMMANDS ON AVERAGE]" ": $AVERAGE_THREE"
fi

if [ $# -eq 0 ] || [ $1 == '5' ]; then
	echo "Random Number 5"
	TOTAL=0
	TIMES=150
	MORE_THAN_12=0
	for i in `seq $TIMES`
	do
	run_test_for_5_numbers 'python3 generate_random_numbers.py 5'
	done
	AVERAGE_FIVE=$(( $TOTAL/$TIMES ))
	printf "\n$CYAN%s$RESET%s" "[NUMBER OF COMMANDS ON AVERAGE]" ": $AVERAGE_FIVE"
	printf "\n$RED%s$RESET%s\n" "[OCCURENECE OF MORE THAN 12 COMMANDS]" ": $MORE_THAN_12"
fi

if [ $# -eq 0 ] || [ $1 == '100' ]; then
	echo "Random Number 100"
	TOTAL=0
	TIMES=200
	for i in `seq $TIMES`
	do
	run_test 'python3 generate_random_numbers.py 100'
	done
	AVERAGE_HUNDRED=$(( $TOTAL/$TIMES ))
	printf "\n$CYAN%s$RESET%s\n" "[NUMBER OF COMMANDS ON AVERAGE]" ": $AVERAGE_HUNDRED"
fi

if [ $# -eq 0 ] || [ $1 == '500' ]; then
	echo "Random Number 500"
	TOTAL=0
	TIMES=200
	for i in `seq $TIMES`
	do
	run_test 'python3 generate_random_numbers.py 500'
	done
	AVERAGE_FIVE_HUNDRED=$(( $TOTAL/$TIMES ))
	printf "\n$CYAN%s$RESET%s\n" "[NUMBER OF COMMANDS ON AVERAGE]" ": $AVERAGE_FIVE_HUNDRED"
fi
