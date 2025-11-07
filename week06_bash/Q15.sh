#! /bin/bash

file_wordcnt() {
    echo "$FILE 파일의 단어의 개수는 $(cat $FILE | wc -w)개 입니다."
}

read -p "Enter a file name: " FILE
file_wordcnt $FILE