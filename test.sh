#!/bin/bash

# Compiler Tester!

# Default Directory Search Path and Compiler Output Paths
INPUT_DIR="./tests"
OUTPUT_DIR="./my_outputs"

# Default Configurations
LEXER="uccompiler.l"
COMPILER_FLAGS="-l"

function run_tests() {
    for file_path in $1/*.uc; do
        ucfile=$(basename "$file_path")
        outfile="my_"${ucfile%.*}.out
        ./$UC_COMPILER $COMPILER_FLAGS <$file_path >$2/$outfile
    done
    echo "
    The test files' outputs are ready. Check ./my_outputs for the files.
    "
}

function compile() {
    flex $1 && clang-3.9 -Wall -Wno-unused-function lex.yy.c -o $2
}

if [ $# -eq 0 ]; then
    echo "
    Usage: ./test.sh [compiler] [-args="compiler_args"]
    Description:

        [compiler] -> REQUIRED
            The name / path of the compiler executable. 
            If the name suplied for the executable does not correspond to a existing executable
            the script will atempt to generate one for you using the default .l file (uccompiler.l)
            or the one that you specify using the -lex flag.

            NOTE: Everytime that the changes are made to the .l file the script will attempt to recompile

        [-args="FLAGS"] -> OPTIONAL
            A string with space separated flags that will be passed to the compiler.
            NOTE: There is the option to always provide a bunch of flags by default. To achive this
            edit the COMPILER_FLAGS
            
    Example Usage: 
        user@computer$ ./test.sh uccompiler
    "
    exit 1

else
    UC_COMPILER=$1
    for option in "$@"; do
        case $option in
        -args=* | --compiler-arguments=*)
            COMPILER_FLAGS="${option#*=}"
            shift
            ;;
        esac
    done

    [[ ! -f $LEXER ]] && (echo -e "${RED}ERROR:${RESET} $LEXER file does not exist!" && exit 1)

    if [[ ! -f $UC_COMPILER || $LEXER -nt $UC_COMPILER ]]; then
        echo -e "${BLUE}INFO:${RESET} Compiling... "

        compile $LEXER $UC_COMPILER

        if [ $? -eq 0 ]; then
            echo -e "${GREEN}DONE!${RESET}"
        else
            echo -e "${RED}FAILED!!${RESET}"
            exit 1
        fi
    fi
    run_tests $INPUT_DIR $OUTPUT_DIR
fi