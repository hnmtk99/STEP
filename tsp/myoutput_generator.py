from common import format_tour, read_input

import solver_greedy2opt

CHALLENGES = 7

def generate_sample_output(solver, name):
    for i in range(CHALLENGES):
        cities = read_input(f'input_{i}.csv')
        tour = solver.solve(cities)
        # my_output/に作る
        with open(f'my_output/{name}_{i}.csv', 'w') as f:
            f.write(format_tour(tour) + '\n')

if __name__ == '__main__':
    #solver, name = select_solution()
    generate_sample_output(solver_greedy2opt, 'greedy2opt')