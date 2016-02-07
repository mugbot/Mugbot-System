www.mugbot.com
の「マグボットの作り方」に掲載しているソーシャルロボットマグボットの４つのソフトです。

mugbot-web-1.1.html
PC、タブレット、スマホのブラウザーから操作するマグボットの操作インタフェースです。
Raspberry Piの/var/www/html/に設置します。

mugbot-server-1.1.rb
RubyによるWebSocketサーバーです。
Raspberry Piの/home/pi/に設置します。

mugbot_arduino_1.1.ino
Arduinoのプログラムです。右目をArduinoのUNOに対応するために13ピンから６ピンに変更しました。
また、MAD 1.1 (Mugbot Action Designer）に対応するために、「k」を受信すると、口のLEDのみを消灯するようにしました。

mugbot-talk-1.1.sh
Open JTalkによるマグボットの音声合成のシェルスクリプトです。
Raspberry Piの/home/pi/に設置します。
