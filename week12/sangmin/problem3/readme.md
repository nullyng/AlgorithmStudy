# 문제 개요

문제 : [구명보트](https://school.programmers.co.kr/learn/courses/30/lessons/42885)

문제 분류 : 그리디

# 문제 풀이

구명보트에 탈 수 있는 인원은 최대 2명이다. 따라서 모든 인원을 무게에따라 정렬한 뒤, 가장 무거운 인원과 가장 가벼운 인원을 비교해가며 둘 다 태울 수 있는 경우

둘 다 태우고 기본적으로 무거운 인원부터 채워넣는다.

가벼운 인원을 나타내는 left와 무거운 인원을 나타내는 right를 두어 left <= right일동안 작업한다. 