
#ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
#echo $ARG
./push_swap $ARG | ./checker $ARG
#./push_swap 3 2 1 4 | ./checker 3 2 1 4
#./push_swap $ARG
#./checker $ARG #| wc -l
