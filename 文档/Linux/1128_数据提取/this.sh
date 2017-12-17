number=$(echo $echo "1 2 3 4 5 6 7 9 a v 你 好 . /8"|tr -c [0-9] ' ')
echo $number
j=0
for i in $number; do
	j=$[$j+$i]
done
echo $j	
