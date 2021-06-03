# ALEX COMMENT:  test pull request - please merge
# pages と links を作成
def read_fdata(pages, links, size):
  with open('data/pages{}.txt'.format(size)) as f:
    for data in f.read().splitlines():
      page = data.split('\t')
      # page[0]: id, page[1]: title
      pages[page[0]] = page[1]

  with open('data/links{}.txt'.format(size)) as f:
    for data in f.read().splitlines():
      link = data.split('\t')
      # link[0]: id (from), links[1]: id (to)
      if link[0] in links:
        links[link[0]].add(link[1])
      else:
        links[link[0]] = {link[1]}


# スタート・ゴールのタイトルからID取得
def start_goal_id(pages, start_point, goal_point):
  for id, title in pages.items():
    if title == start_point:
      start_id = id
    elif title == goal_point:
      goal_id = id 
  return start_id, goal_id


def bfs(pages, links, start, goal):
  que = []
  is_visited = {key: 0 for key in pages.keys()}
  path = {key: -1 for key in links.keys()}

  for next_node in list(links[start]):
    que.append(next_node) # startから直に進めるノードをqueに追加
    is_visited[next_node] = 1 # そのノードは発見状態(1)
    path[next_node] = start

  is_visited[start] = 2

  while is_visited[goal] != 2 and len(que) > 0:
    current = que.pop(0)
    is_visited[current] = 2

    if current == goal:
      break
    elif current in links:
      for n_node in list(links[current]):
        que.append(n_node) # startから直に進めるノードをqueに追加
        is_visited[n_node] = 1 # そのノードは発見状態(1)
        path[n_node] = current
  print('bfs終了')
  print_path(path, pages, start, goal)


# goalからたどって経路を表示
def print_path(path, pages, start, goal):
  tmp = goal
  route = [pages[goal]]
  while path[tmp] != start:
    route.insert(0,pages[path[tmp]])
    tmp = path[tmp]
  route.insert(0,pages[path[tmp]])
  print(route)


pages = {}
links = {}
size = '_small' # '_small'はテストデータ, ''は標準データ

read_fdata(pages, links, size)
start_title = 'Google'
goal_title = '量子コンピュータ'
start_id, goal_id = start_goal_id(pages, start_title, goal_title)
bfs(pages, links, start_id, goal_id)
