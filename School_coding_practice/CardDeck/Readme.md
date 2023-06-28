![image](https://user-images.githubusercontent.com/100823955/224949620-b93d9546-03c8-4f58-97da-c7149e525236.png)
![image](https://user-images.githubusercontent.com/100823955/224949579-431e58c7-c96f-4944-b9f4-38edfe34c683.png)
------------
## 🎉 코드 설명
+ 처음에 카드덱의 사이즈와 Shuffle, Cut 명령어를 몇 번 입력받을지의 N,K를 입력받는다.
+ 먼저, deck 벡터를 1~N 의 숫자들로 채워놓고 시작한다.
+ 명령어를 K번동안 입력받으면서, 명령어가 Cut 인지 Shuffle인지를 String의 compare 함수를 사용하여
조건처리하였다.
+ shuffle인 경우에는 i, i+2/N 의 순서대로 덱이 저장된다.
+ cut의 경우에는 인덱스가 cut의 범위에 속하면 temp1에, 속하지않으면 temp2에 저장한 후
반복문을 돌면서, deck에 temp2를 먼저 복사하고, temp1을 후에 복사한다.
+ deck에 shuffle, cut 된 것들을 저장하기전에 clear를 통해 벡터를 비워준다.
