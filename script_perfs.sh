#definition des variables locales au scripts
ADD_LOOP=100000;
MULT_LOOP=500;
SIZE_OF_SMALL=312;
SIZE_OF_BIG=548;
NUMBER_OF_OPS_ADD_SMALL=$(($SIZE_OF_SMALL * $SIZE_OF_SMALL * $ADD_LOOP));
NUMBER_OF_OPS_ADD_BIG=$(($SIZE_OF_BIG * $SIZE_OF_BIG * $ADD_LOOP));
NUMBER_OF_OPS_MULT_SMALL=$(($SIZE_OF_SMALL * SIZE_OF_SMALL * SIZE_OF_SMALL * 2 * $MULT_LOOP));
NUMBER_OF_OPS_MULT_BIG=$(($SIZE_OF_BIG * SIZE_OF_BIG * SIZE_OF_BIG * 2 * $MULT_LOOP));
#supprime le fichier de sortie
rm -rf perfs.txt;
#crée le fichier de sortie
touch perfs.txt;
#Separating tests
echo "######################################################################################################";
echo "Tests with O0 and openmp";
echo "######################################################################################################";
#clean
make clean > /dev/null 2>&1;
if [ $? == O ]
then
	echo "Failed to clean";
	exit 1;
else
	echo "Cleant successfully";
fi
#compile
make  > /dev/null 2>&1;
if [ $? == O ]
then
	echo "Failed to make";
	exit 1;
else
	echo "Made application successfully for O0 and openmp";
fi
#execute
	echo "######### test with openmp and O0 #########" >> perfs.txt;
	#addition matrice small addition $ADD_LOOP iterations with floats and openmp
		echo "addition matrice small addition "$ADD_LOOP" iterations with floats and openmp : "$NUMBER_OF_OPS_ADD_SMALL" operations" >> perfs.txt;
		echo "addition matrice small addition "$ADD_LOOP" iterations with floats and openmp : "$NUMBER_OF_OPS_ADD_SMALL" operations";
		{ time ./target/debug/test_matrix_small a $ADD_LOOP f < test_mat.txt ; } 2>> perfs.txt;
		echo "done";
	#addition matrice small addition $ADD_LOOP iterations with doubles and openmp
	#	echo "" >> perfs.txt;
	#	echo "addition matrice small addition "$ADD_LOOP" iterations with doubles and openmp : "$NUMBER_OF_OPS_ADD_SMALL" operations" >> perfs.txt;
	#	echo "addition matrice small addition "$ADD_LOOP" iterations with doubles and openmp : "$NUMBER_OF_OPS_ADD_SMALL" operations";
	#	{ time ./target/debug/test_matrix_small a $ADD_LOOP d < test_mat.txt ; } 2>> perfs.txt;
	#	echo "done";
	#addition matrice big addition $ADD_LOOP iterations with floats and openmp
		echo "" >> perfs.txt;
		echo "addition matrice big addition "$ADD_LOOP" iterations with floats and openmp : "$NUMBER_OF_OPS_ADD_BIG" operations" >> perfs.txt;
		echo "addition matrice big addition "$ADD_LOOP" iterations with floats and openmp : "$NUMBER_OF_OPS_ADD_BIG" operations";
		{ time ./target/debug/test_matrix_big a $ADD_LOOP f < test_mat.txt ; } 2>> perfs.txt;
		echo "done";
	#addition matrice big addition $ADD_LOOP iterations with doubles and openmp
	#	echo "" >> perfs.txt;
	#	echo "addition matrice big addition "$ADD_LOOP" iterations with doubles and openmp : "$NUMBER_OF_OPS_ADD_BIG" operations" >> perfs.txt;
	#	echo "addition matrice big addition "$ADD_LOOP" iterations with doubles and openmp : "$NUMBER_OF_OPS_ADD_BIG" operations";
	#	{ time ./target/debug/test_matrix_big a $ADD_LOOP d < test_mat.txt ; } 2>> perfs.txt;
	#	echo "done";
	#multiplication matrice small multiplication $MULT_LOOP iterations with floats and openmp
		echo "" >> perfs.txt;
		echo "multiplication matrice small multiplication "$MULT_LOOP" iterations with floats and openmp : "$NUMBER_OF_OPS_MULT_SMALL" operations" >> perfs.txt;
		echo "multiplication matrice small multiplication "$MULT_LOOP" iterations with floats and openmp : "$NUMBER_OF_OPS_MULT_SMALL" operations";
		{ time ./target/debug/test_matrix_small m $MULT_LOOP f < test_mat.txt ; } 2>> perfs.txt;
		echo "done";
	#multiplication matrice small multiplication $MULT_LOOP iterations with doubles and openmp
	#	echo "" >> perfs.txt;
	#	echo "multiplication matrice small multiplication "$MULT_LOOP" iterations with doubles and openmp : "$NUMBER_OF_OPS_MULT_SMALL" operations" >> perfs.txt;
	#	echo "multiplication matrice small multiplication "$MULT_LOOP" iterations with doubles and openmp : "$NUMBER_OF_OPS_MULT_SMALL" operations";
	#	{ time ./target/debug/test_matrix_small m $MULT_LOOP d < test_mat.txt ; } 2>> perfs.txt;
	#	echo "done";
	#multiplication matrice big multiplication $MULT_LOOP iterations with float and openmp
		echo "" >> perfs.txt;
		echo "multiplication matrice big multiplication "$MULT_LOOP" iterations with floats and openmp : "$NUMBER_OF_OPS_MULT_BIG" operations" >> perfs.txt;
		echo "multiplication matrice big multiplication "$MULT_LOOP" iterations with floats and openmp : "$NUMBER_OF_OPS_MULT_BIG" operations";
		{ time ./target/debug/test_matrix_big m $MULT_LOOP f < test_mat.txt ; } 2>> perfs.txt;
		echo "done";
	#multiplication matrice big multiplication $MULT_LOOP iterations with doubles and openmp
	#	echo "" >> perfs.txt;
	#	echo "multiplication matrice big multiplication "$MULT_LOOP" iterations with doubles and openmp : "$NUMBER_OF_OPS_MULT_BIG" operations" >> perfs.txt;
	#	echo "multiplication matrice big multiplication "$MULT_LOOP" iterations with doubles and openmp : "$NUMBER_OF_OPS_MULT_BIG" operations";
	#	{ time ./target/debug/test_matrix_big m $MULT_LOOP d < test_mat.txt ; } 2>> perfs.txt;
	#	echo "done";
	echo "#########        END OF TEST      #########" >> perfs.txt;
	echo "" >> perfs.txt;
	echo "" >> perfs.txt;
#Separating tests
echo "######################################################################################################";
echo "Tests with O3 and openmp";
echo "######################################################################################################";
#switching make file
mv Makefile MakefileOpenmpO0
mv MakefileOpenmpO3 Makefile
echo "switched makefiles";
#clean
make clean > /dev/null 2>&1;
if [ $? == O ]
then
	echo "Failed to clean";
	exit 1;
else
	echo "Cleant successfully";
fi
#compile
make  > /dev/null 2>&1;
if [ $? == O ]
then
	echo "Failed to make";
	exit 1;
else
	echo "Made application successfully for O3 and openmp";
fi
#execute
	echo "######### test with openmp and O3 #########" >> perfs.txt;
	#addition matrice small addition $ADD_LOOP iterations with floats and openmp
		echo "addition matrice small addition "$ADD_LOOP" iterations with floats and openmp : "$NUMBER_OF_OPS_ADD_SMALL" operations" >> perfs.txt;
		echo "addition matrice small addition "$ADD_LOOP" iterations with floats and openmp : "$NUMBER_OF_OPS_ADD_SMALL" operations";
		{ time ./target/debug/test_matrix_small a $ADD_LOOP f < test_mat.txt ; } 2>> perfs.txt;
		echo "done";
	#addition matrice small addition $ADD_LOOP iterations with doubles and openmp
	#	echo "" >> perfs.txt;
	#	echo "addition matrice small addition "$ADD_LOOP" iterations with doubles and openmp : "$NUMBER_OF_OPS_ADD_SMALL" operations" >> perfs.txt;
	#	echo "addition matrice small addition "$ADD_LOOP" iterations with doubles and openmp : "$NUMBER_OF_OPS_ADD_SMALL" operations";
	#	{ time ./target/debug/test_matrix_small a $ADD_LOOP d < test_mat.txt ; } 2>> perfs.txt;
	#	echo "done";
	#addition matrice big addition $ADD_LOOP iterations with floats and openmp
		echo "" >> perfs.txt;
		echo "addition matrice big addition "$ADD_LOOP" iterations with floats and openmp : "$NUMBER_OF_OPS_ADD_BIG" operations" >> perfs.txt;
		echo "addition matrice big addition "$ADD_LOOP" iterations with floats and openmp : "$NUMBER_OF_OPS_ADD_BIG" operations";
		{ time ./target/debug/test_matrix_big a $ADD_LOOP f < test_mat.txt ; } 2>> perfs.txt;
		echo "done";
	#addition matrice big addition $ADD_LOOP iterations with doubles and openmp
	#	echo "" >> perfs.txt;
	#	echo "addition matrice big addition "$ADD_LOOP" iterations with doubles and openmp : "$NUMBER_OF_OPS_ADD_BIG" operations" >> perfs.txt;
	#	echo "addition matrice big addition "$ADD_LOOP" iterations with doubles and openmp : "$NUMBER_OF_OPS_ADD_BIG" operations";
	#	{ time ./target/debug/test_matrix_big a $ADD_LOOP d < test_mat.txt ; } 2>> perfs.txt;
	#	echo "done";
	#multiplication matrice small multiplication $MULT_LOOP iterations with floats and openmp
		echo "" >> perfs.txt;
		echo "multiplication matrice small multiplication "$MULT_LOOP" iterations with floats and openmp : "$NUMBER_OF_OPS_MULT_SMALL" operations" >> perfs.txt;
		echo "multiplication matrice small multiplication "$MULT_LOOP" iterations with floats and openmp : "$NUMBER_OF_OPS_MULT_SMALL" operations";
		{ time ./target/debug/test_matrix_small m $MULT_LOOP f < test_mat.txt ; } 2>> perfs.txt;
		echo "done";
	#multiplication matrice small multiplication $MULT_LOOP iterations with doubles and openmp
	#	echo "" >> perfs.txt;
	#	echo "multiplication matrice small multiplication "$MULT_LOOP" iterations with doubles and openmp : "$NUMBER_OF_OPS_MULT_SMALL" operations" >> perfs.txt;
	#	echo "multiplication matrice small multiplication "$MULT_LOOP" iterations with doubles and openmp : "$NUMBER_OF_OPS_MULT_SMALL" operations";
	#	{ time ./target/debug/test_matrix_small m $MULT_LOOP d < test_mat.txt ; } 2>> perfs.txt;
	#	echo "done";
	#multiplication matrice big multiplication $MULT_LOOP iterations with float and openmp
		echo "" >> perfs.txt;
		echo "multiplication matrice big multiplication "$MULT_LOOP" iterations with floats and openmp : "$NUMBER_OF_OPS_MULT_BIG" operations" >> perfs.txt;
		echo "multiplication matrice big multiplication "$MULT_LOOP" iterations with floats and openmp : "$NUMBER_OF_OPS_MULT_BIG" operations";
		{ time ./target/debug/test_matrix_big m $MULT_LOOP f < test_mat.txt ; } 2>> perfs.txt;
		echo "done";
	#multiplication matrice big multiplication $MULT_LOOP iterations with doubles and openmp
	#	echo "" >> perfs.txt;
	#	echo "multiplication matrice big multiplication "$MULT_LOOP" iterations with doubles and openmp : "$NUMBER_OF_OPS_MULT_BIG" operations" >> perfs.txt;
	#	echo "multiplication matrice big multiplication "$MULT_LOOP" iterations with doubles and openmp : "$NUMBER_OF_OPS_MULT_BIG" operations";
	#	{ time ./target/debug/test_matrix_big m $MULT_LOOP d < test_mat.txt ; } 2>> perfs.txt;
	#	echo "done";
	echo "#########        END OF TEST      #########" >> perfs.txt;
	echo "" >> perfs.txt;
#Separating tests
echo "######################################################################################################";
echo "Tests with O3 and NO openmp";
echo "######################################################################################################";
#switching make file
mv Makefile MakefileOpenmpO3
mv MakefileNOpenmpO3 Makefile
echo "switched makefiles";
#clean
make clean > /dev/null 2>&1;
if [ $? == O ]
then
	echo "Failed to clean";
	exit 1;
else
	echo "Cleant successfully";
fi
#compile
make  > /dev/null 2>&1;
if [ $? == O ]
then
	echo "Failed to make";
	exit 1;
else
	echo "Made application successfully for O3 and NO openmp";
fi
#execute
	echo "######## test with NO openmp and O3 #######" >> perfs.txt;
	#addition matrice small addition $ADD_LOOP iterations with floats and NO openmp
		echo "addition matrice small addition "$ADD_LOOP" iterations with floats and NO openmp : "$NUMBER_OF_OPS_ADD_SMALL" operations" >> perfs.txt;
		echo "addition matrice small addition "$ADD_LOOP" iterations with floats and NO openmp : "$NUMBER_OF_OPS_ADD_SMALL" operations";
		{ time ./target/debug/test_matrix_small a $ADD_LOOP f < test_mat.txt ; } 2>> perfs.txt;
		echo "done";
	#addition matrice small addition $ADD_LOOP iterations with doubles and NO openmp
	#	echo "" >> perfs.txt;
	#	echo "addition matrice small addition "$ADD_LOOP" iterations with doubles and NO openmp : "$NUMBER_OF_OPS_ADD_SMALL" operations" >> perfs.txt;
	#	echo "addition matrice small addition "$ADD_LOOP" iterations with doubles and NO openmp : "$NUMBER_OF_OPS_ADD_SMALL" operations";
	#	{ time ./target/debug/test_matrix_small a $ADD_LOOP d < test_mat.txt ; } 2>> perfs.txt;
	#	echo "done";
	#addition matrice big addition $ADD_LOOP iterations with floats and NO openmp
		echo "" >> perfs.txt;
		echo "addition matrice big addition "$ADD_LOOP" iterations with floats and NO openmp : "$NUMBER_OF_OPS_ADD_BIG" operations" >> perfs.txt;
		echo "addition matrice big addition "$ADD_LOOP" iterations with floats and NO openmp : "$NUMBER_OF_OPS_ADD_BIG" operations";
		{ time ./target/debug/test_matrix_big a $ADD_LOOP f < test_mat.txt ; } 2>> perfs.txt;
		echo "done";
	#addition matrice big addition $ADD_LOOP iterations with doubles and NO openmp
	#	echo "" >> perfs.txt;
	#	echo "addition matrice big addition "$ADD_LOOP" iterations with doubles and NO openmp : "$NUMBER_OF_OPS_ADD_BIG" operations" >> perfs.txt;
	#	echo "addition matrice big addition "$ADD_LOOP" iterations with doubles and NO openmp : "$NUMBER_OF_OPS_ADD_BIG" operations";
	#	{ time ./target/debug/test_matrix_big a $ADD_LOOP d < test_mat.txt ; } 2>> perfs.txt;
	#	echo "done";
	#multiplication matrice small multiplication $MULT_LOOP iterations with floats and NO openmp
		echo "" >> perfs.txt;
		echo "multiplication matrice small multiplication "$MULT_LOOP" iterations with floats and NO openmp : "$NUMBER_OF_OPS_MULT_SMALL" operations" >> perfs.txt;
		echo "multiplication matrice small multiplication "$MULT_LOOP" iterations with floats and NO openmp : "$NUMBER_OF_OPS_MULT_SMALL" operations";
		{ time ./target/debug/test_matrix_small m $MULT_LOOP f < test_mat.txt ; } 2>> perfs.txt;
		echo "done";
	#multiplication matrice small multiplication $MULT_LOOP iterations with doubles and NO openmp
	#	echo "" >> perfs.txt;
	#	echo "multiplication matrice small multiplication "$MULT_LOOP" iterations with doubles and NO openmp : "$NUMBER_OF_OPS_MULT_SMALL" operations" >> perfs.txt;
	#	echo "multiplication matrice small multiplication "$MULT_LOOP" iterations with doubles and NO openmp : "$NUMBER_OF_OPS_MULT_SMALL" operations";
	#	{ time ./target/debug/test_matrix_small m $MULT_LOOP d < test_mat.txt ; } 2>> perfs.txt;
	#	echo "done";
	#multiplication matrice big multiplication $MULT_LOOP iterations with float and NO openmp
		echo "" >> perfs.txt;
		echo "multiplication matrice big multiplication "$MULT_LOOP" iterations with floats and NO openmp : "$NUMBER_OF_OPS_MULT_BIG" operations" >> perfs.txt;
		echo "multiplication matrice big multiplication "$MULT_LOOP" iterations with floats and NO openmp : "$NUMBER_OF_OPS_MULT_BIG" operations";
		{ time ./target/debug/test_matrix_big m $MULT_LOOP f < test_mat.txt ; } 2>> perfs.txt;
		echo "done";
	#multiplication matrice big multiplication $MULT_LOOP iterations with doubles and NO openmp
	#	echo "" >> perfs.txt;
	#	echo "multiplication matrice big multiplication "$MULT_LOOP" iterations with doubles and NO openmp : "$NUMBER_OF_OPS_MULT_BIG" operations" >> perfs.txt;
	#	echo "multiplication matrice big multiplication "$MULT_LOOP" iterations with doubles and NO openmp : "$NUMBER_OF_OPS_MULT_BIG" operations";
	#	{ time ./target/debug/test_matrix_big m $MULT_LOOP d < test_mat.txt ; } 2>> perfs.txt;
	#	echo "done";
	echo "#########        END OF TEST      #########" >> perfs.txt;
	echo "" >> perfs.txt;
#Separating tests
echo "######################################################################################################";
echo "Tests with O3 and openmp and SSE";
echo "######################################################################################################";
#switching make file
mv Makefile MakefileNOpenmpO3;
mv MakefileOpenmpO3SSE Makefile;
echo "switched makefiles";
#clean
make clean > /dev/null 2>&1;
if [ $? == O ]
then
	echo "Failed to clean";
	exit 1;
else
	echo "Cleant successfully";
fi
#compile
make  > /dev/null 2>&1;
if [ $? == O ]
then
	echo "Failed to make";
	exit 1;
else
	echo "Made application successfully for O3 and openmp and SSE";
fi
#execute
	echo "######## test with openmp and O3 and SSE #######" >> perfs.txt;
	#addition matrice small addition $ADD_LOOP iterations with floats and openmp and SSE
		echo "addition matrice small addition "$ADD_LOOP" iterations with floats and openmp and SSE : "$NUMBER_OF_OPS_ADD_SMALL" operations" >> perfs.txt;
		echo "addition matrice small addition "$ADD_LOOP" iterations with floats and openmp and SSE : "$NUMBER_OF_OPS_ADD_SMALL" operations";
		{ time ./target/debug/test_matrix_small a $ADD_LOOP f < test_mat.txt ; } 2>> perfs.txt;
		echo "done";
	#addition matrice small addition $ADD_LOOP iterations with doubles and NO openmp
	#	echo "" >> perfs.txt;
	#	echo "addition matrice small addition "$ADD_LOOP" iterations with doubles and NO openmp : "$NUMBER_OF_OPS_ADD_SMALL" operations" >> perfs.txt;
	#	echo "addition matrice small addition "$ADD_LOOP" iterations with doubles and NO openmp : "$NUMBER_OF_OPS_ADD_SMALL" operations";
	#	{ time ./target/debug/test_matrix_small a $ADD_LOOP d < test_mat.txt ; } 2>> perfs.txt;
	#	echo "done";
	#addition matrice big addition $ADD_LOOP iterations with floats and NO openmp
		echo "" >> perfs.txt;
		echo "addition matrice big addition "$ADD_LOOP" iterations with floats and openmp and SSE : "$NUMBER_OF_OPS_ADD_BIG" operations" >> perfs.txt;
		echo "addition matrice big addition "$ADD_LOOP" iterations with floats and and openmp and SSE : "$NUMBER_OF_OPS_ADD_BIG" operations";
		{ time ./target/debug/test_matrix_big a $ADD_LOOP f < test_mat.txt ; } 2>> perfs.txt;
		echo "done";
	#addition matrice big addition $ADD_LOOP iterations with doubles and NO openmp
	#	echo "" >> perfs.txt;
	#	echo "addition matrice big addition "$ADD_LOOP" iterations with doubles and NO openmp : "$NUMBER_OF_OPS_ADD_BIG" operations" >> perfs.txt;
	#	echo "addition matrice big addition "$ADD_LOOP" iterations with doubles and NO openmp : "$NUMBER_OF_OPS_ADD_BIG" operations";
	#	{ time ./target/debug/test_matrix_big a $ADD_LOOP d < test_mat.txt ; } 2>> perfs.txt;
	#	echo "done";
	#multiplication matrice small multiplication $MULT_LOOP iterations with floats and NO openmp
		echo "" >> perfs.txt;
		echo "multiplication matrice small multiplication "$MULT_LOOP" iterations with floats and openmp and SSE : "$NUMBER_OF_OPS_MULT_SMALL" operations" >> perfs.txt;
		echo "multiplication matrice small multiplication "$MULT_LOOP" iterations with floats and openmp and SSE : "$NUMBER_OF_OPS_MULT_SMALL" operations";
		{ time ./target/debug/test_matrix_small m $MULT_LOOP f < test_mat.txt ; } 2>> perfs.txt;
		echo "done";
	#multiplication matrice small multiplication $MULT_LOOP iterations with doubles and NO openmp
	#	echo "" >> perfs.txt;
	#	echo "multiplication matrice small multiplication "$MULT_LOOP" iterations with doubles and NO openmp : "$NUMBER_OF_OPS_MULT_SMALL" operations" >> perfs.txt;
	#	echo "multiplication matrice small multiplication "$MULT_LOOP" iterations with doubles and NO openmp : "$NUMBER_OF_OPS_MULT_SMALL" operations";
	#	{ time ./target/debug/test_matrix_small m $MULT_LOOP d < test_mat.txt ; } 2>> perfs.txt;
	#	echo "done";
	#multiplication matrice big multiplication $MULT_LOOP iterations with float and NO openmp
		echo "" >> perfs.txt;
		echo "multiplication matrice big multiplication "$MULT_LOOP" iterations with floats and openmp and SSE : "$NUMBER_OF_OPS_MULT_BIG" operations" >> perfs.txt;
		echo "multiplication matrice big multiplication "$MULT_LOOP" iterations with floats and openmp and SSE : "$NUMBER_OF_OPS_MULT_BIG" operations";
		{ time ./target/debug/test_matrix_big m $MULT_LOOP f < test_mat.txt ; } 2>> perfs.txt;
		echo "done";
	#multiplication matrice big multiplication $MULT_LOOP iterations with doubles and NO openmp
	#	echo "" >> perfs.txt;
	#	echo "multiplication matrice big multiplication "$MULT_LOOP" iterations with doubles and NO openmp : "$NUMBER_OF_OPS_MULT_BIG" operations" >> perfs.txt;
	#	echo "multiplication matrice big multiplication "$MULT_LOOP" iterations with doubles and NO openmp : "$NUMBER_OF_OPS_MULT_BIG" operations";
	#	{ time ./target/debug/test_matrix_big m $MULT_LOOP d < test_mat.txt ; } 2>> perfs.txt;
	#	echo "done";
	echo "#########        END OF TEST      #########" >> perfs.txt;
#restore makefile
mv Makefile MakefileOpenmpO3SSE
mv MakefileOpenmpO0 Makefile
#libère les variables locales
unset ADD_LOOP;
unset MULT_LOOP;
unset SIZE_OF_SMALL;
unset SIZE_OF_BIG;
unset NUMBER_OF_OPS_ADD_SMALL;
unset NUMBER_OF_OPS_ADD_BIG;
unset NUMBER_OF_OPS_MULT_SMALL;
unset NUMBER_OF_OPS_MULT_BIG;
