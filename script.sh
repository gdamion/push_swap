
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
#ARG="4 2 55 32 50 58 7 889 -3 -222 89 51 28 0 -2 -41"
#./push_swap $ARG
./push_swap $ARG | ./checker $ARG
#echo $ARG
#./checker $ARG
#./push_swap 3 2 1 4 | ./checker 3 2 1 4
#./push_swap $ARG
#./checker $ARG #| wc -l