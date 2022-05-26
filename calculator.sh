echo -n "Enter first number : "
read a
echo -n "Enter second number : "
read b
echo "Enter your choice "
echo "1.Addition"
echo "2.Subtraction"
echo "3.Multiplication"
echo "4.Division" 
read choice
case $choice in
	1)res=$((a+b))
	  ;;
	2)res=$((a-b))
	  ;;
	3)res=$((a*b))
	  ;;
	4)res=$((a/b))
	  ;;
	*)  
	res="Invalid Operation"
	echo "ERROR"
	;;
esac
echo "Result : $res"
