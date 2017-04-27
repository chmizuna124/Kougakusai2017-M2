Kougakusai2017-M2
===============

工学祭2017のM2の出し物のリポジトリです

##ソース/ディレクトリの追加について

ソース(`.cpp`)を追加した場合には，`app.cfg`，`Makefile.inc`にオブジェクトファイルを追記してください．

ディレクトリを追加した場合には，`Makefile.appmod`の`SRCDIRS`に追記してください．

##コンパイルについて

まず，環境変数`EV3_ROOT`を， ev3rt の workspace に通してください．

`.zprofile`や`.bash_profile`に，以下を参考に追記すると良いでしょう．

```bash
export EV3_ROOT=/path/to/ev3rt-beta5-release/hrp2/workspace 
```

その後，`src`ディレクトリ直下にて`make`コマンドを実行すると，`selab`が生成されます．これを，SDカードの`ev3rt/apps/`直下に配置してください．

##その他

ロガーによるログファイル(`.log`)及び生成したアプリケーション(`selab`)は git の管理下から除外しておきました．

##センサーとモーターのポート
未定
