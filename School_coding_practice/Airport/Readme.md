#Airport
![image](https://user-images.githubusercontent.com/100823955/223295486-0c3a36c9-f67e-4b3e-9cc8-e28fc178b955.png)
![image](https://user-images.githubusercontent.com/100823955/223295505-b05a6c28-c1f1-4a39-8426-c3053b66c530.png)
-------------------------
## 🎉 코드 설명
+ 문제가 대기열을 STL Queue를 사용하라는 문제라고 생각했다.
+ 우선, 대기열이 20개 이하라고 했으므로, int를 저장하는 Queue를 20개 만들어놓고 시작했다.
+ 각 대기열(Q)의 front 부분을 비교해서 더 작은 값이 먼저 출력이 되어야한다.
+ 각 Q의 front 부분을 비교하여 최소값을 저장할 때, 0이 아닌 값만 비교해야한다.
+ 만약, 각 Q의 front 값이 동일한 경우 Q배열의 idx가 낮은 것을 먼저 출력해야하므로, 그런 경우idx값을
갱신하지 않고 continue로 바로 다음 반복문으로 넘어갔다.
+ 위의 방식으로 while문을 계속해서 돌다가, Q[0] ~ Q[20] 배열의 크기중에서 max 값이 while 반복의 횟수가 되면 모든 Q의 비교와 출력이 끝난것이다.
