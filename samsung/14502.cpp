//미로찾기랑 비슷

#include<iostream>
#include<algorithm>
#include<queue>
#define MAX 8

using namespace std;

int N, M; //N*M 직사각형 연구소 크기
int lab[MAX][MAX]; //연구실 지도
int polluted[MAX][MAX];
int visited[MAX][MAX];
int Min_virus = 0;
queue<pair<int, int> > virus_start_points;

int x_dir[4] = {-1, 1, 0, 0}; //상, 하, 좌, 우
int y_dir[4] = {0, 0, -1, 1};

queue<pair<int, int> > q; //이동할 좌표 저장된 큐

int bfs(int start_x, int start_y, int m[][MAX]){ //m은 세 개의 벽이 세워진 지도, start point는 지도 상 2가 있는 포인트들
  
  int virused = 2;
  m[start_x][start_y] = 2;

  q.push(make_pair(start_x, start_y));
  
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;

    q.pop();

    for (int i=0; i<4; i++){
      int x_new = x + x_dir[i];
      int y_new = y + y_dir[i];

      if((0 <= x_new && x_new < N) && (0 <= y_new && y_new < M) && (m[x_new][y_new] == 0)){
        m[x_new][y_new] = 2;
        q.push(make_pair(x_new, y_new));
        virused += 2;
      }
    }
  }

  return virused;
}

int combination_wall(int m[][MAX]){

    for (int j = 0; j < N; j++){
      for (int k = 0; k < M; k++){
        if(m[j][k] == 0 && cnt != 0)
          m[j][k] = 1;
      }
  }
  return 0;
}

int main(){
  
  cin >> N >> M;

  //3 <= N, M <= 8
  if ((N < 3 || 8 < N) || (M < 3 || 8 < M))
    return 0; 
  
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> lab[i][j];
      if (lab[i][j] == 2)
        virus_start_points.push(make_pair(i, j));
    }
  }
  return 0;
}

벽을 세울 수 있는 모든 조합에 대해 바이러스 전파 시뮬레이션 돌려서
가장 2가 적은 경우를 찾으면 됨

벽을 세우는 조합에 대한 클래스, 벽 세운 지도에서 바이러스 전파할 bfs
바이러스 시작점 찾아서 저장해놓아야 됨.