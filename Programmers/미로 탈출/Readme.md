# 프로그래머스 Lv. 2 미로 탈출
---------------
## 🎉 해결한 부분
- pair를 사용하여 maps의 point를 저장하는 것.

## 🎉 해결하지 못한 부분
- 그래프 탐색 알고리즘(BFS, DFS) 중 하나를 생각해냈어야 했는데, 생각하지 못했음.
	- [BFS 알고리즘](https://github.com/Sangh0Yoon/Tech_Interview_preparation/blob/main/Algorithm/README.md#%EC%8B%9C%EA%B0%84-%EB%B3%B5%EC%9E%A1%EB%8F%84-time-complexity)으로 풀 수 있다.
## 🎉 해결하지 못한 부분 풀이.
- 상하좌우를 dx, dy 배열로 표현
- 방문한 노드를 표시하기 위한 배열 visited
- queue에 pair를 push할 때 { } 쓰는것을 반드시 유의할 것.
- while(!q.empty())를 통해 모든 queue를 순회할 수 있다.
- if(cur_x == dest.first && cur_y == dest.second) 를 통해 목적지에 도착했으면 time을 최소로 초기화.
- while loop 내부 for문을 통해 상하좌우를 모두 edge로 보고 queue에 삽입.
  - 이때, 인덱스 범위를 벗어나거나, 이미 방문한 노드의 경우 continue
- return에서 만약 time의 값이 안바뀌었으면 최단경로를 찾지 못한 것임.
- main문 return에서는 최단 경로를 찾지 못했을 경우와 레버를 찾지 못했을 경우에는 -1을 리턴함.
