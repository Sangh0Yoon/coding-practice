#Cafe
------------------
![image](https://user-images.githubusercontent.com/100823955/223319999-4cf03521-9b8e-407d-bb2d-10c1f7373ad6.png)
![image](https://user-images.githubusercontent.com/100823955/223320054-c9bcdf14-b3ee-41a6-8a81-d31a88952a47.png)
![image](https://user-images.githubusercontent.com/100823955/223320065-d6464de5-f330-4493-a458-0f4892b4eae1.png)
------------------
## 🎉 코드 설명
+ 손님이 카페에 들어오고 나갈 수 있으므로, 데이터의 삽입과 삭제가 용이해야한다고 판단.
+ list 자료구조를 사용했음.
+ seat_info 구조체를 만들어, 손님 ID, 좌석 번호, 좌석간의 거리를 필드로 선언하였음.
+ 만약, 이미 들어온 손님의 id가 한 번 더 입력이 된다면 already 함수로 들어가서 입력받은 id와 좌석에 앉아있는 손님의 id가 같을 때 iterator를 반환받는다.
+ 그리고 중복된 id의 list가 삭제되기 위해서는 삭제될 리스트 이전의 원소의 좌석간 거리가 업데이트 된 후 삭제가 되어야한다.
+ 다음에 들어올 리스트의 좌석 번호는 이전에 들어온 리스트의 좌석번호 + 좌석간거리 + 1이다.
+ 리스트를 순회하면서 max_dist를 찾아내고, max_dist인 위치의 반복자를 기억한다.
+ 이렇게 되면 seating 함수가 호출될 때마다, 이전 좌석과 다음 좌석의 distance가 계속해서 갱신되면서 문제를 풀 수 있다. 
