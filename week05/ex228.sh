#Change it
INTERVAL=13
RED='\033[0;31m'
NC='\033[0m'


#Create the file
if test ! -f ex2
then
    echo 0 > ex2
fi


while true; 
do

    #if locked then wait
    if ! ln ex2 ex2.lock
        then
            echo -e "${RED}This is not an error."
            echo -e "(Everything works as intended) each of 2 processes will increase the initial number by $INTERVAL"
            echo -e ${NC}
            sleep 1
            
    # if locked
    else
    
        for i in `seq 1 $INTERVAL`;
            do
                EGG=$((`tail -1 ex2`+1))
                echo $EGG >> ex2 
            done
        break
        
    fi
    
done

#remove link
rm ex2.lock

