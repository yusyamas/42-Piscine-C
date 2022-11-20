echo "--------------c_file_norminette-------------"
for f in $(find . -name '*.c');
do
    norminette -R CheckForbiddenSourceHeader $f
done
echo "--------------h_file_norminette-------------"
for f in $(find . -name '*.h');
do
    norminette -R CheckDefine $f
done
echo "--------------test_start--------------------"
make build
for i in $(find . -name 'rush0[0-4]');do
    echo "---------------$i : run------------------"
    echo "##########safe_case : (x, y) = (5, 3)##########"
    $i 5 3
    echo "##########safe_case : (x, y) = (5, 1)##########"
    $i 5 1
    echo "##########safe_case : (x, y) = (1, 1)##########"
    $i 1 1
    echo "##########safe_case : (x, y) = (1, 5)##########"
    $i 1 5
    echo "##########safe_case : (x, y) = (4, 4)##########"
    $i 4 4
    echo "##########safe_case : (x, y) = (10, 10)##########"
    $i 10 10
    echo "##########zero_case : (x, y) = (10, 0)##########"
    $i 10 0
    echo "##########zero_case : (x, y) = (0, 2)##########"
    $i 0 2
    echo "##########error_case : argc = 1 ##########"
    $i
    echo "##########error_case : argc = 2 ##########"
    $i 10
    echo "##########error_case : argc = 4 ##########"
    $i 10 1 5
    echo "##########error_case : (x, y) = (10, -1)##########"
    $i 10 -1
    echo "##########error_case : (x, y) = (-7, 14)##########"
    $i -7 14
    echo "##########error_case : (x, y) = (10, a)##########"
    $i 10 a
    echo "##########error_case : (x, y) = (lo, 9)##########"
    $i lo 9
    echo "##########error_case : (x, y) = (7, \t)##########"
    $i 7 \t
    echo "##########error_case : (x, y) = (10, INT_MAX + 1)##########"
    $i 10  2147483648
    echo "##########error_case : (x, y) = (INT_MAX * 10, 5)##########"
    $i 21474836469 5
done
make fclean
