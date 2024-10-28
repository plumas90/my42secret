#!/bin/bash
cat /etc/passwd | sed '/#/d' | cut -d ':' -f1 | awk "NR % 2 == 0" | rev | sort -r  | awk -v FT_LINE1="$FT_LINE1" -v FT_LINE2="$FT_LINE2" 'NR >= FT_LINE1 && NR <= FT_LINE2'  | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./' 
