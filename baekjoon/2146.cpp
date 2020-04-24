#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <vector>

using namespace std;
using Board = vector<vector<bool>>;
using Coord = struct {int y, x; };

int N;

bool inRange(int y , int x){
    return 0 <= y && y < N && 0 <= x && x < N;
}

int bfs(Board &b, Board &v, int y , int x){
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};

    queue<pair<Coord, int>> q;
    Board land(N, vector<bool>(N, false));
    q.push(make_pair(Coord{y,x}, 0));
    land[y][x] = true;

    // search land
    while(!q.empty()){
        auto c = q.front();
        auto p = c.first;
        q.pop();

        for (int i =0;i <4;i++){
            int ny = p.y+dy[i], nx = p.x+dx[i];
            if (inRange(ny, nx) && b[ny][nx] && !land[ny][nx]){
                land[ny][nx] = true;
                v[ny][nx] = true;
                q.push(make_pair(Coord{ny,nx}, 0));
            }
        }
    }

    // search minimum length bridge from current land
    q.push(make_pair(Coord{y,x}, 0));
    Board search(N, vector<bool>(N, false));
    int min_dist = INT_MAX;
    while(!q.empty()) {
        auto c = q.front();
        auto p = c.first;
        int dist = c.second;
        q.pop();

        for (int i =0;i <4;i++){
            int ny = p.y+dy[i], nx = p.x+dx[i];
            if (inRange(ny, nx) && !search[ny][nx]){
                if (land[ny][nx]){
                    search[ny][nx] = true;
                    q.push(make_pair(Coord{ny,nx}, 0));
                    continue;
                }
                if (b[ny][nx]) {
                    min_dist = min(min_dist, dist);
                    continue;
                }

                search[ny][nx] = true;
                q.push(make_pair(Coord{ny,nx}, dist+1));
            }
        }
    }

    return min_dist;
}

int main() {
    cin >> N;
    Board b(N, vector<bool>(N));

    for (int i=0;i <N;i++){
        for (int j =0 ;j<N;j++){
            int k; cin >> k;
            b[i][j] = k >0;
        }
    }

    int minimum = INT_MAX;
    Board visited(N, vector<bool>(N));
    for (int i =0;i <N;i++){
        for (int j= 0;j< N ;j++ ){
            if (b[i][j] && !visited[i][j]) {
                minimum = min(minimum, bfs(b,visited, i,j));
            }
        }
    }

    cout << minimum;
    return 0;
}