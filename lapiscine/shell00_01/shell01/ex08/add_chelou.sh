#!/bin/bash
echo -e  $FT_NBR1 + $FT_NBR2 | tr '\’\\\"?!' '01234' | tr 'mrdoc' '01234' | bc | echo 'obase=13; ibase=5;' | tr '0123456789ABC' 'gtaio luSnemf'
