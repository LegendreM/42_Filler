# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    pool_test.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jle-mene <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 09:31:13 by jle-mene          #+#    #+#              #
#    Updated: 2016/12/14 10:50:53 by jle-mene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

trap ctrl_c INT

AI=./players/wyki.filler

RESULT=./pool_test_result.txt
OUTPUT=/tmp/test.txt

function	ctrl_c
{
	echo "Aborting..."
	exit 1;
}

function	launch_vm
{
	echo "Map $1" >> $RESULT
	for I in {1..5}
	do
		./filler_vm -f ./maps/map$1 -p1 $AI -p2 $line > $OUTPUT
		tail -2 $OUTPUT >> $RESULT

		SCORE1=$(tail -2 $OUTPUT | sed -n 1p)
		SCORE1=${SCORE1##* }
		SCORE2=$(tail -1 $OUTPUT)
		SCORE2=${SCORE2##* }

		if [ $SCORE1 -gt $SCORE2 ]
		then
			echo "$I : \033[92;1mWIN\033[0m" >> $RESULT
		else
			echo "$I : \033[91;1mLOOSE\033[0m" >> $RESULT
		fi
	done

}

function	main
{

	if [ ${PWD##*/} != 'resources' ]
	then
		echo 'Need to be launched in resources folder !'
		echo ${PWD##*/}
		exit 1
	fi

	echo "" > $RESULT

	find ./players -name '*.filler' | while read line
	do
		echo "$line"
		echo "########## TEST ##########" >> $RESULT
		echo "Test $(basename $AI) vs. $(basename $line)" >> $RESULT
		launch_vm '00'
		launch_vm '01'
		launch_vm '02'
		echo "##########################" >> $RESULT
	done
}

main
