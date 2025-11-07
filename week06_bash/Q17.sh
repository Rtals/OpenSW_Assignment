#! /bin/bash

file_wordcnt() {
    files=$(ls *.txt)
    for f in $files; do
        wordcnt=$(cat $f | wc -w)
        echo "$f 파일의 단어는 $wordcnt 개 입니다."
    done
}

file_wordcnt