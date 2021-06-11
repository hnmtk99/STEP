# Google STEP 2021: Travelling Salesman Problem Challenges

Originally By: Hayato Ito (hayato@google.com)  
2020, 2021 Versions By: Hugh O'Cinneide (hughoc@google.com)  

Answered By: Hina Moteki 

## 実行方法
```
python myoutput_generator.py
```

## スコア確認方法
```
python output_verifier.py
```
sampleのoutput_verifierの19行目に、'my_output/greedy2opt'を書き加えた。


## 改善アルゴリズム
### Greedy法＋2-opt法
- sampleのGreedy法で得られた巡回路を用いる
- 以下を改善ができなくなるまで繰り返す
  - 適当な都市aを選び、巡回路でaの次の都市をbとする
  - 都市aの近傍N都市からa, b以外の都市cと、巡回路でcの次の都市dを選ぶ
  - ab+cd > ac+bd であれば辺ab, cdをac, bdに入れ替える
    
## 結果
|  Challenge 0  |  Challenge 1  |  Challenge 2  |  Challenge 3  |  Challenge 4  |  Challenge 5  |  Challenge 6  |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|  3,418.10  |  3,832.29  |  5,065.58  |  9,276.22  |  12,084.32  |  24,191.66  |  47,822.41  |
