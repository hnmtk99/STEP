# class5での同ネームファイルを改善
# Greedy法 + 2-opt法
import random
import sys
import math

from common import get_tour_length, print_tour, read_input

# AB+CD よりも AC+BD の方が短ければ交換
def swap_path(tour,i, j, dist):
    N = len(tour)
    A, B, C, D = tour[i], tour[i+1], tour[j], tour[(j+1) % N] # jが最終だとj+1では都合悪い
    if dist[A][B] + dist[C][D] > dist[A][C] + dist[B][D]:
        tour[i+1:j+1] = reversed(tour[i+1:j+1])

def distance(city1, city2):
    return math.sqrt((city1[0] - city2[0]) ** 2 + (city1[1] - city2[1]) ** 2)

# swap_pathで改善
def improve_tour(dist, tour):
    N = len(tour)
    can_improve = True
    while can_improve:
        original_length = get_tour_length(tour, dist)
        for i in range(N):
            for j in range(i+2, N):
                swap_path(tour, i, j, dist)
        if get_tour_length(tour, dist) >= original_length:
            can_improve = False

# 中身はsampleのgreedyと同様
def solve_each(dist, start_city=0):
    N = len(dist[0])

    unvisited_cities = set(range(0, N))
    unvisited_cities.remove(start_city)
    tour = [start_city]
    current_city = start_city

    while unvisited_cities:
        next_city = min(unvisited_cities,
                        key=lambda city: dist[current_city][city])
        unvisited_cities.remove(next_city)
        tour.append(next_city)
        current_city = next_city
    
    improve_tour(dist, tour)
    return tour

def solve(cities):
    N = len(cities)
    start_points = range(N)
    tours = []
    dist = [[0] * N for i in range(N)]
    # 距離記録
    for i in range(N):
        for j in range(i, N):
            dist[i][j] = dist[j][i] = distance(cities[i], cities[j])
            
    # challenge6, 7: ランダムに選んだ1点で実行
    if N >= 2048:
        start_points = [random.randint(0, N-1)]

    # スタート地点を変えて実行
    for i in start_points:
        tours.append(solve_each(dist, i))
    tours_length = [get_tour_length(tour, dist) for tour in tours]
    shortest_tour = tours[tours_length.index(min(tours_length))]
    return shortest_tour

if __name__ == '__main__':
    assert len(sys.argv) > 1
    tour = solve(read_input(sys.argv[1]))
    print_tour(tour)
