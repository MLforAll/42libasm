#!/bin/bash

msg()
{
	local clr
	case "$1" in
		w )
			clr='\033[1;33m'
			;;
		e )
			clr='\033[1;31m'
			;;
		g )
			clr='\033[1;32m'
			;;
		i )
			clr='\033[1;39m'
			;;
	esac

	local nlc='\n'
	if [ "$2" = '-n' -a ! -z "$3" ]
	then
		nlc=''
		shift
	fi

	if [ ! -t 1 ] || ! echo "$TERM" | grep xterm >/dev/null
	then
		echo "$2"
		return
	fi
	printf "${clr}%s\033[0;39m$nlc" "$2"
}


msg i '=> Make lib'
make -C .. bonus
echo

msg i '=> Run initial_tests'
gcc -o initial_tests initial_tests.c -L.. -lasm -I../includes
[ $? -eq 0 ] || exit 0
./initial_tests
rm -f initial_tests

for t in *
do
	[ -d "$t" ] || continue

	echo
	msg i "===> TEST $t"
	cd "$t"

	gcc -o test main.c -L../.. -lasm -I../../includes
	if [ $? -eq 0 ]
	then
		ls -1 test*.output | sort | while read testfile
		do
			testdiff="${testfile%output}"mine
			./test $(echo "$testfile" | sed 's/[a-zA-Z.]*//g') > "$testdiff" |:
			status=${PIPESTATUS[0]}
			if [ $status -gt 128 ]
			then
				case $status in
					134 )
						msg e -n A
						;;
					139 )
						msg e -n S
						;;
					138 )
						msg e -n B
						;;
					142 )
						msg e -n T
						;;
					* )
						msg e -n C
						;;
				esac
				continue
			fi
			diff "$testdiff" "$testfile" >/dev/null 2>&1
			case $? in
				0 )
					msg g -n .
					;;
				* )
					msg e -n X
					;;
			esac
		done
		echo
		rm -f test
	fi
	cd - >/dev/null
done
