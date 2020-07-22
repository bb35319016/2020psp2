# 課題4 レポート

bb35319016 河内元希

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明

c6~11:ID、性別、身長の構造体を宣言

c24~80:ファイルを読み込みそれぞれ格納

c82~110:IDを聞き対応するIDがあればデータを出力、無ければ”No data"と出力



## 入出力結果
```
input the filename of sample:../sample/heights.csv
the filename of sample: ../sample/heights.csv
input the filename of sample ID ?:../sample/IDs.csv
the filename of sample ID:../sample/IDs.csv
Which ID's date do you want? :45313125
---
ID : 45313125
gender : Female
heights : 152.40

ーーーーーーーーーーーーー
input the filename of sample:../sample/heights.csv
the filename of sample: ../sample/heights.csv
input the filename of sample ID ?:../sample/IDs.csv
the filename of sample ID:../sample/IDs.csv
Which ID's date do you want? :35319016
---
NO date
```


例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴
[comment #20200722]
- データのスペルを間違えています. date -> data
- l.13 #define をつかいましょう.  
#define NUM 15 のように. 
ただ15というのは何の数字でしょうか. heights.csvは15行ありますが, データは14人分なので14を使った方が良いかと思います. 
- iの初期値はゼロなので, l.36からのwhileループ内の [i-1] は負の値になってしまうと思います.  
ファイルの1行目を飛ばしたかったのでしょうか. whileに入る前に fgets を一回行えば, whileの中では2行目以降の処理ができると思います. 
- インデントは揃えましょう

