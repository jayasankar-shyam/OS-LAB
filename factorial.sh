echo "Enter the number"
read n
fact=1
if((n==0))
then
	echo "The factorial of 0 is 1"
else
	for((i=2;i<=n;i++))
	{
		fact=$((fact*i))
	}
	echo "The factorial of $n is $fact"
fi
