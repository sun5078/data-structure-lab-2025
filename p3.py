from collections import deque
# 프로젝트 문제 3번
input_map = [[4, 3, 2, 1],
             [0, 0, 0, 0],
             [0, 0, 9, 0],
             [1, 2, 3, 4]]
N = 4

def problem3(input_map):
    dx = [-1, 0, 0, 1]
    dy = [0, -1, 1, 0]
    
    forest = [row[:] for row in input_map]
    bear_size = 2
    honey_eaten = 0
    time = 0

    # 곰의 초기 위치 찾기
    for i in range(N):
        for j in range(N):
            if forest[i][j] == 9:
                x, y = i, j
                forest[i][j] = 0

    def bfs(x, y, size):
        visited = [[-1] * N for _ in range(N)]
        q = deque()
        q.append((x, y))
        visited[x][y] = 0
        edible = []

        while q:
            cur_x, cur_y = q.popleft()
            for i in range(4):
                nx = cur_x + dx[i]
                ny = cur_y + dy[i]
                if 0 <= nx < N and 0 <= ny < N and visited[nx][ny] == -1:
                    if forest[nx][ny] <= size:
                        visited[nx][ny] = visited[cur_x][cur_y] + 1
                        q.append((nx, ny))
                        if 0 < forest[nx][ny] < size:
                            edible.append((visited[nx][ny], nx, ny))

        edible.sort()
        return edible

    while True:
        targets = bfs(x, y, bear_size)
        if not targets:
            break

        dist, nx, ny = targets[0]
        time += dist
        forest[nx][ny] = 0
        x, y = nx, ny
        honey_eaten += 1

        if honey_eaten == bear_size:
            bear_size += 1
            honey_eaten = 0

    return time

result = problem3(input_map)
print(result)  # 출력: 14
