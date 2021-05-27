echo "Test ID;Return code validation;Out result;StdErr result;File creation result;Global result" >results.csv
nOk=0
nKo=0
nTotal=0
nMis=0

for i in Test*
do

    cp BaseLocalData/logins.csv $i/Dataset/Local/logins.csv
    cp BaseLocalData/individuals.csv $i/Dataset/Local/individuals.csv

    ./test.sh $i results.csv
    result=$?
    if [ $result -eq 0 ]
    then
        let "nKo=$nKo+1"
    elif [ $result -eq 1 ]
    then
        let "nOk=$nOk+1"
    else
        let "nMis=$nMis+1"
    fi
    let "nTotal=$nTotal+1"
done

echo "Passed tests     : $nOk"
echo "Failed tests     : $nKo"
echo "Misformed tests  : $nMis"
echo "-----------------------"
echo "Total            : $nTotal"
