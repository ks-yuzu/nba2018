(リポジトリ内のファイルについて)

# test1 ディレクトリ
- test1.cpp                  : Test-1 の C++ 実装
  + S が[a-zA-Z0-9]+ であることを利用して数字で分割した各部分文字列が大文字を含むかどうかで判定
- test1.pl                   : Test-1 の Perl 実装
  + 正規表現を用いて条件に合う部分文字列を探索
- t/ ディレクトリ            : テスト用ファイル
  + test1 ディレクトリ内で prove コマンド ($ prove -v 等) で実行可能
  + prove コマンドの引数に *.t ファイルを指定しても実行可能

# test2 ディレクトリ
- test2-create.sql           : テスト用テーブルの作成SQL
- test2.sqlite               : test2-create.sql で作成した SQLite3 のデータ
- test2-query.sql            : Test-2 の解答のクエリ (employee.dept_id のチェック無し)
- test2-query-with-check.sql : Test-2 の解答のクエリ (employee.dept_id のチェック有り)

# test3 ディレクトリ
- test3.cpp                  : Test-3 の C++ 実装
