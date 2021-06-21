# malloc challenge

### 初期状態
- 講義で説明された、Linked listの実装がsimple_malloc.cにある
- simple_malloc.cの実行結果
```
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

### Best Fit　実行結果
```
Challenge 1: simple malloc => my malloc
Time: 11 ms => 1533 ms
Utilization: 70% => 70%
==================================
Challenge 2: simple malloc => my malloc
Time: 6 ms => 536 ms
Utilization: 40% => 40%
==================================
Challenge 3: simple malloc => my malloc
Time: 138 ms => 847 ms
Utilization: 8% => 50%
==================================
Challenge 4: simple malloc => my malloc
Time: 42407 ms => 9131 ms
Utilization: 15% => 71%
==================================
Challenge 5: simple malloc => my malloc
Time: 29970 ms => 6011 ms
Utilization: 15% => 74%
==================================
```
