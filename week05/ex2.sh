# You can change SAS to any value
SAS=1488

echo "The script shall start counting from $SAS (you can change it if you want)"
echo 

if test -f "ex2"
then
    rm ex2
fi

touch ex2
echo $SAS >> ex2


sh ex228.sh &
sh ex228.sh

cat ex2
