#! /bin/bash
  
SAB=$(grep -o -i ss result.txt | wc -l)
echo -e "count sa" 
SA=$(grep -o -i sa result.txt | wc -l)
echo $((SA))
echo -e "count sb" 
grep -o -i sb result.txt | wc -l
echo -e "count sab" 
echo $SAB
echo -e "count ra" 
grep -o -i ra result.txt | wc -l
echo -e "count rb" 
grep -o -i rb result.txt | wc -l
RR=$(grep -o -i rr result.txt | wc -l)
RRR=$(grep -o -i rrr result.txt | wc -l)
echo -e "count rr" 
echo $((RR - RRR))
echo -e "count rra" 
grep -o -i rra result.txt | wc -l
echo -e "count rrb" 
grep -o -i rrb result.txt | wc -l
echo -e "count rrr" 
grep -o -i rrr result.txt | wc -l
echo -e "count pa" 
grep -o -i pa result.txt | wc -l
echo -e "count pb" 
grep -o -i pb result.txt | wc -l
echo -e "count instruction"
wc -l result.txt

