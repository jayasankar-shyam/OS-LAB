a=0
b=1
echo "Enter the number of terms : "
read n
echo "The Fibonacci series is : "
for ((i=0;i<n;i++))
do
    echo -n "$a "
    sum=$((a + b))
    a=$b
    b=$sum
done
echo "" 
