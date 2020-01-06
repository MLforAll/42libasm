#!/bin/bash

echo '=> Make lib'
make -C ..
echo

for t in *
do
	[ -d "$t" ] || continue
	echo "===> TEST $t"
	cd "$t"
	gcc -o test main.c -L../.. -lasm -I../../includes
	if [ $? -eq 0 ]
	then
		ls -1 test*.output | sort | while read testfile
		do
			testdiff="${testfile%output}"mine
			./test $(echo "$testfile" | sed 's/[a-zA-Z.]*//g') > "$testdiff"
			diff "$testdiff" "$testfile" >/dev/null 2>&1
			if [ $? -eq 0 ]
			then
				echo -n .
			else
				echo -n X
			fi
		done
		echo
		rm -f test
	fi
	cd - >/dev/null
	echo
done

echo '=> Run initial_tests'
gcc -o initial_tests initial_tests.c -L.. -lasm -I../includes
[ $? -eq 0 ] || exit 0
./initial_tests
rm -f initial_tests
