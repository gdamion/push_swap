
ARG=`ruby -e "puts (1...100).to_a.shuffle.join(' ')"`
./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l