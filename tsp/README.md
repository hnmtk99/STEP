# Google STEP 2021: Travelling Salesman Problem Challenges

Originally By: Hayato Ito (hayato@google.com)  
2020, 2021 Versions By: Hugh O'Cinneide (hughoc@google.com)  

## 実行方法
```
python myoutput_generator.py
```
my_outputフォルダにgreedy2opt_x.csvが作られる。

## スコア確認方法
```
python output_verifier.py
```
sampleのoutput_verifierの19行目に、'my_output/greedy2opt'を書き加えた。


## 改善アルゴリズム
### Greedy法でスタート地点を変えて実行
- sampleのGreedy法で得られた巡回路を用いる
    
## 結果
|  Challenge 0  |  Challenge 1  |  Challenge 2  |  Challenge 3  |  Challenge 4  |  Challenge 5  |  Challenge 6  |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- |
|  3,418.10  |  3,832.29  |  5,065.58  |  9,276.22  |  12,084.32  |  24,191.66  |  47,822.41  |
