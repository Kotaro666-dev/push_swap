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
		printf "$GREEN%s$RESET" "[OK]"
		echo ""
	elif [ $RESULT == $KO ]; then
		printf "$RED%s$RESET" "[KO]"
		echo ""
	elif [ $RESULT == $ERROR ]; then
		printf "$YELLOW%s$RESET" "[Error]"
		echo ""
	fi
	TOTAL=$(( $TOTAL+$COUNT ))
}

function run_test_for_5_numbers()
{
	ARG=`$1`
	/bin/echo $ARG
	COUNT=$(.././push_swap $ARG | wc -l | tr -d ' ')
	if [ $COUNT -gt 12 ]; then
		printf "$RED%s$RESET" "[NG]"
		echo ""
		NG++
	fi
	RESULT=$(.././push_swap $ARG | .././checker $ARG)
	printf "$BLUE%s$RESET" "[COMMANDS]"
	/bin/echo ": $COUNT"
	if [ $RESULT == $OK ]; then
		printf "$GREEN%s$RESET" "[OK]"
		echo ""
	elif [ $RESULT == $KO ]; then
		printf "$RED%s$RESET" "[KO]"
		echo ""
	elif [ $RESULT == $ERROR ]; then
		printf "$YELLOW%s$RESET" "[Error]"
		echo ""
	fi
	TOTAL=$(( $TOTAL+$COUNT ))
}

echo "Random Number 3"
TOTAL=0
TIMES=3
for i in `seq $TIMES`
do
run_test 'python generate_random_numbers.py 3'
done
AVERAGE_THREE=$(( $TOTAL/$TIMES ))

echo "Random Number 5"
TOTAL=0
NG=0
TIMES=150
for i in `seq $TIMES`
do
run_test_for_5_numbers 'python generate_random_numbers.py 5'
done
AVERAGE_FIVE=$(( $TOTAL/$TIMES ))

echo "Random Number 7"
TOTAL=0
TIMES=200
for i in `seq $TIMES`
do
run_test 'python generate_random_numbers.py 7'
done
AVERAGE_SEVEN=$(( $TOTAL/$TIMES ))

echo "Random Number 100"
TOTAL=0
TIMES=200
for i in `seq $TIMES`
do
run_test 'python generate_random_numbers.py 100'
done
AVERAGE_HUNDRED=$(( $TOTAL/$TIMES ))

echo "Random Number 500"
TOTAL=0
TIMES=200
for i in `seq $TIMES`
do
run_test 'python generate_random_numbers.py 500'
done
AVERAGE_FIVE_HUNDRED=$(( $TOTAL/$TIMES ))

printf "\n$BLUE%s$RESET\n" "[NUMBER OF COMMANDS ON AVERAGE]"
printf "$CYAN%s$RESET" "[3 RANDOM NUMBERS]"
/bin/echo ": $AVERAGE_THREE"
printf "$CYAN%s$RESET" "[5 RANDOM NUMBERS]"
/bin/echo ": $AVERAGE_FIVE"
printf "$CYAN%s$RESET" "[7 RANDOM NUMBERS]"
/bin/echo ": $AVERAGE_SEVEN"
printf "$CYAN%s$RESET" "[100 RANDOM NUMBERS]"
/bin/echo ": $AVERAGE_HUNDRED"
printf "$CYAN%s$RESET" "[500 RANDOM NUMBERS]"
/bin/echo ": $AVERAGE_FIVE_HUNDRED"

printf "\n$RED%s$RESET: $NG\n" "[NG 5 RANDOM NUMBERS]"
