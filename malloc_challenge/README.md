# malloc challenge

### 初期状態
- 講義で説明された、Linked listの実装がsimple_malloc.cにある
- simple_malloc.cの実行結果
```
% make run
./malloc_challenge.bin
Challenge 1: simple malloc => my malloc
Time: 11 ms => 821 ms
Utilization: 70% => 3%
==================================
Challenge 2: simple malloc => my malloc
Time: 7 ms => 764 ms
Utilization: 40% => 0%
==================================
Challenge 3: simple malloc => my malloc
Time: 124 ms => 759 ms
Utilization: 8% => 0%
==================================
Challenge 4: simple malloc => my malloc
Time: 45389 ms => 1161 ms
Utilization: 15% => 21%
==================================
Challenge 5: simple malloc => my malloc
Time: 32985 ms => 1021 ms
Utilization: 15% => 16%
==================================
```

### First Fit -> Best Fit
